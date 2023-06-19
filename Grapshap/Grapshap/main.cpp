#include "Graph.h"

int main() {
	Graph prim;

	/* Obican graf */
	prim.insertNode(1);
	prim.insertNode(2);
	prim.insertNode(3);
	prim.insertNode(4);
	prim.insertNode(5);
	prim.insertNode(6, false);
	prim.insertNode(7);
	prim.insertNode(8);
	prim.insertNode(9);
	prim.insertEdge(1, 2, 7);
	prim.insertEdge(1, 3, 5);
	prim.insertEdge(1, 4, 9);
	prim.insertEdge(2, 5, 4);
	prim.insertEdge(2, 6, 5);
	prim.insertEdge(3, 6, 3);
	prim.insertEdge(4, 7, 4);
	prim.insertEdge(5, 8, 7);
	prim.insertEdge(5, 9, 3);
	prim.insertEdge(6, 5, 2);
	prim.insertEdge(6, 9, 6);
	prim.insertEdge(7, 9, 7);
	prim.insertEdge(8, 9, 6);
	prim.insertEdge(9, 1, 10);

	/* Disjunktni graf */
	//prim.insertNode(0);
	//prim.insertNode(1);
	//prim.insertNode(2);
	//prim.insertNode(3);
	//prim.insertNode(4);
	//prim.insertNode(5);
	//prim.insertNode(6);
	//prim.insertNode(7);
	//prim.insertNode(8);
	//prim.insertNode(9);
	//prim.insertNode(10);
	//prim.insertNode(11);
	//prim.insertNode(12);
	//prim.insertNode(13);
	//prim.insertEdge(0, 6);
	//prim.insertEdge(0, 11);
	//prim.insertEdge(6, 0);
	//prim.insertEdge(6, 2);
	//prim.insertEdge(6, 5);
	//prim.insertEdge(5, 6);
	//prim.insertEdge(2, 6);
	//prim.insertEdge(2, 8);
	//prim.insertEdge(8, 2);
	//prim.insertEdge(8, 11);
	//prim.insertEdge(11, 0);
	//prim.insertEdge(11, 8);
	//prim.insertEdge(1, 7);
	//prim.insertEdge(7, 1);
	//prim.insertEdge(3, 4);
	//prim.insertEdge(3, 9);
	//prim.insertEdge(4, 3);
	//prim.insertEdge(4, 10);
	//prim.insertEdge(10, 4);
	//prim.insertEdge(10, 13);
	//prim.insertEdge(13, 10);
	//prim.insertEdge(13, 9);
	//prim.insertEdge(9, 13);
	//prim.insertEdge(9, 3);
	//prim.insertEdge(0, 2);
	//prim.insertEdge(2, 0);

	//prim.insertEdge(13, 1);
	//prim.insertEdge(1, 13);

	///* Dopuna do povezanog */
	////prim.insertEdge(0, 3);
	////prim.insertEdge(3, 0);
	////prim.insertEdge(0, 1);
	////prim.insertEdge(1, 0);
	////prim.insertEdge(0, 12);
	////prim.insertEdge(12, 0);

	prim.print();
	//cout << prim.getMaxConnectionsDisjointSubgraph();
	//cout << prim.numOfSameFlights(prim.findNode(4), prim.findNode(7), prim.findNode(5));
	//prim.connectGraph();
	//prim.connectGraphOptimal();
	//cout << prim.pathExists(prim.findNode(1), prim.findNode(7), prim.findNode(4), prim.findNode(7));
	//cout << prim.BridgeCount(2, 4);
	//cout << prim.brStanica(prim.findNode(1), prim.findNode(9), 8);
	//int brPresedalja;
	//prim.boljiPut(prim.findNode(1), prim.findNode(7), prim.findNode(5), 7, &brPresedalja)->visit();
	//cout << brPresedalja;
	//cout << prim.getTownName();
	//cout << prim.reachableInNHoops(prim.findNode(1), 2);
	//cout << prim.canReachMoreWithUndirrected(prim.findNode(1)) << endl;
	//cout << endl;
	//prim.print();
	//cout << prim.numberOfConnections(1, 9);
	prim.obidjiSveMoguce(1);


	//prim.dijkstra(1);
	//GraphNode* temp = prim.start;
	//while (temp != 0) {
	//	cout << temp->key << " " << temp->distance << endl;
	//	temp = temp->next;
	//}

	//int* arPath = new int[10];
	//int lPath = 0;
	//prim.findPath(1, 8, arPath, & lPath);
	//cout << lPath << endl;
	//for (int i = lPath - 1; i >= 0; i--)
	//	cout << arPath[i] << " ";
	
	//cout << endl;
	//prim.breadthTrav(1);
	//cout << endl;
	//prim.iterativeDepthTrav(1);
	//cout << endl;
	//prim.recursiveDepthTrav(1);
	//cout << endl;
	//prim.topologicalTrav();

}