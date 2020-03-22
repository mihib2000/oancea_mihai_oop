#include "Node.h"

Node::Node(int x) {
	wert = x;
	l = nullptr;
	r = nullptr;
}

Node::Node() {
	wert = 0;
	l = nullptr;
	r = nullptr;
}
