#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

//收集点的坐标
void setPixel(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
//利用bresenham算法利用点求斜率画直线
void lineBres(int x0,int y0,int xEnd,int yEnd){
	int dx = fabs(xEnd - x0);
	int dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy;
	int twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0; 
		y = y0;
	}
	setPixel(x, y);
	while(x<xEnd){
		x++;
		if (p < 0) {
			p = p + twoDy;
		}
		else {
			y++;
			p = p + twoDyMinusDx;
		}
		setPixel(x, y);
	}
}
//初始化
void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
//输入点的坐标
void lineSegment(void) {
	int x1, y1, x2, y2;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	glBegin(GL_LINES);
	printf("第一个坐标：");
	scanf("%d%d", &x1, &y1);
	printf("第二个坐标:");
	scanf("%d%d", &x2, &y2);
	lineBres(x1, y1, x2, y2);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("BresenBam");
	glutDisplayFunc(lineSegment);
	Init();
	glutMainLoop();
}
