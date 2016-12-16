// This is Player Class file. This class contains
// the Player class definition. 

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <random>
using std::string;
using std::discrete_distribution;

class Player {
private:
	string playerName;
	discrete_distribution<> playerProbability;	// discrete_distribution<> is used to contain player probability

public:
	Player();
	Player(string name, discrete_distribution<> probabilityDistribution);

	// This function gets the current player name
	string getPlayerName() const
	{
		return playerName;
	}

	// This function gets the probability of current player	
	discrete_distribution<> getPlayerProbability() const
	{
		return playerProbability;
	}
};

#endif
