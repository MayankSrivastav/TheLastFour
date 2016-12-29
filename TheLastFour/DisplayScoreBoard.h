// This header file defines the Display class
// which is used to display score board

#ifndef DISPLAYSCOREBOARD_H
#define DISPLAYSCOREBOARD_H

#include <string>
#include <iostream>
using std::cout;
using std::string;

class DisplayScoreBoard
{
public:
	DisplayScoreBoard();
	~DisplayScoreBoard();

	// This function displays the final 
	// score board after the match is 
	// over
	void displayScoreBoard(const string& scoreBoard) const;
};

#endif