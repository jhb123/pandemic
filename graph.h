#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "trio.h"

struct compare{ //functor fun for the heap sort
	bool operator()(const trio< node*,node*, unsigned int> &a, const trio< node*,node*, unsigned int> &b) const{
		return a.third > b.third;
	}
};

class graph{
	
	private:
		std::vector<node*> nodes;

	public:
		void addNode(node* n);
		void addNodes(std::vector<node*>);
		void connectNodes(node* n,node* m, unsigned int length);
		void connectNodes(node* n, std::vector<std::pair< node*, unsigned int> > cities);
		void disconnectNodes(node* n, node* m, unsigned int length);
		void printGraph();

		std::vector<node*> dijkstra(node* start, node* end);

};

#endif

