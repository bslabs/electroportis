
#include "gl_wrap.h"

#include <math.h>

void ep_gluPerspective(double fovy, double aspect, double zNear, double zFar)
{
  double xmin, xmax, ymin, ymax;
  ymax = zNear * tan(fovy * M_PI / 360.0);
  ymin = -ymax;
  xmin = ymin * aspect;
  xmax = ymax * aspect;

  glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);
}
