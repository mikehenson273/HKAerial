/*Michael Henson
  CSC215
  Basic User guessing variant
*/
 
//sets up the libraries
#include "pch.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Sets up variables here
int randomNumber = rand();
int searchHigh = 64;
int searchLow = 1;
int targetFinder = 0;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // prevents same number usage between restarts
	int rebelLocal = rand() % 64 + 1; //sets up rebel location on in a number from 1 to 64
	int tries = 0; //player tries

	cout << "\tWelcome to HKAerial Interface\n\n";
	{
		bool isTargetLocated = false;

		do
		{
			cout << "The rebels are hiding at location " << rebelLocal << " on the grid.\n";

			// Recalc guess based off learning.
			targetFinder = ((searchHigh - searchLow) / 2) + searchLow;
			++tries;
			cout << "The HKAerial's new search is at location: " << targetFinder << ".\n";
			cout << "This is the HKAerial's attempt number " << tries << ".";

			// Is Guess too high
			if (targetFinder > rebelLocal)
			{
				// set high search number at a new lower level to 1 less than you guessed.
				searchHigh = (targetFinder - 1);
				cout << "\nThe search was high of rebel base at " << rebelLocal << ". continuing search.\n\n";
				system("pause");
				cout << endl;
			}
			// Is Guess too Low
			else if (targetFinder < rebelLocal)
			{
				// set low search number at a new higher level to 1 more than you guessed.
				searchLow = (targetFinder + 1);
				cout << "\nThe search was low of rebel base at " << rebelLocal << ". continuing search.\n\n";
				system("pause");
				cout << endl;
			}
			// Is Target Found?
			else if (targetFinder == rebelLocal)
			{
				isTargetLocated = true;
				cout << "\nOn the HKAerial's attempt number " << tries << "\n";
				cout << "it has found them. Eliminating threat at grid location " << rebelLocal << ".\n\n";
				system("pause");
			}
			else
			{
				// You should never get to this unless you have a logic error.
				cout << "\nError Something went wrong when trying to classify targetFinder";
			}
		}
		// Keep going until target is found
		while (!isTargetLocated);
		return 0;
	}
}