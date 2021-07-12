#include "NodeIDException.h"

NodeIDException::NodeIDException(const std::string& className, const std::string& reason): m_className(className), m_reason(reason) {
};

std::string NodeIDException::getError() const {
	std::ostringstream output;
	output << "\tKlasse \"" << m_className << "\" konnte nicht initialisiert werden!\n\tGrund: " << m_reason;
	return output.str();
}