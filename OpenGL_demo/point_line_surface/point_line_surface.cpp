/*
 *	描述：opengl学习之点线面
 *	作者：venjieliu
 *	日期：2017.8.20
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void myDisplay();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("point_line_surface");
	glutDisplayFunc(myDisplay);

	glutMainLoop();

	return 0;
}

void myDisplay()
{
	glClearColor(0.0,0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*点*/
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		glVertex2f(0.3f, 0.3f);
		glVertex2f(-0.3f, -0.3f);
		glVertex2f(0.5f, 0.5f);

		glVertex2d(0.2, 0.5);
		glVertex2d(-0.4, -0.6);
		glVertex2d(0.3, 0.6);
	glEnd();

	/* 坐标轴 */
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex2f(-1.0f, 0);
		glVertex2f(1.0f, 0);
		glVertex2f(0, -1.0f);
		glVertex2f(0, 1.0f);
	glEnd();
	
	/*相互连接的线条*/
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.1f, 0.8f);
		glVertex2f(-0.1f, -0.8f);
		glVertex2f(0.1f, -0.8f);
		glVertex2f(-0.1f, 0.8f);
	glEnd();
	
	/*闭合的连接线条*/
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.8f, -0.8f);
		glVertex2f(-0.5f, -0.8f);
		glVertex2f(-0.5f, -0.5f);
	glEnd();

	/*绘制三角形面*/
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.8f, 0.8f);
		glVertex2f(0.5f, 0.8f);
		glVertex2f(0.5f, 0.5f);
	glEnd();

	/*绘制多个三角形面， 第一个三角形为顶点｛1，2，3｝接下来就是｛2，3，4｝依次类推*/
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.8f, -0.4f);
		glVertex2f(0.8f, -0.5f);
		glVertex2f(0.1f, -0.9f);
	glEnd();

	/*绘制多个三角形面， 第一个三角形为顶点｛1，2，3｝接下来就是｛1，3，4｝依次类推*/
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.4f, 0.8f);
	glVertex2f(-0.8f, 0.4f);
	glVertex2f(-0.8f, 0.5f);
	glVertex2f(-0.1f, 0.9f);
	glEnd();

	/*绘制四边形*/
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2f(0.7f, 0.2f);
		glVertex2f(0.9f, 0.2f);
		glVertex2f(0.9f, 0.5f);
		glVertex2f(0.7f, 0.5f);
		
	glEnd();



	glFlush();
}