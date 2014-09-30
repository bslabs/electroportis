/*
 * This is a decompilation of ElectroPaint, a work by David Tristram,
 * distributed with permission.  ElectroPaint is a US trademark owned by
 * Tristram Visual, a sole proprietorship operating in California.  Inquiries
 * may be directed to info@tristram.com and www.tristram.com.
 */
#include "ep.h"
#include "replay_draw.hpp"

#ifdef _MSC_VER
#include "stdafx.h"
#include "saver.hpp"

#if _MSC_VER < 1800
#include "vs2012_math/vs2012_math.h"
#endif

#include "rand48.h"
#pragma warning (disable:4101 4102 4700)
#else /* !_MSC_VER */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#endif /* !_MSC_VER */

#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

static const float flt_100092A8 = 1.00000000f;
static const double dbl_10009300 = 1.0000000000000000;
static const float flt_100092BC = -0.500000000f;
static const float flt_100092B4 = -1.00000000f;
static const float flt_10009294 = -360.000000f;

/* swapBuffers__Q2_10GLXWrapper6windowGv: no regmap info, emitting empty stmt at .text:100061FC */
/* sginap: no regmap info, emitting empty stmt at .text:10006208 */
/* __nw__GUi: no regmap info, emitting empty stmt at .text:1000631C */
/* __ct__Q2_10GLXWrapper6windowGPciN32: no regmap info, emitting empty stmt at .text:1000634C */
/* setRedraw__Q2_10GLXWrapper6windowGPGv_v: no regmap info, emitting empty stmt at .text:100063A8 */
/* setReshape__Q2_10GLXWrapper6windowGPGiT1_v: no regmap info, emitting empty stmt at .text:100063B8 */
/* setIdle__Q2_10GLXWrapper6windowGPGv_v: no regmap info, emitting empty stmt at .text:100063C8 */
/* setKeyboard__Q2_10GLXWrapper6windowGPGi_v: no regmap info, emitting empty stmt at .text:100063D8 */
/* mainLoop__Q2_10GLXWrapper6windowGv: no regmap info, emitting empty stmt at .text:100063E4 */
/* __process_needed_destructions__Gv: no regmap info, emitting empty stmt at .text:10006408 */
/* __assert: no regmap info, emitting empty stmt at .text:1000389C */
char oflag;
char bflag = 1;

static const char aflag = 1;
static const float square[8] = {-0.100000001f, -0.100000001f, 0.100000001f, -0.100000001f, 0.100000001f, 0.100000001f, -0.100000001f, 0.100000001f};
static float outlinecolRGBA[4] = {0.00000000f, 0.00000000f, 1.00000000f, 1.00000000f};
static float colRGBA[4] = {1.00000000f, 0.00000000f, 0.00000000f, 1.00000000f};
static const char *defaultScript = "# created by mkmaster \n#\n# mello script\n#\n#\tDave Tristram\n#\n#\tthis script moves gently on the screen, and uses wheel to maintain\n#\ta 3D look.\n#\n#\n# constants\n#\nactset: 29, 1.0\t\t# \"full\"\nactset: 17, 0.0\t\t# \"auto\"\nactset: 18, 1.0\t\t# \"outline\"\n# actset: 73, 0.107258\t# \"whl\"\nactset: 31, 0.06\t# \"zoom\"\nactset: 38, 60.0\t# \"twst\"\n#actset: 80, 0.23\t# \"spn\" slow\nactset: 108, 1.2\t# \"size\"\nactset: 52, 40.0\t# \"n\"\n#\nseqdo: 1\t# wrist\nseqdo: 2\t# color\nseqdo: 3\t# wheel\nseqdo: 4\t# spin\nseqdo: 5\t# flip\nseqdo: 6\t# arm\nseqdo: 7\t# twist\nseqdo: 8\t# outline\n#\n# \n#\n# wrst anim: gentle radius modulation\n#\nseqname: 1\n#\nduration: 160\nactlim1: 101, -1.5\t\t# wrst\nactlim2: 101,  1.5\t\t# wrst\n#\n#\n#\n# color anim: hue and lightness motion\n#\n#\tthe hues chosen attempt to minimize \"green-out\"\n#\nseqname: 2\n#\nduration: 60\nactset: 127, 0.0\t\t# hue rate chan 0\n#\nactlim1: 123, 0.544053\t\t# hue chan 0 (just near cyan)\nactlim2: 123, 1.295\t\t# hue chan 0 (deep green)\n#\n#\nduration: 80\n#\nactlim1: 130, 0.0\t\t# lightness chan 0 (black)\nactlim2: 130, 1.0\t\t# lightness chan 0 (white)\n#\n#\n#\n# wheel anim: very slow, gentle rocking\n#\nseqname: 3\n#\nduration: 120\n#\nactlim1: 73, 0.137\t\t# wheel, real slow\nactlim2: 73, -0.137\t\t# wheel, real slow\n#\n#\n#\n# spin anim: somewhat fast occasionally\n#\nseqname: 4\n#\nduration: 100\n#\nactlim1: 80,  0.23\t\t# spn slow\nactlim2: 80, -0.23\t\t# spn slow\n#\nranddelay: 1000\n#\n#\nduration: 40\n#\nactlim1: 80,  5.23\t\t# spn fast\nactlim2: 80, -5.23\t\t# spn fast\n#\n#randdelay: 100\nranddelay: 200\n#\nseqloop:\n#\n#\n#\n# flip anim: somewhat fast occasionally\n#\nseqname: 5\n#\nduration: 50\n#\nactlim1: 87,  2.0\t\t# flip slow\nactlim2: 87, -2.0\t\t# flip slow\n#\n#randdelay: 500\nranddelay: 1200\n#\n#\nactlim1: 87,  10.0\t\t# flip fast\nactlim2: 87, -10.0\t\t# flip fast\n#\n#randdelay: 80\nranddelay: 220\n#\n#\nseqloop:\n#\n#\n#\n# arm anim: gentle radius modulation\n#\nseqname: 6\n#\nduration: 90\nactlim1: 94, -2.0\t\t# arm\nactlim2: 94,  2.0\t\t# arm\n#\n#\n#\n# twist anim:\n#\nseqname: 7\n#\n#duration: 1750\nduration: 2250\nactlim1: 38, 200.0\t\t# twst\nactlim2: 38, -200.0\t\t# twst\n#\n#\n#\n# outline anim: on and off infrequently, mostly on\n#\n#\nseqname: 8\n#\nduration: 5000\n#\nactlim1: 18, 0.2\t\t# outline\nactlim2: 18, 1.0\t\t# outline\n#\n#\n#\n# end of generated script";
#pragma pack (1)
struct act
{
  // MUST be 40 bytes
  unsigned char pad_a[4];
  float flt_b;
  float flt_c;
  float flt_d;
  float flt_e;
  float flt_f;
  float flt_g;
  float flt_h;
  float flt_i;
  unsigned char pad_j[4];
};

struct animSeq
{
  // MUST be 40 bytes
  uint32_t seq;   // maybe a signed int? probably doesn't matter
  unsigned char pad_b[4];
  float seqFrame;
  float flt_d;
  float flt_e;
  float flt_f;
  struct animCommand *cmd_g;
  struct animCommand *cmd_h;
  struct animCommand *cmd_i;
  struct animSeq *next;
};

struct animCommand
{
  // MUST be 24 bytes
  uint32_t type;  // maybe this is a signed int? probably doesn't matter
  uint32_t pad_b; // looks like 32b int
  float cmdFrame;
  float flt_d;
  struct animSeq *seq_e;
  struct animCommand *next;
};
#pragma pack ()
static struct act *acttable[1024];
static char sflag;
static float currentFrame;
static float relFrame;
static float baseFrame;
static float absFrame;
static float wheel;
static float x[128];
static float y[128];
static float dzoom[128];
static float arm[128];
static float wrist[128];
static float dtwist[128];
static float flip[128];
static float spin[128];
static float hue[128];
static float light[128];
static float alpha[128];
static float alphaout[128];
static float size[128];
static char outline[128];
static char fill[128];
static float gflip;
static float gspin;
static int n;
static int nlimit;
static float t;
static struct animSeq *seqList;
static struct animSeq *editSeq;

