// NOTA: pentru vizualizarea mai usor a ceea ce se intampla in arbori, prin comenzile de mai jos
// am folosit site-ul: https://www.cs.usfca.edu/~galles/visualization/BST.html
#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"
#include "teste.h"

using namespace std;
int main() {

	testAll();

	Tree t = Tree(5);
	t.insert(14, &t.root);
	t.insert(13, &t.root);
	t.insert(38, &t.root);
	t.insert(42, &t.root);
	t.insert(42, &t.root);
	t.insert(41, &t.root);
	t.insert(37, &t.root);
	t.insert(38, &t.root);
	t.insert(39, &t.root);
	t.insert(18, &t.root);
	t.insert(15, &t.root);
	t.insert(16, &t.root);
	t.insert(19, &t.root);
	t.insert(11, &t.root);
	t.insert(10, &t.root);
	t.insert(37, &t.root);
	t.insert(35, &t.root);
	t.insert(9, &t.root);
	t.insert(7, &t.root);

	cout << "inorder ->" << t.inorder(&t.root) << "<-\n";
	cout << "preorder ->" << t.preorder(&t.root) << "<-\n";
	cout << "postorder ->" << t.postorder(&t.root) << "<-\n";
	cout << '\n';
	cout << "numar noduri: " << t.countNodes(&t.root) << '\n';
	cout << "numar muchii: " << t.countEdges(&t.root) << '\n'; 
	cout << "inaltime: " << t.height(&t.root) << '\n';
	cout << '\n';
	t.del(37, &t.root);
	cout << "inorder ->" << t.inorder(&t.root) << "<-\n";		// daca s-a eliminat corect din arbore nodul cu valoarea 4,
	// atunci cred ca acest lucru va fi cel mai usor vizibil in inordine 

	return 0;
}


