#include<GL/glut.h>
#include<iostream>
using namespace std;

int r = 100;
int X1, Y1;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void putPixel(int cx, int cy, int x, int y)
{
	glColor3f(2.0, 0.5, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(cx + x, cy + y); 
	glVertex2i(cx + y, cy + x);
	glVertex2i(cx - x, cy + y); 
	glVertex2i(cx + y, cy - x);
	glVertex2i(cx + x, cy - y); 
	glVertex2i(cx - y, cy + x);
	glVertex2i(cx - x, cy - y); 
	glVertex2i(cx - y, cy - x);
	glEnd();
	glFlush();
}

void MidPointCircle(int X1, int Y1)
{
	float d;
	int X0 = abs(X1);
	int Y0 = abs(Y1);
	if (X0 > Y0)
	{
		int xx = X0;
		X0 = Y0;
		Y0 = xx;
	}
	int x, y;
	x = 0, y = r;
	d = 1 - r;
	putPixel(X1, Y1, x, y);
	while (x <= y)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		putPixel(X1, Y1, x, y);
	}
}

void display(void)
{
	MidPointCircle(X1, Y1);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
	cout << "Enter X value of the circle center: ";
	cin >> X1;
	cout << "Enter Y value of the circle center: ";
	cin >> Y1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
