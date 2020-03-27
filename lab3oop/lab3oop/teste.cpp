#include "Node.h"
#include "Tree.h"
#include <cassert>
#include <iostream>
void test_constructor1()
{
	Tree t(1);
	assert(t.root.wert == 1);
}

void test_constructor2()
{
	Tree t(2);
	assert(t.root.wert == 2);
}


/*
	structura arbore:

			5
		   / \
		  4   6
		 /     \
		2       7
		 \       \
		  3       8
*/
void test_insert1()
{
	// setup
	Tree t(5);

	// run
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);
	
	// verify
	
		// aici verific subarborele stang
	assert(t.root.l->wert == 4);
	assert(t.root.l->r == nullptr);
	assert(t.root.l->l->wert == 2);
	assert(t.root.l->l->l == nullptr);
	assert(t.root.l->r == nullptr);
	assert(t.root.l->l->l == nullptr);
	assert(t.root.l->l->r->wert == 3);
	assert(t.root.l->l->r->l == nullptr);
	assert(t.root.l->l->r->r == nullptr);

		// aici verific subarborele drept
	assert(t.root.r->wert == 6);
	assert(t.root.r->l == nullptr);
	assert(t.root.r->r->wert == 7);
	assert(t.root.r->r->l == nullptr);
	assert(t.root.r->r->r->wert == 8);
	assert(t.root.r->r->r->r == nullptr);
	assert(t.root.r->r->r->l == nullptr);
}

/*
	structura arbore:

				5
			   / \
              /   \
 			 /     \
			/       \
		   /         \
		  1           9
		   \         /
			3       7
		   / \     / \
          2   4  6    8
		          \
		           6
			        \
			         6
*/
void test_insert2()
{
	// setup
	Tree t(5);

	// run
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
	
	// verify
		// aici verific subarborele stang
	assert(t.root.l->wert == 1);
	assert(t.root.l->l == nullptr);
	assert(t.root.l->r->wert == 3);
	assert(t.root.l->r->l->wert == 2);
	assert(t.root.l->r->l->r == nullptr);
	assert(t.root.l->r->l->l == nullptr);
	assert(t.root.l->r->r->wert == 4);
	assert(t.root.l->r->r->r == nullptr);
	assert(t.root.l->r->r->l == nullptr);
		// aici verific subarborele drept
	assert(t.root.r->wert == 9);
	assert(t.root.r->r == nullptr);
	assert(t.root.r->l->wert == 7);
	assert(t.root.r->l->l->wert == 6);
	assert(t.root.r->l->r->wert == 8);
	assert(t.root.r->l->r->l == nullptr);
	assert(t.root.r->l->r->r == nullptr);
	assert(t.root.r->l->l->l == nullptr);
	assert(t.root.r->l->l->r->wert == 6);
	assert(t.root.r->l->l->r->l == nullptr);
	assert(t.root.r->l->l->r->r->wert == 6);
	assert(t.root.r->l->l->r->r->l == nullptr);
	assert(t.root.r->l->l->r->r->r == nullptr);
}

void test_del1()
{
	// setup
	Tree t(5);
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);

	// run
	t.del(3, &t.root);
	t.del(6, &t.root);	
	t.del(5, &t.root);

	//verify
	assert(t.root.l->l->r == nullptr);
	// assert(t.root.r->wert == 7); // din motive de alegere a implementarii acestei metode, pentru ca acest assert sa functioneze
	// va fi nevoie de mutarea acestuia intre linia 142
	assert(t.root.wert == 7);
}

void test_del2()
{
	// setup
	Tree t(5);
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

	// run
	t.del(3, &t.root);
	t.del(7, &t.root);

	// verify
	assert(t.root.l->r->wert == 4);
	assert(t.root.r->l->wert == 8);

	assert(t.root.r->l->l->wert == 6);
	assert(t.root.r->l->l->r->wert == 6);
	assert(t.root.r->l->l->r->l == nullptr);
	assert(t.root.r->l->l->r->l == nullptr);
	assert(t.root.r->l->l->r->r->wert == 6);
	assert(t.root.r->l->l->r->r->l == nullptr);
}

void test_FindMin1()
{
	// setup
	Tree t(5);
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);

	// run
	Node* minn = t.FindMin(&t.root);

	// verify
	assert(minn->wert == 2);
}

void test_FindMin2()
{
	// setup
	Tree t(5);
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


	// run
	Node* minn = t.FindMin(&t.root);

	// verify
	assert(minn->wert == 1);
}

void test_countNodes1()
{
	// setup
	Tree t(5);
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);

	// run
	int nr = t.countNodes(&t.root);

	//verify
	assert(nr == 7);
}
void test_countNodes2()
{
	// setup
	Tree t(5);
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

	// run
	int nr = t.countNodes(&t.root);

	//verify
	assert(nr == 11);
}
void test_countEdges1()
{
	// setup
	Tree t(5);
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);

	// run
	int nr = t.countEdges(&t.root);

	//verify
	assert(nr == 6);
}
void test_countEdges2()
{
	// setup
	Tree t(5);
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

	// run
	int nr = t.countEdges(&t.root);

	//verify
	assert(nr == 10);

}
void test_height1()
{
	// setup
	Tree t(5);
	t.insert(4, &t.root);
	t.insert(6, &t.root);
	t.insert(2, &t.root);
	t.insert(3, &t.root);
	t.insert(7, &t.root);
	t.insert(8, &t.root);

	// run
	int h = t.height(&t.root);

	//verify
	assert(h == 3);
}
void test_height2()
{
	// setup
	Tree t(5);
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

	// run
	int h = t.height(&t.root);

	//verify
	assert(h == 5);

}
void testAll() {
	test_constructor1();
	test_constructor2();
	test_insert1();
	test_insert2();
	test_del1();
	test_del2();
	test_FindMin1();
	test_FindMin2();
	test_countNodes1();
	test_countNodes2();
	test_countEdges1();
	test_countEdges2();
	test_height1();
	test_height2();
	std::cout << "All tests passed" << '\n';
}