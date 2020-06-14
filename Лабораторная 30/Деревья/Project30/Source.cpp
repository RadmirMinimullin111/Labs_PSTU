#include <glut.h>
#include "tree.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
int winW = 900;
int winH = 720;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	glutInit(&argc, argv);
	int n;
	cout << "введите количество узлов: ";
	do
	{
		cin >> n;
		if (n < 1)
			cout << ">1: ";
	} while (n < 1);
	cout << "дерево из "<<n<<" узлов: " << endl;
	drawTree(winW, winH, 10, n);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(winW, winH);
	glutCreateWindow("DrawTree");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mouseClick);
	glutMainLoop();


}
