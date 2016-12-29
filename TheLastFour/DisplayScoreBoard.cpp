#include "DisplayScoreBoard.h"

DisplayScoreBoard::DisplayScoreBoard()
{ }


DisplayScoreBoard::~DisplayScoreBoard()
{ }

// This function displays the final 
// score board after the match is 
// over
//
// Handle the display of score board in this 
// function. As the scoreBoard variable is a
// string, display can be manipulated as needed.
void DisplayScoreBoard::displayScoreBoard(const string& scoreBoard) const
{
	cout << scoreBoard << '\n';		
}