static void drawit__Gv(EPANOS_ARGS *ARGS, wincount_t wincount);
static void addToSeq__GP7animSeqP11animCommand(struct animSeq *animSeq, struct animCommand *animCommand);
static void animateacts__Gv(void);
static void stopAnimation__Gv(void);
static void readAnimation__Gv(EPANOS_ARGS *ARGS);
static float foldtwixt__GiPffT3(int a0, float *a1, float f14, float f15);
static void drawshape__GiT1(char poly, wincount_t wincount);
static void tasteQueue__Gv(void);
static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS, float *a3, float *a4, float *a5, float f12, float f13, float f14);
static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS, struct animSeq *seq);
static struct act *createBlankActAnim__Gv(void);
static void value__GfN21(EPANOS_ARGS *ARGS);
static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS, struct animCommand *cmd);
static void setacttargets__Gv(void);
static float twixt__GiPff(int a0, const float *a1, float f14);
static float exprand__Gf(float arg);

#if defined(_MSC_VER) && (_MSC_VER < 1800)
static double
trunc(double d)
{
    return (d > 0) ? floor(d) : ceil(d);
}
#endif // _MSC_VER

static int32_t
trunc_w_d(double x)
{
    double r = trunc(x);
    if (r > INT32_MAX || r < INT32_MIN)
        return INT32_MAX;
    else
        return (int32_t)r;
}

void
init_ep(void)
{
    EPANOS_ARGS ARGS;

    memset(acttable, 0, sizeof(acttable));
    createActTable__Gv();
    memset(outline, 1, sizeof(outline));
    memset(fill, 1, sizeof(fill));

    if (aflag == 1)
        readAnimation__Gv(&ARGS);

    srand48(0);

// If in test mode, don't seed the RNG (so it'll do the same show every time)
#ifndef TEST
    srand48(time(NULL));
#endif

    nlimit = 52;
    wheel = 0.0f;
}

static void drawit__Gv(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG t5;
  EPANOS_REG s0;
  EPANOS_REG s3;
  EPANOS_REG f5;
  const EPANOS_REG f20 = {.s = 0.0f};
  const EPANOS_REG f22 = {.s = 1.0f};
  EPANOS_REG f24;
  EPANOS_REG f26;
  EPANOS_REG f28;
  EPANOS_REG f30;
  float var_110;
  float var_108;
  float var_100;
  char *var_78;
  float var_F0;
  float var_E8;
  float var_E0;
  float var_D8;
  float var_D0;
  float var_C8;
  uint64_t var_A8;
  char *var_A0;

  wrap_glColor3f(1.0f, 1.0f, 1.0f, wincount);
  wrap_glPushMatrix(wincount);

  {
    wrap_glRotatef(wheel, f22.s, f20.s, f20.s, wincount);
  }
  memcpy(&f24, &flt_100092BC, 4);
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->a4.u64 = n;
  s3.u64 = ARGS->a4.u64;
  if (0 < nlimit)
  {
    var_A8 = 1;
    goto loc_100054B8;
  }
  else
  {
    var_A8 = 0;
    goto loc_100054E4;
  }

  loc_1000545C:
  if (((signed) s0.i64) < ((signed) 128))
  {
  }
  else
  {
    s0.u64 = (int32_t) (s0.u32 + -128);
  }

  {
    ARGS->f14.s = twixt__GiPff(s0.u64, dzoom, t) * f24.s;
    wrap_glTranslatef(f20.s, f20.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->a0.u64 = nlimit;
  ARGS->a4.u64 = n;
  s3.u64 = (int32_t) (s3.u32 + -1);
  ARGS->a0.u64 = (int32_t) (ARGS->a4.u32 - ARGS->a0.u32);
  if (((signed) ARGS->a0.i64) < ((signed) s3.i64))
    ARGS->a2.u64 = 1;
  else
    ARGS->a2.u64 = 0;

  if (ARGS->a2.u64 == 0)
  {
    if (((signed) ARGS->a0.i64) < ((signed) ARGS->a4.i64))
      ARGS->a2.u64 = 1;
    else
      ARGS->a2.u64 = 0;

    goto loc_100054E0;
  }
  else
    if (((signed) ARGS->a0.i64) < ((signed) ARGS->a4.i64))
    ARGS->a2.u64 = 1;
  else
    ARGS->a2.u64 = 0;


  loc_100054B8:
  ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);

  ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  if (ARGS->a0.i64 >= 0)
  {
    s0.u64 = ARGS->a0.u64;
  }
  else
  {
    s0.u64 = (int32_t) (ARGS->a0.u32 + 128);
  }
  goto loc_1000545C;

  loc_100054E0:
  var_A8 = ARGS->a2.u64;

  loc_100054E4:
  s3.u64 = ARGS->a4.u64;
  if (var_A8 == 0)
  {
    wrap_glPopMatrix(wincount);
    return;
  }

  {
    ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);

    ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
    ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
    ARGS->a0.u64 = ARGS->a0.u64 & 127;
    ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
    ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
    goto loc_10005848;
  }
  loc_1000552C:
  if (((signed) s0.i64) < ((signed) 128))
    ARGS->a5.u64 = 1;
  else
    ARGS->a5.u64 = 0;


  if (ARGS->a5.u64 == 0)
  {
    s0.u64 = (int32_t) (s0.u32 + -128);
  }

  f30.s = twixt__GiPff(s0.u64, x, t);
  var_D0 = twixt__GiPff(s0.u64, y, t);
  var_100 = twixt__GiPff(s0.u64, dzoom, t);
  var_C8 = twixt__GiPff(s0.u64, arm, t);
  f28.s = twixt__GiPff(s0.u64, wrist, t);
  var_108 = twixt__GiPff(s0.u64, size, t);
  var_E0 = foldtwixt__GiPffT3(s0.u64, spin, t, 360.0f);
  var_D8 = foldtwixt__GiPffT3(s0.u64, flip, t, 360.0f);
  var_110 = twixt__GiPff(s0.u64, dtwist, t);
  f26.s = foldtwixt__GiPffT3(s0.u64, hue, t, f22.s);
  var_E8 = twixt__GiPff(s0.u64, alpha, t);
  f24.s = foldtwixt__GiPffT3(s0.u64, light, t, f22.s);
  var_F0 = twixt__GiPff(s0.u64, alphaout, t);

  {
    hls_to_rgb__GfN21PfN24(ARGS, colRGBA, &(colRGBA[1]), &(colRGBA[2]), f26.s, f24.s, f22.s);
  }
  f5.s = f26.s + 0.5f;
  ARGS->f2.d = f5.s;
  outlinecolRGBA[3] = var_F0;
  colRGBA[3] = var_E8;
  ARGS->f12.s = f5.s;

  if ((double)1.0 < ARGS->f2.d)
  {
    memcpy(&ARGS->f12, &flt_100092B4, 4);
    ARGS->f12.s = f5.s + ARGS->f12.s;
  }

  {
    hls_to_rgb__GfN21PfN24(ARGS, outlinecolRGBA, &(outlinecolRGBA[1]), &(outlinecolRGBA[2]),
        ARGS->f12.s, f22.s - f24.s, f22.s);
  }

  wrap_glPushMatrix(wincount);
  wrap_glTranslatef(f30.s, var_D0, f20.s, wincount);
  wrap_glRotatef(var_E0, f20.s, f20.s, f22.s, wincount);
  wrap_glTranslatef(f20.s, var_C8, f20.s, wincount);
  wrap_glRotatef(var_D8, f20.s, f22.s, f20.s, wincount);
  wrap_glTranslatef(f28.s, f20.s, f20.s, wincount);

  var_78 = &(fill[s0.u32]);
  if (*var_78 != 0)
  {
    wrap_glColor3f(colRGBA[0], colRGBA[1], colRGBA[2], wincount);
    drawshape__GiT1(1, wincount);
  }

  var_A0 = &(outline[s0.u32]);
  if (*var_A0 != 0)
  {
    wrap_glColor3f(outlinecolRGBA[0], outlinecolRGBA[1], outlinecolRGBA[2], wincount);
    drawshape__GiT1(0, wincount);
  }

  wrap_glPopMatrix(wincount);

  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  if (sflag == 0)
  {
    goto loc_100058AC;
  }

  loc_10005818:
  s3.u64 = (int32_t) (s3.u32 + -1);
  t5.u64 = n;
  ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);
  ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
  t5.u64 = (int32_t) (t5.u32 - nlimit);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);

  if (((signed) t5.i64) < ((signed) s3.i64))
    t5.u64 = 1;
  else
    t5.u64 = 0;

  if (t5.u64 == 0)
  {
    wrap_glPopMatrix(wincount);
    return;
  }

  loc_10005848:
  s0.u64 = ARGS->a0.u64;
  if (ARGS->a0.i64 >= 0)
  {
    goto loc_1000552C;
  }

  s0.u64 = (int32_t) (ARGS->a0.u32 + 128);
  goto loc_1000552C;

  loc_100058AC:
  wrap_glScalef(f22.s, -1.0f, f22.s, wincount);
  wrap_glPushMatrix(wincount);
  wrap_glTranslatef(f30.s, var_D0, f20.s, wincount);
  wrap_glRotatef(var_E0, f20.s, f20.s, f22.s, wincount);
  wrap_glTranslatef(f20.s, var_C8, f20.s, wincount);
  wrap_glRotatef(var_D8, f20.s, f22.s, f20.s, wincount);
  wrap_glTranslatef(f28.s, f20.s, f20.s, wincount);
  wrap_glScalef(var_108, var_108, f22.s, wincount);

  if (*var_78 != 0)
  {
    wrap_glColor3f(colRGBA[0], colRGBA[1], colRGBA[2], wincount);
    drawshape__GiT1(1, wincount);
  }

  if (*var_A0 != 0)
  {
    wrap_glColor3f(outlinecolRGBA[0], outlinecolRGBA[1], outlinecolRGBA[2], wincount);
    drawshape__GiT1(0, wincount);
  }

  wrap_glPopMatrix(wincount);
  wrap_glRotatef(180.0f, f20.s, f20.s, f22.s, wincount);
  wrap_glPushMatrix(wincount);
  wrap_glTranslatef(f30.s, var_D0, f20.s, wincount);

  wrap_glRotatef(var_E0, f20.s, f20.s, f22.s, wincount);
  wrap_glTranslatef(f20.s, var_C8, f20.s, wincount);
  wrap_glRotatef(var_D8, f20.s, f22.s, f20.s, wincount);
  wrap_glTranslatef(f28.s, f20.s, f20.s, wincount);
  wrap_glScalef(var_108, var_108, f22.s, wincount);

  if (*var_78 != 0)
  {
    wrap_glColor3f(colRGBA[0], colRGBA[1], colRGBA[2], wincount);
    drawshape__GiT1(1, wincount);
  }

  if (*var_A0 != 0)
  {
    wrap_glColor3f(outlinecolRGBA[0], outlinecolRGBA[1], outlinecolRGBA[2], wincount);
    drawshape__GiT1(0, wincount);
  }

  wrap_glPopMatrix(wincount);
  wrap_glScalef(f22.s, -1.0f, f22.s, wincount);
  wrap_glPushMatrix(wincount);
  wrap_glTranslatef(f30.s, var_D0, f20.s, wincount);
  wrap_glRotatef(var_E0, f20.s, f20.s, f22.s, wincount);
  wrap_glTranslatef(f20.s, var_C8, f20.s, wincount);
  wrap_glRotatef(var_D8, f20.s, f22.s, f20.s, wincount);
  wrap_glTranslatef(f28.s, f20.s, f20.s, wincount);
  wrap_glScalef(var_108, var_108, f22.s, wincount);

  if (*var_78 != 0)
  {
    wrap_glColor3f(colRGBA[0], colRGBA[1], colRGBA[2], wincount);
    drawshape__GiT1(1, wincount);
  }

  if (*var_A0 != 0)
  {
    wrap_glColor3f(outlinecolRGBA[0], outlinecolRGBA[1], outlinecolRGBA[2], wincount);
    drawshape__GiT1(0, wincount);
  }

  wrap_glPopMatrix(wincount);
  wrap_glRotatef(var_110, f20.s, f20.s, f22.s, wincount);
  wrap_glTranslatef(f20.s, f20.s, var_100, wincount);
  ARGS->a1.u64 = (uint64_t) (&n);
  {
    ARGS->a3.u64 = (uint64_t) (&nlimit);
    goto loc_10005818;
  }
}

