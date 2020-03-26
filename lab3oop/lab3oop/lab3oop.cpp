#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"
#include "teste.h"

using namespace std;
int main() {


	Tree t = Tree(5);



	t.insert(4, &t.root);
	//t.insert(3, &t.root); 
	//cout << t.root.wert << ' ' << t.root.l->wert << endl;

	cout << t.root.wert << ' ' << t.root.l->wert << endl;

	cout << "inorder ->" << t.inorder(&t.root) << "<-\n";
	cout << t.countNodes(&t.root) << " " << t.countEdges(&t.root) << " " << t.height(&t.root) << endl;



	t.del(4, &t.root);

	cout << t.root.wert << ' ' << t.root.l << endl;

	Node n = t.root;


	testAll();




	cout << "test pentru git";


}


