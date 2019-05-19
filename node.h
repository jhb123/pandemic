#ifndef NODE_H
#define NODE_H

#include <vector>
#include <utility>
#include <iostream>
#include <string> 

class node{
	
	private:
		int identity;
		std::string name;
		std::vector<std::pair<node*,unsigned int> > connections;
	
	public:
		node(std::string idWord, int id);
		void addConnection(node* n, unsigned int length);
		void addConnections(std::vector<std::pair< node*, unsigned int> >);
		void printConnections();
		std::vector<std::pair<node*,unsigned int> > getConnections();

		std::string getName();

};

#endif