static void addToSeq__GP7animSeqP11animCommand(struct animSeq *animSeq, struct animCommand *animCommand)
{
  animCommand->seq_e = animSeq;

  struct animCommand *a4 = animSeq->cmd_g;

  if (animSeq->cmd_g == NULL)
  {
    animSeq->cmd_i = animCommand;
    animSeq->cmd_g = animCommand;
    return;
  }

  struct animCommand *a3 = a4->next;

  if (animCommand->cmdFrame < a4->cmdFrame)
  {
    animCommand->next = animSeq->cmd_g;
    animSeq->cmd_g = animCommand;
    return;
  }

  if (a4->next == NULL)
  {
    a4->next = animCommand;
    animSeq->cmd_i = animCommand;
    return;
  }

  loc_10003930:

  if (animCommand->cmdFrame < a3->cmdFrame)
  {
    animCommand->next = a3;
    a4->next = animCommand;
  }
  else
  {
    a4 = a3;
    a3 = a3->next;
    if (a3 != NULL)
    {
      goto loc_10003930;
    }
  }

  if (animCommand->next != NULL)
    return;

  animSeq->cmd_i->next = animCommand;
  animSeq->cmd_i = animCommand;
  return;
}

static void animateacts__Gv(void)
{
  struct act **a4 = acttable;

  for (unsigned int a3 = 1; a3 < NELEMS(acttable); a3++)
  {
    struct act *act = *a4;
    a4++;

    if (act == NULL)
    {
      continue;
    }

    if (act->pad_a[0] == 0)
    {
      continue;
    }

    if (act->pad_a[1] == 0)
    {
      continue;
    }

    float f0 = act->flt_c - (act->flt_f + act->flt_g);
    f0 = act->flt_b * f0;
    if (f0 < 0)
    {
      act->flt_g = act->flt_c;
      act->pad_a[1] = 0;
    }
    else
    {
      act->flt_g = act->flt_f + act->flt_g;
    }
  }
}

static void stopAnimation__Gv(void)
{
  for (unsigned int i = 0; i < NELEMS(acttable); i++)
  {
    struct act *act = acttable[i];

    if (act != NULL)
    {
      act->pad_a[0] = 0;
    }
  }
}

