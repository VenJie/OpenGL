/*
 描述：opengl学习：红色矩形，简单的opengl程序。
 作者：venjieliu
 日期：2017.8.20
*/


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);		/*清除颜色*/
	glColor3f(1.0f, 0.0f, 0.0f);		/*设置红色*/
	glRectf(-0.5f, -0.5, 0.5f, 0.5f);	/*绘制矩形*/
	glFlush();							/*立即执行之前的glut命令*/
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);							/*初始化glut程序*/
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	/*初始化glut显示模式*/
	glutInitWindowSize(400, 300);					/*初始化窗口大小*/
	glutInitWindowPosition(100, 100);					/*初始化窗口位置*/
	glutCreateWindow("red rectangle");				/*创建窗口，并设置标题*/
	glutDisplayFunc(myDisplay);						/*glut绘制函数*/
	glutMainLoop();									/*glut消息循环*/

	return 0;
}