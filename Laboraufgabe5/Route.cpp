#include "Route.h"

Route::Route(Node& rSrc, Node& rDst, double distance) : Edge(rSrc, rDst)
{
	m_distance = distance;
}


//---------------------------------------------------------------------------------------------------------------------

Route::Route(const Edge& rOther, double distance) : Edge(rOther)
{
	m_distance = distance;
}

Route::~Route() {

}