static void readAnimation__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG s0;
  struct animCommand *cmd;
  EPANOS_REG s4;
  EPANOS_REG s7;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f4;
  EPANOS_REG f6;
  EPANOS_REG f10;
  EPANOS_REG f21;
  int var_2E0;
  uint64_t var_60;
  uint64_t var_58;
  char var_2D8[256];
  uint64_t var_88;
  uint64_t var_80;
  uint64_t var_78;
  uint64_t var_70;
  uint64_t var_68;
  char var_1D8[256];

  s0.u64 = (uint64_t) defaultScript;
  if (oflag != 0)
  {
    printf("# reading animation...");
    printf("\n");
  }

  goto loc_10003B54;

  loc_10003A40:
  if (strncmp("#", var_2D8, 1) == 0)
  {
    if (oflag != 0)
    {
      printf("%s", var_2D8);
    }

    free(cmd);

    goto loc_10003AE8;
  }

  if (oflag != 0)
  {
    printf("bad command: %s", var_2D8);
  }

  {
    free(cmd);
  }

  ARGS->a1.u64 = 1;
  var_58 = ARGS->a1.u64;
  ARGS->a2.u64 = var_58;
  loc_10003A8C:
  var_60 = ARGS->a2.u64;

  loc_10003A90:
  ARGS->a3.u64 = var_60;
  var_68 = ARGS->a3.u64;

  loc_10003A98:
  ARGS->a4.u64 = var_68;
  var_70 = ARGS->a4.u64;

  loc_10003AA4:
  ARGS->a5.u64 = var_70;
  var_78 = ARGS->a5.u64;

  loc_10003AA8:
  ARGS->a6.u64 = var_78;
  var_80 = ARGS->a6.u64;

  loc_10003AB4:
  ARGS->a7.u64 = var_80;
  var_88 = ARGS->a7.u64;

  loc_10003AB8:
  fp.u64 = var_88;
  loc_10003AC0:
  s7.u64 = fp.u64;

  s4.u64 = s7.u64;

  loc_10003AC4:
  fp.u64 = s4.u64;

  loc_10003AC8:
  s7.u64 = fp.u64;

  loc_10003ACC:
  s4.u64 = s7.u64;

  loc_10003AD0:
  s7.u64 = s4.u64;

  loc_10003AD4:
  fp.u64 = s7.u64;

  loc_10003AD8:
  s7.u64 = fp.u64;

  loc_10003ADC:
  s4.u64 = s7.u64;

  loc_10003AE0:
  if (s4.u64 == 0)
  {
    goto loc_10003DA4;
  }
    loc_10003AE4:



  loc_10003AE8:
  {
    sscanf((const char *) s0.u64, "%[^\n]\n", var_1D8);
  }
  if (oflag != 0)
  {
    printf("%s\n", var_1D8);
  }

  var_1D8[0] = 0;
  if (bflag == 0)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    if (scanf("%[^\n]\n", var_2E0) == EOF)
    {
      goto loc_100041A4;
    }
    else
    {
      s0.u64 = var_2E0;
      goto loc_10003B54;
    }
  }

  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, "\n");
  }
  s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
  s0.u64 = (int32_t) (s0.u32 + 1);
  {
    ARGS->v0.u64 = (unsigned int) strlen((const char *) s0.u64);
  }
  ARGS->a1.u64 = (uint64_t) seqList;
  if (ARGS->v0.u64 == 0)
  {
    goto loc_100041A4;
  }

  loc_10003B54:
  var_58 = 0;

  var_60 = 0;
  var_68 = 0;
  var_70 = 0;
  var_78 = 0;
  var_80 = 0;
  var_88 = 0;
  cmd = NULL;
  fp.u64 = 0;
  s7.u64 = 0;
  s4.u64 = 0;
  {
    ARGS->v0.u64 = (int) sscanf((const char *) s0.u64, "%s", var_2D8);
  }
  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
  }
  {
    cmd = calloc(1, sizeof(struct animCommand));
  }
  {
    cmd->cmdFrame = absFrame;
  }
  if (strcmp("frame:", var_2D8) == 0)
  {
    {
      cmd->type = 0;
      sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
    ARGS->v0.u64 = (unsigned int)strcspn((const char *)s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      f1.s = cmd->flt_d;
      f1.d = f1.s;
      ARGS->a2.u64 = f1.u64;
      printf("%s %f", var_2D8, (double) ARGS->a2.d);
    }

    f4.s = cmd->flt_d;

    relFrame = relFrame + f4.s;
    absFrame = baseFrame + relFrame;

    loc_10003DA4:
    if (editSeq == NULL)
    {
      editSeq = calloc(sizeof(struct animSeq), 1);

      editSeq->pad_b[0] = 1;
      editSeq->seq = 0;
      editSeq->seqFrame = 0.0f;
      editSeq->flt_e = 300.0f;
      editSeq->flt_f = 1.0f;
      editSeq->cmd_i = NULL;
      editSeq->cmd_h = NULL;
      editSeq->cmd_g = NULL;
      editSeq->next = NULL;

      if (seqList != NULL)
      {
        editSeq->next = seqList;
      }

      seqList = editSeq;
    }

    addToSeq__GP7animSeqP11animCommand(editSeq, cmd);

    editSeq->flt_d = relFrame;
    goto loc_10003AE4;
  }

  if (strcmp("relframe:", var_2D8) == 0)
  {
    {
      cmd->type = 0;
      sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
    ARGS->v0.u64 = (unsigned int)strcspn((const char *)s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      f6.s = cmd->flt_d;
      f6.d = f6.s;
      ARGS->a2.u64 = f6.u64;
      printf("%s %f", var_2D8, (double) ARGS->a2.d);
    }

    relFrame = relFrame + cmd->flt_d;
    absFrame = baseFrame + relFrame;

    goto loc_10003AE0;
  }

  s4.u64 = 0;
  if (strcmp("absframe:", var_2D8) == 0)
  {
    {
      cmd->type = 1;
      ARGS->v0.u64 = (int) sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
    ARGS->v0.u64 = (unsigned int)strcspn((const char *)s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      f10.s = cmd->flt_d;
      f10.d = f10.s;
      ARGS->a2.u64 = f10.u64;
      {
        printf("%s %f", var_2D8, (double) ARGS->a2.d);
      }
    }

    relFrame = 0.0f;
    baseFrame = cmd->flt_d;
    absFrame = cmd->flt_d;
    {
      goto loc_10003ADC;
    }
  }

  s7.u64 = 0;
  if (strcmp("randdelay:", var_2D8) == 0)
  {
    {
      cmd->type = 103;
      sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      ARGS->f13.s = cmd->flt_d;
      ARGS->f13.d = ARGS->f13.s;
      ARGS->a2.u64 = ARGS->f13.u64;
      printf("%s %f", var_2D8, (double) ARGS->a2.d);
    }
    goto loc_10003AD8;
  }

  fp.u64 = 0;
  if (strcmp("duration:", var_2D8) == 0)
  {
    s7.u64 = 0;
    cmd->type = 101;
    {
      sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    if (oflag != 0)
    {
      ARGS->f14.s = cmd->flt_d;
      ARGS->f14.d = ARGS->f14.s;
      ARGS->a2.u64 = ARGS->f14.u64;
      printf("%s %f", var_2D8, (double) ARGS->a2.d);
    }

    goto loc_10003AD4;
  }

  if (strcmp("variance:", var_2D8) == 0)
  {
    cmd->type = 102;
    {
      sscanf((const char *) s0.u64, "%f", &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      ARGS->f15.s = cmd->flt_d;
      ARGS->f15.d = ARGS->f15.s;
      ARGS->a2.u64 = ARGS->f15.u64;
      printf("%s %f", var_2D8, (double) ARGS->a2.d);
    }

    goto loc_10003AD0;
  }

  s4.u64 = 0;
  if (strcmp("actlim1:", var_2D8) == 0)
  {
    cmd->type = 2;
    {
      sscanf((const char *) s0.u64, "%d, %f", &(cmd->pad_b), &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      ARGS->f16.s = cmd->flt_d;
      ARGS->f16.d = ARGS->f16.s;
      ARGS->a3.u64 = ARGS->f16.u64;
      printf("%s %d, %f", var_2D8, cmd->pad_b, (double) ARGS->a3.d);
    }

    goto loc_10003ACC;
  }

  s7.u64 = 0;
  if (strcmp("actlim2:", var_2D8) == 0)
  {
    cmd->type = 3;
    {
      sscanf((const char *) s0.u64, "%d, %f", &(cmd->pad_b), &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      ARGS->f17.s = cmd->flt_d;
      ARGS->f17.d = ARGS->f17.s;
      ARGS->a3.u64 = ARGS->f17.u64;
      printf("%s %d, %f", var_2D8, cmd->pad_b, (double) ARGS->a3.d);
    }

    goto loc_10003AC8;
  }

  fp.u64 = 0;
  if (strcmp("actset:", var_2D8) == 0)
  {
    cmd->type = 4;
    {
      sscanf((const char *) s0.u64, "%d, %f", &(cmd->pad_b), &(cmd->flt_d));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      f21.s = cmd->flt_d;
      f21.d = f21.s;
      ARGS->a3.u64 = f21.u64;
      printf("%s %d, %f", var_2D8, cmd->pad_b, (double) ARGS->a3.d);
    }
    goto loc_10003AC4;
  }

  if (strcmp("actreset:", var_2D8) == 0)
  {
    cmd->type = 5;
    {
      sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      printf("%s %d", var_2D8, cmd->pad_b);
    }
    goto loc_10003AC0;
  }

  if (strcmp("actresetall:", var_2D8) == 0)
  {
    cmd->type = 6;
    if (oflag != 0)
      printf("%s", var_2D8);

    goto loc_10003AC0;
  }

  if (strcmp("actstop:", var_2D8) == 0)
  {
    cmd->type = 7;
    {
      sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
    }
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
    }
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (oflag != 0)
    {
      printf("%s %d", var_2D8, cmd->pad_b);
    }
    goto loc_10003AB8;
  }

  if (strcmp("actstopall:", var_2D8) != 0)
  {
    if (strcmp("seqname:", var_2D8) == 0)
    {
      goto loc_100044F8;
    }

    if (strcmp("seqdo:", var_2D8) == 0)
    {
      cmd->type = 10;
      {
        sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
      }
      {
        ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
      }
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      if (oflag != 0)
      {
        printf("%s %d", var_2D8, cmd->pad_b);
      }

      goto loc_10003AA8;
    }

    if (strcmp("seqloop:", var_2D8) == 0)
    {
      cmd->type = 12;
      if (oflag != 0)
      {
        printf("%s", var_2D8);
      }

      goto loc_10003AA4;
    }

    if (strcmp("seqstop:", var_2D8) == 0)
    {
      cmd->type = 11;
      {
        sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
      }
      {
        ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
      }
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      if (oflag != 0)
      {
        printf("%s %d", var_2D8, cmd->pad_b);
      }
      goto loc_10003A98;
    }

    if (strcmp("seqrepeat:", var_2D8) == 0)
    {
      cmd->type = 13;
      {
        sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
      }
      {
        ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
      }
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      if (oflag != 0)
      {
        printf("%s %d", var_2D8, cmd->pad_b);

        printf("warning: %s not implemented\n", var_2D8);
      }

      free(cmd);
      goto loc_10003AE8;
    }

    if (strcmp("seqkill:", var_2D8) == 0)
    {
      cmd->type = 14;
      {
        sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
      }
      {
        ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, " \t\n");
      }
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      if (oflag != 0)
      {
        printf("%s %d", var_2D8, cmd->pad_b);
      }
      goto loc_10003A90;
    }

    if (strcmp("seqkillall:", var_2D8) == 0)
    {
      cmd->type = 15;
      ARGS->a2.u64 = var_58;
      if (oflag != 0)
      {
        printf("%s", var_2D8);
      }
      goto loc_10003A8C;
    }

    goto loc_10003A40;
  }

  cmd->type = 8;
  if (oflag != 0)
  {
    printf("%s", var_2D8);
  }

  goto loc_10003AB4;


  loc_100041A4:
  ARGS->a1.u64 = seqList;

  s4.u64 = ARGS->a1.u64;
  if (seqList == NULL)
  {
    goto loc_100041C4;
  }

  loc_100041B0:
  ARGS->a2.u64 = *((int32_t *) (s4.u32 + 0));

  if (ARGS->a2.u64 == 0)
  {
    *((uint32_t *) (s4.u32 + 28)) = *((int32_t *) (s4.u32 + 24));
    goto loc_100041C4;
  }

  s4.u64 = *((int32_t *) (s4.u32 + 36));
  if (s4.u64 != 0)
  {
    goto loc_100041B0;
  }

  loc_100041C4:
  if (oflag != 0)
  {
    printf("# done reading animation\n");
  }

  ARGS->a1.u64 = seqList;

  if (ARGS->a1.u64 == 0)
  {
    return;
  }
  else
    s4.u64 = ARGS->a1.u64;

  goto loc_1000424C;

  loc_100041FC:
  s0.u64 = *((int32_t *) (s0.u32 + 20));

  if (s0.u64 == 0)
  {
    goto loc_10004240;
  }

  loc_10004208:
  if (oflag == 0)
  {
    goto loc_100041FC;
  }

  memcpy(&ARGS->f18, (char *) (s0.u32 + 12), 4);
  ARGS->f18.d = ARGS->f18.s;
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 4));
  ARGS->a3.u64 = ARGS->f18.u64;
  {
    ARGS->v0.u64 = (int) printf("  cmd %d,\t%d\t%f\n", (int32_t) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
  }
  s0.u64 = *((int32_t *) (s0.u32 + 20));
  if (s0.u64 != 0)
  {
    goto loc_10004208;
  }

  loc_10004240:
  s4.u64 = *((int32_t *) (s4.u32 + 36));

  if (s4.u64 == 0)
  {
    return;
  }

  loc_1000424C:
  if (oflag != 0)
  {
    memcpy(&ARGS->f19, (char *) (s4.u32 + 8), 4);
    ARGS->f19.d = ARGS->f19.s;
    ARGS->a1.u64 = *((int32_t *) (s4.u32 + 0));
    ARGS->a2.u64 = ARGS->f19.u64;
    {
      printf("seq %d at %.2f\n", (int32_t) ARGS->a1.u64, (double) ARGS->a2.d);
    }
  }

  s0.u64 = *((int32_t *) (s4.u32 + 24));

  if (s0.u64 == 0)
    goto loc_10004240;
  else
    goto loc_10004208;

  loc_100044F8:
  cmd->type = 9;
  {
    sscanf((const char *) s0.u64, "%d", &(cmd->pad_b));
  }
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
  }
  s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
  if (oflag != 0)
  {
    printf("%s %d", var_2D8, cmd->pad_b);
  }

  ARGS->a4.u64 = (uint64_t) (&relFrame);

  ARGS->a5.u64 = (uint64_t) (&absFrame);
  ARGS->a3.u64 = (uint64_t) seqList;
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  ARGS->a3.u64 = seqList;
  baseFrame = 0.0f;
  absFrame = 0.0f;
  relFrame = 0.0f;
  s4.u64 = ARGS->a3.u64;
  if (ARGS->a3.u64 == 0)
  {
    if (s4.u64 != 0)
    {
      goto loc_10004614;
    }
    else
    {
      goto loc_10004588;
    }
  }

  ARGS->v0.u64 = cmd->pad_b;
  loc_10004570:
  ARGS->a7.u64 = *((int32_t *) (s4.u32 + 0));

  if (ARGS->a7.u64 == ARGS->v0.u64)
  {
    ARGS->v0.u64 = (uint64_t) editSeq;

    editSeq = s4.u32;

    return;
  }

  s4.u64 = *((int32_t *) (s4.u32 + 36));
  if (s4.u64 != 0)
  {
    goto loc_10004570;
  }

  loc_10004588:
  {
    editSeq = calloc(sizeof(struct animSeq), 1);
  }

  ARGS->a4.u64 = (uint64_t) editSeq;

  editSeq->seq = cmd->pad_b;
  editSeq->pad_b[0] = 1;
  editSeq->seqFrame = 0.0f;
  editSeq->flt_e = 300.0f;
  editSeq->flt_f = 1.0f;
  editSeq->cmd_g = NULL;
  editSeq->cmd_h = NULL;
  editSeq->cmd_i = NULL;

  editSeq->next = NULL;

  ARGS->a4.u64 = editSeq;
  if (seqList != NULL)
  {
    editSeq->next = seqList;
  }

  seqList = editSeq;
  loc_10004614:
  {
    free(cmd);
  }

  {
    goto loc_10003AE8;
  }
}

static float foldtwixt__GiPffT3(int a0, float *a1, float f14, float f15)
{
  float f0;
  float f4;
  float f5;
  float f6;
  float f7;
  float f8;
  float f10;

  int a4 = a0 - 1;

  if (a0 <= 0)
  {
    a4 = a4 + 128;
  }

  f5 = a1[a0];
  f6 = a1[a4];
  f8 = f15 * 0.5f;
  f4 = f5 - f6;
  f7 = 1.0f - f14;

  if (f8 < f4)
  {
    f0 = f6 + f15;

    float f1 = f5 * f14;
    f0 = f7 * f0;
    f0 = f0 + f1;
    return f0;
  }

  f10 = f15 * -0.5f;
  f8 = f7 * f6;

  if (f4 < f10)
  {
    f0 = f5 + f15;
    f0 = f14 * f0;
    f0 = f8 + f0;
    return f0;
  }
  else
  {
    f0 = f5 * f14;
    f0 = f8 + f0;
    return f0;
  }
}

static void drawshape__GiT1(char poly, wincount_t wincount)
{
  if (poly == 0)
  {
    wrap_glBegin(GL_LINES, wincount);
    wrap_glVertex2f(square[0], square[1], wincount);
    wrap_glVertex2f(square[2], square[3], wincount);
    wrap_glVertex2f(square[2], square[3], wincount);
    wrap_glVertex2f(square[4], square[5], wincount);
    wrap_glVertex2f(square[4], square[5], wincount);
    wrap_glVertex2f(square[6], square[7], wincount);
    wrap_glVertex2f(square[6], square[7], wincount);
    wrap_glVertex2f(square[0], square[1], wincount);
  }
  else
  {
    wrap_glBegin(GL_POLYGON, wincount);
    wrap_glVertex2f(square[0], square[1], wincount);
    wrap_glVertex2f(square[2], square[3], wincount);
    wrap_glVertex2f(square[4], square[5], wincount);
    wrap_glVertex2f(square[6], square[7], wincount);
  }

  wrap_glEnd(wincount);
  return;
}

static void tasteQueue__Gv(void)
{
  struct animSeq *seq;
  struct animCommand *cmd;
  EPANOS_ARGS ARGS;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  
  currentFrame = currentFrame + 1.0f;

  for (seq = seqList; seq != NULL; seq = seq->next)
  {
    double f4 = (double)currentFrame + 0.5;
    cmd = seq->cmd_h;
    if ((double)seq->seqFrame < f4)
    {
      ;
    }
    else
    {
      continue;
    }

    if (seq->pad_b[0] == 0)
    {
      continue;
    }

    if (cmd == NULL)
    {
      continue;
    }

    f6.s = cmd->cmdFrame;
    f6.s = f6.s + seq->seqFrame;
    f6.d = f6.s;
    if (f6.d < f4)
    {
      ;
    }
    else
    {
      continue;
    }

    loc_10004F7C:
    processCommand__GP11animCommand(&ARGS, cmd);

    f9.s = seq->seqFrame;
    f8.s = currentFrame;
    cmd = seq->cmd_h;
    if (seq->pad_b[0] == 0)
    {
      continue;
    }

    if (cmd == NULL)
    {
      continue;
    }

    f7.s = cmd->cmdFrame;
    f8.d = f8.s;
    f7.s = f7.s + f9.s;
    f8.d = f8.d + 0.5;
    f7.d = f7.s;
    if (f7.d < f8.d)
    {
      goto loc_10004F7C;
    }
  }
}

static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS, float *a3, float *a4, float *a5, float f12, float f13, float f14)
{
  float f4;
  float f5;
  float f20;
  double var_50;
  double var_48;
  double var_40;

  f4 = f13;
  f5 = f12;

  ARGS->f0.d = f13;
  if (ARGS->f0.d <= 0.5)
  {
    f20 = f14 + 1.0f;
    f20 = f13 * f20;
  }
  else
  {
    float f21 = f13 * f14;

    f20 = f13 + f14;
    f20 = f20 - f21;
  }

  if (f14 == 0.0f)
  {
    *a5 = f4;
    *a4 = f4;
    *a3 = f4;
    return;
  }

  ARGS->f14.d = f5;
  ARGS->f14.d = ARGS->f14.d * 360.00000000000000;
  ARGS->f12.s = 2.0f;
  ARGS->f14.s = ARGS->f14.d;
  memcpy(&var_50, &ARGS->f14, 8);
  ARGS->f14.d = ARGS->f14.s;
  ARGS->f12.s = f4 * ARGS->f12.s;
  memcpy(&var_48, &ARGS->f14, 8);
  ARGS->f14.d = ARGS->f14.d + 120.00000000000000;
  ARGS->f12.s = ARGS->f12.s - f20;
  ARGS->f13.s = f20;
  memcpy(&var_40, &ARGS->f12, 8);
  {
    ARGS->f14.s = ARGS->f14.d;
    value__GfN21(ARGS);
  }
  *a3 = ARGS->f0.s;
  memcpy(&ARGS->f12, &var_40, 8);
  ARGS->f13.s = f20;
  {
    memcpy(&ARGS->f14, &var_50, 8);
    value__GfN21(ARGS);
  }
  memcpy(&ARGS->f14, &var_48, 8);
  ARGS->f14.d = ARGS->f14.d + -120.00000000000000;
  memcpy(&ARGS->f12, &var_40, 8);
  *a4 = ARGS->f0.s;
  ARGS->f13.s = f20;
  {
    ARGS->f14.s = ARGS->f14.d;
    value__GfN21(ARGS);
  }
  {
    *a5 = ARGS->f0.s;
    return;
  }
}

static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS, struct animSeq *seq)
{
  const EPANOS_REG s0 = { .u64 = seq };
  EPANOS_REG s1;

  if (seq == NULL)
  {
    return;
  }

  s1.u64 = (uint64_t) seqList;
  seq->pad_b[0] = 0;
  ARGS->a3.u64 = seqList;
  if (seq == seqList)
  {
    ARGS->a0.u64 = *((int32_t *) (ARGS->a3.u32 + 36));
    seqList = ARGS->a0.u32;
    ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
    if (ARGS->a0.u64 != 0)
    {
      loc_1000487C:

      s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
      free((void *) ARGS->a0.u64);

      ARGS->a0.u64 = s1.u64;
      if (s1.u64 != 0)
      {
        goto loc_1000487C;
      }
    }

    s1.u64 = (uint64_t) seqList;

    ARGS->a0.u64 = s0.u64;
    free((void *) ARGS->a0.u64);

    ARGS->a3.u64 = seqList;
  }

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 36));

  if (ARGS->a2.u64 == 0)
  {
    return;
  }

  loc_100048B0:
  if (ARGS->a2.u64 != s0.u64)
  {
    ARGS->a3.u64 = ARGS->a2.u64;
    ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 36));
    if (ARGS->a2.u64 != 0)
    {
      goto loc_100048B0;
    }
    else
    {
      return;
    }
  }

  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 36));

  *((uint32_t *) (ARGS->a3.u32 + 36)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 24));
  ARGS->a0.u64 = ARGS->a1.u64;
  if (ARGS->a1.u64 != 0)
  {
    loc_100048E4:

    s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    free((void *) ARGS->a0.u64);

    ARGS->a0.u64 = s1.u64;
    if (s1.u64 != 0)
    {
      goto loc_100048E4;
    }
  }

  ARGS->a0.u64 = s0.u64;
  free((void *) ARGS->a0.u64);

  return;
}

