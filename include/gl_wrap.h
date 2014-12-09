/*
 * Copyright (C) 2014 Mark Laws
 * Moved out of replay_draw.hpp by Brendan Shanks
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

/* The wrap_gl* functions exist so the OpenGL calls can be intercepted and stored
 * for later playback/execution, in multiple OpenGL contexts if desired.
 *
 * Currently this functionality is only implemented on Windows, on all other
 * platforms the wrap_gl* functions are #defined straight to the gl* equivalent
 */

#ifdef _WIN32

#include "saver.hpp" // for wincount_t

#ifdef __cplusplus
extern "C" {
#endif
void wrap_glColor3f(GLfloat r, GLfloat g, GLfloat b, const wincount_t wincount);
void wrap_glPushMatrix(const wincount_t wincount);
void wrap_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glTranslatef(GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glPopMatrix(const wincount_t wincount);
void wrap_glScalef(GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glBegin(GLenum mode, const wincount_t wincount);
void wrap_glVertex2f(GLfloat x, GLfloat y, const wincount_t wincount);
void wrap_glEnd(const wincount_t wincount);
void wrap_glClear(GLbitfield mask, const wincount_t wincount);
void wrap_glFinish(const wincount_t wincount);
#ifdef __cplusplus
}
#endif

#else /* !_WIN32 */

#define wrap_glColor3f(r, g, b, wincount)        glColor3f(r, g, b)
#define wrap_glPushMatrix(wincount)              glPushMatrix()
#define wrap_glRotatef(angle, x, y, z, wincount) glRotatef(angle, x, y, z)
#define wrap_glTranslatef(x, y, z, wincount)     glTranslatef(x, y, z)
#define wrap_glPopMatrix(wincount)               glPopMatrix()
#define wrap_glScalef(x, y, z, wincount)         glScalef(x, y, z)
#define wrap_glBegin(mode, wincount)             glBegin(mode)
#define wrap_glVertex2f(x, y, wincount)          glVertex2f(x, y)
#define wrap_glEnd(wincount)                     glEnd()
#define wrap_glClear(mask, wincount)             glClear(mask)
#define wrap_glFinish(wincount)                  glFinish()

#endif /* !_WIN32 */
