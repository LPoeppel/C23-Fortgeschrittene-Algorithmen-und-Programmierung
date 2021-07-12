#pragma once
#include "Node.h"
#include "NodeIDException.h"
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

class Edge {
private:
public:
	Edge(Node&, Node&);
	Edge(const std::string, const std::string);
	~Edge();
	std::string m_toString();
	Node m_getSrcNode();
	Node m_getDstNode();

	Node &m_srcNode;
	Node &m_dstNode;
};