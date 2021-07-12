#include "Node.h"

int Node::s_numInstances = 0;

	Node::Node(std::string ID) {
		for (int i = 0; i < ID.length(); i++) {
			if (!isalnum(ID[i])) { throw NodeIDException("Node", "String 'ID' nicht alphanumerisch"); }
		}
		m_ID = toID(ID);
		s_numInstances++;
		std::cout << "Node mit ID " << m_ID << " wurde erstellt." << std::endl;
	};

	Node::Node() {
		m_ID = toID(s_numInstances);
		s_numInstances++;
		std::cout << "Node mit ID " << m_ID << " wurde erstellt." << std::endl;
	};

	Node::~Node() {
		std::cout << "delete[" << m_getID() << "]" << std::endl;
	}

	std::string Node::m_getID() {
		return m_ID;
	}

	template <class T> 
	std::string Node::toID(T input){
		std::ostringstream output;
		output << "Node_" << std::setw(4) << std::setfill('0') << input;
		return output.str();
	}