void createActTable__Gv(void)
{
  acttable[18] = createBlankActAnim__Gv();
  acttable[73] = createBlankActAnim__Gv();
  acttable[31] = createBlankActAnim__Gv();
  acttable[38] = createBlankActAnim__Gv();
  acttable[80] = createBlankActAnim__Gv();
  acttable[108] = createBlankActAnim__Gv();
  acttable[52] = createBlankActAnim__Gv();
  acttable[52]->flt_g = 52.0000000f;
  acttable[101] = createBlankActAnim__Gv();
  acttable[127] = createBlankActAnim__Gv();
  acttable[123] = createBlankActAnim__Gv();
  acttable[87] = createBlankActAnim__Gv();
  acttable[94] = createBlankActAnim__Gv();
  acttable[45] = createBlankActAnim__Gv();
  acttable[45]->flt_g = flt_100092A8;
  acttable[130] = createBlankActAnim__Gv();

  return;
}

static struct act *createBlankActAnim__Gv(void)
{
  struct act *ret = calloc(1, sizeof(struct act));
  
  ret->flt_b = flt_100092A8;
  ret->flt_i = 0.600000024f;

  return ret;
}

static void value__GfN21(EPANOS_ARGS *ARGS)
{
  EPANOS_REG f1;
  const double f3 = 60.000000000000000;
  const float f5 = 240.000000f;
  const float f6 = 180.000000f;
  const float f7 = 360.000000f;

  memcpy(&ARGS->f0, &flt_10009294, 4);

  if (f7 < ARGS->f14.s)
  {
    ARGS->f14.s = ARGS->f14.s + ARGS->f0.s;
  }

  f1.u32 = 0;

  ARGS->f0.s = 60.0000000f;

  if (ARGS->f14.s < f1.s)
    ARGS->f14.s = ARGS->f14.s + f7;

  if (ARGS->f14.s < ARGS->f0.s)
  {
    ARGS->f0.s = ARGS->f13.s;

    ARGS->f2.d = ARGS->f14.s;
    ARGS->f2.d = ARGS->f2.d / f3;
    f1.s = ARGS->f13.s - ARGS->f12.s;
    f1.d = f1.s;
    ARGS->f0.d = ARGS->f12.s;
    f1.d = f1.d * ARGS->f2.d;
    ARGS->f0.d = ARGS->f0.d + f1.d;
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  else
  {
    ARGS->f0.s = ARGS->f13.s;
  }

  if (ARGS->f14.s < f6)
    return;

  ARGS->f0.s = ARGS->f12.s;
  if (ARGS->f14.s < f5)
  {
    ;
  }
  else
  {
    return;
  }

  ARGS->f2.s = f5 - ARGS->f14.s;
  ARGS->f2.d = ARGS->f2.s;
  ARGS->f2.d = ARGS->f2.d / f3;
  f1.s = ARGS->f13.s - ARGS->f12.s;
  f1.d = f1.s;
  ARGS->f0.d = ARGS->f12.s;
  f1.d = f1.d * ARGS->f2.d;
  ARGS->f0.d = ARGS->f0.d + f1.d;
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
}

static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS, struct animCommand *cmd)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f11;

  ARGS->a0.u64 = cmd;
  s0.u64 = ARGS->a0.u64;
  if (oflag != 0)
  {
    printf("proc: currentFrame %.2f, seq %d,\tseqFrame %f, cmdtype %d, cmdFrame %f\n",
        currentFrame, cmd->seq_e->seq, cmd->seq_e->seqFrame, cmd->type, cmd->cmdFrame);
  }

  ARGS->a4.u64 = (uint64_t) (&currentFrame);
  {
    switch (cmd->type)
    {
      case 0:
      {
        cmd->seq_e->cmd_h = cmd->seq_e->cmd_h->next;
        return;
      }
      break;

      case 1:
      {
        ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
        ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
        *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
        return;
      }
      break;

      case 2:
      {
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

        ARGS->a0.u64 = (uint64_t) acttable;
        ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
        ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
        if (ARGS->a0.u64 != 0)
        {
          memcpy(&f5, (char *) (s0.u32 + 12), 4);
          memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
          if (f4.s < f5.s)
          {
            f5.s = f4.s;
          }
          memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);
        }

        t6.u64 = *((int32_t *) (s0.u32 + 16));

        t5.u64 = *((int32_t *) (t6.u32 + 28));
        t5.u64 = *((int32_t *) (t5.u32 + 20));
        *((uint32_t *) (t6.u32 + 28)) = t5.u32;
        return;
      }
      break;

      case 3:
      {
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

        ARGS->a0.u64 = (uint64_t) acttable;
        ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
        ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
        if (ARGS->a0.u64 != 0)
        {
          memcpy(&f5, (char *) (s0.u32 + 12), 4);
          memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
          memcpy(&f6, (char *) (ARGS->a0.u32 + 12), 4);
          if (f4.s < f5.s)
          {
            if (f5.s < f6.s)
            {
              f5.s = f6.s;
            }

            memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);
          }
          else
          {
            f5.s = f4.s;
            if (f4.s < f6.s)
            {
              f5.s = f6.s;
            }

            memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);

            memcpy(&f6, (char *) (s0.u32 + 12), 4);
            f5.s = f6.s;
            if (f4.s < f6.s)
            {
              f5.s = f4.s;
            }

            memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);
          }

          ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));

          memcpy(&ARGS->f13, (char *) (ARGS->v0.u32 + 16), 4);
          memcpy((char *) (ARGS->a0.u32 + 28), &ARGS->f13, 4);
          at.u64 = *((int32_t *) (s0.u32 + 16));
          memcpy(&ARGS->f12, (char *) (at.u32 + 20), 4);
          *((uint8_t *) (ARGS->a0.u32 + 0)) = 1;
          memcpy((char *) (ARGS->a0.u32 + 32), &ARGS->f12, 4);
        }
        ARGS->a0.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->v1.u64 = *((int32_t *) (ARGS->a0.u32 + 28));
        ARGS->v1.u64 = *((int32_t *) (ARGS->v1.u32 + 20));
        *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->v1.u32;
        return;
      }
      break;

      case 4:
      {
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

        ARGS->a0.u64 = (uint64_t) acttable;
        ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
        ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
        if (ARGS->a0.u64 != 0)
        {
          memcpy(&f8, (char *) (s0.u32 + 12), 4);
          memcpy((char *) (ARGS->a0.u32 + 24), &f8, 4);
        }

        ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
        ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
        *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
        return;
      }
      break;

      case 101:
      {
        if ((double)cmd->flt_d < 1.0)
          cmd->seq_e->flt_e = 1.0;
        else
          cmd->seq_e->flt_e = cmd->flt_d;

        cmd->seq_e->cmd_h = cmd->seq_e->cmd_h->next;
        return;
      }
      break;

      case 102:
      {
        memcpy(&f4, (char *) (s0.u32 + 12), 4);

        f6.u64 = 0;
        f4.d = f4.s;
        memcpy(&f5, &dbl_10009300, 8);

        if (f4.d < f6.d)
        {
          f4.d = f6.d;
        }
        else
        {
          if (f5.d < f4.d)
          {
            f4.d = f5.d;
          }
        }

        t9.u64 = *((int32_t *) (s0.u32 + 16));

        f11.s = f4.d;
        memcpy((char *) (t9.u32 + 20), &f11, 4);
        t9.u64 = *((int32_t *) (s0.u32 + 16));
        t8.u64 = *((int32_t *) (t9.u32 + 28));
        t8.u64 = *((int32_t *) (t8.u32 + 20));
        *((uint32_t *) (t9.u32 + 28)) = t8.u32;
        return;
      }
      break;

      case 103:
      {
        memcpy(&f8, &flt_100092A8, 4);
        memcpy(&f4, (char *) (s0.u32 + 12), 4);
        ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));
        f9.d = 2.0000000000000000;
        f7.d = exprand__Gf(flt_100092A8);
        memcpy(&f5, (char *) (ARGS->a4.u32 + 20), 4);
        f7.d = f7.d * f9.d;
        f6.d = f4.s;
        f8.s = f8.s - f5.s;
        f6.d = f6.d * f7.d;
        memcpy(&f3, (char *) (ARGS->a4.u32 + 8), 4);
        f5.d = f5.s;
        f4.s = f4.s * f8.s;
        f5.d = f5.d * f6.d;
        f4.d = f4.s;
        f3.d = f3.s;
        f4.d = f4.d + f5.d;
        f3.d = f3.d + f4.d;
        f3.s = f3.d;
        memcpy((char *) (ARGS->a4.u32 + 8), &f3, 4);
        ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));
        ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 28));
        ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
        *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
        return;
      }
      break;

      case 8:
      {
        stopAnimation__Gv();
        ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));
        at.u64 = *((int32_t *) (ARGS->v0.u32 + 28));
        at.u64 = *((int32_t *) (at.u32 + 20));
        *((uint32_t *) (ARGS->v0.u32 + 28)) = at.u32;
        return;
      }
      break;

      case 9:
      {
        EPANOS_REG ra;
        at.u64 = *((int32_t *) (s0.u32 + 16));

        ra.u64 = *((int32_t *) (at.u32 + 28));
        ra.u64 = *((int32_t *) (ra.u32 + 20));
        *((uint32_t *) (at.u32 + 28)) = ra.u32;
        return;
      }
      break;

      case 10:
      {
        ARGS->a0.u64 = seqList;
        if (seqList == 0)
        {
          goto loc_10004DA0;
        }
        else
        {
          ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
          goto loc_10004D94;
        }
      }
      break;

      case 11:
      {
        ARGS->a0.u64 = seqList;
        if (seqList == 0)
        {
          goto loc_10004D60;
        }

        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
        goto loc_10004D54;
      }
      break;

      case 12:
      {
        t7.u64 = *((int32_t *) (s0.u32 + 16));

        t6.u64 = *((int32_t *) (t7.u32 + 24));
        *((uint32_t *) (t7.u32 + 28)) = t6.u32;
        t5.u64 = *((int32_t *) (s0.u32 + 16));
        memcpy(&f6, (char *) (t5.u32 + 12), 4);
        memcpy(&f5, (char *) (t5.u32 + 8), 4);
        f5.s = f5.s + f6.s;
        memcpy((char *) (t5.u32 + 8), &f5, 4);
        return;
      }
      break;

      case 13:
      {
        t5.u64 = *((int32_t *) (s0.u32 + 16));

        t4.u64 = *((int32_t *) (t5.u32 + 28));
        t4.u64 = *((int32_t *) (t4.u32 + 20));
        *((uint32_t *) (t5.u32 + 28)) = t4.u32;
        return;
      }
      break;

      case 14:
      {
        ARGS->a7.u64 = seqList;
        ARGS->a0.u64 = ARGS->a7.u64;

        if (ARGS->a7.u64 == 0)
        {
          goto loc_10004D24;
        }

        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
        goto loc_10004D18;
      }
      break;

      case 15:
      {
        ARGS->a5.u64 = (uint64_t) seqList;

        ARGS->a5.u64 = seqList;
        ARGS->a0.u64 = ARGS->a5.u64;
        if (ARGS->a5.u64 == 0)
        {
          goto def_100049B4;
        }

        loc_10004AD8:
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

        if (ARGS->a1.u64 != ARGS->a0.u64)
        {
          goto loc_100049BC;
        }

        ARGS->a6.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
        ARGS->a6.u64 = *((int32_t *) (ARGS->a6.u32 + 20));
        *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a6.u32;
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));
        if (ARGS->a0.u64 != 0)
        {
          goto loc_10004AD8;
        }

        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
        goto def_100049B4;
      }
      break;

      case 7:
      {
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

        ARGS->a0.u64 = (uint64_t) acttable;
        ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
        ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
        if (ARGS->a0.u64 != 0)
        {
          *((uint8_t *) (ARGS->a0.u32 + 0)) = 0;
        }
        ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
        ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
        *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
        return;
      }
      break;

      case 6:
      {
        ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 28));
        ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
        *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
        return;
      }
      break;

      case 5:
      {
        ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

        ARGS->a0.u64 = (uint64_t) acttable;
        ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
        ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
        ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
        if (ARGS->a0.u64 != 0)
        {
          memcpy(&f7, (char *) (ARGS->a0.u32 + 36), 4);
          memcpy((char *) (ARGS->a0.u32 + 24), &f7, 4);
        }

        ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

        ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
        ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
        *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
        return;
      }
      break;

      default:
        goto def_100049B4;
    }
  }
  loc_100049BC:
  killSeq__GP7animSeq(ARGS, ARGS->a0.u64);

  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
  def_100049B4:

  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  {
    printf("warning: bad command type (%d) in sequence cmd->seq\n", cmd->type);
  }
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a2.u32 + 28));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a1.u32 + 20));
  *((uint32_t *) (ARGS->a2.u32 + 28)) = ARGS->a1.u32;

  return;



  loc_10004D0C:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    goto loc_10004D24;
  }

  loc_10004D18:
  ARGS->a3.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a3.u64 != ARGS->a1.u64)
  {
    goto loc_10004D0C;
  }

  loc_10004D24:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 != ARGS->a0.u64)
  {
    return;
  }

  if (ARGS->a0.u64 == 0)
  {
    ARGS->a0.u64 = *((int32_t *) (ARGS->a1.u32 + 28));

    ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a0.u32;
  }
  else
  {
    killSeq__GP7animSeq(ARGS, ARGS->a0.u64);
  }
  return;

  loc_10004D48:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 != 0)
  {
    loc_10004D54:
    ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

    if (ARGS->a4.u64 != ARGS->a1.u64)
    {
      goto loc_10004D48;
    }

    loc_10004D60:
    if (ARGS->a0.u64 != 0)
    {
      *((uint32_t *) (ARGS->a0.u32 + 28)) = 0;
    }
  }

  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    return;
  }

  ARGS->a5.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  ARGS->a5.u64 = *((int32_t *) (ARGS->a5.u32 + 20));
  *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a5.u32;
  return;

  loc_10004D88:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    goto loc_10004DB8;
  }

  loc_10004D94:
  ARGS->a6.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a6.u64 != ARGS->a1.u64)
  {
    goto loc_10004D88;
  }

  loc_10004DA0:
  if (ARGS->a0.u64 != 0)
  {
    ARGS->a7.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
    *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->a7.u32;
    memcpy(&f9, (char *) (ARGS->a4.u32 + 0), 4);
    memcpy((char *) (ARGS->a0.u32 + 8), &f9, 4);
  }

  loc_10004DB8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    return;
  }

  t4.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  t4.u64 = *((int32_t *) (t4.u32 + 20));
  *((uint32_t *) (ARGS->a1.u32 + 28)) = t4.u32;
  return;

}

