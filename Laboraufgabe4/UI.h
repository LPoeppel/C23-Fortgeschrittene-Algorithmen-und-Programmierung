#include "Edge.h"
#include "Node.h"

class UI {
private:
public:
	template <class T> void print(T&);
	void printEdge(Edge&);
	void printNode(Node&);
	UI();
	~UI();
};