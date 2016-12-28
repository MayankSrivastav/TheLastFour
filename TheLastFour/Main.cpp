// This is the driver program of TheLastFour

#include <iostream>
//#include "Player.h"
#include "ScoreCalculation.h"
using namespace std;

int main()
{
	// Initialize the current match summary
	int numberOfRunsToScore = 40;
	int wicketsLeft = 3;
	int oversRemaining = 4;

	vector<pair<string, discrete_distribution<int>>> players;
	pair<string, discrete_distribution<int>> p1 = { "Kirat Boli", { 5, 30, 25, 10, 15, 1, 9, 5 } };
	pair<string, discrete_distribution<int>> p2 = { "NS Nodhi", { 10, 40, 20, 5, 10, 1, 4, 10 } };
	pair<string, discrete_distribution<int>> p3 = { "R Rumrah", { 20, 30, 15, 5, 5, 1, 4, 20 } };
	pair<string, discrete_distribution<int>> p4 = { "Shashi Henra", { 30, 25, 5, 0, 5, 1, 4, 30 } };
	players.emplace_back(p1);
	players.emplace_back(p2);
	players.emplace_back(p3);
	players.emplace_back(p4);

	//for (int i = 0; i < 50; ++i) {	// Test loop, to be removed //
		// Set all the members as required. 	

		ScoreCalculation sim;
		sim.setRunsToScore(numberOfRunsToScore);	// Number of runs to score
		sim.setRunsToScoreNow(sim.getRunsToScore());
		sim.setWicketsLeft(wicketsLeft);			// Number of wickets left
		sim.setOversRemaining(oversRemaining);		// Number of overs remaining		
		sim.setPlayer1(0);
		sim.setPlayer2(1);
		sim.setNextPlayer(sim.getPlayer2() + 1);
		sim.setAtStrike(sim.getPlayer1());
		sim.setWonOrLost("yet to be decided");
		sim.setPlayer(players);
		
		string finalScoreBoard = to_string(oversRemaining) + " overs left. " +
										 to_string(numberOfRunsToScore) + " runs to win\n";
		sim.setScoreBoard(finalScoreBoard);


		// Get the finalScoreBoard (i.e. the result of the match)
		// by calling the simulateMatch() function
		sim.simulateMatch(sim);
	
		// Display the finalScoreBoard (i.e. the result of the match)
		sim.displayFinalScoreBoard();
	//}
	return 0;
}