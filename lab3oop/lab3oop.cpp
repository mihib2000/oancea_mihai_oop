

#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"

using namespace std;
int main() {


	//Tree t = Tree(5);
	Tree t = Tree(29);

	/*
	t.insert(4, &t.root); 
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);
	*/

	/*
	t.insert(1, &t.root);
	t.insert(9, &t.root);
	t.insert(3, &t.root);
	t.insert(4, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);
	t.insert(2, &t.root);
	t.insert(6, &t.root);
	t.insert(6, &t.root);
	t.insert(6, &t.root);
	t.insert(6, &t.root);
	*/
	/*
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
	*/

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


	

	
	
	
	cout << "test pentru git";


}


