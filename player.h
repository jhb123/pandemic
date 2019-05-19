#include node.h

class player: public node{
	
	private:
		std::vector<int> hand;
	public:
		int move(node* start, node* end);
		int shareKnowledge(int);
		int buildResearchStation(int);
		int treatDisease(int);
		int discoverCure();


};

#endif