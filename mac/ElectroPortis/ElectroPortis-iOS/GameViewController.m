//
//  GameViewController.m
//  ElectroPortis-iOS
//
//  Created by Brendan Shanks on 3/14/16.
//  Copyright © 2016 Brendan Shanks. All rights reserved.
//

#import "GameViewController.h"

#include "ep.h"

@interface GameViewController () {
}
@property (strong, nonatomic) EAGLContext *context;

- (void)setupGL;
- (void)tearDownGL;

@end

@implementation GameViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    
    [self setupGL];
}

- (void)dealloc
{    
    [self tearDownGL];
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];

    if ([self isViewLoaded] && ([[self view] window] == nil)) {
        self.view = nil;
        
        [self tearDownGL];
        
        if ([EAGLContext currentContext] == self.context) {
            [EAGLContext setCurrentContext:nil];
        }
        self.context = nil;
    }

    // Dispose of any resources that can be recreated.
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)setupGL
{
    [EAGLContext setCurrentContext:self.context];
    
    self.preferredFramesPerSecond = 30;
    
    init_ep();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Call reshape() with the screen resolution
    {
        // Get view dimensions in pixels
        UIScreen *mainscr = [UIScreen mainScreen];
        
        GLsizei backingPixelWidth  = (GLsizei)(mainscr.currentMode.size.width);
        GLsizei backingPixelHeight = (GLsizei)(mainscr.currentMode.size.height);
        
        NSLog(@"reshape %d %d", backingPixelWidth, backingPixelHeight);
        
        reshape__GiT1(backingPixelWidth, backingPixelHeight);
    }
}

- (void)tearDownGL
{
    [EAGLContext setCurrentContext:self.context];
}

#pragma mark - GLKView and GLKViewController delegate methods

- (void)update
{
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    //glClearColor(0.65f, 0.65f, 0.65f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    display__Gv(NULL);
}

- (void)viewWillLayoutSubviews
{

}

- (void)viewDidLayoutSubviews
{

}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator
{

}

@end
