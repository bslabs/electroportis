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

static float flt_100092A0 = 180.000000f;
static float flt_100092A8 = 1.00000000f;
static double dbl_10009300 = 1.0000000000000000;
static float flt_100092B0 = 300.000000f;
static double dbl_100092D0 = 60.000000000000000;
static float flt_100092BC = -0.500000000f;
static double dbl_100092D8 = 0.50000000000000000;
static float flt_100092B4 = -1.00000000f;
static float flt_10009290 = 360.000000f;
static float flt_10009294 = -360.000000f;
static const char *aD = "%d";
static const char *aF = "%f";
static const char *aSDF = "%s %d, %f";
static const char *aSF = "%s %f";
static const char *aSD = "%s %d";
static const char *aS = "%s";
static const char *aDF = "%d, %f";

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

static char aflag = 1;
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
#pragma pack ()
static struct act *acttable[1024];
static char sflag;
static float currentFrame;
static float relFrame;
static float baseFrame;
static float absFrame;
static float wheel;
static float dwheel;
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
static float dflip;
static float gspin;
static float dspin;
static int n;
static int nlimit;
static float t;
static uintptr_t *seqList;
static uintptr_t *editSeq;
static int theWindow;

static void drawit__Gv(EPANOS_ARGS *ARGS, wincount_t wincount);
static void addToSeq__GP7animSeqP11animCommand(EPANOS_ARGS *ARGS);
static void animateacts__Gv(void);
static void stopAnimation__Gv(void);
static void readAnimation__Gv(EPANOS_ARGS *ARGS);
static float foldtwixt__GiPffT3(int a0, float *a1, float f14, float f15);
static void drawshape__GiT1(char poly, wincount_t wincount);
static void tasteQueue__Gv(EPANOS_ARGS *ARGS);
static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS, float *a3, float *a4, float *a5);
static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS);
static struct act *createBlankActAnim__Gv(void);
static void value__GfN21(EPANOS_ARGS *ARGS);
static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS);
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

  ARGS->f12.s = f26.s;
  ARGS->f13.s = f24.s;
  ARGS->f14.s = f22.s;
  {
    hls_to_rgb__GfN21PfN24(ARGS, colRGBA, &(colRGBA[1]), &(colRGBA[2]));
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

  ARGS->f13.s = f22.s - f24.s;
  ARGS->f14.s = f22.s;
  {
    hls_to_rgb__GfN21PfN24(ARGS, outlinecolRGBA, &(outlinecolRGBA[1]), &(outlinecolRGBA[2]));
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

static void addToSeq__GP7animSeqP11animCommand(EPANOS_ARGS *ARGS)
{
  EPANOS_REG at;
  EPANOS_REG f1;
  EPANOS_REG f4;

  *((uint32_t *) (ARGS->a1.u32 + 16)) = ARGS->a0.u32;

  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  memcpy(&f4, (char *) (ARGS->a1.u32 + 8), 4);
  if (ARGS->a4.u64 == 0)
  {
    *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;
    *((uint32_t *) (ARGS->a0.u32 + 24)) = ARGS->a1.u32;
    return;
  }

  memcpy(&ARGS->f0, (char *) (ARGS->a4.u32 + 8), 4);
  ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 20));

  if (f4.s < ARGS->f0.s)
  {
    *((uint32_t *) (ARGS->a1.u32 + 20)) = ARGS->a4.u32;
    *((uint32_t *) (ARGS->a0.u32 + 24)) = ARGS->a1.u32;
    return;
  }

  if (ARGS->a3.u64 == 0)
  {
    *((uint32_t *) (ARGS->a4.u32 + 20)) = ARGS->a1.u32;
    *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;
    return;
  }

  loc_10003930:
  memcpy(&f1, (char *) (ARGS->a3.u32 + 8), 4);

  if (f4.s < f1.s)
  {
    *((uint32_t *) (ARGS->a1.u32 + 20)) = ARGS->a3.u32;

    *((uint32_t *) (ARGS->a4.u32 + 20)) = ARGS->a1.u32;
  }
  else
  {
    ARGS->a4.u64 = ARGS->a3.u64;
    ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
    if (ARGS->a3.u64 != 0)
    {
      goto loc_10003930;
    }
  }

  at.u64 = *((int32_t *) (ARGS->a1.u32 + 20));

  if (at.u64 != 0)
  {
    return;
  }

  ARGS->v0.u64 = *((int32_t *) (ARGS->a0.u32 + 32));
  *((uint32_t *) (ARGS->v0.u32 + 20)) = ARGS->a1.u32;
  *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;
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
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s2;
  EPANOS_REG s4;
  EPANOS_REG s7;
  EPANOS_REG t8;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f23;
  EPANOS_REG f25;
  EPANOS_REG f27;
  EPANOS_REG f29;
  int var_2E0;
  uint64_t var_60;
  uint64_t var_D8;
  uint64_t var_58;
  uint64_t var_B8;
  uint64_t var_B0;
  char var_2D8[256];
  uint64_t var_A8;
  uint64_t var_A0;
  uint64_t var_98;
  uint64_t var_90;
  uint64_t var_28;
  uint64_t var_88;
  uint64_t var_80;
  uint64_t var_78;
  uint64_t var_70;
  uint64_t var_68;
  char var_1D8[256];
  readAnimation__Gv:

  s0.u64 = (uint64_t) defaultScript;
  if (oflag != 0)
  {
    printf("# reading animation...");
    printf("\n");
  }



  f20.u32 = 0;
  ARGS->a1.u64 = var_2E0;
  {
    var_A8 = ARGS->a1.u64;
    goto loc_10003B54;
  }
  loc_10003A40:
  if (strncmp("#", var_2D8, 1) == 0)
  {
    if (oflag != 0)
    {
      printf("%s", var_2D8);
    }

    free((void *) s2.u64);

    goto loc_10003AE8;
  }

  if (oflag != 0)
  {
    printf("bad command: %s", var_2D8);
  }

  {
    free(s2.u64);
  }

  ARGS->a1.u64 = 1;
  var_58 = ARGS->a1.u64;
  ARGS->a2.u64 = var_58;
  loc_10003A8C:
  var_60 = ARGS->a2.u64;

  loc_10003A90:
  ARGS->a3.u64 = var_60;

  loc_10003A94:
  var_68 = ARGS->a3.u64;

  loc_10003A98:
  ARGS->a4.u64 = var_68;

  loc_10003A9C:
  var_70 = ARGS->a4.u64;

  ARGS->a5.u64 = var_70;
  loc_10003AA4:
  var_78 = ARGS->a5.u64;

  loc_10003AA8:
  ARGS->a6.u64 = var_78;

  loc_10003AAC:
  var_80 = ARGS->a6.u64;

  ARGS->a7.u64 = var_80;
  loc_10003AB4:
  var_88 = ARGS->a7.u64;

  loc_10003AB8:
  fp.u64 = var_88;

  loc_10003ABC:
  s7.u64 = fp.u64;

  loc_10003AC0:
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
    ARGS->v0.u64 = (int) sscanf((const char *) s0.u64, "%[^\n]\n", var_1D8);
  }
  t4.u64 = oflag;
  if (t4.u64 == 0)
  {
    t5.u64 = (uint64_t) (&bflag);
    goto loc_10003B18;
  }
  else
    t5.u64 = (uint64_t) (&bflag);

  {
    printf("%s\n", var_1D8);
  }
  t5.u64 = (uint64_t) (&bflag);
  loc_10003B18:
  t5.u64 = bflag;

  s2.u64 = (uint64_t) strlen;
  var_1D8[0] = 0;
  if (t5.u64 == 0)
  {
    goto loc_10003DD8;
  }

  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) s0.u64, "\n");
  }
  s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
  s0.u64 = (int32_t) (s0.u32 + 1);
  {
    ARGS->a0.u64 = s0.u64;
    ARGS->v0.u64 = (unsigned int) strlen((const char *) ARGS->a0.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041A4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  loc_10003B54:
  var_58 = 0;

  var_60 = 0;
  var_68 = 0;
  var_70 = 0;
  var_78 = 0;
  var_80 = 0;
  var_88 = 0;
  var_90 = 0;
  var_98 = 0;
  s2.u64 = 0;
  var_A0 = 0;
  fp.u64 = 0;
  s7.u64 = 0;
  var_B0 = 0;
  s4.u64 = 0;
  var_B8 = 0;
  ARGS->a0.u64 = s0.u64;
  ARGS->a2.u64 = (uint64_t) (&var_2D8[0]);
  var_D8 = 0;
  {
    ARGS->a1.u64 = (uint64_t) aS;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (char *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
    var_28 = s2.u64;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
  }
  ARGS->a0.u64 = 24;
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }
  t8.u64 = (uint64_t) (&absFrame);
  memcpy(&ARGS->f0, &absFrame, 4);
  s2.u64 = ARGS->v0.u64;
  {
    memcpy((char *) (ARGS->v0.u32 + 8), &ARGS->f0, 4);
  }
  if (strcmp("frame:", var_2D8) == 0)
  {
    goto loc_10003D30;
  }

  if (strcmp("relframe:", var_2D8) == 0)
  {
    goto loc_10003E58;
  }

  s4.u64 = var_D8;
  if (strcmp("absframe:", var_2D8) == 0)
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

    ARGS->a1.u64 = (uint64_t) aF;
    ARGS->a0.u64 = s0.u64;
    s4.u64 = 1;
    {
      *((uint32_t *) (s2.u32 + 0)) = s4.u32;
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
    ARGS->v0.u64 = (unsigned int)strcspn((const char *)ARGS->a0.u64, " \t\n");
    }
    ARGS->a7.u64 = oflag;
    if (ARGS->a7.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003F24;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&f10, (char *) (s2.u32 + 12), 4);
    f10.d = f10.s;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->a2.u64 = f10.u64;
    {
      ARGS->a0.u64 = (uint64_t) aSF;
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
    }
    loc_10003F24:
    t6.u64 = (uint64_t) (&relFrame);

    t5.u64 = (uint64_t) (&baseFrame);
    memcpy(&relFrame, &f20, 4);
    memcpy(&ARGS->f12, (char *) (s2.u32 + 12), 4);
    t4.u64 = (uint64_t) (&absFrame);
    memcpy(&baseFrame, &ARGS->f12, 4);
    memcpy(&f11, (char *) (s2.u32 + 12), 4);
    {
      memcpy(&absFrame, &f11, 4);
      goto loc_10003ADC;
    }
  }

  s7.u64 = var_B8;
  if (strcmp("randdelay:", var_2D8) == 0)
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

    ARGS->a1.u64 = (uint64_t) aF;
    ARGS->a0.u64 = s0.u64;
    s4.u64 = 103;
    {
      *((uint32_t *) (s2.u32 + 0)) = s4.u32;
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    t7.u64 = oflag;
    if (t7.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003AD8;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&ARGS->f13, (char *) (s2.u32 + 12), 4);
    ARGS->f13.d = ARGS->f13.s;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->a2.u64 = ARGS->f13.u64;
    {
      ARGS->a0.u64 = (uint64_t) aSF;
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
    }
    {
      s7.u64 = fp.u64;
      goto loc_10003ADC;
    }
  }

  fp.u64 = var_B0;
  if (strcmp("duration:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    s7.u64 = var_28;
    ARGS->a1.u64 = (uint64_t) aF;
    s4.u64 = 101;
    *((uint32_t *) (s2.u32 + 0)) = s4.u32;
    {
      ARGS->a2.u64 = (int32_t) (s2.u32 + 12);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a3.u64 = oflag;
    if (ARGS->a3.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003AD4;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&ARGS->f14, (char *) (s2.u32 + 12), 4);
    ARGS->f14.d = ARGS->f14.s;
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->a2.u64 = ARGS->f14.u64;
    {
      ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
    }
    {
      fp.u64 = s7.u64;
      goto loc_10003AD8;
    }
  }

  if (strcmp("variance:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = (uint64_t) aF;
    s7.u64 = 102;
    *((uint32_t *) (s2.u32 + 0)) = s7.u32;
    {
      ARGS->a2.u64 = (int32_t) (s2.u32 + 12);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a4.u64 = oflag;
    if (ARGS->a4.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003AD0;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&ARGS->f15, (char *) (s2.u32 + 12), 4);
    ARGS->f15.d = ARGS->f15.s;
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->a2.u64 = ARGS->f15.u64;
    {
      ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
    }
    {
      s7.u64 = s4.u64;
      goto loc_10003AD4;
    }
  }

  s4.u64 = var_A0;
  if (strcmp("actlim1:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = (uint64_t) aDF;
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    s4.u64 = 2;
    *((uint32_t *) (s2.u32 + 0)) = s4.u32;
    {
      ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a5.u64 = oflag;
    if (ARGS->a5.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003ACC;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&ARGS->f16, (char *) (s2.u32 + 12), 4);
    ARGS->f16.d = ARGS->f16.s;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->a3.u64 = ARGS->f16.u64;
    {
      ARGS->a0.u64 = (uint64_t) (&aSDF[0]);
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
    }
    {
      s4.u64 = s7.u64;
      goto loc_10003AD0;
    }
  }

  s7.u64 = var_98;
  if (strcmp("actlim2:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = (uint64_t) aDF;
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    s4.u64 = 3;
    *((uint32_t *) (s2.u32 + 0)) = s4.u32;
    {
      ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a1.u64 = oflag;
    if (ARGS->a1.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003AC8;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&ARGS->f17, (char *) (s2.u32 + 12), 4);
    ARGS->f17.d = ARGS->f17.s;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->a3.u64 = ARGS->f17.u64;
    {
      ARGS->a0.u64 = (uint64_t) (&aSDF[0]);
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
    }
    {
      s7.u64 = fp.u64;
      goto loc_10003ACC;
    }
  }

  fp.u64 = var_90;
  if (strcmp("actset:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = (uint64_t) aDF;
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    s7.u64 = 4;
    *((uint32_t *) (s2.u32 + 0)) = s7.u32;
    {
      ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a1.u64 = oflag;
    if (ARGS->a1.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003AC4;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    memcpy(&f21, (char *) (s2.u32 + 12), 4);
    f21.d = f21.s;
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->a3.u64 = f21.u64;
    {
      ARGS->v0.u64 = (int) printf("%s %d, %f", var_2D8, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
    }
    {
      fp.u64 = s4.u64;
      goto loc_10003AC8;
    }
  }

  if (strcmp("actreset:", var_2D8) == 0)
  {
    goto loc_100043B4;
  }

  if (strcmp("actresetall:", var_2D8) != 0)
  {
    goto loc_10003DFC;
  }

  ARGS->a2.u64 = 6;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = oflag;
  if (ARGS->a1.u64 == 0)
  {
    s7.u64 = fp.u64;
    goto loc_10003AC0;
  }
  else
    s7.u64 = fp.u64;

  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    s7.u64 = fp.u64;
    goto loc_10003AC0;
  }
  loc_10003D30:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  {
    *((uint32_t *) (s2.u32 + 0)) = 0;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
	ARGS->v0.u64 = (unsigned int)strcspn((const char *)ARGS->a0.u64, " \t\n");
  }
  ARGS->a3.u64 = oflag;
  if (ARGS->a3.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003D7C;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f1, (char *) (s2.u32 + 12), 4);
  f1.d = f1.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = f1.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10003D7C:
  memcpy(&f4, (char *) (s2.u32 + 12), 4);

  ARGS->a5.u64 = (uint64_t) (&relFrame);
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  memcpy(&f3, &relFrame, 4);
  memcpy(&ARGS->f2, &baseFrame, 4);
  f3.s = f3.s + f4.s;
  ARGS->a4.u64 = (uint64_t) (&absFrame);
  memcpy(&relFrame, &f3, 4);
  ARGS->f2.s = ARGS->f2.s + f3.s;
  memcpy(&absFrame, &ARGS->f2, 4);
  loc_10003DA4:
  ARGS->a0.u64 = (uint64_t) editSeq;

  ARGS->a0.u64 = editSeq;
  if (ARGS->a0.u64 == 0)
  {
    goto loc_1000445C;
  }

  loc_10003DB0:
  {
    ARGS->a1.u64 = s2.u64;
    addToSeq__GP7animSeqP11animCommand(ARGS);
  }
  ARGS->a1.u64 = (uint64_t) editSeq;
  ARGS->a2.u64 = (uint64_t) (&relFrame);
  ARGS->a1.u64 = editSeq;
  memcpy(&f5, &relFrame, 4);
  {
    memcpy((char *) (ARGS->a1.u32 + 12), &f5, 4);
    goto loc_10003AE4;
  }
  loc_10003DD8:

  s0.u64 = -1;
  {
    ARGS->v0.u64 = (int) scanf("%[^\n]\n", (char *) var_A8);
  }
  if (ARGS->v0.u64 == s0.u64)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041A4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  {
    s0.u64 = var_A8;
    goto loc_10003B54;
  }
  loc_10003DFC:

  if (strcmp("actstop:", var_2D8) == 0)
  {
    goto loc_10004408;
  }

  if (strcmp("actstopall:", var_2D8) != 0)
  {
    if (strcmp("seqname:", var_2D8) == 0)
    {
      goto loc_100044F8;
    }

    if (strcmp("seqdo:", var_2D8) == 0)
    {
      ARGS->a0.u64 = s0.u64;

      ARGS->a1.u64 = (uint64_t) aD;
      ra.u64 = 10;
      *((uint32_t *) (s2.u32 + 0)) = ra.u32;
      {
        ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
        ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
      }
      ARGS->a0.u64 = s0.u64;
      {
        ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
      }
      if (oflag == 0)
      {
        s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
        goto loc_10003AA8;
      }
      else
        s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

      ARGS->a0.u64 = (uint64_t) aSD;
      ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
      {
        ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
        ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
      }
      {
        ARGS->a6.u64 = var_78;
        goto loc_10003AAC;
      }
    }

    if (strcmp("seqloop:", var_2D8) != 0)
    {
      goto loc_10004328;
    }

    ARGS->a2.u64 = 12;
    *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
    ARGS->a1.u64 = oflag;
    if (ARGS->a1.u64 == 0)
    {
      ARGS->a5.u64 = var_70;
      goto loc_10003AA4;
    }
    else
      ARGS->a5.u64 = var_70;

    ARGS->a0.u64 = (uint64_t) aS;
    {
      ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
    }
    {
      ARGS->a5.u64 = var_70;
      goto loc_10003AA4;
    }
  }

  ARGS->a2.u64 = 8;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = oflag;
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a7.u64 = var_80;
    goto loc_10003AB4;
  }
  else
    ARGS->a7.u64 = var_80;

  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    ARGS->a7.u64 = var_80;
    goto loc_10003AB4;
  }
  loc_10003E58:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  {
    *((uint32_t *) (s2.u32 + 0)) = 0;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
	ARGS->v0.u64 = (unsigned int)strcspn((const char *)ARGS->a0.u64, " \t\n");
  }
  ARGS->a3.u64 = oflag;
  if (ARGS->a3.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003EA4;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f6, (char *) (s2.u32 + 12), 4);
  f6.d = f6.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = f6.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10003EA4:
  memcpy(&f9, (char *) (s2.u32 + 12), 4);

  ARGS->a5.u64 = (uint64_t) (&relFrame);
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  memcpy(&f8, &relFrame, 4);
  memcpy(&f7, &baseFrame, 4);
  f8.s = f8.s + f9.s;
  ARGS->a4.u64 = (uint64_t) (&absFrame);
  memcpy(&relFrame, &f8, 4);
  f7.s = f7.s + f8.s;
  {
    memcpy(&absFrame, &f7, 4);
    goto loc_10003AE0;
  }
  ARGS->a1.u64 = (uint64_t) seqList;
  loc_100041A4:
  ARGS->a1.u64 = seqList;

  if (ARGS->a1.u64 == 0)
  {
    s4.u64 = ARGS->a1.u64;
    goto loc_100041C4;
  }
  else
    s4.u64 = ARGS->a1.u64;

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
    ARGS->a3.u64 = oflag;
    goto loc_100041B0;
  }
  else
    loc_100041C4:
  ARGS->a3.u64 = oflag;


  if (ARGS->a3.u64 == 0)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041E4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  {
    printf("# done reading animation\n");
  }
  ARGS->a1.u64 = (uint64_t) seqList;
  loc_100041E4:
  ARGS->a1.u64 = seqList;

  if (ARGS->a1.u64 == 0)
  {
    return;
  }
  else
    s4.u64 = ARGS->a1.u64;

  {
    goto loc_1000424C;
  }
  loc_100041FC:
  s0.u64 = *((int32_t *) (s0.u32 + 20));

  if (s0.u64 == 0)
  {
    ;
    goto loc_10004240;
  }
  else
    ;

  loc_10004208:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_100041FC;
  }
  else
    ;


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
    ;
    goto loc_10004280;
  }
  else
    ;

  loc_10004240:
  s4.u64 = *((int32_t *) (s4.u32 + 36));

  if (s4.u64 == 0)
  {
    return;
  }

  loc_1000424C:
  if (oflag == 0)
  {
    ;
    goto loc_10004274;
  }
  else
    ;


  memcpy(&ARGS->f19, (char *) (s4.u32 + 8), 4);
  ARGS->f19.d = ARGS->f19.s;
  ARGS->a1.u64 = *((int32_t *) (s4.u32 + 0));
  ARGS->a2.u64 = ARGS->f19.u64;
  {
    ARGS->v0.u64 = (int) printf("seq %d at %.2f\n", (int32_t) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10004274:
  s0.u64 = *((int32_t *) (s4.u32 + 24));

  if (s0.u64 == 0)
  {
    goto loc_10004240;
  }

  loc_10004280:
  {
    ARGS->a0.u64 = oflag;
    goto loc_10004208;
  }

  {
    return;
  }
  loc_10004328:

  if (strcmp("seqstop:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = (uint64_t) aD;
    ARGS->v1.u64 = 11;
    *((uint32_t *) (s2.u32 + 0)) = ARGS->v1.u32;
    {
      ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a0.u64 = oflag;
    if (ARGS->a0.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003A98;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    ARGS->a0.u64 = (uint64_t) aSD;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    {
      ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
    }
    {
      ARGS->a4.u64 = var_68;
      goto loc_10003A9C;
    }
  }

  if (strcmp("seqrepeat:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = 13;
    *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
    ARGS->a1.u64 = (uint64_t) aD;
    {
      ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a2.u64 = oflag;
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    if (ARGS->a2.u64 == 0)
    {
      goto loc_10004758;
    }

    ARGS->a0.u64 = (uint64_t) aSD;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    {
      ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
    }
    ARGS->a3.u64 = oflag;
    if (ARGS->a3.u64 != 0)
    {
      printf("warning: %s not implemented\n", var_2D8);
    }

    loc_10004758:
    free((void *) s2.u64);
    goto loc_10003AE8;
  }

  if (strcmp("seqkill:", var_2D8) == 0)
  {
    ARGS->a0.u64 = s0.u64;

    ARGS->a1.u64 = 14;
    *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
    ARGS->a1.u64 = (uint64_t) aD;
    {
      ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
      ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
    }
    ARGS->a0.u64 = s0.u64;
    {
      ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
    }
    ARGS->a2.u64 = oflag;
    if (ARGS->a2.u64 == 0)
    {
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
      goto loc_10003A90;
    }
    else
      s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

    ARGS->a0.u64 = (uint64_t) aSD;
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    {
      ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
      ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
    }
    {
      ARGS->a3.u64 = var_60;
      goto loc_10003A94;
    }
  }

  if (strcmp("seqkillall:", var_2D8) != 0)
  {
    goto loc_10003A40;
  }

  ARGS->a2.u64 = 15;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = oflag;
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a2.u64 = var_58;
    goto loc_10003A8C;
  }
  else
    ARGS->a2.u64 = var_58;

  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    ARGS->a2.u64 = var_58;
    goto loc_10003A8C;
  }
  loc_100043B4:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = (uint64_t) aD;
  ARGS->a3.u64 = 5;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a3.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
  }
  ARGS->a4.u64 = oflag;
  if (ARGS->a4.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AC0;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    s4.u64 = s7.u64;
    goto loc_10003AC4;
  }
  loc_10004408:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = (uint64_t) aD;
  ARGS->a5.u64 = 7;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a5.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
  }
  ARGS->a6.u64 = oflag;
  if (ARGS->a6.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AB8;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    fp.u64 = var_88;
    goto loc_10003ABC;
  }
  loc_1000445C:

  {
    ARGS->a0.u64 = 40;
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }
  ARGS->a4.u64 = (uint64_t) editSeq;
  editSeq = ARGS->v0.u32;
  t8.u64 = 1;
  *((uint8_t *) (ARGS->v0.u32 + 4)) = t8.u8;
  t7.u64 = editSeq;
  *((uint32_t *) (t7.u32 + 0)) = 0;
  t6.u64 = editSeq;
  memcpy(&f25, &flt_100092B0, 4);
  memcpy((char *) (t6.u32 + 8), &f20, 4);
  t5.u64 = editSeq;
  memcpy(&f23, &flt_100092A8, 4);
  memcpy((char *) (t5.u32 + 16), &f25, 4);
  t4.u64 = editSeq;
  memcpy((char *) (t4.u32 + 20), &f23, 4);
  ARGS->a7.u64 = editSeq;
  memcpy((char *) (ARGS->a7.u32 + 16), &f25, 4);
  ARGS->a6.u64 = editSeq;
  memcpy((char *) (ARGS->a6.u32 + 20), &f23, 4);
  ARGS->a5.u64 = editSeq;
  *((uint32_t *) (ARGS->a5.u32 + 32)) = 0;
  ARGS->a3.u64 = editSeq;
  *((uint32_t *) (ARGS->a3.u32 + 28)) = 0;
  ARGS->a2.u64 = editSeq;
  *((uint32_t *) (ARGS->a2.u32 + 24)) = 0;
  ARGS->a1.u64 = editSeq;
  ARGS->a0.u64 = (uint64_t) seqList;
  *((uint32_t *) (ARGS->a1.u32 + 36)) = 0;
  ARGS->a0.u64 = seqList;
  if (ARGS->a0.u64 == 0)
  {
    ARGS->a4.u64 = editSeq;
    goto loc_100044E8;
  }
  else
    ARGS->a4.u64 = editSeq;

  *((uint32_t *) (ARGS->a4.u32 + 36)) = ARGS->a0.u32;
  loc_100044E8:
  ARGS->a0.u64 = (uint64_t) editSeq;

  ARGS->a0.u64 = editSeq;
  {
    seqList = ARGS->a0.u32;
    goto loc_10003DB0;
  }
  loc_100044F8:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = 9;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
  ARGS->a1.u64 = (uint64_t) aD;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, " \t\n");
  }
  ARGS->a2.u64 = oflag;
  if (ARGS->a2.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10004544;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  loc_10004544:
  ARGS->a4.u64 = (uint64_t) (&relFrame);

  ARGS->a5.u64 = (uint64_t) (&absFrame);
  ARGS->a3.u64 = (uint64_t) seqList;
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  ARGS->a3.u64 = seqList;
  memcpy(&baseFrame, &f20, 4);
  memcpy(&absFrame, &f20, 4);
  memcpy(&relFrame, &f20, 4);
  if (ARGS->a3.u64 == 0)
  {
    s4.u64 = ARGS->a3.u64;
    if (s4.u64 != 0)
    {
      goto loc_10004614;
    }
    else
    {
      goto loc_10004588;
    }
  }
  else
    s4.u64 = ARGS->a3.u64;

  ARGS->v0.u64 = *((int32_t *) (s2.u32 + 4));
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
    ARGS->a0.u64 = 40;
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }

  ARGS->a4.u64 = (uint64_t) editSeq;
  editSeq = ARGS->v0.u32;
  t7.u64 = *((int32_t *) (s2.u32 + 4));
  *((uint32_t *) (ARGS->v0.u32 + 0)) = t7.u32;
  t6.u64 = editSeq;
  t5.u64 = 1;
  *((uint8_t *) (t6.u32 + 4)) = t5.u8;
  t4.u64 = editSeq;
  memcpy(&f29, &flt_100092B0, 4);
  memcpy((char *) (t4.u32 + 8), &f20, 4);
  ARGS->a7.u64 = editSeq;
  memcpy(&f27, &flt_100092A8, 4);
  memcpy((char *) (ARGS->a7.u32 + 16), &f29, 4);
  ARGS->a6.u64 = editSeq;
  memcpy((char *) (ARGS->a6.u32 + 20), &f27, 4);
  ARGS->a5.u64 = editSeq;
  *((uint32_t *) (ARGS->a5.u32 + 24)) = 0;
  ARGS->a3.u64 = editSeq;
  *((uint32_t *) (ARGS->a3.u32 + 28)) = 0;
  ARGS->a2.u64 = editSeq;
  *((uint32_t *) (ARGS->a2.u32 + 32)) = 0;
  ARGS->a1.u64 = editSeq;
  ARGS->a0.u64 = (uint64_t) seqList;
  *((uint32_t *) (ARGS->a1.u32 + 36)) = 0;
  ARGS->a0.u64 = seqList;
  t8.u64 = (uint64_t) editSeq;
  if (ARGS->a0.u64 == 0)
  {
    ARGS->a4.u64 = editSeq;
    goto loc_10004608;
  }
  else
    ARGS->a4.u64 = editSeq;

  *((uint32_t *) (ARGS->a4.u32 + 36)) = ARGS->a0.u32;
  loc_10004608:
  t8.u64 = editSeq;

  seqList = t8.u32;
  loc_10004614:
  {
    ARGS->a0.u64 = s2.u64;
    free((void *) ARGS->a0.u64);
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

static void tasteQueue__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG at;
  EPANOS_REG f1;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f20;
  int EPANOS_fp_cond;
  tasteQueue__Gv:

  ARGS->v0.u64 = (int32_t) (1 << 16);
  ARGS->v0.u64 = 49368;
  memcpy(&f1, &flt_100092A8, 4);
  s1.u64 = (uint64_t) (&currentFrame);
  at.u64 = (uint64_t) seqList;
  memcpy(&ARGS->f0, &currentFrame, 4);
  at.u64 = seqList;
  s2.u64 = (uint64_t) processCommand__GP11animCommand;
  memcpy(&f20, &dbl_100092D8, 8);
  ARGS->f0.s = ARGS->f0.s + f1.s;
  s0.u64 = at.u64;
  if (at.u64 == 0)
  {
    memcpy(&currentFrame, &ARGS->f0, 4);
    goto loc_10004FCC;
  }
  else
    memcpy(&currentFrame, &ARGS->f0, 4);

  {
    memcpy(&f4, &currentFrame, 4);
    goto loc_10004F2C;
  }
  loc_10004F20:
  s0.u64 = *((int32_t *) (s0.u32 + 36));

  loc_10004F24:
  if (s0.u64 == 0)
  {
    memcpy(&f4, (char *) (s1.u32 + 0), 4);
    goto loc_10004FCC;
  }
  else
    memcpy(&f4, (char *) (s1.u32 + 0), 4);


  loc_10004F2C:
  memcpy(&f5, (char *) (s0.u32 + 8), 4);

  f4.d = f4.s;
  ARGS->f2.d = f5.s;
  f4.d = f4.d + f20.d;
  if (ARGS->f2.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));
  if (!EPANOS_fp_cond)
  {
    ARGS->a2.u64 = *((int8_t *) (s0.u32 + 4));
    goto loc_10004F20;
  }
  else
    ARGS->a2.u64 = *((int8_t *) (s0.u32 + 4));

  if (ARGS->a2.u64 == 0)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  memcpy(&f6, (char *) (ARGS->a0.u32 + 8), 4);
  f6.s = f6.s + f5.s;
  f6.d = f6.s;
  if (f6.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  loc_10004F7C:
  {
    ;
    processCommand__GP11animCommand(ARGS);
  }

  ARGS->v1.u64 = *((int8_t *) (s0.u32 + 4));
  memcpy(&f9, (char *) (s0.u32 + 8), 4);
  memcpy(&f8, (char *) (s1.u32 + 0), 4);
  if (ARGS->v1.u64 == 0)
  {
    ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));
    goto loc_10004FC4;
  }
  else
    ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004FC4;
  }
  else
    ;

  memcpy(&f7, (char *) (ARGS->a0.u32 + 8), 4);
  f8.d = f8.s;
  f7.s = f7.s + f9.s;
  f8.d = f8.d + f20.d;
  f7.d = f7.s;
  if (f7.d < f8.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    goto loc_10004F7C;
  }

  loc_10004FC4:
  {
    s0.u64 = *((int32_t *) (s0.u32 + 36));
    goto loc_10004F24;
  }

  loc_10004FCC:

  {
    return;
  }
}

static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS, float *a3, float *a4, float *a5)
{
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  float f4;
  float f5;
  float f20;
  double var_50;
  double var_48;
  double var_40;

  f4 = ARGS->f13.s;
  f5 = ARGS->f12.s;
  s1.u64 = a5;
  s0.u64 = a4;
  s2.u64 = a3;

  ARGS->f0.d = ARGS->f13.s;
  if (ARGS->f0.d <= 0.5)
  {
    f20 = ARGS->f14.s + 1.0f;
    f20 = ARGS->f13.s * f20;
  }
  else
  {
    float f21 = ARGS->f13.s * ARGS->f14.s;

    f20 = ARGS->f13.s + ARGS->f14.s;
    f20 = f20 - f21;
  }

  if (ARGS->f14.s == 0.0f)
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
  memcpy((char *) (s2.u32 + 0), &ARGS->f0, 4);
  memcpy(&ARGS->f12, &var_40, 8);
  ARGS->f13.s = f20;
  {
    memcpy(&ARGS->f14, &var_50, 8);
    value__GfN21(ARGS);
  }
  memcpy(&ARGS->f14, &var_48, 8);
  ARGS->f14.d = ARGS->f14.d + -120.00000000000000;
  memcpy(&ARGS->f12, &var_40, 8);
  memcpy((char *) (s0.u32 + 0), &ARGS->f0, 4);
  ARGS->f13.s = f20;
  {
    ARGS->f14.s = ARGS->f14.d;
    value__GfN21(ARGS);
  }
  {
    memcpy((char *) (s1.u32 + 0), &ARGS->f0, 4);
    return;
  }
}

static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS)
{
  EPANOS_REG s0;
  EPANOS_REG s1;
  killSeq__GP7animSeq:

  s0.u64 = ARGS->a0.u64;
  if (ARGS->a0.u64 == 0)
  {
    goto loc_10004904;
  }

  s1.u64 = (uint64_t) seqList;
  *((uint8_t *) (ARGS->a0.u32 + 4)) = 0;
  ARGS->a3.u64 = seqList;
  if (ARGS->a0.u64 != ARGS->a3.u64)
  {
    goto loc_100048A4;
  }

  ARGS->a0.u64 = *((int32_t *) (ARGS->a3.u32 + 36));
  seqList = ARGS->a0.u32;
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  if (ARGS->a0.u64 == 0)
  {
    goto loc_10004894;
  }

  loc_1000487C:

  {
    s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    free((void *) ARGS->a0.u64);
  }
  if (s1.u64 != 0)
  {
    ARGS->a0.u64 = s1.u64;
    goto loc_1000487C;
  }
  else
    ARGS->a0.u64 = s1.u64;

  loc_10004894:
  s1.u64 = (uint64_t) seqList;

  {
    ARGS->a0.u64 = s0.u64;
    free((void *) ARGS->a0.u64);
  }
  ARGS->a3.u64 = seqList;
  loc_100048A4:
  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 36));

  if (ARGS->a2.u64 == 0)
  {
    goto loc_10004904;
  }

  loc_100048B0:
  if (ARGS->a2.u64 == s0.u64)
  {
    ;
    goto loc_100048D0;
  }
  else
    ;


  ARGS->a3.u64 = ARGS->a2.u64;
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 36));
  if (ARGS->a2.u64 != 0)
  {
    ;
    goto loc_100048B0;
  }
  else
    ;

  {
    goto loc_10004908;
  }
  loc_100048D0:
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 36));

  *((uint32_t *) (ARGS->a3.u32 + 36)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 24));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a1.u64;
    goto loc_100048F8;
  }
  else
    ARGS->a0.u64 = ARGS->a1.u64;

  loc_100048E4:

  {
    s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    free((void *) ARGS->a0.u64);
  }
  if (s1.u64 != 0)
  {
    ARGS->a0.u64 = s1.u64;
    goto loc_100048E4;
  }
  else
    ARGS->a0.u64 = s1.u64;

  loc_100048F8:

  {
    ARGS->a0.u64 = s0.u64;
    free((void *) ARGS->a0.u64);
  }
  loc_10004904:

  loc_10004908:

  {
    return;
  }
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
  EPANOS_REG f3;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  int EPANOS_fp_cond;
  value__GfN21:
  ARGS->v0.u64 = 55680;

  memcpy(&f7, &flt_10009290, 4);
  if (f7.s < ARGS->f14.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  memcpy(&f3, &dbl_100092D0, 8);
  if (!EPANOS_fp_cond)
  {
    memcpy(&ARGS->f0, &flt_10009294, 4);
    goto loc_10003640;
  }
  else
    memcpy(&ARGS->f0, &flt_10009294, 4);

  ARGS->f14.s = ARGS->f14.s + ARGS->f0.s;
  loc_10003640:
  f1.u32 = 0;

  ;
  if (ARGS->f14.s < f1.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->f0.s = 60.0000000f;
  f5.s = 240.000000f;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f6, &flt_100092A0, 4);
    goto loc_10003660;
  }
  else
    memcpy(&f6, &flt_100092A0, 4);

  ARGS->f14.s = ARGS->f14.s + f7.s;
  loc_10003660:
  if (ARGS->f14.s < ARGS->f0.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (EPANOS_fp_cond)
  {
    ARGS->f0.s = ARGS->f13.s;
    goto loc_100036C0;
  }
  else
    ARGS->f0.s = ARGS->f13.s;

  if (ARGS->f14.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    ;
    goto locret_100036E8;
  }
  else
    ;

  if (ARGS->f14.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ARGS->f0.s = ARGS->f12.s;
    goto locret_100036B8;
  }
  else
    ARGS->f0.s = ARGS->f12.s;

  ARGS->f2.s = f5.s - ARGS->f14.s;
  ARGS->f2.d = ARGS->f2.s;
  ARGS->f2.d = ARGS->f2.d / f3.d;
  f1.s = ARGS->f13.s - ARGS->f12.s;
  f1.d = f1.s;
  ARGS->f0.d = ARGS->f12.s;
  f1.d = f1.d * ARGS->f2.d;
  ARGS->f0.d = ARGS->f0.d + f1.d;
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  locret_100036B8:
  {
    ;
    return;
  }

  loc_100036C0:
  memcpy(&f3, &dbl_100092D0, 8);

  ARGS->f2.d = ARGS->f14.s;
  ARGS->f2.d = ARGS->f2.d / f3.d;
  f1.s = ARGS->f13.s - ARGS->f12.s;
  f1.d = f1.s;
  ARGS->f0.d = ARGS->f12.s;
  f1.d = f1.d * ARGS->f2.d;
  ARGS->f0.d = ARGS->f0.d + f1.d;
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  locret_100036E8:
  {
    ;
    return;
  }

}

