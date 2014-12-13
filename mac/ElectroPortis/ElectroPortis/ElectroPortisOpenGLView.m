//
//  ElectroPortisOpenGLView.m
//  ElectroPortis
//
//  Created by Brendan Shanks on 12/8/14.
//  Copyright (c) 2014 Brendan Shanks. All rights reserved.
//

#import "ElectroPortisOpenGLView.h"

#include "ep.h"

#include <OpenGL/gl.h>

@interface ElectroPortisOpenGLView()
{
    CVDisplayLinkRef displayLink; // display link for managing rendering thread
}
@end

@implementation ElectroPortisOpenGLView

- (void)prepareOpenGL
{
    [super prepareOpenGL];

    // Synchronize buffer swaps with vertical refresh rate
    GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];
    
    // Create a display link capable of being used with all active displays
    CVDisplayLinkCreateWithActiveCGDisplays(&displayLink);
    
    // Set the renderer output callback function
    CVDisplayLinkSetOutputCallback(displayLink, &MyDisplayLinkCallback, (__bridge void *)(self));
    
    // Set the display link for the current renderer
    CGLContextObj cglContext = [[self openGLContext] CGLContextObj];
    CGLPixelFormatObj cglPixelFormat = [[self pixelFormat] CGLPixelFormatObj];
    CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext(displayLink, cglContext, cglPixelFormat);
    
    // Activate the display link
    CVDisplayLinkStart(displayLink);
    
    init_ep();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT);
}

// This is the renderer output callback function
static CVReturn MyDisplayLinkCallback(CVDisplayLinkRef displayLink, const CVTimeStamp* now, const CVTimeStamp* outputTime,
                                      CVOptionFlags flagsIn, CVOptionFlags* flagsOut, void* displayLinkContext)
{
    @autoreleasepool
    {
        CVReturn result = [(__bridge ElectroPortisOpenGLView*)displayLinkContext getFrameForTime:outputTime];
        return result;
    }
}

- (CVReturn)getFrameForTime:(const CVTimeStamp*)outputTime
{
    // Add your drawing codes here
    
    [[self openGLContext] makeCurrentContext];
    
    display__Gv(NULL);
    
    [[self openGLContext] flushBuffer];
    
    return kCVReturnSuccess;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
}

- (void)reshape
{
    // Get view dimensions in pixels
    NSRect backingBounds = [self convertRectToBacking:[self bounds]];

    GLsizei backingPixelWidth  = (GLsizei)(backingBounds.size.width);
    GLsizei backingPixelHeight = (GLsizei)(backingBounds.size.height);
    
    //NSLog(@"reshape %d %d", backingPixelWidth, backingPixelHeight);

    reshape__GiT1(backingPixelWidth, backingPixelHeight);
}

- (void)dealloc
{
    // Stop the display link BEFORE releasing anything in the view
    // otherwise the display link thread may call into the view and crash
    // when it encounters something that has been released
    CVDisplayLinkStop(displayLink);

    // Release the display link
    CVDisplayLinkRelease(displayLink);
}

@end
