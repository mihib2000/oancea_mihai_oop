#include <iostream>
#include <string.h>
#include "Node.h"
#include "Tree.h"
#include "tests.h"
using namespace std;
int main() {

	test_all();

	/*
	//Tree t = Tree(5);
	Tree t = Tree(29);

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
	t.insert(11, &t.root);
	t.insert(12, &t.root);
	t.insert(14, &t.root);

	cout <<"inorder -> "<< t.inorder(&t.root)<<"<-\n";
	cout <<"preorder -> "<< t.preorder(&t.root)<<"<-\n";
	cout <<"postorder -> "<< t.postorder(&t.root)<<"<-\n";
	
	cout << t.countNodes(&t.root)<<" "<<t.countEdges(&t.root)<<" "<<t.height(&t.root)<<endl;

	//cout << " a " + "bcd";

//	t.del(4, &t.root);
	
	cout << t.root.wert << ' ' << t.root.l << endl;

	Node n = t.root;


	
	//string a = "'\n'";

	//char b = '\n';
	//cout << a;
	//cout << b;
	
	
	//std::cin.getline(a);
	string a;
	//cin >> noskipws >> a;
	//cout << a << '\n';
	//cout << "test pentru git";

	//cin.get(a);
	//a = cin.getline();

/*
	while(a = cin.get())
	if (a == "\n")
		cout << "este endline";
	else
		cout << "nu este endline; sirul este: " << a;
*/
	
	return 0;
}


