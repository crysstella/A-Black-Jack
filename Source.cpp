/*
Name: Vo Van Anh Nguyen
Student ID: 01739843
Homework : A Black Jack
Date: 02/20/20
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*Write a program that scores a blackjack hand.In blackjack, a player can have between 2 and 5 cards.
	The cards either have a numeric value(2, 3, 4, 5, 6, 7, 8, 9, and 10) or a letter value(Jack, Queen, King, and Ace).
	To add up the score of a hand, follow these steps : The numeric cards add their value to the final score.
	For example, if the user has a 2 in their hand, it adds 2 points to the total.
	If the user has an 8 in their hand, it adds 8 points to the total.Face cards(Jack, Queen, and King) all add 10 points each to the total.
	The Ace card adds either 1 or 11 to the score, whichever is more helpful for the user.
	The goal of blackjack is to get a score as close to 21 as possible without going over.
	If the user gets over 21, they have "busted" and automatically lose. If the user scores 21, they have received a "blackjack".
	If they score less than 21, they simply are told the score they have received.
	Your program should ask the user how many cards they have, and then ask for the value of each.
	Tip : Have each value the user inputs placed in a 'char' variable(even the numbers).
	If the user has a 3 card, they will enter '3'.If the user has a king, they will enter 'k', and so forth.
	After the card values are entered, add the value of each card to a total(think switch or if / else statement).
	Example hand : The user has an aceand two 8s.
	This can either be scored as 17 (with the ace counting as 1 point) or 27 (with the ace counting as 11 points).Since 27 is a bust, the user's score should be calculated as 17.*/

	string value = "a";
	int NumberofCards = 0, total = 0, count = 0, order = 0;

	cout << " ----- A BLACKJACK HAND -----" << endl;
	while (NumberofCards < 1 || NumberofCards > 5)
	{
		cout << "HOW MANY CARDS YOU HAVE? ";
		cin >> NumberofCards;
		if (NumberofCards < 1 || NumberofCards > 5)
		{
			cout << " You must have at least 2 to 5 cards in hand. Please play again." << endl;
		}
	}

	for (int i = 1; i <= NumberofCards; i++)
	{
			cout << "The value of your card number " << i << " : ";
			cin >> value;

			if (value == "J" || value == "j" || value == "Q" || value == "q" || value == "K" || value == "k")
			{
				total += 10;
			}
			else if (value == "A" || value == "a")
			{
				count++;
				total += 11;
				if (total > 21)
				{
					total -= 10;
					order++;
				}
			}
			else if (stoi(value) > 1 && stoi(value) < 11)
			{
				for (int j = 2; j < 11; j++)
				{
					if (stoi(value) == j)
					{
						total += j;
					}
				}
			}
			else 
				{
					cout << "Wrong value" << endl;
					break;
				}
	}

	if (total > 21 && order < count)
	{
		total -= 10 * (count - order);
	}
	if (total < 21)
	{
		cout << "Your score is: " << total;
	}
	else if (total == 21)
	{
		cout << "A BlackJack! Your score is: " <<total;
	}
	else
	{
		cout << "Busted! You losed! Your score is: " << total;
	}
	return 0;
}
