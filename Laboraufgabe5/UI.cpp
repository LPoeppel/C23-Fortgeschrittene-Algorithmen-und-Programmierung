#include <iostream>
#include <sstream>
#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

void UI::printEdge(Edge *e) {
	std::cout << e->toString() << std::endl;
}

void UI::printEdgeList(std::list<Edge*> edges) {
	if (edges.empty()) {
		std::cout << "\t" << "Edge list is empty." << std::endl;
	}
	else {
		std::cout << "Edges: " << std::endl;
		int i = 0;
		for (std::list<Edge*>::iterator ptr = edges.begin(); ptr != edges.end(); ++ptr) {
			i++;
			Edge *a = *ptr;
			std::cout << "\t" << i << ": " << a->toString() << "\t" << a->getWeight() << "km" << std::endl;
		}
	}
}
void UI::printEdgeList(std::list<Edge*> edges, std::string s) {
	if (edges.empty()) {
		std::cout << "\t" << "Edge list is empty." << std::endl;
	}
	else if (s == "out") {
		std::cout << "Edge out:" << std::endl;
			int i = 0;
		for (std::list<Edge*>::iterator ptr = edges.begin(); ptr != edges.end(); ++ptr) {
			i++;
			Edge *a = *ptr;
			std::cout << "\t" << i << ": " << a->toString() << std::endl;
		}
	}
	else if (s == "in") {
		std::cout << "Edge in:" << std::endl;
		int i = 0;
		for (std::list<Edge*>::iterator ptr = edges.begin(); ptr != edges.end(); ++ptr) {
			i++;
			Edge *a = *ptr;
			std::cout << "\t" << i << ": " << a->toString() << "\t" << a->getWeight() << "km" << std::endl;
		}
	}
	else {
		printEdgeList(edges);
	}
}

void UI::printNodeList(std::list<Node*> nodes) {
	if (nodes.empty()) {
		std::cout << "Node list is empty." << std::endl;
	}
	else {
		int i = 0;
		std::cout << "Nodes:" << std::endl;
		for (std::list<Node*>::iterator ptr = nodes.begin(); ptr != nodes.end(); ++ptr) {
			i++;
			Node *a = *ptr;
			std::cout << "\t" << i << ": " << a->getID() << std::endl;
		}
	}
}

void UI::printVector(std::vector<Edge*> vec)
{
	if (vec.empty()) {
		std::cout << "No Edges with these Nodes as Source and Destination found." << std::endl;
	}
	else {
		std::cout << "Edges with "<<(*(vec.begin()))->getSrcNode().getID()<<" as source and "<<(*(vec.begin()))->getDstNode().getID()<<" as destination:" << std::endl;
		int i = 1;
		for (std::vector<Edge*>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
			std::cout << "\t" << i << ": " << (*it)->toString() << "\t" << (*it)->getWeight() << "km" << std::endl;
			i++;
		}
	}
}

/**************************************************************/


void UI::printTaxi(Taxi *t) {
	int i = t->getState().length();
	std::cout << std::setw(i) << std::setfill('-') << "-" << std::endl;
	std::cout << t->getState() << std::endl;
	std::cout << std::setw(i) << std::setfill('-') << "-" << std::endl;
	std::cout << std::endl;
}

int UI::auswahlTaxi() {
	int auswahl;
	std::cout << "****************************" << std::endl << "Bitte waehlen Sie ein Taxi: "
		<< std::endl << "  [1] Taxi 1"
		<< std::endl << "  [2] Taxi 2"
		<< std::endl << "[0] Quit" << std::endl;
	std::cout << "Taxi: ";
	std::cin >> auswahl;
	if (auswahl != 1 && auswahl != 2 && auswahl != 0) {
		std::fflush;
		std::cout << "Fehler. Bitte erneut Taxi auswaehlen." << std::endl;
		auswahlTaxi();
	}
	else {
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return auswahl;
	}
}

