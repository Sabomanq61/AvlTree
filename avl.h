#pragma once
#include "BinTree.h"
class avl:public BinTree
{
	Node* Add(Node*, Node*, int);
	Node* rotateleft(Node*);
	Node* rotateright(Node*);
	int bfactor(Node*);
	Node* balance(Node*);
	Node* Del(Node*, int);
public:
	avl();
	Node* findmin(Node*);
	Node* findmax(Node*);
	Node* delmin(Node*);
	Node* Find_key(Node*,int);
	void DelKey(int);
	~avl();
};

