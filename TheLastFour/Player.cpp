// The is the Player class implementation file

#include "Player.h"

Player::Player() { }

// Initialize each Player Object
Player::Player(string name, discrete_distribution<> probabilityDistribution)
{
	this->playerName = name;
	this->playerProbability = probabilityDistribution;
}
