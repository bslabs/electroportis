#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "ep.h"

#include <stdlib.h>

int mainwinid;

#ifdef TEST
#include <stdio.h>
static GLubyte imageData[1024*768*4];

void write_sshot(void)
{
  static unsigned int num = 0;

  if (num == 10000)
    exit(0);

  char name[20];
  sprintf(name, "shot%05u.rgba", num);
  FILE *fp = fopen(name, "wb");

  fwrite(imageData, sizeof(imageData), 1, fp);

  fclose(fp);

  // 'convert' is from ImageMagick
  char cmd[200];
  sprintf(cmd, "convert -size 1024x768 -depth 8 -define png:exclude-chunk=date ephemeral:shot%05u.rgba shot%05u.png &", num, num);
  system(cmd);

  num++;
}
#endif

void menuhandler(int value)
{
  switch (value)
  {
    case 1:
      // Quit
      exit(0);
      break;

    default:
      break;
  }
}

void drawfunc(void)
{
  display__Gv(NULL);
  glutSwapBuffers();

#ifdef TEST
  glReadPixels(0, 0, 1024, 768, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
  write_sshot();
#endif
}

void iterate(void)
{
  drawfunc();
  //usleep(1000);
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1024, 768);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  mainwinid = glutCreateWindow("ElectroPortis");

  glutDisplayFunc(drawfunc);
  glutReshapeFunc(reshape__GiT1);
  glutIdleFunc(iterate);

  glutCreateMenu(menuhandler);
  glutAddMenuEntry("Quit", 1);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  init_ep();
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glShadeModel(GL_FLAT);
  glClear(GL_COLOR_BUFFER_BIT);

  reshape__GiT1(1024, 768);

  glutMainLoop();
}
