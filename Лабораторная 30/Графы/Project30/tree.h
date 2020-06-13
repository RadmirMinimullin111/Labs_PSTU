#include <glut.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

class Tree
{
private:
	int number;
	Tree* left;
	Tree* right;
	Tree* parent;
	int x;
	int y;
	bool cursor;
public:
	Tree();
	Tree(const Tree&);
	~Tree();
	static Tree* balancedTree(int n);
	void AddLeftTree(Tree* temp);
	void AddRightTree(Tree* temp);
	int height(Tree*);
	void reorderSetCoords(Tree* temp, char dir);
	int searchAtributes(Tree* temp, int data, int& k);

	int get_X() { return this->x; }
	int get_Y() { return this->y; }
	Tree* getLeft() { return this->left; }
	Tree* getRight() { return this->right; }
	int getNumber() { return this->number; }
	Tree* getPatrent() { return this->parent; }
	bool getCursor() { return this->cursor; }

	void set_X(int x) { this->x = x; }
	void set_Y(int y) { this->y = y; }
	void setLeft(Tree* left) { this->left = left; }
	void setRight(Tree* right) { this->right = right; }
	void setNumber(int num) { this->number = num; }
	void setParent(Tree* parent) { this->parent = parent; }
	void setCursor(bool c) { cursor = c; }

	int GetLevelUntil(Tree* node, int data, int level);
	int GetLevel(Tree* node, int data);
	Tree* GetNode(int x, int y);

	void operator<< (const Tree& point);
	void operator>> (Tree& point);
	friend bool operator==(Tree& a, Tree& b);
};




struct SGlutContextStruct
{
	Tree* tree;
	int winW, winH, treeH, treeW, shift, R;
	int b1_x, b1_y, b1_state = 0;//кнопки
	int b2_x, b2_y, b2_state = 0;
	int b3_x, b3_y, b3_state = 0;
	int b4_x, b4_y, b4_state = 0;
	int nodes = 0;
};

static SGlutContextStruct gc;
static vector<Tree> V;
static int k = 0;

void drawTree(int window_width, int window_height, int shift, int n);
void display();
void reshape(int, int);
void drawButton1();
void drawButton2();
void drawButton3();
void drawButton4();
void drawText(string data, int x0, int y0, bool state);
void drawLine(int x1, int y1, int x2, int y2);
void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
