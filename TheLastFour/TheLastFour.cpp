// This is the main program to simulate the match
// It returns the final summary of the match

#include "TheLastFour.h"
#include "ScoreCalculation.h"
#include <random>
#include <iostream>
using namespace std;

TheLastFour::TheLastFour()
{ }

// This funtion sets the number of runs to score
void TheLastFour::setRunsToScore(int runsToScore)
{
	this->runsToScore = runsToScore;
}

// This function returns the number of runs to score
int TheLastFour::getRunsToScore() const
{
	return runsToScore;
}

void TheLastFour::setAtStrike(const int atStrike)
{
	this->atStrike = atStrike;
}

int TheLastFour::getAtStrike() const
{
	return atStrike;
}

void TheLastFour::setPlayer1(int player1)
{
	this->player1 = player1;
}

int TheLastFour::getPlayer1() const
{
	return player1;
}

void TheLastFour::setPlayer2(const int player2)
{
	this->player2 = player2;
}

int TheLastFour::getPlayer2() const
{
	return player2;
}

void TheLastFour::setNextPlayer(const int nextPlayer)
{
	this->nextPlayer = nextPlayer;
}

int TheLastFour::getNextPlayer() const
{
	return nextPlayer;
}

// This function sets the number of wickets left
void TheLastFour::setWicketsLeft(int wicketsLeft)
{
	this->wicketsLeft = wicketsLeft;
}

// This function returns the number of wickets left
int TheLastFour::getWicketsLeft() const
{
	return wicketsLeft;
}

// This function sets the number of overs remaining
void TheLastFour::setOversRemaining(int oversRemaining)
{
	this->oversRemaining = oversRemaining;
}

// This function gets the number of overs remaining
int TheLastFour::getOverRemaining() const
{
	return oversRemaining;
}

// This function sets the current score board
void TheLastFour::setScoreBoard(string scoreBoard)
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

void TheLastFour::setPlayer(vector<pair<string, discrete_distribution<int>>> players)
{
	this->player = players;
}

void TheLastFour::setWonOrLost(const string wonOrLost)
{
	this->wonOrLost = wonOrLost;
}

string TheLastFour::getWonOrLost() const
{
	return wonOrLost;
}

// This is main function to display the final score board (summary)
// of the match.
void TheLastFour::displayFinalScoreBoard() const
{	
	cout << scoreBoard;
	/*for (auto score : scoreBoard) {
		cout << score << endl;
	}*/
	cout << endl;
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
	int runScoredPerBall = 0;

	// Simulation starts with ball no. 1 and goes upto number of balls remaining
	for (ballNo = 1; ballNo <= noOfBallsRemaining; ++ballNo) {
		runScoredPerBall = player[atStrike].second(gen);// Generate the run scored this ball for the current player at strike
		
		sim.calculateScore(ballNo, runScoredPerBall);

		if (wonOrLost != "yet to be decided") { break; }
	}
}

