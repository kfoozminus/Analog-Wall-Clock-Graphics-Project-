#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define HOUR_LEN 85
#define MIN_LEN 135
#define SEC_LEN 135
#define MIN_NOTE_START 135
#define MIN_NOTE_END 145
#define HOUR_NOTE_START 125
#define HOUR_NOTE_END 145
#define F first
#define S second

double toRad(double ang)
{
      return PI * ang/180;
}

void DrawCircle(float cx, float cy, float r)
{
      glBegin(GL_POLYGON);
	for(int ii = 0; ii < 200; ii++)
	{
		float theta = 2.0 * PI * float(ii) / 200.0;

		float x = r * cos(theta);
		float y = r * sin(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void line(double x1, double yy1, double x2, double y2)
{
      glBegin(GL_LINES);
      glVertex2f(x1, yy1);
      glVertex2f(x2, y2);
      glEnd();
}

void init(void)
{
      glClearColor(.2, .31, .16, 0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-250, 250, -300, 300);
}

double x1, yy1, x2, y2, x3, y3;
int n;

double angRotate(double x)
{
      x = x - 90;
      x = 360 - x;
      //x %= 360;
      return x;
}

void callLine(int LEN, double ang)
{
      line(0, 0, LEN * cos(toRad(ang)), LEN * sin(toRad(ang)));
      line(0, 0, 20 * cos(toRad(180+ang)), 20 * sin(toRad(180+ang)));
}

void hourFunc(double ang)
{
      ang = angRotate(ang);
      glLineWidth(10);
      glColor3f(0, 0, 0);
	  callLine(HOUR_LEN, ang);
}
void minFunc(double ang)
{
      ang = angRotate(ang);
      glLineWidth(4);
      glColor3f(0, 0, 0);
	  callLine(MIN_LEN, ang);
}
void secFunc(double ang)
{
      ang = angRotate(ang);
      glLineWidth(2);
      glColor3f(0, 0, 0);
	  callLine(SEC_LEN, ang);
}

void perSecond()
{
      time_t _sec = time(NULL);
      int sec = (int) _sec;
      sec += 6 * 3600;
      sec %= 12 * 3600;

      hourFunc(sec*360/12/3600);

      sec %= 3600;
      minFunc(sec*360/3600);

      sec %= 60;
      secFunc(sec*360/60);
}

void display()
{
      glClear(GL_COLOR_BUFFER_BIT);

      //clock border
      glColor3f(.27, .16, .06);
      DrawCircle(0, 0, 195);
      glColor3f(.38, .22, .09);
      DrawCircle(0, 0, 185);
      glColor3f(.47, .28, .11);
      DrawCircle(0, 0, 175);
      glColor3f(.65, .39, .15);
      DrawCircle(0, 0, 165);

      //clock background
      glColor3f(.91, .89, .76);
      DrawCircle(0, 0, 155);

      //clock name
      glColor3f(0, 0, 0);
      glRasterPos2f(-25, 60);
      string name = "CASIO";
      for(int i = 0; i < name.size(); i ++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);

      //quarter time indicator
      glColor3f(0, 0, 0);
      DrawCircle(140, 0, 7);
      DrawCircle(0, 140, 7);
      DrawCircle(-140, 0, 7);
      DrawCircle(0, -140, 7);

      //minute indicator
      glColor3f(0, 0, 0);
      glLineWidth(4);
      for(int i = 0; i < 60; i ++) {
            if(i % 15 == 0) continue;
            line(MIN_NOTE_START * cos(toRad(i * 6)), MIN_NOTE_START * sin(toRad(i * 6)), MIN_NOTE_END * cos(toRad(i * 6)), MIN_NOTE_END * sin(toRad(i * 6)));
      }

      //hour indicator
      glLineWidth(10);
      for(int i = 0; i < 12; i ++) {
            if(i % 3 == 0) continue;
            line(HOUR_NOTE_START * cos(toRad(i * 30)), HOUR_NOTE_START * sin(toRad(i * 30)), HOUR_NOTE_END * cos(toRad(i * 30)), HOUR_NOTE_END * sin(toRad(i * 30)));
      }

      perSecond();

      //center
      glColor3f(.55, .56, .59);
      DrawCircle(0, 0, 5);

      glFlush();

      glutSwapBuffers();
}

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(1000, Timer, value);
}

int main(int argc, char **argv)
{
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 600);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("Analog Clock");
      init();
      glutDisplayFunc(display);
      Timer(0);
      glutMainLoop();
      return 0;
}
