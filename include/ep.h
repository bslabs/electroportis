/*
 * This file is part of a decompilation of ElectroPaint, a work by David
 * Tristram, distributed with permission. ElectroPaint is a US trademark owned
 * by Tristram Visual, a sole proprietorship operating in California. Inquiries
 * may be directed to info@tristram.com and www.tristram.com.
 *
 * Some further clarification from an email conversation with David Tristram:
 *
 * "The implication regarding derived works is simply that any code that you may
 * produce that includes any part of ElectroPaint does not belong to you, so you
 * can't sell it, for example, or if you do, I'd have a legal interest in the
 * proceeds. If you are interested in modifying the program's behavior or
 * appearance, I think that's okay as long as you share the modified source with
 * me. All this includes decompiled source recovered from the binaries."
 */
#pragma once

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

typedef union EPANOS_REG {
    uint8_t u8;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float s;
    double d;
} EPANOS_REG;

typedef struct EPANOS_ARGS {
    EPANOS_REG v0;
    EPANOS_REG v1;
    EPANOS_REG a0;
    EPANOS_REG a1;
    EPANOS_REG a2;
    EPANOS_REG a3;
    EPANOS_REG f0;
    EPANOS_REG f2;
} EPANOS_ARGS;

#ifdef __cplusplus
extern "C" {
#endif
extern char oflag, bflag;

void init_ep(void);
void reshape__GiT1(const GLuint width, const GLuint height);
void createActTable__Gv(void);
void display__Gv(const void *context);
#ifdef __cplusplus
}
#endif
