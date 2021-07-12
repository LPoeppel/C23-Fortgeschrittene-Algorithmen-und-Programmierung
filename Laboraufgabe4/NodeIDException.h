#pragma once
#include <string>
#include <sstream>
#include <iostream>

class NodeIDException {
private:
	std::string m_className;
	std::string m_reason;
public:
	NodeIDException(const std::string&, const std::string&);
	std::string getError() const;
};