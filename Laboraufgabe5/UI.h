#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "Taxi.h"
#include <iterator>
#include <vector>

class UI
{
private:
public:
	UI();
	~UI();

	void printEdge(Edge*);
	void printEdgeList(std::list<Edge*>);
	void printEdgeList(std::list<Edge*>, std::string);
	static void printNodeList(std::list<Node*>);
	static void printVector(std::vector<Edge*>);
	/***********************************/
	static void printTaxi(Taxi*);
	static int auswahlTaxi();
	static int auswahlAktion(Taxi*, Graph&);
	static double auswahlStrecke(const std::list<Node*>&, Graph&);
	//static void setTaxiName(Taxi*);
};
