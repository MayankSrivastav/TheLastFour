// This is the class definition file for TheLastFour class

#ifndef THELASTFOUR_H
#define THELASTFOUR_H

//#include "Player.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

class ScoreCalculation;	
class TheLastFour
{
private:
	int runsToScore;	// Number of runs to score 
	vector<pair<string, discrete_distribution<int>>> player;	// player variable, stores the player object

protected:	
	int atStrike;			// Current player at the strikers end
	int nextPlayer;			// Player to come next after a player is out
	int player1, player2;	// Current two players in the middle
	int wicketsLeft;		// Number of wickets left now
	int oversRemaining;		// Overs remaining now
	string wonOrLost;		// Lengaburu won or lost the match
	string scoreBoard;		// Current score board of the match

public:	
	TheLastFour();

	TheLastFour(int runsToScore, vector<pair<string, discrete_distribution<int>>> player,
		int player1, int player2, int nextPlayer, int atStrike, int wicketsLeft, int oversRemaining,
		string wonOrLost, string scoreBoard);

	// This funtion sets the number of runs to score
	void setRunsToScore(const int& runsToScore);

	// This function returns the number of runs to score
	int getRunsToScore() const;

	// This function sets the current player at strike
	void setAtStrike(const int& atStrike);

	// This function gets the current player at strike
	int getAtStrike() const;

	// This function sets the one of two players
	void setPlayer1(const int& player1);

	// This function gets the one of two players
	int getPlayer1() const;

	// This function sets the one of two players
	void setPlayer2(const int& player2);

	// This function gets the one of two players
	int getPlayer2() const;

	// This function specifies which player will
	// play next after some player gets out
	void setNextPlayer(const int& nextPlayer);

	// This function gets the next player
	int getNextPlayer() const;

	// This function sets the number of wickets left
	void setWicketsLeft(const int& wicketsLeft);

	// This function returns the number of wickets left
	int getWicketsLeft() const;

	// This function sets the number of overs remaining
	void setOversRemaining(const int& oversRemaining);

	// This function gets the number of overs remaining
	int getOverRemaining() const;

	// This function sets the current score board
	void setScoreBoard(const string& scoreBoard);

	// This function gets the current score board
	string getScoreBoard() const;

	// This function sets the player object. This
	// defines the players and their probabilities
	void setPlayer(const vector<pair<string, discrete_distribution<int>>>& players);

	// This function gets the player object
	vector<pair<string, discrete_distribution<>>> getPlayer() const;

	// This function finally sets the status of 
	// the match. i.e. if Lengaburu won or lost
	void setWonOrLost(const string& wonOrLost);

	// This function gets the status of the 
	// match, i.e. if Lengaburu won or lost
	string getWonOrLost() const;

	// This is the main function to start simulation of the match based
	// on the given parameters. 
	// Returns the result of the match simulation.
	void simulateMatch(ScoreCalculation&);
};

#endif
