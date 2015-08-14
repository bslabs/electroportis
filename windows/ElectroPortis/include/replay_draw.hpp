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
#pragma once

#include <GL/gl.h>

#include "gl_wrap.h"
#include "saver.hpp"

typedef enum gl_cmd {
    GLCOLOR4F,
    GLPUSHMATRIX,
    GLROTATEF,
    GLTRANSLATEF,
    GLPOPMATRIX,
    GLSCALEF,
    GLBEGIN,
    GLVERTEX2F,
    GLEND,
    GLCLEAR,
    GLFINISH
} gl_cmd;

#ifdef __cplusplus
#include "SHRWLocks.hpp"

struct gl_arg_t {
    gl_arg_t() {}

    gl_arg_t(const unsigned int ui)
        : ui(ui)
    {}

    gl_arg_t(const float f)
        : f(f)
    {}

    inline operator unsigned int() const { return ui; }
    inline operator float() const { return f; }
    gl_arg_t operator=(gl_arg_t& x) const { return *this; }

    union {
        // GLbitfield, GLenum, ...
        unsigned int ui;
        // GLfloat, ...
        float f;
    };
};

typedef std::vector<gl_arg_t> gl_args_t;
typedef std::pair<gl_cmd, gl_args_t> gl_record_t;

extern SHRW2 g_replay_list_lock;
extern std::vector<gl_record_t> g_replay_list;
#endif

void replay_draw(void);
void clear_replay_list(void);
