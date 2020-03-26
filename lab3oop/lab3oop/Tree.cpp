#include "Tree.h"
#include <vector>
#include <iostream>
Tree::Tree(Node r) {
	root = r;

}

void Tree::insert(int v, Node *r) {

	if (v <= r->wert)
		if (r->l == nullptr) {

			r->l = new Node();
			r->l->wert = v;
			r->l->l = nullptr;
			r->l->r = nullptr;

			std::cout << r->l->wert << " a fost bagat in stanga " << r->wert << std::endl;

		}
		else
			insert(v, r->l);
	else
		if (r->r == nullptr) {

			r->r = new Node();
			r->r->wert = v;
			r->r->l = nullptr;
			r->r->r = nullptr;

			std::cout << "a bagat in dreapta";
		}
		else
			insert(v, r->r);


}

Node* Tree::FindMin(Node* root)
{
	while (root->l != NULL) root = root->l;
	return root;
}

Node* Tree::del(int data, Node* root) {
	if (root == NULL) return root;
	else
		if (data < root->wert)
			root->l = del(data, root->l);
		else
			if (data > root->wert)
				root->r = del(data, root->r);
	// root = nodul de sters
			else {
				// Case 1:  Frunza
				if (root->l == NULL && root->r == NULL) {
					delete root;
					root = NULL;
				}
				//Case 2: Un singur copil 
				else if (root->l == NULL) {
					Node *temp = root;
					root = root->r;
					delete temp;
				}
				else if (root->r == NULL) {
					Node *temp = root;
					root = root->l;
					delete temp;
				}
				// case 3: 2 copii
				else {
					Node *temp = FindMin(root->r);
					root->wert = temp->wert;
					root->r = del(temp->wert, root->r);
				}
			}
	return root;
}

std::string Tree::postorder(Node* node)
{
	if (node == NULL)
		return "";

	//postorder(node->l);

	//postorder(node->r);


	return postorder(node->l) + " " + postorder(node->r) + " " + std::to_string(node->wert) + " ";
}

std::string Tree::inorder(Node* node)
{
	if (node == NULL)
		return "";

	//inorder(node->l);

	return inorder(node->l) + " " + std::to_string(node->wert) + " " + inorder(node->r) + " ";


	//inorder(node->r);
}

std::string Tree::preorder(Node* node)
{
	if (node == NULL)
		return "";

	return std::to_string(node->wert) + " " + preorder(node->l) + " " + preorder(node->r) + " ";


	//std::cout << node->wert << " ";

	//preorder(node->l);

	//preorder(node->r);
}

int Tree::countNodes(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return 1 + countNodes(node->l) + countNodes(node->r);
	}
}

int Tree::countEdges(Node* node) {
	//std::cout << "edges";
	return countNodes(node) - 1;
}

int Tree::height(Node* node) {

	if (node == NULL)
		return 0;
	else
	{

		int l_height = height(node->l);
		int r_height = height(node->r);


		if (l_height > r_height)
			return(l_height + 1);
		else
			return(r_height + 1);
	}
}