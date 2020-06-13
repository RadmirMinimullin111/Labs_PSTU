#include "tree.h"
using namespace std;

Tree::Tree()
{

	left = NULL;
	right = NULL;
	parent = NULL;
	cursor = false;
}

Tree::Tree(const Tree& a)
{
	number = a.number;
}

void Tree::operator<< (const Tree& point)
{
	cout << "Значение узла: " << point.number << endl;
}

void Tree::operator>>(Tree& point)
{
	cout << endl<< "Введите значение узла: ";
	cin >> point.number;
}

Tree::~Tree()
{
}

int Tree::height(Tree* node)  //получение высоты ид. баланс. дерева
{
	int level = 1;
	while (node->left != NULL)
	{
		node = node->left;
		level++;
	}
	return level;
}

Tree* Tree::balancedTree(int n) //создание дерева
{
	if (n == 0)
		return NULL;
	Tree* tree = new Tree(V[k]);
	k++;
	tree->AddLeftTree(balancedTree(n / 2));
	tree->AddRightTree(balancedTree(n - n / 2 - 1));
	return tree;
}

void Tree::AddLeftTree(Tree* tree) //добавление левого поддерева
{
	if (tree != NULL) {
		tree->parent = this;
		left = tree;
	}
}

void Tree::AddRightTree(Tree* tree)//добавление правого поддерева
{
	if (tree != NULL) {
		tree->parent = this;
		right = tree;
	}
}

int Tree::GetLevelUntil(Tree* node, int data, int level) //получение текущего уровня узла (высоты)
{
	if (node == NULL)
		return 0;

	if (node->number == data)
		return level;

	int downlevel = GetLevelUntil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = GetLevelUntil(node->right, data, level + 1);
	return downlevel;
}

int Tree::GetLevel(Tree* node, int data) //вызов того что выше
{
	return GetLevelUntil(node, data, 1);
}

void Tree::reorderSetCoords(Tree* tree, char dir) //расстановка координат
{                                               
	if (tree != NULL)
	{
		int curLevel = GetLevel(gc.tree, tree->getNumber());
		if (dir == '0')
		{
			tree->x = gc.winW / 2;
			tree->y = gc.winH - (gc.winH / gc.treeH / 2);
		}
		else if (dir == 'r') //левый
		{
			tree->x = tree->parent->x - gc.winW / pow(2, curLevel);

			if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
				tree->y = gc.winH / 2;
			else
				tree->y = tree->parent->y - gc.winH / gc.treeH;
		}
		else if (dir == 'l') //правый
		{

			tree->x = tree->parent->x + gc.winW / pow(2, curLevel);

			if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
				tree->y = gc.winH / 2;
			else
				tree->y = tree->parent->y - gc.winH / gc.treeH;

		}
		reorderSetCoords(tree->left, 'r'); //дерево рисуется зеркально
		reorderSetCoords(tree->right, 'l');//поэтому меняем узлы местами
	}
}


int Tree::searchAtributes(Tree* tree, int data, int&distance)
{
	if (distance == -228)
		if (tree != NULL)
		{
			if (data == tree->number)
			{
				cout << "узел найден, значение: " << tree->number << endl;
				distance = 0;
				while (tree->parent != NULL)
				{
					tree = tree->parent;
					distance++;
				}
				return distance;
			}
			else
			{
				searchAtributes(tree->right, data, distance);
				searchAtributes(tree->left, data, distance);
			}
			return distance;
		}
}

void drawButton1() //кнопка +
{
	if (gc.b1_state == 1)
		glColor3f(256, 256, 0);
	else
		glColor3f(256, 0, 0);
	glBegin(GL_QUADS);

	glVertex2i(0, gc.winH);
	glVertex2i(0, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, gc.winH);
	glVertex2i(0, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH);
	glEnd();

	glRasterPos2i(2, gc.winH - 12);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '+');

	gc.b1_x = gc.winW / 16;
	gc.b1_y = gc.winH / 18;
}

void drawButton2() //кнопка -
{
	if (gc.b2_state == 1)
		glColor3f(256, 256, 0);
	else
		glColor3f(256, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, gc.winH - (3 / 2) * gc.b1_y);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b1_y));
	glEnd();

	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b1_y - 12);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '-');

	gc.b2_x = gc.winW / 16;
	gc.b2_y = gc.winH / 18 + (3 / 2) * gc.b1_y;
}

