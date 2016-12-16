// This is the main program to simulate the match
// It returns the final summary of the match

#include "TheLastFour.h"
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
void TheLastFour::setScoreBoard(vector<string> scoreBoard)
{
	this->scoreBoard = scoreBoard;
}

// This function gets the current score board
vector<string> TheLastFour::getScoreBoard() const
{
	return scoreBoard;
}

// This is main function to display the final score board (summary)
// of the match.
void TheLastFour::displayFinalScoreBoard(const vector<string>& finalScoreBoard) const
{	
	for (auto score : finalScoreBoard) {
		cout << score << endl;
	}
	cout << endl;
}

// This is the main function to start simulation of the match based
// on the given parameters. 
//
// Returns the result of the match simulation. The match summary is
// stored in vector of strings.
vector<string> TheLastFour::simulateMatch(const vector<Player>& players)
{
	// Generate uniformly distributed random number
	random_device rd;
	mt19937 gen(rd());
	
	// Initialize local variables 
	enum runType { Zero = 0, One = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Out = 7 };
	int runsToScoreNow = runsToScore;
	int ballNo, noOfBallsRemaining = oversRemaining * 6;
	int currentOver = 0, runScoredPerBall = 0, runsThisOver = 0;
	string runsScored;
	int ballNoThisOver = 0;
	bool win = false;
	int player1 = 0, player2 = 1;	// Current player in the middle
	int atStrike = player1, nextPlayer = player2 + 1;	// player1 is at strike. next Player will 1 down (which is aliased as player2 + 1 and so on)

	// Simulation starts with ball no. 1 and goes upto number of balls remaining
	for (ballNo = 1; ballNo <= noOfBallsRemaining; ++ballNo) {
		runScoredPerBall = players[atStrike].getPlayerProbability()(gen);// Generate the run scored this ball for the current player at strike
		ballNoThisOver++;

		if (runScoredPerBall == Zero || runScoredPerBall == Two || runScoredPerBall == Four || runScoredPerBall == Six) {	// No strike change for 0, 2, 4 and 6 runs
			// runs scored summary for the current ball
			runsScored = to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' + players[atStrike].getPlayerName() + " scores " + to_string(runScoredPerBall) + " run(s)";
			// update the score board
			scoreBoard.emplace_back(runsScored);
		}
		else if (runScoredPerBall == One || runScoredPerBall == Three || runScoredPerBall == Five) { // Players change strike for 1, 3 and 5 runs
			// runs scored summary for the current ball
			runsScored = to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' + players[atStrike].getPlayerName() + " scores " + to_string(runScoredPerBall) + " run(s)";
			// update the score board
			scoreBoard.emplace_back(runsScored);
			// change the strike of players
			atStrike = (atStrike == player2 ? player1 : player2);
		}
		else if (runScoredPerBall == Out) {	// Player gets out, 7 means out
			// runs scored summary for the current ball
			runsScored = to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' + players[atStrike].getPlayerName() + " gets out";
			// update the score board
			scoreBoard.emplace_back(runsScored);

			// Bring the next player at the same position
			auto currPlayer = atStrike;						
			atStrike = nextPlayer;
			currPlayer == player1 ? (player1 = atStrike) : (player2 = atStrike);
			nextPlayer++;

			// Update the number of wickets left
			wicketsLeft--;
		}

		// Update the number of runs to score now, if runsScoredPerBall is 7, that means out
		runsToScoreNow = (runScoredPerBall != Out ? runsToScoreNow - runScoredPerBall : runsToScoreNow);

		// If the number of runs to score now is less than or equal to 0, 
		// then Lengaburu has won the match. Break out of the for loop
		//
		// Else if runsToScoreNow is more than 0, but no wickets are left
		// then Lengaburu has lost the match. Break of the loop
		if (runsToScoreNow <= Zero) {
			win = true;
			break;
		}
		else if (runsToScoreNow > Zero && wicketsLeft == 0) {
			win = false;
			break;
		}

		// Increase Over counter every 6 balls
		// Update the status after the over
		if (ballNo % 6 == 0) {
			ballNoThisOver = 0;
			currentOver++;	
			oversRemaining--;
			runsThisOver = 0;

			atStrike = (atStrike == player2 ? player1 : player2);	// Change strike after the over
			if (oversRemaining > 0) {
				scoreBoard.emplace_back(" ");
				scoreBoard.emplace_back(to_string(oversRemaining) + " overs left." + " " + to_string(runsToScoreNow) + " runs to win");
			}
		}
	}

	// Display initial match summary
	if (win) {
		cout << "Lengaburu won by " + to_string(wicketsLeft) + " wickets and " + to_string(24 - ballNo) + " balls remaining" << endl << endl;
	}
	else {
		cout << "Lengaburu lost by " + to_string(runsToScoreNow) + " runs" << endl << endl;
	}

	// Return the final match summary
	return scoreBoard;
}
