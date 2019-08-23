#include "avl.h"
Node * avl::Add(Node *t, Node *pr, int key)
{
	if (!t)
	{
		t = new Node(key, pr);
	}
	else
	{
		if (t->key < key)
		{
			t->right = Add(t->right, t, key);
		}
		else
			t->left = Add(t->left, t, key);
	}
	return balance(t);
}

Node * avl::rotateleft(Node *t)
{
	Node* p = t->right;
	t->right = p->left;
	p->left = t;
	fixheight(p);
	fixheight(t);
	return p;
}

Node * avl::rotateright(Node *t)
{
	Node* q = t->left;
	t->left = q->right;
	q->right = t;
	fixheight(t);
	fixheight(q);
	return q;
}

int avl::bfactor(Node *t)
{
	return height(t->right) - height(t->left);
}

Node * avl::balance(Node *p)
{	
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

avl::avl()
{
	root = nullptr;
}


Node* avl::Del(Node* temp, int k) {
	if (temp == nullptr) return nullptr;

	if (temp->key > k)
	{
		temp->left = Del(temp->left, k);
	}
	else if (temp->key < k)
	{
		temp->right = Del(temp->right, k);
	}
	else 
	{
		Node* l = temp->left;
		Node* r = temp->right;
		delete temp;
		if (r == nullptr) return l;
		Node* min = findmin(r);
		min->right = delmin(r);
		min->left = l;
		return balance(min);
	}

	return balance(temp);
}

Node * avl::findmin(Node *t)
{
	if (t->left)
		return findmin(t->left);
	else
		return t;
}

Node * avl::findmax(Node *t)
{
	if (t->right)
		return findmax(t->right);
	else
		return t;
}

Node * avl::delmin(Node *t)
{
	if (!t->left)
		return t->right;
	t->left = delmin(t->left);
	return balance(t);
}

Node * avl::Find_key(Node *t,int key)
{
	if (t->key < key)
	{
		return Find_key(t->right, key);
	}
	else if (t->key > key)
	{
		return Find_key(t->left, key);
	}
	else
	{
		return t;
	}
}

void avl::DelKey(int key)
{
	root = Del(root, key);
}

avl::~avl()
{
}