static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG ra;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  int EPANOS_fp_cond;
  uint64_t var_10;
  processCommand__GP11animCommand:
  ARGS->v0.u64 = (int32_t) (1 << 16);

  ARGS->v0.u64 = 50812;
  at.u64 = (uint64_t) (&oflag);
  at.u64 = oflag;
  s0.u64 = ARGS->a0.u64;
  if (at.u64 == 0)
  {
    var_10 = ra.u64;
    goto loc_10004990;
  }
  else
    var_10 = ra.u64;

  memcpy(&ARGS->f2, (char *) (ARGS->a0.u32 + 8), 4);
  ARGS->a2.u64 = *((int32_t *) (ARGS->a0.u32 + 16));
  ARGS->a3.u64 = (uint64_t) (&currentFrame);
  memcpy(&f1, (char *) (ARGS->a2.u32 + 8), 4);
  memcpy(&ARGS->f0, &currentFrame, 4);
  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  ARGS->f2.d = ARGS->f2.s;
  t9.u64 = (uint64_t) printf;
  f1.d = f1.s;
  ARGS->a5.u64 = ARGS->f2.u64;
  ARGS->f0.d = ARGS->f0.s;
  ARGS->a3.u64 = f1.u64;
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 0));
  ARGS->a1.u64 = ARGS->f0.u64;
  {
    printf("proc: currentFrame %.2f, seq %d,\tseqFrame %f, cmdtype %d, cmdFrame %f\n",
        (double) ARGS->a1.d, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d, (int32_t) ARGS->a4.u64, (double) ARGS->a5.d);
  }
  loc_10004990:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));

  ;
  ;
