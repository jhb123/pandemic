#ifndef NODE_H
#define NODE_H

#include <vector>
#include <utility>
#include <iostream>
#include <string> 

class node{
	
	private:
		std::string name;
		std::vector<std::pair<node*,unsigned int> > connections;
	
	public:
		node(std::string identity);
		void addConnection(node* n, unsigned int length);
		void printConnections();
		std::string getName();

};

#endif