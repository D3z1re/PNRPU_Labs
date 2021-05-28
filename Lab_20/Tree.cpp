#include "Tree.h"

Tree::Tree()
{
	parent = NULL;
	right = NULL;
	left = NULL;
}
Tree::Tree(double tmp)
{
	data = tmp;
	parent = NULL;
	right = NULL;
	left = NULL;
}
Tree::~Tree()
{
	if (this != NULL) delete this;
}

void Tree::insert_r(double tmp)
{
	Tree* node = new Tree(tmp);
	if (this->right != NULL) 
	{
		this->right->parent = node;
		node->right = this->left;
		this->right = node;
		node->parent = this;
	}
	else
	{
		Tree* node = new Tree(tmp);
		this->right = node;
		node->parent = this;
	}
}
void Tree::insert_l(double tmp)
{
	Tree* node = new Tree(tmp);
	if (this->left != NULL) 
	{
		this->left->parent = node;
		node->left = this->left;
		this->left = node;
		node->parent = this;
	}
	else 
	{
		Tree* node = new Tree(tmp);
		this->left = node;
		node->parent = this;
	}
}
void Tree::insert_node(Tree*& rt, double tmp)
{
	if (rt == NULL)
	{
		rt = new Tree(tmp);
		return;
	}
	Tree* node = rt;
	while (node != NULL)
	{
		if (tmp >= node->data)
		{
			if (node->right != NULL) node = node->right;
			else
			{
				node->insert_r(tmp);
				return;
			}
		}
		else
		{
			if (node->left != NULL) node = node->left;
			else
			{
				node->insert_l(tmp);
				return;
			}
		}
	}
}

void Tree::in_order(Tree* node)
{
	if (node == NULL) return;
	in_order(node->left);
	cout << node->data << "|";
	in_order(node->right);
}

int Tree::get_h()
{
	int h1 = 0, h2 = 0;
	if (this == NULL) return 0;
	if (this->left != NULL) h1 = this->left->get_h();
	if (this->right != NULL) h2 = this->right->get_h();
	if (h1 >= h2) return (h1 + 1);
	else return (h2 + 1);
}

Tree* Tree::find_node(double tmp)
{
	Tree* node = this;
	while (node != NULL)
	{
		if (node->data == tmp) return node;
		else 
		{
			if (node->data > tmp) node = node->left;
			else node = node->right;
		}
	}
	return NULL;
}
