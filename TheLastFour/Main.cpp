// This is the driver program of TheLastFour

#include <iostream>
#include "Player.h"
#include "TheLastFour.h"
using namespace std;

int main()
{
	// Initialize Players (Object) with player probabilities. 
	// Add players as required
	Player p1("Kirat Boli", { 5, 30, 25, 10, 15, 1, 9, 5 });
	Player p2("NS Nodhi", { 10, 40, 20, 5, 10, 1, 4, 10 });
	Player p3("R Rumrah", { 20, 30, 15, 5, 5, 1, 4, 20 });
	Player p4("Shashi Henra", { 30, 25, 5, 0, 5, 1, 4, 30 });

	// Create a vector of Player objects and pass to 
	// simulateMatch() function as an argument
	vector<Player> p({ p1, p2, p3, p4 });

	// Initialize the current match summary
	int numberOfRunsToScore = 40;
	int wicketsLeft = 3;
	int oversRemaining = 4;

	for (int i = 0; i < 10; ++i) {	// Test loop, to be removed //
		// Set all the members as required. 		
		TheLastFour sim;	
		sim.setRunsToScore(numberOfRunsToScore);	// Number of runs to score
		sim.setWicketsLeft(wicketsLeft);			// Number of wickets left
		sim.setOversRemaining(oversRemaining);		// Number of overs remaining
		
		vector<string> finalScoreBoard = { to_string(oversRemaining) + " overs left. " + to_string(numberOfRunsToScore) + " runs to win" };
		sim.setScoreBoard(finalScoreBoard);

		// Get the finalScoreBoard (i.e. the result of the match)
		// by calling the simulateMatch() function
		finalScoreBoard = sim.simulateMatch(p);

		// Display the finalScoreBoard (i.e. the result of the match)
		sim.displayFinalScoreBoard(finalScoreBoard);
	}
	return 0;
}