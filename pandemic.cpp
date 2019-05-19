#include <iostream>
#include <cstdarg>
#include "graph.h"
#include "node.h"
#include <string>
#include "trio.h"
#include "pandemicBoard.h"

int main(){
	
	std::cout<<"Welcome to pandemic v.0.4- now with dijkstra!\n";
	//create cities
	std::vector<node*> cities;

	for(int i = sanFrancisco; i <= johannesburg; ++i){
		node* minisTirithCityOfTheGuard = new node(getTextForEnum(i),i); //create cities on the heap
		cities.push_back(minisTirithCityOfTheGuard);
	}

	//put cities in the world, nothing interesting here
	graph world;
	world.addNodes(cities);
	//time to get janky, this is done with pen and paper, avoid double counting connections!
	//connections to sanfran:
	//define the connections in a vector of pairs, then pass this to the world
	std::vector< std::pair< node*, unsigned int> > sanFranciscoConnections = {
		std::make_pair(cities[tokyo],1),std::make_pair(cities[manila],1),std::make_pair(cities[losAngeles],1),std::make_pair(cities[chicago],1)};
	world.connectNodes(cities[sanFrancisco],sanFranciscoConnections);
	//connections to chicago
	std::vector< std::pair< node*, unsigned int> > chicagoConnections = {
		std::make_pair(cities[losAngeles],1),std::make_pair(cities[atlanta],1),std::make_pair(cities[mexicoCity],1),std::make_pair(cities[montreal],1)};
	world.connectNodes(cities[chicago],chicagoConnections);
	//connections to montreal
	std::vector< std::pair< node*, unsigned int> > montrealConnections = {
		std::make_pair(cities[newYork],1),std::make_pair(cities[washington],1)};
	world.connectNodes(cities[montreal],montrealConnections);
	//connections to atlanta
	std::vector< std::pair< node*, unsigned int> > atlantaConnections = {
		std::make_pair(cities[washington],1),std::make_pair(cities[miami],1)};
	world.connectNodes(cities[atlanta],atlantaConnections);
	//connections to washington
	std::vector< std::pair< node*, unsigned int> > washingtonConnections = {
		std::make_pair(cities[miami],1),std::make_pair(cities[newYork],1)};
	world.connectNodes(cities[washington],washingtonConnections);	
	//connections to new York
	std::vector< std::pair< node*, unsigned int> > newYorkConnections = {
		std::make_pair(cities[london],1),std::make_pair(cities[madrid],1)};
	world.connectNodes(cities[newYork],newYorkConnections);
	//connections to london
	std::vector< std::pair< node*, unsigned int> > londonConnections = {
		std::make_pair(cities[essen],1),std::make_pair(cities[madrid],1),std::make_pair(cities[paris],1)};
	world.connectNodes(cities[london],londonConnections);
	//connections to madrid
	std::vector< std::pair< node*, unsigned int> > madridConnections = {
		std::make_pair(cities[saoPaulo],1),std::make_pair(cities[paris],1),std::make_pair(cities[algiers],1)};
	world.connectNodes(cities[madrid],madridConnections);
	//connections to paris
	std::vector< std::pair< node*, unsigned int> > parisConnections = {
		std::make_pair(cities[essen],1),std::make_pair(cities[milan],1),std::make_pair(cities[algiers],1)};
	world.connectNodes(cities[paris],parisConnections);
	//connections to essen
	std::vector< std::pair< node*, unsigned int> > essenConnections = {
		std::make_pair(cities[stPetersburg],1),std::make_pair(cities[milan],1)};
	world.connectNodes(cities[essen],essenConnections);
	//connections to milan
	std::vector< std::pair< node*, unsigned int> > milanConnections = {
		std::make_pair(cities[istanbul],1)};
	world.connectNodes(cities[milan],milanConnections);
	//connections to stPetersburg
	std::vector< std::pair< node*, unsigned int> > stPetersburgConnections = {
		std::make_pair(cities[moscow],1),std::make_pair(cities[istanbul],1)};
	world.connectNodes(cities[stPetersburg],stPetersburgConnections);
	//connections to algiers
	std::vector< std::pair< node*, unsigned int> > algiersConnections = {
		std::make_pair(cities[istanbul],1),std::make_pair(cities[cairo],1)};
	world.connectNodes(cities[algiers],algiersConnections);
	//connections to moscow
	std::vector< std::pair< node*, unsigned int> > moscowConnections = {
		std::make_pair(cities[istanbul],1),std::make_pair(cities[tehran],1)};
	world.connectNodes(cities[moscow],moscowConnections);
	//connections to istanbul
	std::vector< std::pair< node*, unsigned int> > istanbulConnections = {
		std::make_pair(cities[baghdad],1),std::make_pair(cities[cairo],1)};		
	world.connectNodes(cities[istanbul],istanbulConnections);
	//connections to cairo
	std::vector< std::pair< node*, unsigned int> > cairoConnections = {
		std::make_pair(cities[baghdad],1),std::make_pair(cities[riyadh],1)};
	world.connectNodes(cities[cairo],cairoConnections);
	//connections to baghdad
	std::vector< std::pair< node*, unsigned int> > baghdadConnections = {
		std::make_pair(cities[tehran],1),std::make_pair(cities[karachi],1),std::make_pair(cities[riyadh],1)};
	world.connectNodes(cities[baghdad],baghdadConnections);
	//connections to tehran
	std::vector< std::pair< node*, unsigned int> > tehranConnections = {
		std::make_pair(cities[karachi],1),std::make_pair(cities[delhi],1)};
	world.connectNodes(cities[tehran],tehranConnections);
	//connections to karachi
	std::vector< std::pair< node*, unsigned int> > karachiConnections = {
		std::make_pair(cities[riyadh],1),std::make_pair(cities[delhi],1),std::make_pair(cities[mumbai],1)};
	world.connectNodes(cities[karachi],karachiConnections);
	//connections to mumbai
	std::vector< std::pair< node*, unsigned int> > mumbaiConnections = {
		std::make_pair(cities[chennai],1),std::make_pair(cities[delhi],1)};
	world.connectNodes(cities[mumbai],mumbaiConnections);
	//connections to chennai
	std::vector< std::pair< node*, unsigned int> > chennaiConnections = {
		std::make_pair(cities[delhi],1),std::make_pair(cities[kolkata],1),std::make_pair(cities[bangkok],1)};
	world.connectNodes(cities[chennai],chennaiConnections);		
	//connections to kolkata
	std::vector< std::pair< node*, unsigned int> > kolkataConnections = {
		std::make_pair(cities[delhi],1),std::make_pair(cities[bangkok],1),std::make_pair(cities[hongKong],1)};
	world.connectNodes(cities[kolkata],kolkataConnections);
	//connections to bangkok
	std::vector< std::pair< node*, unsigned int> > bangkokConnections = {
		std::make_pair(cities[hongKong],1),std::make_pair(cities[hoChiMinCity],1),std::make_pair(cities[jakarta],1)};
	world.connectNodes(cities[bangkok],bangkokConnections);
	//connections to jakarta
	std::vector< std::pair< node*, unsigned int> > jakartaConnections = {
		std::make_pair(cities[chennai],1),std::make_pair(cities[hoChiMinCity],1),std::make_pair(cities[sydney],1)};
	world.connectNodes(cities[jakarta],jakartaConnections);
	//connections to sydney
	std::vector< std::pair< node*, unsigned int> > sydneyConnections = {
		std::make_pair(cities[manila],1),std::make_pair(cities[losAngeles],1)};
	world.connectNodes(cities[sydney],sydneyConnections);
	//connections to manila
	std::vector< std::pair< node*, unsigned int> > manilaConnections = {
		std::make_pair(cities[hoChiMinCity],1),std::make_pair(cities[hongKong],1),std::make_pair(cities[taipei],1)};
	world.connectNodes(cities[manila],manilaConnections);
	//connections to hongKong
	std::vector< std::pair< node*, unsigned int> > hongKongConnections = {
		std::make_pair(cities[taipei],1),std::make_pair(cities[shanghai],1),std::make_pair(cities[hoChiMinCity],1)};
	world.connectNodes(cities[hongKong],hongKongConnections);
	//connections to shanghai
	std::vector< std::pair< node*, unsigned int> > shanghaiConnections = {
		std::make_pair(cities[beijing],1),std::make_pair(cities[seoul],1),std::make_pair(cities[tokyo],1),std::make_pair(cities[taipei],1)};
	world.connectNodes(cities[shanghai],shanghaiConnections);
	//connections to seoul
	std::vector< std::pair< node*, unsigned int> > seoulConnections = {
		std::make_pair(cities[beijing],1),std::make_pair(cities[tokyo],1)};
	world.connectNodes(cities[seoul],seoulConnections);
	//connections to tokyo
	std::vector< std::pair< node*, unsigned int> > tokyoConnections = {
		std::make_pair(cities[osaka],1)};
	world.connectNodes(cities[tokyo],tokyoConnections);
	//connections to osaka
	std::vector< std::pair< node*, unsigned int> > osakaConnections = {
		std::make_pair(cities[taipei],1)};
	world.connectNodes(cities[osaka],osakaConnections);
	//connections to khartoum
	std::vector< std::pair< node*, unsigned int> > khartoumConnections = {
		std::make_pair(cities[cairo],1),std::make_pair(cities[lagos],1),std::make_pair(cities[kinshasa],1),std::make_pair(cities[johannesburg],1)};
	world.connectNodes(cities[khartoum],khartoumConnections);
	//connections to kinshasa
	std::vector< std::pair< node*, unsigned int> > kinshasaConnections = {
		std::make_pair(cities[lagos],1),std::make_pair(cities[johannesburg],1)};
	world.connectNodes(cities[kinshasa],kinshasaConnections);
	//connections to bogota
	std::vector< std::pair< node*, unsigned int> > bogotaConnections = {
		std::make_pair(cities[miami],1),std::make_pair(cities[mexicoCity],1),std::make_pair(cities[lima],1),std::make_pair(cities[buenosAires],1),std::make_pair(cities[saoPaulo],1)};
	world.connectNodes(cities[bogota],bogotaConnections);
	//connections to saoPaulo
	std::vector< std::pair< node*, unsigned int> > saoPauloConnections = {
		std::make_pair(cities[buenosAires],1),std::make_pair(cities[lagos],1)};
	world.connectNodes(cities[saoPaulo],saoPauloConnections);
	//connections to lima
	std::vector< std::pair< node*, unsigned int> > limaConnections = {
		std::make_pair(cities[mexicoCity],1),std::make_pair(cities[santiago],1)};
	world.connectNodes(cities[lima],limaConnections);
	//connections to mexicoCity
	std::vector< std::pair< node*, unsigned int> > mexicoCityConnections = {
		std::make_pair(cities[miami],1),std::make_pair(cities[losAngeles],1)};
	world.connectNodes(cities[mexicoCity],mexicoCityConnections);


	//now the cities have been set up...

	world.dijkstra(cities[santiago],cities[moscow]);

	cities.erase(cities.begin(),cities.end()); //free up memory



	return 0;
}