void drawButton3() //кнопка вывода атрибутов в консоль
{
	if (gc.b3_state == 1)
		glColor3f(256, 256, 0);
	else
		glColor3f(256, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
	glEnd();

	string but31 = "Height";
	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b2_y - 12);
	for (int i = 0; i < but31.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, but31[i]);

	gc.b3_x = gc.winW / 16;
	gc.b3_y = gc.winH / 18 + (3 / 2) * gc.b2_y;
}

void drawButton4()
{
	if (gc.b4_state == 1)
		glColor3f(256, 256, 0);
	else
		glColor3f(256, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b3_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b3_y));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b3_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b3_y));
	glEnd();

	string but33 = "Distance";

	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b3_y - 12);
	for (int i = 0; i < but33.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, but33[i]);
	gc.b4_x = gc.winW / 16;
	gc.b4_y = gc.winH / 18 + (3 / 2) * gc.b3_y;
}

void drawCircle(int x, int y)
{
	glColor3f(256, 256, 0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = gc.R * cos(theta) + y;
		x1 = gc.R * sin(theta) + x;;

		glVertex2f(x1, y1);

	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = gc.R * cos(theta) + y;
		x2 = gc.R * sin(theta) + x;;

		glVertex2f(x2, y2);

	}
	glEnd();

}

void drawBorderedCircle(int x, int y)
{
	glColor3f(0.0f, 0.256f, 0.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = gc.R * cos(theta) + y;
		x1 = gc.R * sin(theta) + x;;

		glVertex2f(x1, y1);

	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = gc.R * cos(theta) + y;
		x2 = gc.R * sin(theta) + x;;

		glVertex2f(x2, y2);
	}
	glEnd();

}

void drawLine(int x0, int y0, int x1, int y1) //соединяющие линии
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

Tree* checkCircle(Tree* node, int x, int y) //проверяем входит ли мышь в зону круга
{
	if (pow(x - node->get_X(), 2) + pow(y - node->get_Y(), 2) <= pow(gc.R, 2))
		return node;
	Tree* temp = NULL;
	if (node->getLeft() != NULL)
		temp = checkCircle(node->getLeft(), x, y);
	if (temp != NULL)
		return temp;
	if (node->getRight() != NULL)
		temp = checkCircle(node->getRight(), x, y);
	return temp;
}

Tree* Tree::GetNode(int x, int y)
{
	Tree* node = this;
	node = checkCircle(node, x, y);
	return node;
}

void display() //функция отображения
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, gc.winW, 0, gc.winH); //ставим начало координат в левый нижний угол
	glViewport(0, 0, gc.winW, gc.winH);
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Tree* tree = gc.tree;
	int R = (gc.winH / gc.treeH) / 2;   //высчитываем нужный радиус
	gc.R = (R / 2) / (gc.winH / gc.winW + 1) - gc.shift;
	tree->reorderSetCoords(tree, '0');
	queue<Tree*> Q; 
	Tree* current = NULL; 
	Q.push(tree);
	int x0, y0, x1, y1;

	drawButton1();  //отрисовка кнопок
	drawButton2();
	drawButton3();
	drawButton4();

	while (!Q.empty())
	{
		tree = Q.front();   //1 элемент очереди
		Q.pop();
		x0 = tree->get_X();  //получаем его координаты
		y0 = tree->get_Y();
		if (tree->getLeft())    //если у него есть левый потомок
		{
			current = tree->getLeft();
			Q.push(current);    //записываем в очередь
			x1 = current->get_X();   //и получаем его координаты
			y1 = current->get_Y();
			drawLine(x0, y0, x1, y1);   //отрисовка соед. линии
		}
		if (tree->getRight()) //и то же самое с правым
		{
			current = tree->getRight();
			Q.push(current);
			x1 = current->get_X();
			y1 = current->get_Y();
			drawLine(x1, y1, x0, y0);
		}
		drawCircle(x0, y0);		//отрисока круга 
		drawText(to_string(tree->getNumber()), x0, y0, false);    //и текста

		if (tree->getCursor())  //если курсор в зоне круга
		{
			drawBorderedCircle(x0, y0); //рисуем другой круг
			drawText(to_string(tree->getNumber()), x0, y0, true);
			tree->setCursor(false);
		}
	}
	glutSwapBuffers();

}

void mouseMove(int x, int y) //функция отслеживания движения мыши
{
	Tree* node = gc.tree->GetNode(x, gc.winH - y);

	if (node != NULL)
	{
		node->setCursor(true);
	}

	if (x <= gc.b1_x and y <= gc.b1_y)  //если входит в одну из кнопок
		gc.b1_state = 1;
	else
		gc.b1_state = 0;

	if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y)
		gc.b2_state = 1;
	else
		gc.b2_state = 0;

	if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y)
		gc.b3_state = 1;
	else
		gc.b3_state = 0;
	if (x <= gc.b4_x and y <= gc.b4_y and y >= gc.b3_y)
		gc.b4_state = 1;
	else
		gc.b4_state = 0;
	glutPostRedisplay(); 
}

