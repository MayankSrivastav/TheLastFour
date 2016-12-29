#include "ScoreCalculation.h"
#include <iostream>

const enum runType { Zero = 0, One = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Out = 7 };
ScoreCalculation::ScoreCalculation()
{ }

//ScoreCalculation::ScoreCalculation(int player1, int player2, int nextPlayer,
//	int runsToScoreNow, int ballNoThisOver, int currentOver) 
//{		
//	this->player1 = player1;
//	this->player2 = player2;
//	this->nextPlayer = nextPlayer;
//	this->runsToScoreNow = runsToScoreNow;	
//	this->ballNoThisOver = ballNoThisOver;
//	this->currentOver = currentOver;	
//}


ScoreCalculation::~ScoreCalculation()
{ }

// This function sets the number of runs to 
// score now
void ScoreCalculation::setRunsToScoreNow(const int& runsToScoreNow)
{
	this->runsToScoreNow = runsToScoreNow;
}

// This function gets the number of runs to 
// score now
int ScoreCalculation::getRunsToScoreNow() const
{
	return runsToScoreNow;
}

// This function sets the current ball 
// in the over
void ScoreCalculation::setBallNoThisOver(const int& ballNoThisOVer)
{
	this->ballNoThisOver = ballNoThisOVer;
}

// This function gets the current ball 
// in the over
int ScoreCalculation::getBallNoThisOver() const
{
	return ballNoThisOver;
}

// This function sets the current over in
// the match
void ScoreCalculation::setCurrentOver(const int& currentOver)
{
	this->currentOver = currentOver;
}

// This function gets the current over in
// the match
int ScoreCalculation::getCurrentOver() const
{
	return currentOver;
}

// This function calculates the score on every delivery
// and updates the objects/members accordingly
void ScoreCalculation::calculateScore(const int& ballNo, const int& runsScoredPerBall)
{	
	ballNoThisOver++;

	if (runsScoredPerBall == Zero || runsScoredPerBall == Two || runsScoredPerBall == Four || runsScoredPerBall == Six) {	// No strike change for 0, 2, 4 and 6 runs
																														// runs scored summary for the current ball
		scoreBoard += to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' +
			getPlayer()[atStrike].first + " scores " + to_string(runsScoredPerBall) + " run(s)\n";	
	}
	else if (runsScoredPerBall == One || runsScoredPerBall == Three || runsScoredPerBall == Five) { // Players change strike for 1, 3 and 5 runs
																								 // runs scored summary for the current ball
		scoreBoard += to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' +
			getPlayer()[atStrike].first + " scores " + to_string(runsScoredPerBall) + " run(s)\n";

		atStrike = (atStrike == player2 ? player1 : player2);
	}
	else if (runsScoredPerBall == Out) {	// Player gets out, 7 means out
										// runs scored summary for the current ball
		scoreBoard += to_string(currentOver) + '.' + to_string(ballNoThisOver) + ' ' + getPlayer()[atStrike].first + " gets out\n";		

		// Bring the next player at the same position
		auto currPlayer = atStrike;
		atStrike = nextPlayer;
		currPlayer == player1 ? (player1 = atStrike) : (player2 = atStrike);
		nextPlayer++;

		// Update the number of wickets left
		wicketsLeft--;
	}	

	// Score Calculation
	// Update the number of runs to score now, if runsScoredPerBall is 7, that means out
	runsToScoreNow = (runsScoredPerBall != Out ? runsToScoreNow - runsScoredPerBall : runsToScoreNow);

	// If the number of runs to score now is less than or equal to 0, 
	// then Lengaburu has won the match. Break out of the for loop
	//
	// Else if runsToScoreNow is more than 0, but no wickets are left
	// then Lengaburu has lost the match. Break of the loop
	if (runsToScoreNow <= Zero) {
		wonOrLost = "WON";	
		scoreBoard = "Lengaburu won by " + to_string(wicketsLeft) + " wickets and " + 
			to_string(24 - ballNo) + " balls remaining\n\n" + scoreBoard;

		return;
	}
	else if (runsToScoreNow > Zero && wicketsLeft == 0) {
		wonOrLost = "LOST";
		scoreBoard = "Lengaburu lost by " + to_string(runsToScoreNow) + " runs\n\n" + scoreBoard;
		
		return;
	}

	// Increase Over counter every 6 balls
	// Update the status after the over
	if (ballNo % 6 == 0) {
		ballNoThisOver = 0;
		currentOver++;
		oversRemaining--;

		atStrike = (atStrike == player2 ? player1 : player2);	// Change strike after the over
		if (oversRemaining > 0) {
			scoreBoard += "\n" + to_string(oversRemaining) + " overs left." + " " + to_string(runsToScoreNow) + " runs to win\n";			
		}
	}
}

