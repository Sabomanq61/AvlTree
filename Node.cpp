#include "Node.h"
Node::Node(int k, Node *pr,Node *l, Node *r)
{
	key = k;
	parent = pr;
	left = l;
	right = r;
	h = 1;

}


