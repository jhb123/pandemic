#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>


struct comparison{
    bool operator()(const auto  &a,const auto &b) const{
        return a<1> > b<1>;
    }
};

class graph{
	
	private:
		std::vector<node*> nodes;

	public:
		void addNode(node* n);
		void connectNodes(node* n,node* m, unsigned int length);
		void printGraph();

		std::vector<node*> dijkstra(node* start, node* end);

};

#endif

