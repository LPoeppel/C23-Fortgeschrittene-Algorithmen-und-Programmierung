#include <iostream>
#include <sstream>
#include "UI.h"

/*
//warum auch immer die nicht geht
template <class T>
void UI::print(T &var) {
	std::cout << var.m_toString() << std::endl;
}
*/

void UI::printEdge(Edge &var) {
	std::cout << var.m_toString() << std::endl;
}

void UI::printNode(Node &var) {
	std::cout << var.m_getID() << std::endl;
}

UI::UI() {
}

UI::~UI() {

}