int UI::auswahlAktion(Taxi *t, Graph& g) {
	int auswahl;
	double strecke;
	std::cout << "Sie haben Taxi " << t->getMID() << " gewaehlt." << std::endl;
	printTaxi(t);
	std::cout << "Bitte waehlen Sie eine Aktion: "
		<< std::endl << "  [1] Buche Fahrt mit Gaesten."
		<< std::endl << "  [2] Buche Fahrt ohne Gaeste."
		<< std::endl << "  [3] Auftanken."
		<< std::endl << "  [4] Taxi-Status ausgeben."
		<< std::endl << "[0] zueruck" << std::endl;
	std::cout << "Aktion: ";
	std::cin >> auswahl;
	if (auswahl != 1 && auswahl != 2 && auswahl != 3 && auswahl != 4 && auswahl != 0) {
		std::cout << "Fehler. Bitte erneut Aktion auswaehlen." << std::endl;
		auswahlAktion(t, g);
	}
	else {
		switch (auswahl) {
		case 1:		strecke = auswahlStrecke(g.getNodes(), g); t->bookTrip(strecke, true);
			break;
		case 2:		strecke = auswahlStrecke(g.getNodes(), g); t->bookTrip(strecke, false);
			break;
		case 3:		std::cout << "Bitte geben Sie den Spritpreis pro Liter an: "; std::cin >> auswahl; t->fillUp(auswahl / 100);
			break;
		case 4:		printTaxi(t);
			break;
		case 0:		return 0;
			break;
		default:	std::cout << "Fehler. Erneut Aktion waehlen." << std::endl;
			auswahlAktion(t, g);
		}
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

double UI::auswahlStrecke(const std::list<Node*>& nlist, Graph& g) {
	double strecke =0;
	int auswahl = 0;
	std::vector<Edge*> elist;
	std::deque<Edge*> path;

	std::cout << "Bitte waehlen Sie: "
		<< std::endl << "  [1] Strecke (in km) eingeben."
		<< std::endl << "  [2] Start und Zielpunkt auswaehlen."
		<< std::endl << "[0] zueruck" << std::endl;
	std::cout << "Aktion: ";
	std::cin >> auswahl;
	if (auswahl != 1 && auswahl != 2 && auswahl && auswahl != 0) {
		std::cout << "Fehler. Bitte erneut Aktion auswaehlen." << std::endl;
		auswahlStrecke(nlist, g);
	}
	else {
		switch (auswahl) {
		case 1:		std::cout << "Bitte Distanz eingeben: "; std::cin >> strecke;
			return strecke;
			break;
		case 2:		
					std::cin.clear();

					//Startpunkt wählen
					std::cout << "Bitte waehlen Sie einen Startpunkt: " << std::endl;
					printNodeList(nlist);
					std::cout << "Start: ";
					std::cin >> auswahl;
					Node *startNode;
					if (nlist.size() > auswahl-1) { std::list<Node*>::const_iterator it = std::next(nlist.begin(), auswahl-1); startNode = *it; }
					else { std::cout << "Fehler. Element nicht in Liste."; return 0; }
					std::cout << startNode->getID() << std::endl;

					//Endpunkt wählen
					std::cout << "Bitte waehlen Sie einen Endpunkt: " << std::endl;
					printNodeList(nlist);
					std::cout << "Ende: ";
					std::cin.clear();
					std::cin >> auswahl;
					Node *endNode;
					if (nlist.size() > auswahl-1) { std::list<Node*>::const_iterator it = std::next(nlist.begin(), auswahl-1); endNode = *it; }
					else { std::cout << "Fehler. Element nicht in Liste."; return 0; }
					std::cout << endNode->getID() << std::endl;

					//Liste verfügbarer Direktpfade
					elist = g.findEdges(*startNode, *endNode);

					//wenn keine Direktpfade, ermittel mit Dijkstra kürzesten Weg
					if (elist.empty()) {
						g.findShortestPathDijkstra(path, *startNode, *endNode);
						for (Edge* output : path) {
							std::cout << "\tDie kuerzeste Weg ist: " << output->toString() << std::endl;
							strecke += output->getWeight();
						}
					}
					//wenn Direktpfade, such dir doch einenen davon aus
					else {
						std::cout << "Bitte waehlen Sie: " << std::endl;
						printVector(elist);
						std::cout << std::endl;
						std::cout << "Edge: ";
						std::cin.clear();
						std::cin >> auswahl;
						if (elist.size() > auswahl - 1) { std::vector<Edge*>::iterator it = std::next(elist.begin(), auswahl - 1); std::cout << (*it)->toString() << std::endl; strecke = (*it)->getWeight(); }
					}

					std::cout << "Die Gesamt-Strecke betraegt " << strecke << "km." << std::endl;
					return strecke;

			break;
		case 0:		return 0;
			break;
		default:	std::cout << "Fehler. Erneut Aktion waehlen." << std::endl;
			auswahlStrecke(nlist, g);
		}
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}



/*removed since we use ID instead of string name
void UI::setTaxiName(Taxi *t) {
	std::string name;
	std::cout << "Enter your Taxiname: ";
	std::cin >> name;
	if (name.size() <= 8) {	t->setName(name); }
	else if (name.size() > 8) { std::cout << "Fehler. Name zu lang.\n" <<std::endl; }
}
*/