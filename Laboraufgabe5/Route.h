#pragma once
#include <Edge.h>

class Route : public Edge{
public:
	Route(Node&, Node&, double);
	Route(const Edge&, double);
	~Route();
	double getWeight() { return m_distance; }
	std::string toString() const;
private:
	double m_distance;

};