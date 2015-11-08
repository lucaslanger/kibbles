#include <stdio.h>
#include <string.h>

struct VideoGame{
	char title[50];
	char company[50];
	char version[50];
	int cost;
};

void printGameInfo(struct VideoGame vg){
	printf("%d dollars for Name: %s by: %s V: %s\n", vg.cost, vg.title, vg.company, vg.version);
}

int main(){
	struct VideoGame WOW;
	struct VideoGame League;

	strcpy( WOW.title, "World of Warcraft");
	strcpy( WOW.company, "Blizzard Entertainment");
	strcpy( WOW.version, "4.0");
	WOW.cost = 50;

	strcpy( League.title, "League of Legends");
	strcpy( League.company, "Riot Games");
	strcpy( League.version, "6.0");
	League.cost = 0;

	printGameInfo(WOW);
	printGameInfo(League);

	return 0;
}