void display__Gv(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG t9;
  EPANOS_REG ra;
  EPANOS_REG f5;
  float var_50;

  wrap_glClear(GL_COLOR_BUFFER_BIT, wincount);
  wrap_glColor3f(1.0f, 1.0f, 1.0f, wincount);

  ARGS->a0.u64 = n;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + 1);
  ARGS->a3.u64 = (int32_t) (ARGS->a0.i32 >> 31);

  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  if ((double)1.0 <= (double)(t + acttable[45]->flt_g))
  {
    t = 0;
    ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
    ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
    n = ARGS->a0.u32;
    s3.u64 = 1;
  }
  else
  {
    s3.u64 = 0;
  }

  if (aflag != 0)
  {
    tasteQueue__Gv();
    setacttargets__Gv();
    animateacts__Gv();
  }

  y[n] = 0;
  x[n] = 0;
  dzoom[n] = acttable[31]->flt_g;
  arm[n] = acttable[94]->flt_g;
  wrist[n] = acttable[101]->flt_g;

  var_50 = acttable[73]->flt_g;

  dtwist[n] = acttable[38]->flt_g;

  nlimit = trunc_w_d(floor((double) acttable[52]->flt_g));

  if (0.0 < (double)acttable[18]->flt_g)
    outline[n] = 1;
  else
    outline[n] = 0;

  f5.s = acttable[123]->flt_g;

  hue[n] = acttable[123]->flt_g;

  if (1.0f <= acttable[123]->flt_g)
  {
    f5.s = f5.s + -1.0f;
    hue[n] = f5.s;
  }

  if (f5.s <= 1.0f)
  {
    hue[n] = f5.s + 1.0f;
  }

  light[n] = acttable[130]->flt_g;

  if (s3.u64 != 0)
  {
    gflip = fmodf(gflip + acttable[87]->flt_g, 360.0f);
    gspin = fmodf(gspin + acttable[80]->flt_g, 360.0f);

    s2.u64 = n;
    ra.u64 = (int32_t) (s2.i32 >> 31);
    t9.u64 = s2.u64 ^ ra.u64;
    t9.u64 = (int32_t) (t9.u32 - ra.u32);
    t9.u64 = t9.u64 & 127;
    t9.u64 = t9.u64 ^ ra.u64;
    t9.u64 = (int32_t) (t9.u32 - ra.u32);

    flip[t9.u32] = gflip;
    spin[t9.u32] = gspin;
  }

  wheel = fmodf(wheel - var_50, 360.0f);

  drawit__Gv(ARGS, wincount);

  t = t + acttable[45]->flt_g;

  wrap_glFinish(wincount);

  //t9.u64 = (uint64_t) swapBuffers__Q2_10GLXWrapper6windowGv;

  ARGS->a0.u64 = 0;

  return;
}

