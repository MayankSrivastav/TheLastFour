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

	void displayScoreBoard(const string& scoreBoard) const;
};

#endif