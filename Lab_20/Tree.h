#pragma once
#include <iostream>
#include "GL/glut.h"
#include <string>
#include <cmath>
#include <windows.h>
#include <stdio.h>
using namespace std;

class Tree
{
	double data;
	Tree *parent, *left, *right;
public:
	GLfloat x = 0, y = 4;
	int state, level = 1;

	Tree();
	Tree(double tmp);
	~Tree();

	void insert_r(double tmp);
	void insert_l(double tmp);
	void insert_node(Tree*& rt, double tmp);
	void in_order(Tree* node);

	int get_h();

	Tree* find_node(double tmp);

	friend void LevelCounter(Tree* root);
	friend void CountLevels(Tree* root, void (*LevelCounter)(Tree* root));
	friend void Coords(Tree* node);
	friend void CoordsCalculate(Tree* node, void (*Coords)(Tree* node));
	friend void DrawOneNode(Tree* root);
	friend void DrawNodes(Tree* root, void (*DrawOneNode)(Tree* root));
	friend void DrawOneLine(Tree* root);
	friend void DrawLines(Tree* root, void (*DrawOneLine)(Tree* root));
	void drawTree(int argc, char** argv, int win_height, int win_width);
};