//  ARGS->a0.u64 = (uint64_t) (&jpt_100049B4[0]);
  ARGS->a4.u64 = (uint64_t) (&currentFrame);
  ;
  ;
  ;
  {
    switch (ARGS->a1.u64)
    {
      case 0:
        goto loc_10004A00;

      case 1:
        goto loc_10004CF8;

      case 2:
        goto loc_10004CBC;

      case 3:
        goto loc_10004C70;

      case 4:
        goto loc_10004C38;

      case 101:
        goto loc_10004AA4;

      case 102:
        goto loc_10004A80;

      case 103:
        goto loc_10004A14;

      case 8:
        goto loc_10004B98;

      case 9:
        goto loc_10004B84;

      case 10:
        goto loc_10004B6C;

      case 11:
        goto loc_10004B54;

      case 12:
        goto loc_10004B30;

      case 13:
        goto loc_10004B1C;

      case 14:
        goto loc_10004B04;

      case 15:
        goto loc_10004AC8;

      case 7:
        goto loc_10004BB8;

      case 6:
        goto loc_10004BEC;

      case 5:
        goto loc_10004C00;

      default:
        goto def_100049B4;

    }

  }
  loc_100049BC:
  {
    ;
    killSeq__GP7animSeq(ARGS);
  }

  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
  def_100049B4:
  t9.u64 = (uint64_t) printf;

  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  {
    printf("warning: bad command type (%d) in sequence cmd->seq\n", (int32_t) ARGS->a1.u64);
  }
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a2.u32 + 28));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a1.u32 + 20));
  *((uint32_t *) (ARGS->a2.u32 + 28)) = ARGS->a1.u32;
  loc_100049EC:
  ra.u64 = var_10;

  loc_100049F0:

  {
    return;
  }
  loc_10004A00:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004A14:

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
  {
    *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
    goto loc_100049EC;
  }
  loc_10004A80:
  memcpy(&f4, (char *) (s0.u32 + 12), 4);

  f6.u64 = 0;
  f4.d = f4.s;
  if (f4.d < f6.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f5, &dbl_10009300, 8);
    goto loc_10004E0C;
  }
  else
    memcpy(&f5, &dbl_10009300, 8);

  {
    f4.d = f6.d;
    goto loc_10004E20;
  }
  loc_10004AA4:
  memcpy(&f4, (char *) (s0.u32 + 12), 4);

  memcpy(&f5, &dbl_10009300, 8);
  f4.d = f4.s;
  if (f4.d < f5.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004DEC;
  }
  else
    ;

  {
    f4.d = f5.d;
    goto loc_10004DEC;
  }
  loc_10004AC8:
  ARGS->a5.u64 = (uint64_t) seqList;

  ARGS->a5.u64 = seqList;
  if (ARGS->a5.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a5.u64;
    goto def_100049B4;
  }
  else
    ARGS->a0.u64 = ARGS->a5.u64;

  loc_10004AD8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 != ARGS->a0.u64)
  {
    t9.u64 = (uint64_t) killSeq__GP7animSeq;
    goto loc_100049BC;
  }
  else
    t9.u64 = (uint64_t) killSeq__GP7animSeq;

  ARGS->a6.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  ARGS->a6.u64 = *((int32_t *) (ARGS->a6.u32 + 20));
  *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a6.u32;
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));
  if (ARGS->a0.u64 != 0)
  {
    ;
    goto loc_10004AD8;
  }
  else
    ;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
    goto def_100049B4;
  }
  loc_10004B04:
  ARGS->a7.u64 = (uint64_t) seqList;

  ARGS->a7.u64 = seqList;
  if (ARGS->a7.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a7.u64;
    goto loc_10004D24;
  }
  else
    ARGS->a0.u64 = ARGS->a7.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D18;
  }
  loc_10004B1C:
  t5.u64 = *((int32_t *) (s0.u32 + 16));

  t4.u64 = *((int32_t *) (t5.u32 + 28));
  t4.u64 = *((int32_t *) (t4.u32 + 20));
  {
    *((uint32_t *) (t5.u32 + 28)) = t4.u32;
    goto loc_100049EC;
  }
  loc_10004B30:
  t7.u64 = *((int32_t *) (s0.u32 + 16));

  t6.u64 = *((int32_t *) (t7.u32 + 24));
  *((uint32_t *) (t7.u32 + 28)) = t6.u32;
  t5.u64 = *((int32_t *) (s0.u32 + 16));
  memcpy(&f6, (char *) (t5.u32 + 12), 4);
  memcpy(&f5, (char *) (t5.u32 + 8), 4);
  f5.s = f5.s + f6.s;
  {
    memcpy((char *) (t5.u32 + 8), &f5, 4);
    goto loc_100049EC;
  }
  loc_10004B54:
  t8.u64 = (uint64_t) seqList;

  t8.u64 = seqList;
  if (t8.u64 == 0)
  {
    ARGS->a0.u64 = t8.u64;
    goto loc_10004D60;
  }
  else
    ARGS->a0.u64 = t8.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D54;
  }
  loc_10004B6C:
  t9.u64 = (uint64_t) seqList;

  t9.u64 = seqList;
  if (t9.u64 == 0)
  {
    ARGS->a0.u64 = t9.u64;
    goto loc_10004DA0;
  }
  else
    ARGS->a0.u64 = t9.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D94;
  }
  loc_10004B84:
  at.u64 = *((int32_t *) (s0.u32 + 16));

  ra.u64 = *((int32_t *) (at.u32 + 28));
  ra.u64 = *((int32_t *) (ra.u32 + 20));
  {
    *((uint32_t *) (at.u32 + 28)) = ra.u32;
    goto loc_100049EC;
  }
  loc_10004B98:
  t9.u64 = (uint64_t) stopAnimation__Gv;

  {
    ;
    stopAnimation__Gv();
  }
  ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));
  at.u64 = *((int32_t *) (ARGS->v0.u32 + 28));
  at.u64 = *((int32_t *) (at.u32 + 20));
  {
    *((uint32_t *) (ARGS->v0.u32 + 28)) = at.u32;
    goto loc_100049EC;
  }
  loc_10004BB8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004BD8;
  }
  else
    ;

  *((uint8_t *) (ARGS->a0.u32 + 0)) = 0;
  loc_10004BD8:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004BEC:
  ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 28));
  ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
  {
    *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
    goto loc_100049EC;
  }
  loc_10004C00:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004C24;
  }
  else
    ;

  memcpy(&f7, (char *) (ARGS->a0.u32 + 36), 4);
  memcpy((char *) (ARGS->a0.u32 + 24), &f7, 4);
  loc_10004C24:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004C38:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004C5C;
  }
  else
    ;

  memcpy(&f8, (char *) (s0.u32 + 12), 4);
  memcpy((char *) (ARGS->a0.u32 + 24), &f8, 4);
  loc_10004C5C:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004C70:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004E6C;
  }
  else
    ;

  memcpy(&f5, (char *) (s0.u32 + 12), 4);
  memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
  if (f4.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f6, (char *) (ARGS->a0.u32 + 12), 4);
    goto loc_10004E80;
  }
  else
    memcpy(&f6, (char *) (ARGS->a0.u32 + 12), 4);

  if (f5.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004E40;
  }
  else
    ;

  {
    f5.s = f6.s;
    goto loc_10004E40;
  }
  loc_10004CBC:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DD8;
  }
  else
    ;

  memcpy(&f5, (char *) (s0.u32 + 12), 4);
  memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
  if (f4.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004DD4;
  }
  else
    ;

  {
    f5.s = f4.s;
    goto loc_10004DD4;
  }
  loc_10004CF8:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004D0C:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D24;
  }
  else
    ;

  loc_10004D18:
  ARGS->a3.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a3.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D0C;
  }
  else
    ;

  loc_10004D24:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 != ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  if (ARGS->a0.u64 == 0)
  {
    t9.u64 = (uint64_t) killSeq__GP7animSeq;
    goto loc_10004EB4;
  }
  else
    t9.u64 = (uint64_t) killSeq__GP7animSeq;

  {
    ;
    killSeq__GP7animSeq(ARGS);
  }
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  loc_10004D48:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D6C;
  }
  else
    ;

  loc_10004D54:
  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a4.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D48;
  }
  else
    ;

  loc_10004D60:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D6C;
  }
  else
    ;


  *((uint32_t *) (ARGS->a0.u32 + 28)) = 0;
  loc_10004D6C:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  ARGS->a5.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  ARGS->a5.u64 = *((int32_t *) (ARGS->a5.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a5.u32;
    goto loc_100049EC;
  }
  loc_10004D88:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DB8;
  }
  else
    ;

  loc_10004D94:
  ARGS->a6.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a6.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D88;
  }
  else
    ;

  loc_10004DA0:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DB8;
  }
  else
    ;


  ARGS->a7.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->a7.u32;
  memcpy(&f9, (char *) (ARGS->a4.u32 + 0), 4);
  memcpy((char *) (ARGS->a0.u32 + 8), &f9, 4);
  loc_10004DB8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  t4.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  t4.u64 = *((int32_t *) (t4.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = t4.u32;
    goto loc_100049EC;
  }
  loc_10004DD4:
  memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);

  loc_10004DD8:
  t6.u64 = *((int32_t *) (s0.u32 + 16));

  t5.u64 = *((int32_t *) (t6.u32 + 28));
  t5.u64 = *((int32_t *) (t5.u32 + 20));
  {
    *((uint32_t *) (t6.u32 + 28)) = t5.u32;
    goto loc_100049EC;
  }
  loc_10004DEC:
  t7.u64 = *((int32_t *) (s0.u32 + 16));

  f10.s = f4.d;
  memcpy((char *) (t7.u32 + 16), &f10, 4);
  t7.u64 = *((int32_t *) (s0.u32 + 16));
  t6.u64 = *((int32_t *) (t7.u32 + 28));
  t6.u64 = *((int32_t *) (t6.u32 + 20));
  {
    *((uint32_t *) (t7.u32 + 28)) = t6.u32;
    goto loc_100049EC;
  }
  loc_10004E0C:
  if (f5.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004E20;
  }
  else
    ;

  f4.d = f5.d;
  loc_10004E20:
  t9.u64 = *((int32_t *) (s0.u32 + 16));

  f11.s = f4.d;
  memcpy((char *) (t9.u32 + 20), &f11, 4);
  t9.u64 = *((int32_t *) (s0.u32 + 16));
  t8.u64 = *((int32_t *) (t9.u32 + 28));
  t8.u64 = *((int32_t *) (t8.u32 + 20));
  {
    *((uint32_t *) (t9.u32 + 28)) = t8.u32;
    goto loc_100049EC;
  }
  loc_10004E40:
  {
    memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);
    goto loc_10004E4C;
  }

  loc_10004E48:
  memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);

  loc_10004E4C:
  ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));

  memcpy(&ARGS->f13, (char *) (ARGS->v0.u32 + 16), 4);
  memcpy((char *) (ARGS->a0.u32 + 28), &ARGS->f13, 4);
  at.u64 = *((int32_t *) (s0.u32 + 16));
  memcpy(&ARGS->f12, (char *) (at.u32 + 20), 4);
  ra.u64 = 1;
  *((uint8_t *) (ARGS->a0.u32 + 0)) = ra.u8;
  memcpy((char *) (ARGS->a0.u32 + 32), &ARGS->f12, 4);
  loc_10004E6C:
  ARGS->a0.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->v1.u64 = *((int32_t *) (ARGS->a0.u32 + 28));
  ARGS->v1.u64 = *((int32_t *) (ARGS->v1.u32 + 20));
  {
    *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->v1.u32;
    goto loc_100049EC;
  }
  loc_10004E80:
  if (f4.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    f5.s = f4.s;
    goto loc_10004E94;
  }
  else
    f5.s = f4.s;

  f5.s = f6.s;
  loc_10004E94:
  memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);

  memcpy(&f6, (char *) (s0.u32 + 12), 4);
  if (f4.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    f5.s = f6.s;
    goto loc_10004E48;
  }
  else
    f5.s = f6.s;

  {
    f5.s = f4.s;
    goto loc_10004E48;
  }
  loc_10004EB4:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a1.u32 + 28));

  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a0.u32;
    goto loc_100049EC;
  }
}