void mouseClick(int button, int state, int x, int y) //отслеживание нажатий
{
	if (x <= gc.b1_x and y <= gc.b1_y) 
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			k = 0;
			drawTree(gc.winW, gc.winH, 10, 1);
		}
	}
	if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y) 
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if (gc.nodes == 1)
				cout << endl<<"\nнельзя удалить корень\n";  
			else
			{
				Tree dt;
				k = 0;
				cout << endl<<"Удаление: ";
				dt.operator>>(dt);

				for (vector<Tree>::iterator i = V.begin(); i != V.end(); i++) 
				{
					if (dt == *i)
					{
						vector<Tree>::iterator j = i;
						V.erase(j); 
						gc.nodes--;
						break;
					}
				}
				drawTree(gc.winW, gc.winH, 10, 0); 
				cout << "узел удалён." << endl;
			}
		}
	}
	if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y)  
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			cout<<"высота дерева: "<<gc.tree->height(gc.tree);
		}
	}

	if (x <= gc.b4_x and y <= gc.b4_y and y >= gc.b3_y)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			cin.ignore(32767, '\n');
			int na;
			cout << endl<< " Введите значение искомого узла: ";
			cin >> na;
			int distance = -228;
			gc.tree->searchAtributes(gc.tree, na, distance);
			cout << "расстояние от вершины: " << distance;
		}
	}

}

void reshape(int w, int h)
{
	gc.winW = w;
	gc.winH = h;
	glViewport(0, 0, (GLsizei)gc.winW, (GLsizei)gc.winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)gc.winW, 0, (GLdouble)gc.winH);
	glutPostRedisplay();
}

void drawText(string data, int x0, int y0, bool state)
{
	if (gc.winH < 375 or gc.winW < 375)
		return;

	GLvoid* font_style;
	int counter = 0;
	vector<string> v;
	string temp;
	int strX;
	int strY = 12;

	if (state == true)
	{
		font_style = GLUT_BITMAP_9_BY_15;
		glColor3f(1.0f, 1.00f, 1.0f);
		strX = 9;
	}
	else   //иначе
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		font_style = GLUT_BITMAP_8_BY_13;
		strX = 8;
	}

	for (int i = 0; i < data.length() + 1; i++)
	{
		temp += data[i];
		if (data[i] == ' ' or data[i] == '\0')
		{
			counter++;
			v.push_back(temp);
			temp = "";
		}
	}
	int y = y0 + ((strY * counter / 2)) - 5;
	for (int i = 0; i < v.size(); i++)
	{
		int ka = v[i].length() / 2;   
		glRasterPos2i(x0 - ka * strX, y - (strY * i));
		for (int j = 0; j < v[i].length(); j++)
			glutBitmapCharacter(font_style, v[i][j]);
	}
}

void drawTree(int window_width, int window_height, int shift, int n) 
{
	static bool start = false;
	for (int i = 0; i < n; i++)
	{

		bool yes = false;
		Tree dt;
		dt.operator>>(dt);
		for (int i = 0; i < V.size(); i++)
			if (dt == V[i])
				yes = true;
		if (!yes)
		{
			V.push_back(dt);
			gc.nodes++;
		}
		else
		{
			if (!start)
			{
				cout << "ошибка" << endl;
				n++;
			}
			else
			{
				if (gc.nodes == 1)
					cout << "\nнельзя удалить корень\n";  
				else
				{
					for (vector<Tree>::iterator i = V.begin(); i != V.end(); i++) 
					{
						if (dt == *i)
						{
							vector<Tree>::iterator j = i;
							V.erase(j); 
							gc.nodes--;
							break;
						}
					}
					cout << "Заданный узел найден в дереве. Узел удалён." << endl;
				}
			}

		}

	}
	Tree* tree = Tree::balancedTree(gc.nodes);
	gc.tree = tree;
	gc.winW = window_width;
	gc.winH = window_height;
	gc.shift = shift;
	gc.treeH = tree->height(tree);
	gc.treeW = pow(2, gc.treeH - 1); 
	tree->reorderSetCoords(tree, '0'); 
	glViewport(0, 0, gc.winW, gc.winH);
	start = true;
}

bool operator==(Tree& a, Tree& b)
{
	if (a.number == b.number)
		return true;
	else
		return false;
}
