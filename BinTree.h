#pragma once
#include "Node.h"
#include <Windows.h>

class BinTree
{
protected:
	Node *root;
public:
	BinTree();
	BinTree(int key);
	BinTree(int*, int);
	BinTree(BinTree&);
	void fixheight(Node*);
	virtual Node* Add(Node *, Node*, int);
	int height(Node*);
	Node* get_R();
	BinTree operator=(BinTree&);
	void DelAll(Node *);
	void Push(int);
	virtual void Delkey(int);
	void Print_lkr(Node *);
	void paint(Node*, int, int, int);
	Node* Copy(Node *);
	virtual Node* Find_key(Node *,int);
	int Get_height(Node *);
	~BinTree();
};

