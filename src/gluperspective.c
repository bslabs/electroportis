
#include "stdafx.h"
#include "gl_wrap.h"

#define _USE_MATH_DEFINES // needed for MSVC to define M_PI
#include <math.h>

void ep_gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
  GLdouble xmin, xmax, ymin, ymax;
  ymax = zNear * tan(fovy * M_PI / 360.0);
  ymin = -ymax;
  xmin = ymin * aspect;
  xmax = ymax * aspect;

  glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
}
