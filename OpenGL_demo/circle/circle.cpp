/*
 *	描述：绘制一个圆，并添加了键盘控制，鼠标控制
 *	作者：venjieliu
 *	时间：2017/8/20
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>


const GLfloat Pi = 3.1415926;
GLfloat red, green, blue;
GLfloat number = 10;
GLfloat r = 0.3f; 

void myDisplayFunc();										/*绘制函数*/
void myKeyboardFunc(unsigned char key, int x, int y);		/*键盘按键事件处理函数*/
void mySpecialKeyboardFunc(int key, int x, int y);			/*键盘特殊键事件处理函数*/
void myMouseFunc(int button, int state, int x, int y);		/*鼠标事件处理函数*/
void myIdleFunc();											/*程序空闲时运行程序*/

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("circle");
	glutDisplayFunc(myDisplayFunc);
	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyboardFunc);
	glutMouseFunc(myMouseFunc);
	glutIdleFunc(myIdleFunc);
	
	glutMainLoop();

	return 0;
}

/*绘制圆圈*/
void myDisplayFunc()
{
	int i = 0;

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);

	glBegin(GL_POLYGON);
	for (i = 0; i < number; i++)
	{
		glVertex2f(r*cos(2*Pi/number*i), r*sin(2*Pi/number*i));
	}
	glEnd();

	glutSwapBuffers();
	glFlush();

}
/*键盘控制，q-退出，n-增加顶点数，m-减少顶点数*/
void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'n':
	case 'N':
		number += 5;
		break;
	case 'm':
	case 'M':
		if (number >10)
			number -= 5;
		break;
	}
}
/*特殊键控制，F1-使用红色绘制, F2-使用绿色绘制，F3-使用蓝色绘制*/
void mySpecialKeyboardFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F1:
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f;
		break;
	case GLUT_KEY_F2:
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f;
		break;
	case GLUT_KEY_F3:
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f;
		break;
	}
}
/*鼠标控制，左键按下表示增加圆圈半径，右键按下表示减小圆圈半径，中间按下表示使用最大的半径*/
void myMouseFunc(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
	{
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		if (r < 1.0f)
			r += 0.1f;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		if (r > 0.2f)
			r -= 0.1f;
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		r = 1.0f;
	}
}
/*空闲函数*/
void myIdleFunc()
{
	glutPostRedisplay();	/*标记重新绘制*/
}
