# pandemic
## Current features
All that is in this is the ability to find the shortest path between stuff, but there is a bit of infrastructure to add the other features.
### pandemic.cpp 
contains main, and is currently just a place where I test stuff. Right now there is a way of testing how to make a map with cities on it, and testing the path finding between the cities. 
### pandemicBoard.h
this is a bunch of enums that makes setting up the board easier. i.e. comparisons between strings is harder than comparisons bewteen integers
### node.cpp and node.h
A node is an object that has an identity (e.g. player, city) that forms connections with other nodes. It has methods associated with making and destroying connections.
### player.h
A player is a special node that has cards and can do things like cure etc.
### graph.cpp and graph.h
A graph has a vector of node pointers, which allows it to use the nodes functions (can connect the nodes for instance). It also has a pathfinding algorithm to find the distance between 2 nodes in the graph. Its basically a way of managing the nodes
### trio.h
This is a template, like the pair in the standard libary, I've forgotten how this works but there probably is a good example of how to implement a pair using the template stuff in c++

## Stuff to add
### a make file would be nice
### a cities object that can have disease functions (e.g. city.infect(yellow) type behaviour)
### turn sequence (events, drawing cards etc.)


