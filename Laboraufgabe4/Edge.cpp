#include "Edge.h"


Edge::Edge(Node &rSrc, Node &rDst): m_srcNode(rSrc), m_dstNode(rDst) {
};

	Edge::Edge(std::string src, std::string dst) : m_srcNode(*(new Node(src))), m_dstNode(*(new Node(dst))) {
		
		#
		for (int i = 0; i < src.length(); i++) {
			if(!isalnum(src[i])) { throw NodeIDException("Edge", "String 'src' nicht alphanumerisch"); }
		}
		for (int i = 0; i < dst.length(); i++) {
			if(!isalnum(dst[i])) { throw NodeIDException("Edge", "String 'dst' nicht alphanumerisch"); }
		}
	};


Edge::~Edge() {
	std::cout << "delete[Edge]" << std::endl;
}

std::string Edge::m_toString() {
	std::ostringstream output;
	output << m_srcNode.m_getID() << " --> " << m_dstNode.m_getID();
	return output.str();
}

Node Edge::m_getSrcNode()
{
	return m_srcNode;
}

Node Edge::m_getDstNode()
{
	return m_dstNode;
}
