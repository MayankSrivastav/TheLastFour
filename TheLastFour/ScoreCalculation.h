// This header file defines the class which
// handles the calculation of score during
// match

#ifndef SCORECALCULATION_H
#define SCORECALCULATION_H

#include "TheLastFour.h"

class ScoreCalculation :
	public TheLastFour
{
private:	
	int runsToScoreNow;	
	int ballNoThisOver;
	int currentOver;	

public:	
	ScoreCalculation();

	// Constructor to initialize TheLastFour class members
	// and as well as ScoreCalculation members
	ScoreCalculation(int runsToScore, vector<pair<string, discrete_distribution<int>>> player,
		int player1, int player2, int nextPlayer, int atStrike, int wicketsLeft, int oversRemaining,
		string wonOrLost, string scoreBoard, int runsToScoreNow, int ballNoThisOver, int currentOver);
		
	~ScoreCalculation();	

	// This function sets the number of runs to 
	// score now
	void setRunsToScoreNow(const int& runsToScoreNow);

	// This function gets the number of runs to 
	// score now
	int getRunsToScoreNow() const;

	// This function sets the current ball 
	// in the over
	void setBallNoThisOver(const int& ballNoThisOVer);

	// This function gets the current ball 
	// in the over
	int getBallNoThisOver() const;

	// This function sets the current over in
	// the match
	void setCurrentOver(const int& currentOver);

	// This function gets the current over in
	// the match
	int getCurrentOver() const;

	// This function calculates the score on every delivery
	// and updates the objects/members accordingly
	void calculateScore(const int& ballNo, const int& runsScoredPerBall);
};

#endif