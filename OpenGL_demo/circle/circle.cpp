/*
 *	����������һ��Բ��������˼��̿��ƣ�������
 *	���ߣ�venjieliu
 *	ʱ�䣺2017/8/20
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

void myDisplayFunc();										/*���ƺ���*/
void myKeyboardFunc(unsigned char key, int x, int y);		/*���̰����¼�������*/
void mySpecialKeyboardFunc(int key, int x, int y);			/*����������¼�������*/
void myMouseFunc(int button, int state, int x, int y);		/*����¼�������*/
void myIdleFunc();											/*�������ʱ���г���*/

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

/*����ԲȦ*/
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
/*���̿��ƣ�q-�˳���n-���Ӷ�������m-���ٶ�����*/
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
/*��������ƣ�F1-ʹ�ú�ɫ����, F2-ʹ����ɫ���ƣ�F3-ʹ����ɫ����*/
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
/*�����ƣ�������±�ʾ����ԲȦ�뾶���Ҽ����±�ʾ��СԲȦ�뾶���м䰴�±�ʾʹ�����İ뾶*/
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
/*���к���*/
void myIdleFunc()
{
	glutPostRedisplay();	/*������»���*/
}
