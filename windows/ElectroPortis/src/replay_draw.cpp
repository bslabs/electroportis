/*
 * Copyright (C) 2014 Mark Laws
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
#include "stdafx.hpp"
#include "replay_draw.hpp"
#include "gl_wrap.h"
#include "saver.hpp"

SHRW2 g_replay_list_lock;
std::vector<gl_record_t> g_replay_list;

extern "C" {
void
wrap_glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha, const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glColor4f(r, g, b, alpha);
    if (1 < wincount)
        g_replay_list.push_back({ GLCOLOR4F, { r, g, b, alpha } });
}

void
wrap_glPushMatrix(const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glPushMatrix();
    if (1 < wincount)
        g_replay_list.push_back({ GLPUSHMATRIX, {} });
}

void
wrap_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z,
               const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glRotatef(angle, x, y, z);
    if (1 < wincount)
        g_replay_list.push_back({ GLROTATEF, { angle, x, y, z } });
}

void
wrap_glTranslatef(GLfloat x, GLfloat y, GLfloat z,
                  const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glTranslatef(x, y, z);
    if (1 < wincount)
        g_replay_list.push_back({ GLTRANSLATEF, { x, y, z } });
}

void
wrap_glPopMatrix(const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glPopMatrix();
    if (1 < wincount)
        g_replay_list.push_back({ GLPOPMATRIX, {} });
}

void
wrap_glScalef(GLfloat x, GLfloat y, GLfloat z, const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glScalef(x, y, z);
    if (1 < wincount)
        g_replay_list.push_back({ GLSCALEF, { x, y, z } });
}

void
wrap_glBegin(GLenum mode, const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glBegin(mode);
    if (1 < wincount)
        g_replay_list.push_back({ GLBEGIN, { mode } });
}

void
wrap_glVertex2f(GLfloat x, GLfloat y, const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glVertex2f(x, y);
    if (1 < wincount)
        g_replay_list.push_back({ GLVERTEX2F, { x, y } });
}

void
wrap_glEnd(const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glEnd();
    if (1 < wincount)
        g_replay_list.push_back({ GLEND, {} });
}

void
wrap_glClear(GLbitfield mask, const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glClear(mask);
    if (1 < wincount)
        g_replay_list.push_back({ GLCLEAR, { mask } });
}

void
wrap_glFinish(const void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glFinish();
    if (1 < wincount)
        g_replay_list.push_back({ GLFINISH, {} });
}

void
wrap_glEnableClientState(GLenum array, void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glEnableClientState(array);
    if (1 < wincount)
        g_replay_list.push_back({ GLENABLECLIENTSTATE, { array } });
}

void
wrap_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer, void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glVertexPointer(size, type, stride, pointer);
    if (1 < wincount)
        g_replay_list.push_back({ GLVERTEXPOINTER, { size, type, stride, pointer } });
}

void
wrap_glDrawArrays(GLenum mode, GLint first, GLsizei count, void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glDrawArrays(mode, first, count);
    if (1 < wincount)
        g_replay_list.push_back({ GLDRAWARRAYS , { mode, first, count } });
}

void
wrap_glDisableClientState (GLenum array, void *context)
{
    wincount_t wincount = *(static_cast<const wincount_t *>(context));
    glDisableClientState(array);
    if (1 < wincount)
        g_replay_list.push_back({ GLDISABLECLIENTSTATE, { array } });
}
}

void
replay_draw(void)
{
    for (const auto &list : g_replay_list) {
        const auto &args = list.second;

        switch (list.first) {
        case GLCOLOR4F:
            glColor4f(args[0], args[1], args[2], args[3]);
            break;

        case GLPUSHMATRIX:
            glPushMatrix();
            break;

        case GLROTATEF:
            glRotatef(args[0], args[1], args[2], args[3]);
            break;

        case GLTRANSLATEF:
            glTranslatef(args[0], args[1], args[2]);
            break;

        case GLPOPMATRIX:
            glPopMatrix();
            break;

        case GLSCALEF:
            glScalef(args[0], args[1], args[2]);
            break;

        case GLBEGIN:
            glBegin(args[0]);
            break;

        case GLVERTEX2F:
            glVertex2f(args[0], args[1]);
            break;

        case GLEND:
            glEnd();
            break;

        case GLCLEAR:
            glClear(args[0]);
            break;

        case GLFINISH:
            glFinish();
            break;

        case GLENABLECLIENTSTATE:
            glEnableClientState(args[0]);
            break;

        case GLVERTEXPOINTER:
            glVertexPointer(args[0], args[1], args[2], args[3]);
            break;

        case GLDRAWARRAYS:
            glDrawArrays(args[0], args[1], args[2]);
            break;

        case GLDISABLECLIENTSTATE:
            glDisableClientState(args[0]);
            break;

        default:
            assert(0);
        }
    }
}

void
clear_replay_list(void)
{
    g_replay_list.clear();
}