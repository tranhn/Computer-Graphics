#include<GL/glut.h>
#include<cmath>

int Xi, Xf, Yi, Yf;
int first = 0;

void putPixel(int x, int y)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Bresenham(int X1, int Y1, int X2, int Y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;

	dx = abs(X2 - X1);
	dy = abs(Y2 - Y1);
	incx = 1;
	if (X2 < X1)
		incx = -1;
	incy = 1;
	if (Y2 < Y1)
		incy = -1;

	int x = X1, y = Y1;
	if (dx > dy) {
		putPixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			putPixel(x, y);
		}
	}
	else {
		putPixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			putPixel(x, y);
		}
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch (first)
		{
		case 0:
			Xi = x;
			Yi = (480 - y);
			first = 1;
			break;
		case 1:
			Xf = x;
			Yf = (480 - y);
			Bresenham(Xi, Yi, Xf, Yf);
			first = 0;
			break;
		}
	}
}

void init(void)
{
	glViewport(0, 0, 640, 480);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Breshanman Line Algorithm ");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
