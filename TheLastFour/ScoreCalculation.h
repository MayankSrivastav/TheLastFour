#ifndef SCORECALCULATION_H
#define SCORECALCULATION_H

#include "TheLastFour.h"
class TheLastFour;
class ScoreCalculation :
	public TheLastFour
{
private:	
	int runsToScoreNow;	
	int ballNoThisOver;
	int currentOver;	

public:	
	ScoreCalculation();
	//ScoreCalculation(int player1, int player2, int nextPlayer,
	//	int runsToScoreNow, int ballNoThisOver, int currentOver);
	~ScoreCalculation();	

	void setRunsToScoreNow(const int runsToScoreNow);

	int getRunsToScoreNow() const;

	void setBallNoThisOver(const int ballNoThisOVer);

	int getBallNoThisOver() const;

	void setCurrentOver(const int currentOver);

	int getCurrentOver() const;

	// This function calculates the score on every delivery
	// and updates the objects/members accordingly
	void calculateScore(int ballNo, int runsScoredPerBall);
};

#endif