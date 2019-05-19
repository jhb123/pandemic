#include "node.h"

void node::addConnection(node* n, unsigned int length){
	std::pair< node*, unsigned int> connection (n,length);
	connections.push_back(connection);
}

void node::addConnections(std::vector<std::pair< node*, unsigned int> > cities){
	for(auto iter = cities.begin(); iter != cities.end(); ++iter){
		addConnection(iter->first,iter->second);
	}
}

node::node(std::string idWord, int id): name(idWord),identity(id){
//ben would be proud
}

void node::printConnections(){
	std::cout<< name << " is connected to: \n";
	for(auto iter = std::begin(connections); iter != std::end(connections); ++iter){
		std::cout<< "name: " << (*iter).first->name << ". Distance: " << (*iter).second <<"\n";
	}
	std::cout<<std::endl;
}

std::string node::getName(){
	return name;
}

std::vector<std::pair<node*,unsigned int> > node::getConnections(){
	return connections;
}