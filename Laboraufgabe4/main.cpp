#include <iostream>
#include <string>
#include "UI.h"
#include "Edge.h"
#include "Node.h"

int main() {
	UI test = UI();

	Node start = Node();
	Node end = Node();

	Edge connect = Edge(start, end);
	Edge &c = connect;
	test.printEdge(c);

	try {
		Edge knoten1 = Edge("start", "ende");
		Edge knoten2 = Edge("sta/rt", "ende");
		test.printEdge(knoten1);
		test.printEdge(knoten2);
	
	Node *t1, *t2;
		Node kante = Node("_aödm");
		t1 = new Node("text");
		t2 = new Node("abs__?atz");
		test.printNode(kante);
		test.printNode(*t1);
		test.printNode(*t2);
		delete t1, t2;
	}
	catch (const NodeIDException& e) {
		std::cout << "Exception:\n" << e.getError() << std::endl;
	}
	catch (...) {
		std::cout << "Undefined error." << std::endl;
	}
	return 0;
}
