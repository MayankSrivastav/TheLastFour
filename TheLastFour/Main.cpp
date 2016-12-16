// This is the driver program of TheLastFour

#include <iostream>
#include "Player.h"
#include "TheLastFour.h"
using namespace std;

int main()
{
	// Initialize Players (Object). Add players as required
	Player p1("Kirat Boli", { 5, 30, 25, 10, 15, 1, 9, 5 });
	Player p2("NS Nodhi", { 10, 40, 20, 5, 10, 1, 4, 10 });
	Player p3("R Rumrah", { 20, 30, 15, 5, 5, 1, 4, 20 });
	Player p4("Shashi Henra", { 30, 25, 5, 0, 5, 1, 4, 30 });

	// Create a vector of Player of objects and pass to 
	// simulateMatch() function as an argument
	vector<Player> p({ p1, p2, p3, p4 });

	for (int i = 0; i < 50; ++i) {	// Test loop, to be removed //
		// Set all the members as required. 		
		TheLastFour sim;	
		sim.setRunsToScore(40);		// Number of runs to score
		sim.setWicketsLeft(3);		// Number of wickets left
		sim.setOversRemaining(4);	// Number of overs remaining
		
		// Get the finalScoreBoard (i.e. the result of the match)
		// by calling the simulateMatch() function
		vector<string> finalScoreBoard = sim.simulateMatch(p);

		// Display the finalScoreBoard (i.e. the result of the match)
		sim.displayFinalScoreBoard(finalScoreBoard);
	}
	return 0;
}