#include <iostream>
#include <string>
#include <list>
#include "UI.h"
#include "Taxi.h"
#include "Route.h"


int main() {
		
		/*
		UI ui = UI();
		double fuelCost = 1.55;
		Taxi *ptr[2];
		/*
		Taxi m1 = Taxi(7.2, 0.7, 75);
		ui.printTaxi(&m1);
		ptr[0] = &m1;
		Taxi m2 = Taxi(m1);
		m2.setCurrentTankful(17.677);
		ui.printTaxi(&m2);
		ptr[1] = &m2;
		ui.printTaxi(ptr[1]);
//AUSKOMMENTIERT ZU
		Taxi m1 = Taxi(7.2, 0.7, 75);
		ui.printTaxi(&m1);

		Taxi m2 = Taxi(12.5, 0.95, 90);
		ui.printTaxi(&m2);

		m1.bookTrip(100, true);
		m2.bookTrip(100, true);
		ui.printTaxi(&m1);
		ui.printTaxi(&m2);

		m1.bookTrip(10, false);
		m2.bookTrip(15, false);
		ui.printTaxi(&m1);
		ui.printTaxi(&m2);

		m1.fillUp(fuelCost);
		m2.fillUp(fuelCost);
		ui.printTaxi(&m1);
		ui.printTaxi(&m2);

		Graph *g = new Graph();
		Node *a = new Node();
		Node *b = new Node();
		Edge *e = new Edge(*a, *b);

		Node *one = new Node("10");
		Node *two = new Node("20");
		g->addNode(a);
		g->addNode(b);
		g->addEdge(e);
		g->addNode(one);
		g->addNode(two);
		Edge *d = new Edge(*one, *two);
		Edge *f = new Edge(*a, *one);

		g->addEdge(d);
		g->addEdge(f);

		while(true) {
			switch (ui.auswahlTaxi()) {
				case 1: ui.auswahlAktion(&m1,*g);
					break;
				case 2: ui.auswahlAktion(&m2, *g);
					break;
				case 0: return false;
					break;
				default: std::cout << "Falsche eingabe" << std::endl;
					return true;
			}

		}
		ui.printTaxi(&m1);
		ui.printTaxi(&m2);
		*/
/*********************************************************************************/

/*********************************************************************************/
	
/*********************************************************************************/
	
/*********************************************************************************/
	
	UI *ui = new UI();
	Graph *berlin = new Graph();
	Taxi *m1 = new Taxi(7.2, 0.7, 75);
	Taxi *m2 = new Taxi(12.5, 0.95, 90);
	
	Node *alexanderplatz = new Node("Alexanderplatz");
	Node *funkturm = new Node("Funkturm");
	Node *strandbadWannsee = new Node("Strandbad Wannsee");
	Node *brandenburgerTor = new Node("Brandenburger Tor");
	Node *ostkreuz = new Node("Ostkreuz");
	Node *regattastreckeGruenau = new Node("Regattastrecke Gruenau");
	Node *grenzallee = new Node("Grenzallee");
	Node *zitadelleSpandau = new Node("Zitadelle Spandau");
	
	Route *berlinEins = new Route(*alexanderplatz, *funkturm, 10.2);
	Route *berlinZwei = new Route(*funkturm, *strandbadWannsee, 11.2);
	Route *berlinDrei = new Route(*strandbadWannsee, *brandenburgerTor, 18.0);
	Route *berlinVier = new Route(*brandenburgerTor, *alexanderplatz, 2.3);
	Route *berlinFuenf = new Route(*alexanderplatz, *ostkreuz, 6.2);
	Route *berlinSechs = new Route(*ostkreuz, *regattastreckeGruenau, 14.6);
	Route *berlinSieben = new Route(*regattastreckeGruenau, *grenzallee, 12.8);
	Route *berlinAcht = new Route(*grenzallee, *alexanderplatz, 11.2);
	Route *berlinNeun = new Route(*grenzallee, *funkturm, 14.9);
	Route *berlinZehn = new Route(*funkturm, *zitadelleSpandau, 8.5);

	berlin->addNode(alexanderplatz);
	berlin->addNode(funkturm);
	berlin->addNode(strandbadWannsee);
	berlin->addNode(brandenburgerTor);
	berlin->addNode(ostkreuz);
	berlin->addNode(regattastreckeGruenau);
	berlin->addNode(grenzallee);
	berlin->addNode(zitadelleSpandau);

	berlin->addEdge(berlinEins);
	berlin->addEdge(berlinZwei);
	berlin->addEdge(berlinDrei);
	berlin->addEdge(berlinVier);
	berlin->addEdge(berlinFuenf);
	berlin->addEdge(berlinSechs);
	berlin->addEdge(berlinSieben);
	berlin->addEdge(berlinAcht);
	berlin->addEdge(berlinNeun);
	berlin->addEdge(berlinZehn);

	ui->printNodeList(berlin->getNodes());
	ui->printEdgeList(berlin->getEdges());

	ui->printTaxi(m1);
	ui->printTaxi(m2);

	while (true) {
		switch (ui->auswahlTaxi()) {
		case 1: ui->auswahlAktion(m1, *berlin);
			break;
		case 2: ui->auswahlAktion(m2, *berlin);
			break;
		case 0: return false;
			break;
		default: std::cout << "Falsche eingabe" << std::endl;
			return true;
		}
	}


	//TEST DJIKSTRA

		/*
		Node* testDijkstraEins = new Node();
		Node* testDijkstraZwei = new Node();
		Node* testDijkstraDrei = new Node();
		Node* testDijkstraVier = new Node();
		Node* testDijkstraFuenf = new Node();

		Graph testDick;

		testDick.addNode(testDijkstraEins);
		testDick.addNode(testDijkstraZwei);
		testDick.addNode(testDijkstraDrei);
		testDick.addNode(testDijkstraVier);
		testDick.addNode(testDijkstraFuenf);

		testDick.addEdge(new Edge(*testDijkstraEins, *testDijkstraZwei));
		testDick.addEdge(new Edge(*testDijkstraEins, *testDijkstraDrei));
		testDick.addEdge(new Edge(*testDijkstraZwei, *testDijkstraDrei));
		testDick.addEdge(new Edge(*testDijkstraDrei, *testDijkstraFuenf));
		testDick.addEdge(new Edge(*testDijkstraVier, *testDijkstraFuenf));

		std::deque<Edge*> path;

		testDick.findShortestPathDijkstra(path,*testDijkstraEins,*testDijkstraFuenf);

		for (Edge* output : path) {
			std::cout << "shortes path :" << output->toString() << std::endl << std::endl;
		}
		*/
//		delete testDijkstraEins, testDijkstraZwei, testDijkstraDrei, testDijkstraVier, testDijkstraFuenf;
		//TEST DJIKSTRA ENDE


	/*
		*Wird ein Konstruktor, der nicht der Standard-Konstruktor ist, erstellt / angegeben,
		* 'verfaellt' der Standardkonstruktor - es wird in Visual Studio gehandhabt, wie eine
		*fehlerhafte Eingabe - mit dem Fehler: "Kein geeigneter Standardkonstruktor erfügbar".
	*/
		system("pause");
		return 0;
	}

