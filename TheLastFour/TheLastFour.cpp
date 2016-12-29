// This is the main program to simulate the match
// It returns the final summary of the match

#include "TheLastFour.h"
#include "ScoreCalculation.h"
#include <random>
#include <iostream>
using namespace std;

TheLastFour::TheLastFour()
{ }

TheLastFour::TheLastFour(int runsToScore, vector<pair<string, discrete_distribution<int>>> player,
	int player1, int player2, int nextPlayer, int atStrike, int wicketsLeft, int oversRemaining,
	string wonOrLost, string scoreBoard)
{
	this->runsToScore = runsToScore;
	this->player = player;
	this->atStrike = atStrike;
	this->nextPlayer = nextPlayer;
	this->player1 = player1;
	this->player2 = player2;
	this->wicketsLeft = wicketsLeft;
	this->oversRemaining = oversRemaining;
	this->wonOrLost = wonOrLost;
	this->scoreBoard = scoreBoard;
}

// This funtion sets the number of runs to score
void TheLastFour::setRunsToScore(const int& runsToScore)
{
	this->runsToScore = runsToScore;
}

// This function returns the number of runs to score
int TheLastFour::getRunsToScore() const
{
	return runsToScore;
}

void TheLastFour::setAtStrike(const int& atStrike)
{
	this->atStrike = atStrike;
}

int TheLastFour::getAtStrike() const
{
	return atStrike;
}

void TheLastFour::setPlayer1(const int& player1)
{
	this->player1 = player1;
}

int TheLastFour::getPlayer1() const
{
	return player1;
}

void TheLastFour::setPlayer2(const int& player2)
{
	this->player2 = player2;
}

int TheLastFour::getPlayer2() const
{
	return player2;
}

void TheLastFour::setNextPlayer(const int& nextPlayer)
{
	this->nextPlayer = nextPlayer;
}

int TheLastFour::getNextPlayer() const
{
	return nextPlayer;
}

// This function sets the number of wickets left
void TheLastFour::setWicketsLeft(const int& wicketsLeft)
{
	this->wicketsLeft = wicketsLeft;
}

// This function returns the number of wickets left
int TheLastFour::getWicketsLeft() const
{
	return wicketsLeft;
}

// This function sets the number of overs remaining
void TheLastFour::setOversRemaining(const int& oversRemaining)
{
	this->oversRemaining = oversRemaining;
}

// This function gets the number of overs remaining
int TheLastFour::getOverRemaining() const
{
	return oversRemaining;
}

// This function sets the current score board
void TheLastFour::setScoreBoard(const string& scoreBoard)
{
	this->scoreBoard = scoreBoard;
}

// This function gets the current score board
string TheLastFour::getScoreBoard() const
{
	return scoreBoard;
}

vector<pair<string, discrete_distribution<>>> TheLastFour::getPlayer() const
{
	return this->player;
}

void TheLastFour::setPlayer(const vector<pair<string, discrete_distribution<int>>>& players)
{
	this->player = players;
}

void TheLastFour::setWonOrLost(const string& wonOrLost)
{
	this->wonOrLost = wonOrLost;
}

string TheLastFour::getWonOrLost() const
{
	return wonOrLost;
}

// This is the main function to start simulation of the match based
// on the given parameters. 
//
// Returns the result of the match simulation. The match summary is
// stored in vector of strings.
void TheLastFour::simulateMatch(ScoreCalculation& sim)
{
	// Generate uniformly distributed random number
	random_device rd;
	mt19937 gen(rd());

	// Initialize local variables 
	int ballNo, noOfBallsRemaining = oversRemaining * 6;
	int runScoredPerBall = 0;	// Runs scored on each delivery

	// Simulation starts with ball no. 1 and goes upto number of balls remaining
	for (ballNo = 1; ballNo <= noOfBallsRemaining; ++ballNo) {
		// Generate the run scored this ball for the current player at strike
		runScoredPerBall = player[atStrike].second(gen);
		
		// Calculate the score and update the score
		// board and assign it to the sim object
		sim.calculateScore(ballNo, runScoredPerBall);

		// If Lengaburu won or lost then return
		if (wonOrLost != "yet to be decided") { break; }
	}
}

