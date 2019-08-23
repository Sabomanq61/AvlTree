#include "BinTree.h"

Node * BinTree::Add(Node *t, Node *p, int key)
{
	if (!t)
	{
		t = new Node(key, p);
	}
	else
	{
		if (!t->left)
			t->left = Add(t->left, t, key);
		else if (!t->right)
			t->right = Add(t->right, t, key);
		else if (rand() % 100 < 50)
			t->left = Add(t->left, t, key);
		else
			t->right = Add(t->right, t, key);
		fixheight(t);
	}
	return t;
}

int BinTree::height(Node *t)
{
	if (t)
		return t->h;
	else
		return 0;
}

BinTree::BinTree()
{
	root = nullptr;
}

BinTree::BinTree(int key)
{
	root = new Node(key);
}

BinTree::BinTree(int *a, int n)
{
	for (int i = 0; i < n; i++)
		root = Add(root,0, a[i]);
}

BinTree::BinTree(BinTree &t)
{
	root = Copy(t.root);
}

void BinTree::fixheight(Node *t)
{
	int i1 = height(t->left);
	int i2 = height(t->right);
	if (i1 > i2)
		t->h = i1 + 1;
	else
		t->h = i2 + 1;
}

Node * BinTree::get_R()
{
	return root;
}

BinTree BinTree::operator=(BinTree &t)
{
	DelAll(this->root);
	root = Copy(t.root);
	return *this;
}

void BinTree::DelAll(Node *r)
{
	if (r) {
		if (r->left)
			DelAll(r->left);
		if (r->right)
			DelAll(r->right);
		if (r)
			delete r;
	}
}

void BinTree::Push(int key)
{
	root = Add(root,nullptr,key);
}

void BinTree::Delkey(int t)
{
	Node *temp = Find_key(root, t);
	if (temp)
	{
		if(!temp->parent)
		{ 
			if (temp->right)
			{
				root = temp->right;
				Node*t = temp->right;
				for (; t->left; t = t->left);
				t->left = temp->left;
				if (temp->left)
					temp->left->parent = t;
			}
			else
			{
				root = temp->left;
			}
		}
		else
		{
			if (temp->right)
			{
				if (temp->parent->right == temp)
					temp->parent->right = temp->right;
				else
					temp->parent->left = temp->right;
				Node*t = temp->right;
				for (; t->left; t = t->left);
				t->left = temp->left;
				if (temp->left)
					temp->left->parent = t;
			}
			else
			{
				if (temp->parent->right == temp)
					temp->parent->right = temp->left;
				else
					temp->parent->left = temp->left;
			}
		}
		delete temp;
	}
}


void BinTree::Print_lkr(Node *root)
{
	if (root) {
		if (root->left)
			Print_lkr(root->left);
		cout << root->key << endl;
		if (root->right)
			Print_lkr(root->right);
	}
}

void BinTree::paint(Node *_node, int left, int right, int y)
{
	if (_node == nullptr) return;

	int x = (left + right) / 2;

	COORD pos = { x,y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	cout << _node->Get_key();
	paint(_node->get_l(), left, x, y + 3);
	paint(_node->get_r(), x, right, y + 3);
	pos.X = 0;
	pos.Y = y + 20;
	SetConsoleCursorPosition(output, pos);
}


Node * BinTree::Copy(Node *temp)
{
	if (!temp)
		return nullptr;
	Node *r = new Node(temp->key);
	r->left = Copy(temp->left);
	r->right = Copy(temp->right);
	if (r->left)
		r->left->parent = r;
	if (r->right)
		r->right->parent = r;
	return r;
}

Node * BinTree::Find_key(Node *r,int k)
{
	if (r->key == k)
		return r;
	else
	{
		Node *find = nullptr;
		if (r->left)
			find = Find_key(r->left, k);
		if (!find && r->right)
			find = Find_key(r->right, k);
		return find;
	}
}

int BinTree::Get_height(Node *n)
{
	if (n == nullptr) {
		return 0;
	}

	int lefth = Get_height(n->left);
	int righth = Get_height(n->right);

	if (lefth > righth) {
		return lefth + 1;
	}
	else {
		return righth + 1;
	}
}

BinTree::~BinTree()
{
	DelAll(root);
}
