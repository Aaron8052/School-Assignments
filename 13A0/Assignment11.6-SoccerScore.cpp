/*
	Name: Assignment: 11.6: Soccer Scores
	Copyright: 2024
	Author: Yu Jiang
	Date: 07/04/24 09:22
	Description: 
		A program that store data about a team of soccer players
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Player Structure
struct Player
{
	string name;
	long number;
	long score;
};

// Prototypes
void getInput(Player*, int);
void outputPlayer(Player);
void outputPlayers(Player*, int);
int getTotalPoints(Player*, int);
Player getBestPlayer(Player*, int);
const int MAX_OUTPUT_NAME_LENGTH = 15;

// Main Driver
int main(int argc, char** argv)
{
	const int SIZE = 3;
	Player players[SIZE];
	getInput(players, SIZE);
	outputPlayers(players, SIZE);
	cout << "\n[Total Scores]\t" << getTotalPoints(players, SIZE) << endl;
	cout << "\nBest Player:" << endl;
	outputPlayer(getBestPlayer(players, SIZE));
}

// gets input from user for player's score with validation
int getScoreInput(int index)
{
	int score = 0;
	cout << "Please enter score of Player #" << index << ": ";
	cin >> score;
	while (score < 0)
	{
		cout << "-- Score must be greater than 0! --" << endl;
		cout << "Please enter score of Player #" << index << ": ";
		cin >> score;
	}
	return score;
}

// gets input from user for player's number with validation
int getNumberInput(int index)
{
	int num = -1;
	cout << "Please enter number of Player #" << index << ": ";
	cin >> num;
	while (num < 0)
	{
		cout << "-- Player number must be greater than 0! --" << endl;
		cout << "Please enter number of Player #" << index << ": ";
		cin >> num;
	}
	return num;
}

// gets input from user for player's info
void getInput(Player* players, int size)
{
	for(int i = 0; i < size; i++)
	{
		int num = i + 1;
		cout << "Please enter name of Player #" << num << ": ";
		getline(cin, players[i].name);
		players[i].number = getNumberInput(num);
		players[i].score = getScoreInput(num);
		cout << endl;
		cin.ignore(100, '\n');
	}
}

// output info for ONE player
void outputPlayer(Player player)
{
	cout << "[Number]\t" << setw(5) << player.number << "\t";
		 	 
	// Limits the max output length of player's name
	cout << "[Name]\t" << setw(MAX_OUTPUT_NAME_LENGTH);	 
	if(player.name.length() >= MAX_OUTPUT_NAME_LENGTH)
		cout << player.name.substr(0, MAX_OUTPUT_NAME_LENGTH);
	else
		cout << player.name;
	cout << "\t"
		 << "[Score]\t" << setw(10) << player.score 
		 << endl;
}

// output all player's info as table
void outputPlayers(Player* players, int size)
{
	cout << "------------------------- Players -------------------------" << endl;
	for(int i = 0; i < size; i++)
	{
		outputPlayer(players[i]);
	}
}

// gets the total points earned by the team
int getTotalPoints(Player* players, int size)
{
	long long scores = 0;
	for(int i = 0; i < size; i++)
	{
		scores += players[i].score;
	}
	return scores;
}

// gets the player with best score
Player getBestPlayer(Player* players, int size)
{
	int bestScore = -1;
	int bestPlayerIndex = 0;
	for(int i = 0; i < size; i++)
	{
		if(players[i].score <= bestScore)
			continue;
		bestScore = players[i].score;
		bestPlayerIndex = i;
	}
	return players[bestPlayerIndex];
}