void display__Gv(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG ra;
  EPANOS_REG f1;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f23;
  EPANOS_REG f25;
  EPANOS_REG f27;
  EPANOS_REG f29;
  int EPANOS_fp_cond;
  double var_50;
  double var_48;
  double var_40;
  display__Gv:
  at.u64 = (int32_t) (1 << 16);

  at.u64 = 45256;
  t9.u64 = (uint64_t) glClear;
  ARGS->a0.u64 = 16384;
  {
    wrap_glClear((unsigned int) ARGS->a0.u64, wincount);
  }
  memcpy(&f20, &flt_100092A8, 4);
  t9.u64 = (uint64_t) glColor3f;
  ARGS->f14.s = f20.s;
  ARGS->f13.s = f20.s;
  {
    ARGS->f12.s = f20.s;
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  s0.u64 = (uint64_t) acttable;
  ARGS->v1.u64 = (uint64_t) (&t);
  ARGS->v0.u64 = acttable[45];
  memcpy(&f1, &t, 4);
  memcpy(&ARGS->f2, (char *) (ARGS->v0.u32 + 24), 4);
  s1.u64 = (uint64_t) (&n);
  memcpy(&ARGS->f0, &dbl_10009300, 8);
  f1.s = f1.s + ARGS->f2.s;
  ARGS->a0.u64 = n;
  f1.d = f1.s;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + 1);
  ARGS->a3.u64 = (int32_t) (ARGS->a0.i32 >> 31);
  if (ARGS->f0.d <= f1.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a2.u64 = (uint64_t) (&aflag);
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
  s3.u64 = 1;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
  ARGS->a1.u64 = aflag;
  ARGS->f0.u32 = 0;
  if (!EPANOS_fp_cond)
  {
    ARGS->a0.u64 = ARGS->a0.u64 & 127;
    goto loc_10005F8C;
  }
  else
    ARGS->a0.u64 = ARGS->a0.u64 & 127;

  memcpy(&t, &ARGS->f0, 4);
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
  {
    n = ARGS->a0.u32;
    goto loc_10005F90;
  }
  loc_10005F8C:
  s3.u64 = 0;

  loc_10005F90:
  if (ARGS->a1.u64 == 0)
  {
    t9.u64 = (uint64_t) tasteQueue__Gv;
    goto loc_10005FB8;
  }
  else
    t9.u64 = (uint64_t) tasteQueue__Gv;


  {
    ;
    tasteQueue__Gv(ARGS);
  }
  t9.u64 = (uint64_t) setacttargets__Gv;
  {
    setacttargets__Gv();
  }
  t9.u64 = (uint64_t) animateacts__Gv;
  {
    animateacts__Gv();
  }
  loc_10005FB8:
  t9.u64 = (uint64_t) floor;

  ARGS->a2.u64 = (uint64_t) dtwist;
  ARGS->a4.u64 = (uint64_t) (&dwheel);
  ARGS->a6.u64 = (uint64_t) wrist;
  t4.u64 = (uint64_t) arm;
  s2.u64 = (uint64_t) (&n);
  t6.u64 = (uint64_t) dzoom;
  s2.u64 = n;
  ARGS->f18.u32 = 0;
  t8.u64 = (uint64_t) y;
  ra.u64 = (uint64_t) x;
  s1.u64 = (int32_t) (s2.u32 << 2);
  t7.u64 = acttable[31];
  t8.u64 = (int32_t) (s1.u32 + t8.u32);
  ra.u64 = (int32_t) (s1.u32 + ra.u32);
  memcpy((char *) (t8.u32 + 0), &ARGS->f18, 4);
  memcpy((char *) (ra.u32 + 0), &ARGS->f18, 4);
  memcpy(&ARGS->f17, (char *) (t7.u32 + 24), 4);
  t5.u64 = acttable[94];
  t6.u64 = (int32_t) (s1.u32 + t6.u32);
  memcpy((char *) (t6.u32 + 0), &ARGS->f17, 4);
  memcpy(&ARGS->f16, (char *) (t5.u32 + 24), 4);
  ARGS->a7.u64 = acttable[101];
  t4.u64 = (int32_t) (s1.u32 + t4.u32);
  memcpy((char *) (t4.u32 + 0), &ARGS->f16, 4);
  memcpy(&ARGS->f15, (char *) (ARGS->a7.u32 + 24), 4);
  ARGS->a5.u64 = acttable[73];
  ARGS->a6.u64 = (int32_t) (s1.u32 + ARGS->a6.u32);
  memcpy((char *) (ARGS->a6.u32 + 0), &ARGS->f15, 4);
  memcpy(&ARGS->f14, (char *) (ARGS->a5.u32 + 24), 4);
  ARGS->a3.u64 = acttable[38];
  memcpy(&dwheel, &ARGS->f14, 4);
  memcpy(&ARGS->f13, (char *) (ARGS->a3.u32 + 24), 4);
  ARGS->a1.u64 = acttable[52];
  ARGS->a2.u64 = (int32_t) (s1.u32 + ARGS->a2.u32);
  memcpy((char *) (ARGS->a2.u32 + 0), &ARGS->f13, 4);
  memcpy(&ARGS->f12, (char *) (ARGS->a1.u32 + 24), 4);
  memcpy(&var_50, &ARGS->f14, 8);
  {
    ARGS->f12.d = ARGS->f12.s;
    ARGS->f0.d = (double) floor((double) ARGS->f12.d);
  }
  ARGS->a6.u64 = (uint64_t) (&nlimit);
  f23.i32 = trunc_w_d(ARGS->f0.d);
  memcpy(&nlimit, &f23, 4);
  ARGS->a5.u64 = acttable[18];
  memcpy(&f21, (char *) (ARGS->a5.u32 + 24), 4);
  ARGS->f19.u64 = 0;
  f21.d = f21.s;
  ARGS->a4.u64 = (uint64_t) outline;
  if (ARGS->f19.d < f21.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a3.u64 = 1;
  ARGS->a4.u64 = (int32_t) (s2.u32 + ARGS->a4.u32);
  ARGS->a2.u64 = acttable[123];
  if (EPANOS_fp_cond)
  {
    ;
    goto loc_10006094;
  }
  else
    ;

  ARGS->a3.u64 = 0;
  loc_10006094:
  *((uint8_t *) (ARGS->a4.u32 + 0)) = ARGS->a3.u8;

  memcpy(&f5, (char *) (ARGS->a2.u32 + 24), 4);
  memcpy(&f6, &flt_100092B4, 4);
  ARGS->a1.u64 = (uint64_t) hue;
  if (f20.s <= f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a3.u64 = (uint64_t) light;
  ARGS->a1.u64 = (int32_t) (s1.u32 + ARGS->a1.u32);
  ARGS->a2.u64 = acttable[130];
  ARGS->a7.u64 = (int32_t) (s1.u32 + ARGS->a3.u32);
  if (!EPANOS_fp_cond)
  {
    memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);
    goto loc_100060C8;
  }
  else
    memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);

  f5.s = f5.s + f6.s;
  memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);
  loc_100060C8:
  if (f5.s <= f20.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_100060E0;
  }
  else
    ;

  f25.s = f5.s + f20.s;
  memcpy((char *) (ARGS->a1.u32 + 0), &f25, 4);
  loc_100060E0:
  memcpy(&f27, (char *) (ARGS->a2.u32 + 24), 4);

  memcpy(&f20, &flt_10009290, 4);
  if (s3.u64 == 0)
  {
    memcpy((char *) (ARGS->a7.u32 + 0), &f27, 4);
    goto loc_10006194;
  }
  else
    memcpy((char *) (ARGS->a7.u32 + 0), &f27, 4);

  t5.u64 = *((int32_t *) (s0.u32 + 320));
  t6.u64 = (uint64_t) (&dflip);
  t7.u64 = *((int32_t *) (s0.u32 + 348));
  s3.u64 = (uint64_t) (&gflip);
  memcpy(&ARGS->f13, (char *) (t7.u32 + 24), 4);
  memcpy(&ARGS->f12, &gflip, 4);
//  s3.u64 = (uint64_t) fmodf;
  memcpy(&dflip, &ARGS->f13, 4);
  memcpy(&f29, (char *) (t5.u32 + 24), 4);
  t4.u64 = (uint64_t) (&dspin);
  t9.u64 = s3.u64;
  memcpy(&var_48, &f29, 8);
  ARGS->f12.s = ARGS->f12.s + ARGS->f13.s;
  ARGS->f13.s = f20.s;
  {
    memcpy(&dspin, &f29, 4);
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  s1.u64 = (uint64_t) (&gspin);
  memcpy(&ARGS->f13, &var_48, 8);
  memcpy(&ARGS->f12, &gspin, 4);
  t9.u64 = s3.u64;
  t8.u64 = (uint64_t) (&gflip);
  memcpy(&var_40, &ARGS->f0, 8);
  memcpy(&gflip, &ARGS->f0, 4);
  ARGS->f12.s = ARGS->f12.s + ARGS->f13.s;
  {
    ARGS->f13.s = f20.s;
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  ra.u64 = (int32_t) (s2.i32 >> 31);
  t9.u64 = s2.u64 ^ ra.u64;
  t9.u64 = (int32_t) (t9.u32 - ra.u32);
  t9.u64 = t9.u64 & 127;
  memcpy(&ARGS->f15, &var_40, 8);
  t9.u64 = t9.u64 ^ ra.u64;
  at.u64 = (uint64_t) flip;
  t9.u64 = (int32_t) (t9.u32 - ra.u32);
  ra.u64 = (uint64_t) spin;
  t9.u64 = (int32_t) (t9.u32 << 2);
  memcpy(&gspin, &ARGS->f0, 4);
  at.u64 = (int32_t) (t9.u32 + at.u32);
  t9.u64 = (int32_t) (t9.u32 + ra.u32);
  memcpy((char *) (at.u32 + 0), &ARGS->f15, 4);
  memcpy((char *) (t9.u32 + 0), &ARGS->f0, 4);
  loc_10006194:
//  t9.u64 = (uint64_t) fmodf;

  ra.u64 = (uint64_t) (&wheel);
  memcpy(&ARGS->f13, &var_50, 8);
  memcpy(&ARGS->f12, &wheel, 4);
  ARGS->f12.s = ARGS->f12.s - ARGS->f13.s;
  {
    ARGS->f13.s = f20.s;
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  t9.u64 = (uint64_t) drawit__Gv;
  at.u64 = (uint64_t) (&wheel);
  {
    memcpy(&wheel, &ARGS->f0, 4);
    drawit__Gv(ARGS, wincount);
  }
  ARGS->v1.u64 = *((int32_t *) (s0.u32 + 180));
  ARGS->v0.u64 = (uint64_t) (&t);
  memcpy(&ARGS->f15, (char *) (ARGS->v1.u32 + 24), 4);
  memcpy(&ARGS->f14, &t, 4);
  t9.u64 = (uint64_t) glFinish;
  ARGS->f14.s = ARGS->f14.s + ARGS->f15.s;
  {
    memcpy(&t, &ARGS->f14, 4);
    wrap_glFinish(wincount);
  }
  //t9.u64 = (uint64_t) swapBuffers__Q2_10GLXWrapper6windowGv;
  ARGS->a0.u64 = (uint64_t) (&theWindow);
  {
    ARGS->a0.u64 = theWindow;
    ;
  }
  //t9.u64 = (uint64_t) (&sginap);
  {
    ARGS->a0.u64 = 0;
    ;
  }
  {
    return;
  }
}

static void setacttargets__Gv(void)
{
  struct act **s0 = acttable;
  float f0;
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
