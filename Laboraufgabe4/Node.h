#pragma once
#include "NodeIDException.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>

class Node {
private:
	static int s_numInstances;
	std::string m_ID;
public:
	Node();
	Node(std::string);
	~Node();
	std::string m_getID();
	template <class T> std::string toID(T);
};

