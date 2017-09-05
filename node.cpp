#include "node.h"

void node::addConnection(node* n, unsigned int length){
	std::pair< node*, unsigned int> connection (n,length);
	connections.push_back(connection);
}

node::node(std::string identity): name(identity){
//ben would be proud
}

void node::printConnections(){
	std::cout<< name << " is connected to: \n";
	for(auto iter = std::begin(connections); iter != std::end(connections); ++iter){
		std::cout<< "name: " << (*iter).first->getName() << ". Distance: " << (*iter).second <<"\n";
	}
	std::cout<<std::endl;
}

std::string node::getName(){
	return name;
}