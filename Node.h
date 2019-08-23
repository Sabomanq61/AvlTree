#pragma once
#include <iostream>
using namespace std;

class Node
{
	Node *left, *right;
	Node *parent;
	int key;
	int h;
	friend class BinTree;
	friend class avl;
	public:
	Node(int key = 0, Node *parent = nullptr,Node *l = nullptr, Node *r = nullptr);
	int Get_key(){
		return key;
	}
	friend ostream& operator<<(ostream &out, Node *node)
	{
		out << node->key;
		return out;
	}
	auto get_l(){ return left; }
	auto get_r() { return right; }
	auto get_p() { return parent; }
	int height()
	{
		return h;
	}
};

