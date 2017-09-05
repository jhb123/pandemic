#include <iostream>
#include "graph.h"
#include "node.h"
#include <string>

int main(){
	
	std::cout<<"Welcome to pandemic v.0.2 - now with a graph\n";

	node alpha("alpha");
	node beta("beta");
	node gamma("gamma");
	node delta("delta");

	graph world;

	world.addNode(&alpha);
	world.addNode(&beta);
	world.addNode(&gamma);
	world.addNode(&delta);

	world.connectNodes(&alpha,&gamma,1);
	world.connectNodes(&alpha,&beta,5);
	world.connectNodes(&beta,&gamma,2);
	world.connectNodes(&beta,&delta,3);

	world.printGraph();
	world.dijkstra(&alpha,&beta);

	return 0;
}
