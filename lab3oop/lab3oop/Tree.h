#pragma once
#include "Node.h"
#include <vector>
#include <string>
class Tree
{

public:
	Node root;


	Tree(Node r);
	void insert(int v, Node *r);
	Node* del(int v, Node* r);
	Node* FindMin(Node* root);
	std::string postorder(Node* node);
	std::string inorder(Node* node);
	std::string preorder(Node* node);
	int countNodes(Node* node);
	int countEdges(Node* node);
	int height(Node* node);

};

