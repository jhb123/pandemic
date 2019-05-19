#include "graph.h"

//dijkstra needs to have none connected nodes capabilities.

void graph::addNode(node* n){
	nodes.push_back(n);
}

void graph::addNodes(std::vector<node*> n){
	nodes.insert(nodes.end(),n.begin(),n.end());
}

void graph::connectNodes(node* n, node* m, unsigned int length){
	n->addConnection(m, length);
	m->addConnection(n, length);
}

void graph::connectNodes(node* n, std::vector<std::pair< node*, unsigned int> > cities){
	for(auto iter = cities.begin(); iter != cities.end(); ++iter){
		connectNodes(n,iter->first,iter->second);
	}
}

void graph::printGraph(){
	std::vector<node*>::iterator iter;
	for(iter = nodes.begin(); iter != nodes.end(); ++iter){
		(*iter)->printConnections();
	}
}

void graph::disconnectNodes(node* n, node* m, unsigned int length){
	n->addConnection(m, length);
	m->addConnection(n, length);
}

std::vector<node*> graph::dijkstra(node* start, node* end){

	//create vector with node, via, distance - trio! this is tenetive stuff
	//the first node represents 'itself', the second node represents where
	//to come from to get there, and the unsigned int represents the distance
	std::vector<trio< node*,node*, unsigned int> >  tenetive; //to be checked
	std::vector<trio< node*,node*, unsigned int> > checked; //already checked

	//step 1 ------------------------------------------------------------------
	//theres is probably an include that could do this, but that is less fun
	unsigned int max = ~(uint)0;

	//set up the tenetive vector so all the none starting nodes are max distance
	for(auto iter = nodes.begin(); iter != nodes.end(); ++iter){
		if(*iter == start) tenetive.push_back(make_trio(*iter,start, (uint)0));
		else tenetive.push_back(make_trio(*iter,start,max));
	}
	//fun with the functor, it is to compare the ints in the trio
	// (im not sure how this works honestly)
	std::make_heap(tenetive.begin(),tenetive.end(),compare());
	std::sort_heap(tenetive.begin(),tenetive.end(),compare());


	//step 2 and 3 ------------------------------------------------------------
	while(true){ //this keeps going until the node* being checked is the destination
		if(tenetive.back().first == end){
			checked.push_back(tenetive.back());
			tenetive.pop_back();
			break;
		}

		/*
		//print out the tenetive vector state
		std::cout<<"====tenetive vector====\n"; 
		for(auto iter = tenetive.begin(); iter != tenetive.end(); ++iter){
			std::cout<< "node: "<<(*iter).first->getName() << "\t via:"
			<< (*iter).second->getName() << "\t distance: "
			<< (*iter).third << std::endl;
		}
		std::cout<<std::endl;
		*/
		//look at nodes connected to first tenetive node.
		auto currentNode = tenetive.back().first->getConnections(); //god save the auto keyword
		//update vias and distance
		for(auto iter = currentNode.begin(); iter != currentNode.end(); ++iter){
			for(auto jiter = tenetive.begin(); jiter != tenetive.end(); ++jiter){
				if(jiter->first == iter->first ){ //find node in tenetive list
					if(jiter->third > iter->second + tenetive.back().third){ //is it closer than the current distance?
						jiter->second = tenetive.back().first; //update via
						jiter->third = iter->second + tenetive.back().third; //update distance
					}
				}
			}
		}

		checked.push_back(tenetive.back());
		//the trio which has just been checked gets put in the checked vector
		tenetive.pop_back();
		//the trio which has just been checked gets removed from the tenetive vector
		std::make_heap(tenetive.begin(),tenetive.end(),compare());
		//this reorgansises the tenetive vector into a heap so that it can be sorted
		//compare is a functor that looks at the third entry in the trio
		std::sort_heap(tenetive.begin(),tenetive.end(),compare());
		//this sorts it so that the smallest value is at the bottom.


	}

	//step 4 ------------------------------------------------------------------
	//trace the route back through
	//std::vector< trio<node*,node*,distance> >  \\node via distance
	std::vector<node*> path;
	path.push_back(end);
/*
	std::cout<<"====checked vector====\n"; 
	for(auto iter = checked.begin(); iter != checked.end(); ++iter){
		std::cout<< "node: "<<(*iter).first->getName() << "\t via:"
		<< (*iter).second->getName() << "\t distance: "
		<< (*iter).third << std::endl;
	}
*/
	trio<node*,node*,unsigned int>* tracer = &checked.back();

	while(tracer->first != start){
		for(auto iter = checked.begin(); iter != checked.end();++iter){
			if(	tracer->second == iter->first){
				path.push_back(iter->first);
				tracer = &(*iter); //boo!
			}
		}
	
	}

	std::cout<<"path from "<< start->getName() << " to " << end->getName() <<" has cost "<< checked.back().third<<"\n";
	for(auto iter = path.rbegin(); iter !=path.rend(); ++iter){
		std::cout<< (*iter)->getName()<< ", ";
	}
	std::cout<<std::endl;

	return path;
}