static void setacttargets__Gv(void)
{
  struct act **s0 = acttable;
  float f1;
  float f5;
  const float f20 = 1.00000000f;

  for (unsigned int s1=0; s1 < NELEMS(acttable); s1++,s0++)
  {
    struct act *act = *s0;

    if (act == NULL)
    {
      continue;
    }

    if (act->pad_a[0] == 0)
    {
      continue;
    }

    if (act->pad_a[1] != 0)
    {
      continue;
    }

    act->pad_a[1] = 1;

    {
      float f0 = drand48();
      f1 = act->flt_e;
      float f2 = f20 - f0;
      f0 = act->flt_d * f0;
      f1 = f1 * f2;
      f0 = f0 + f1;
      act->flt_c = f0;
    }
    {
      float f2 = act->flt_i;
      f1 = act->flt_h;
      float f3 = exprand__Gf(f20) * 2.00000000f;
      float f4 = f20 - f2;
      f3 = f1 * f3;
      f1 = f1 * f4;
      f2 = f2 * f3;
      f1 = f1 + f2;
    }
    f5 = f20;

    if (f1 < f20)
      ;
    else
    {
      float f7 = act->flt_i;
      f5 = act->flt_h;
      float f8 = exprand__Gf(f20) * 2.00000000f;
      float f9 = f20 - f7;
      f8 = f5 * f8;
      f5 = f5 * f9;
      f7 = f7 * f8;
      f5 = f5 + f7;
    }

    {
      float f4 = act->flt_c;
      f4 = f4 - act->flt_f;
      f4 = f4 / f5;
      s0++;
      act->flt_f = f4;

      if (0 < f4)
        f4 = f20;
      else
        f4 = -1.00000000f;

      act->flt_b = f4;
    }

    if (s1 < NELEMS(acttable)-1)
    {
      s1++;
    }
    else
    {
      return;
    }
  }
}

void reshape__GiT1(const GLuint width, const GLuint height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(300.0,
                   (GLdouble)((float)width / (float)height),
                   0.01,
                   10000.0);
    glTranslatef(0.0f, 0.0f, -4.0f);
    glMatrixMode(GL_MODELVIEW);
}

static float twixt__GiPff(int a0, const float *a1, float f14)
{
  float f0;
  float f1;
  float f2;
  int a4 = a0 - 1;

  if (a0 <= 0)
  {
    a4 = a4 + 128;
  }

  f2 = 1.0f - f14;
  f0 = a1[a0] * f14;
  f1 = a1[a4] * f2;
  {
    f0 = f0 + f1;
    return f0;
  }
}

static float exprand__Gf(float arg)
{
  assert ((double)arg > 0.0);

  return (double)expm1(drand48() * (double)arg) / (double)expm1(1.0);
}
