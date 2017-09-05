#include "graph.h"

void graph::addNode(node* n){
	nodes.push_back(n);
}

void graph::connectNodes(node* n, node* m, unsigned int length){
	n->addConnection(m, length);
	m->addConnection(n, length);
}

void graph::printGraph(){
	std::vector<node*>::iterator iter;
	for(iter = nodes.begin(); iter != nodes.end(); ++iter){
		(*iter)->printConnections();
	}
}

std::vector<node*> graph::dijkstra(node* start, node* end){

	//create vector with node, distance, via - tuple! this is the tenetive stuff
	//set distance to maximum int
	//make checked vector.
	std::vector<std::tuple< node*,unsigned int,node*> >  tenetive;
	std::vector<std::tuple< node*,unsigned int,node*> > checked;

	bool exitFlag = false;

	unsigned int max = 0;
	max =~ max; //fun bit hacking

	//creation of tenetive vector
	for(auto iter = std::begin(nodes); iter != std::end(nodes); ++iter){
		if(*iter == start) tenetive.push_back(std::make_tuple(*iter,0,start));
		else tenetive.push_back(std::make_tuple(*iter,max,start));
	}

	//exit if smallest distance = max or end is marked as checked or
	while(!exitFlag){
		//make a heap
		std::make_heap(nodes.begin(),nodes.end(),comparison());

	}


	//for loop with 2 steps...
	//use make_heap
	//check nodes and update distance
	//put node into checked
	//check if end

	//if end follow the via pointers to get path


	return nodes; //place holder...
}