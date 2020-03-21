#pragma once
#include "Node.h"
#include <vector>
class Tree
{

private:
	Node root;

public:
	Tree(Node* r);
	void insert(int v, Node r);

};

