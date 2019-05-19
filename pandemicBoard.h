//theres nothing pretty here :()
enum pandemicWords{
	//blue
	sanFrancisco,
	chicago,
	atlanta,
	montreal,
	washington,
	newYork,
	london,
	madrid,
	paris,
	essen,
	milan,
	stPetersburg,

	//black 
	algiers,
	istanbul,
	moscow,
	cairo,
	baghdad,
	tehran,
	riyadh,
	karachi,
	delhi,
	mumbai,
	kolkata,
	chennai,

	//red 
	beijing,
	seoul,
	shanghai,
	tokyo,
	hongKong,
	taipei,
	osaka,
	bangkok,
	hoChiMinCity,
	manila,
	jakarta,
	sydney,

	//yellow 
	losAngeles,
	mexicoCity,
	miami,
	bogota,
	lima,
	saoPaulo,
	santiago,
	buenosAires,
	lagos,
	khartoum,
	kinshasa,
	johannesburg,

	//colours
	blue,
	black,
	red,
	yellow,
};
//Handy trick from stack over flow
static const char * EnumStrings[] = {
	//blue
	"San Francisco",
	"Chicago",
	"Atlanta",
	"Montreal",
	"Washington",
	"NewYork",
	"London",
	"Madrid",
	"Paris",
	"Essen",
	"Milan",
	"St Petersburg",

	//black 
	"Algiers",
	"Istanbul",
	"Moscow",
	"Cairo",
	"Baghdad",
	"Tehran",
	"Riyadh",
	"Karachi",
	"Delhi",
	"Mumbai",
	"Kolkata",
	"Chennai",

	//red 
	"Beijing",
	"Seoul",
	"Shanghai",
	"Tokyo",
	"Hong Kong",
	"Taipei",
	"Osaka",
	"Bangkok",
	"Ho Chi Min City",
	"Manila",
	"Jakarta",
	"Sydney",

	//yellow 
	"los Angeles",
	"Mexico City",
	"Miami",
	"Bogota",
	"Lima",
	"Sao Paulo",
	"Santiago",
	"BuenosAires",
	"Lagos",
	"Khartoum",
	"Kinshasa",
	"Johannesburg",

	//colours
	"blue",
	"black",
	"red",
	"yellow" };

const char * getTextForEnum( int enumVal )
{
  return EnumStrings[enumVal];
}