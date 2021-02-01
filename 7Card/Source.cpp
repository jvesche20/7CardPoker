/*
Jacob Vesche
7 Card Poker Extra credit
"I have neither given nor received unauthorized aid in completing this work,
nor have I presented someone else's work as my own."

*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>


using namespace std;

void SortTD(int[][7], int[][7]);
bool checkFlush(int[][7], int);
bool checkStraight(int[][7], int);
//bool checkHighStraight(int[][7], int);
bool checkRoyalFlush(int[][7], int[][7], int);
bool checkOnePair(int[][7], int);
bool checkFourKind(int[][7], int);
bool checkThreeKind(int[][7], int);
bool checkStraightFlush(int[][7], int[][7], int);
bool checkFullHouse(int[][7], int);
bool checkTwoPair(int[][7], int);
bool checkHighCard(int[][7], int);
int checkWinner(int[]);
int checkWinnerIndex(int[], int);
void SortTD(int[][7]);
void checkStraightVoid(int[][7], int[][7],int);
void checkHighCardVoid(int[][7], int[][7], int);
void checkThreeKindVoid(int[][7], int[][7], int);
void checkTwoPairVoid(int[][7], int[][7], int);
void checkOnePairVoid(int[][7], int[][7], int);
void checkFlushVoid(int[][7], int[][7], int);
void checkRoyalFlushVoid(int[][7], int[][7], int);
void checkFullHouseVoid(int[][7], int[][7], int);
void checkFourKindVoid(int[][7], int[][7], int);
void checkStraightFlushVoid(int[][7], int[][7], int);
void SortTD(int[][5]);
void SortTD(int[][5], int[][5]);




int main() {

	system("color A0"); // Sets the color to green background and blue text

	int fiveCards[5][5], fiveSuits[5][5], points[5] = { 10, 10,10,10,10 }, cards[52], winTotal, winnerIndex, dup[52] = { 0 }, newPlayers[7][7], i, j, k, total, number, players[7][7], suits[7][7], totals[7];
	bool royalFlush = false, PlayAgain = true;
	string howWon[5], again = "Y";

	while (PlayAgain) {
		Beep(523, 500);

		system("cls");
		srand((unsigned int)time(NULL));

		for (i = 0; i < 52; i++)
			dup[i] = 0;

		for (i = 0; i < 52; i++) {
			number = rand() % 52;

			while (dup[number])
				number = rand() % 52;

			cards[i] = number;
			dup[number]++;
		}

		k = 0;

		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				number = cards[k];
				players[i][j] = number % 13; // 0-12
				suits[i][j] = number / 13 + 3; // 0,1,2,3
				k++;
			}
		}

		for (i = 0; i < 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			cout << "Player " << i + 1 << ": ";
			for (j = 0; j < 7; j++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				if ((suits[i][j] == 4) || (suits[i][j] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

				if (players[i][j] > 9) {
					if (players[i][j] == 10)
						cout << 'J';
					else if (players[i][j] == 11)
						cout << 'Q';
					else
						cout << 'K';
				}
				else {
					if (players[i][j] == 0)
						cout << 'A';
					else
						cout << players[i][j] + 1;
				}
				if ((suits[i][j] == 4) || (suits[i][j] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << char(suits[i][j]) << ' ';

			}

			cout << endl << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

		SortTD(players, suits);


		// cout << "after" << endl << endl;
		/*
		for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
		if (players[i][j] > 9) {
		if (players[i][j] == 10)
		cout << 'J';
		else if (players[i][j] == 11)
		cout << 'Q';
		else
		cout << 'K';
		}
		else {
		if (players[i][j] == 0)
		cout << 'A';
		else
		cout << players[i][j] + 1;
		}
		cout << char(suits[i][j]) << ' ';
		}

		cout << endl << endl;
		}*/
		for (i = 0; i < 7; i++) {
			for (int x = 0; x < 7; x++) {
				if (players[i][x] == 0)
					newPlayers[i][x] = 13;
				else
					newPlayers[i][x] = players[i][x];
			}
		}
		SortTD(newPlayers);
		SortTD(players, suits);

		
		/*
		for (i = 0; i < 5; i++) {
			if (checkRoyalFlush(players, suits, i)) {
				cout << "royalflush " << i << endl;

				checkRoyalFlushVoid(players, suits, i);
			}


			else if (checkStraightFlush(players, suits, i)) {
				cout << "straight flush " << i << endl;

				checkStraightFlushVoid(players, suits, i);
			}

			else if (checkFourKind(players, i)) {
				cout << "testing " << i << endl;

				checkFourKindVoid(players, i);
			}
			else if (checkFullHouse(players, i)) {
				cout << "full " << i << endl;

				checkFullHouseVoid(players, i);
			}
			else if (checkFlush(suits, i)) {
				cout << "flush " << i << endl;

				checkFlushVoid(players, suits, i);
			}

			else if (checkStraight(players, i)) {
				cout << "straight " << i << endl;
				checkStraightVoid(players, i);
			}
			else if (checkThreeKind(players, i)) {
				cout << "threekind " << i << endl;

				checkThreeKindVoid(players, i);
			}
			else if (checkTwoPair(players, i)) {
				cout << "2pair " << i << endl;

				checkTwoPairVoid(players, i);
			}
			else if (checkOnePair(players, i)) {
				cout << "1pair " << i << endl;

				checkOnePairVoid(players, i);
			}

			
			else {
				cout << "high " << i << endl;

				checkHighCardVoid(players, i);
			}
			cout << endl;
		}
		*/

		for (i = 0; i < 5; i++) {
			/*
			cout << "Player " << i + 1 << " flush T or F? " << checkFlush(suits, i) << endl;
			cout << "Player " << i + 1 << " straight T or F? " << checkStraight(players, i) << endl;
			cout << "Player " << i + 1 << " Royal flush T or F? " << checkRoyalFlush(players, suits, i) << endl;
			cout << "Player " << i + 1 << " 1 Pair T or F? " << checkOnePair(players, i) << endl;
			cout << "Player " << i + 1 << " Four of a kind T or F? " << checkFourKind(players, i) << endl;
			cout << "Player " << i + 1 << " Three of a kind T or F? " << checkThreeKind(players, i) << endl;
			cout << "Player " << i + 1 << " Straight flush T or F? " << checkStraightFlush(players, suits, i) << endl;
			cout << "Player " << i + 1 << " Full house T or F? " << checkFullHouse(players, i) << endl;
			cout << "Player " << i + 1 << " Two Pair T or F? " << checkTwoPair(players, i) << endl;
			cout << "Player " << i + 1 << " High card T or F? " << checkHighCard(players, i) << endl;
			*/

			if (checkRoyalFlush(players, suits, i)) {
				checkRoyalFlushVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = fiveCards[i][0] + fiveCards[i][1] * 1000 + fiveCards[i][2] * 3000 + fiveCards[i][3] * 5000 + fiveCards[i][4] * 10000 + 10000000;
				howWon[i] = "Royal Flush";
			}
			else if (checkStraightFlush(players, suits, i)) {
				checkStraightFlushVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = 9000000 + fiveCards[i][4];
				howWon[i] = "Straight Flush";

			}
			else if (checkFourKind(players, i)) {
				checkFourKindVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = 8000000 + fiveCards[i][4];
				howWon[i] = "Four of a Kind";

			}
			else if (checkFullHouse(players, i)) {
				checkFullHouse(players, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				if ((fiveCards[i][4] == fiveCards[i][3]) && (fiveCards[i][4] == fiveCards[i][2]))
					total = 100000 * fiveCards[i][4] + fiveCards[i][0] + 7000000;
				else if ((fiveCards[i][0] == fiveCards[i][1]) && (fiveCards[i][0] == fiveCards[i][2]))
					total = 100000 * fiveCards[i][0] + fiveCards[i][4] + 7000000;

				howWon[i] = "Full House";

			}
			else if (checkFlush(suits, i)) {
				checkFlushVoid(players, suits, i);
				SortTD(players, suits);
				
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = fiveCards[i][0] + fiveCards[i][1] * 10 + fiveCards[i][2] * 100 + fiveCards[i][3] * 1000 + fiveCards[i][4] * 10000 + 6000000;
				howWon[i] = "Flush";

			}
			else if (checkStraight(players, i)) {
				
				checkStraightVoid(players, suits, i);

				cout << endl;
				SortTD(players, suits);
				SortTD(fiveCards, fiveSuits);
				
				cout << endl;
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = fiveCards[i][2] + 5000000;
				howWon[i] = "Straight";

			}
			else if (checkThreeKind(players, i)) {
				checkThreeKindVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				if ((fiveCards[i][0] == fiveCards[i][1]) && (fiveCards[i][0] == fiveCards[i][2]))
					total = 4000000 + fiveCards[i][0];
				else if ((fiveCards[i][1] == fiveCards[i][2]) && (fiveCards[i][1] == fiveCards[i][3]))
					total = 4000000 + fiveCards[i][1];
				else if ((fiveCards[i][2] == fiveCards[i][3]) && (fiveCards[i][2] == fiveCards[i][4]))
					total = 4000000 + fiveCards[i][2];
				howWon[i] = "Three of a Kind";

			}
			else if (checkTwoPair(players, i)) {
				checkTwoPairVoid(players, suits, i);
				SortTD(players, suits);
				
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				if ((fiveCards[i][0] == fiveCards[i][1]) && (fiveCards[i][3] == fiveCards[i][4]))
					total = 3000000 + fiveCards[i][0] * 1000 + fiveCards[i][3] * 10000 + fiveCards[i][2];

				else if ((fiveCards[i][1] == fiveCards[i][2]) && (fiveCards[i][3] == fiveCards[i][4]))
					total = 3000000 + fiveCards[i][1] * 1000 + fiveCards[i][3] * 10000 + fiveCards[i][0];

				else if ((fiveCards[i][0] == fiveCards[i][1]) && (fiveCards[i][2] == fiveCards[i][3]))
					total = 3000000 + fiveCards[i][0] * 1000 + fiveCards[i][3] * 10000 + fiveCards[i][4];


				
				howWon[i] = "Two Pair";

			}
			else if (checkOnePair(players, i)) {
				checkOnePairVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				if (fiveCards[i][0] == fiveCards[i][1])
					total = 2000000 + fiveCards[i][0] * 10000 + fiveCards[i][4] * 1000 + fiveCards[i][3] * 100 + fiveCards[i][2];
				else if (fiveCards[i][1] == fiveCards[i][2])
					total = 2000000 + fiveCards[i][1] * 10000 + fiveCards[i][4] * 1000 + fiveCards[i][3] * 100 + fiveCards[i][0];
				else if (fiveCards[i][2] == fiveCards[i][3])
					total = 2000000 + fiveCards[i][2] * 10000 + fiveCards[i][4] * 1000 + fiveCards[i][1] * 100 + fiveCards[i][0];
				else if (fiveCards[i][3] == fiveCards[i][4])
					total = 2000000 + fiveCards[i][3] * 10000 + fiveCards[i][2] * 1000 + fiveCards[i][1] * 100 + fiveCards[i][0];
				howWon[i] = "One pair";

			}
			else {
				checkHighCardVoid(players, suits, i);
				SortTD(players, suits);
				for (int a = 0; a < 5; a++) {					
					fiveCards[i][a] = players[i][a + 2];
					fiveSuits[i][a] = suits[i][a + 2];
				}
				SortTD(fiveCards, fiveSuits);
				total = fiveCards[i][4] * 5000 + fiveCards[i][3] * 3000 + fiveCards[i][2] * 2000 + fiveCards[i][1] * 1000 + fiveCards[i][0];
				howWon[i] = "High Card";
			}
			totals[i] = total;

		

			// cout << "Player " << i + 1 << " high straight T or F? " << checkHighStraight(players, i) << endl;

			
		}

		cout << endl;
		cout << "Five cards each player gets to use.\n" << endl;

		for (i = 0; i < 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			cout << "Player " << i + 1 << ": ";
			for (j = 0; j < 5; j++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				if ((fiveSuits[i][j] == 4) || (fiveSuits[i][j] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

				if (fiveCards[i][j] > 9) {
					if (fiveCards[i][j] == 10)
						cout << 'J';
					else if (fiveCards[i][j] == 11)
						cout << 'Q';
					else
						cout << 'K';
				}
				else {
					if (fiveCards[i][j] == 0)
						cout << 'A';
					else
						cout << fiveCards[i][j] + 1;
				}
				if ((fiveSuits[i][j] == 4) || (fiveSuits[i][j] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << char(fiveSuits[i][j]) << ' ';

			}

			cout << endl << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
		
		winTotal = checkWinner(totals);
		winnerIndex = checkWinnerIndex(totals, winTotal);
		int c = winnerIndex;
		
		for (i = 0; i < 5; i++) {
			if (winnerIndex == i) {
				points[i]++;
			}

			else
				if (winTotal == totals[i]) {
					cout << "Theres more than one winner! " << endl;
					
					cout << "Player " << i + 1 << " won with having " << howWon[winnerIndex] << endl;
					cout << "Winning cards: ";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
					cout << "Player " << i + 1 << ": ";
					for (int z = 0; z < 5; z++) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
						if ((fiveSuits[i][z] == 4) || (fiveSuits[i][z] == 3))
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
						else
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

						if (fiveCards[i][z] > 9) {
							if (fiveCards[i][z] == 10)
								cout << 'J';
							else if (fiveCards[i][z] == 11)
								cout << 'Q';
							else
								cout << 'K';
						}
						else {
							if (fiveCards[i][z] == 0)
								cout << 'A';
							else
								cout << fiveCards[i][z] + 1;
						}
						if ((fiveSuits[i][z] == 4) || (fiveSuits[i][z] == 3))
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
						else
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
						cout << char(fiveSuits[i][z]) << ' ';

					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

					cout << endl;
					points[i]++;
					
				}
				else {
					points[i]--;
				}
				
		}
		
		cout << "Player " << checkWinnerIndex(totals, checkWinner(totals)) + 1 << " won with having " << howWon[winnerIndex] << endl;
		cout << "Winning cards: ";
		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			cout << "Player " << c + 1 << ": ";
			for (int z = 0; z < 5; z++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				if ((fiveSuits[c][z] == 4) || (fiveSuits[c][z] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);

				if (fiveCards[c][z] > 9) {
					if (fiveCards[c][z] == 10)
						cout << 'J';
					else if (fiveCards[c][z] == 11)
						cout << 'Q';
					else
						cout << 'K';
				}
				else {
					if (fiveCards[c][z] == 0)
						cout << 'A';
					else
						cout << fiveCards[c][z] + 1;
				}
				if ((fiveSuits[c][z] == 4) || (fiveSuits[c][z] == 3))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 164);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << char(fiveSuits[c][z]) << ' ';
				
			}
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			cout << endl << endl;
		

		
		cout << "----------------------------------------------" << endl;
		cout << "Each game cost 1 chip. Winner gets 1 chip. If theres a tie both get 1 chip." << endl;
		cout << "Chips:" << endl;
		for (i = 0; i < 5; i++) {
			cout << "Player " << i + 1 << " chip count: " << points[i] << endl;
			
		}

		/*
		check if ex.
		int newDeck[5];
		if(checkStraight(cards)){
			checkStraightVoid(cards);
			sortTD(cards);

			for(int i = 0; i < 5; i++){

				newDeck[i] = cards[i+2];
			
			}

		}
		*/
		

		cout << "Would you like to play again? Y or N: ";
		cin >> again;
		if (again == "Y" || again == "y")
			PlayAgain = true;
		else
			PlayAgain = false;
	}
	system("pause");
	return 0;
}

void SortTD(int TD[][7]) { //done
	int i, maxElement, index, temp;

	for (i = 0; i < 7; i++) {
		for (maxElement = 6; maxElement > 0; maxElement--) {
			for (index = 0; index < maxElement; index++) {
				if (TD[i][index] > TD[i][index + 1]) {
					temp = TD[i][index];
					TD[i][index] = TD[i][index + 1];
					TD[i][index + 1] = temp;
				}
			}
		}
	}
	return;
}
void SortTD(int TD[][5]) { //done
	int i, maxElement, index, temp;

	for (i = 0; i < 5; i++) {
		for (maxElement = 4; maxElement > 0; maxElement--) {
			for (index = 0; index < maxElement; index++) {
				if (TD[i][index] > TD[i][index + 1]) {
					temp = TD[i][index];
					TD[i][index] = TD[i][index + 1];
					TD[i][index + 1] = temp;
				}
			}
		}
	}
	return;
}


void SortTD(int TD[][7], int suit[][7]) { // done
	int i, maxElement, index, temp;

	for (i = 0; i < 7; i++) {
		for (maxElement = 6; maxElement > 0; maxElement--) {
			for (index = 0; index < maxElement; index++) {
				if (TD[i][index] > TD[i][index + 1]) {
					temp = TD[i][index];
					TD[i][index] = TD[i][index + 1];
					TD[i][index + 1] = temp;
					temp = suit[i][index];
					suit[i][index] = suit[i][index + 1];
					suit[i][index + 1] = temp;
				}
			}
		}
	}
	return;
}

void SortTD(int TD[][5], int suit[][5]) { // done
	int i, maxElement, index, temp;

	for (i = 0; i < 5; i++) {
		for (maxElement = 4; maxElement > 0; maxElement--) {
			for (index = 0; index < maxElement; index++) {
				if (TD[i][index] > TD[i][index + 1]) {
					temp = TD[i][index];
					TD[i][index] = TD[i][index + 1];
					TD[i][index + 1] = temp;
					temp = suit[i][index];
					suit[i][index] = suit[i][index + 1];
					suit[i][index + 1] = temp;
				}
			}
		}
	}
	return;
}


int checkWinnerIndex(int players[], int highest) { // done
	for (int i = 0; i < 5; i++) {
		if (highest == players[i])
			return i;
		
	}
	return -1;
}
int checkWinner(int players[]) { // done
	int highest = players[0];
	for (int i = 0; i < 7; i++) {
		if (players[i] > highest)
			highest = players[i];
	}
	return highest;
}

bool checkHighCard(int players[][7], int i) { // done
	if ((players[i][0] == 0) || (players[i][0] == 13))
		return true;
	return false;
}
void checkHighCardVoid(int players[][7], int suit[][7], int i) { // done
	int temp[5], tempSuit[5];
	if ((players[i][0] == 0) || (players[i][0] == 13)) {
		temp[4] = players[i][0];
		temp[3] = players[i][6];
		temp[2] = players[i][5];
		temp[1] = players[i][4];
		temp[0] = players[i][3];
		players[i][0] = temp[4];
		players[i][1] = temp[3];
		players[i][2] = temp[2];
		players[i][3] = temp[1];
		players[i][4] = temp[0];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[4] = suit[i][0];
		tempSuit[3] = suit[i][6];
		tempSuit[2] = suit[i][5];
		tempSuit[1] = suit[i][4];
		tempSuit[0] = suit[i][3];
		suit[i][0] = tempSuit[4];
		suit[i][1] = tempSuit[3];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[1];
		suit[i][4] = tempSuit[0];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else {

		temp[4] = players[i][2];
		temp[3] = players[i][6];
		temp[2] = players[i][5];
		temp[1] = players[i][4];
		temp[0] = players[i][3];
		players[i][0] = temp[4];
		players[i][1] = temp[3];
		players[i][2] = temp[2];
		players[i][3] = temp[1];
		players[i][4] = temp[0];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[4] = suit[i][2];
		tempSuit[3] = suit[i][6];
		tempSuit[2] = suit[i][5];
		tempSuit[1] = suit[i][4];
		tempSuit[0] = suit[i][3];
		suit[i][0] = tempSuit[4];
		suit[i][1] = tempSuit[3];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[1];
		suit[i][4] = tempSuit[0];
		suit[i][5] = -1;
		suit[i][6] = -1;

	}
}


bool checkTwoPair(int players[][7], int i) { // 18 if statements
	if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][3]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][3] == players[i][4]) && (players[i][5] == players[i][6]))
		return true;
	else
		return false;
}
void checkTwoPairVoid(int players[][7], int suit[][7], int i) { // 18 if statements
	int temp[5], tempSuit[5];
	if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][3])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][3];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][3];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][2] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][3] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][3] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][4])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][3] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][4]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
}



void checkFullHouseVoid(int players[][7], int suit[][7], int i) { // done

	int temp[5], tempSuit[5];
	if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][0];
			temp[4] = players[i][1];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][0];
			tempSuit[4] = suit[i][1];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

		else {

		}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

		else {

		}
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][6]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][4];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

		else {

		}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][3];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

		else {

		}
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1]) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

		else {

		}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][1] == players[i][2]) {
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
		if (players[i][1] == players[i][2])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][1] == players[i][2])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][1] == players[i][2])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][2] == players[i][3])
		{
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][4])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][4];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][4];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][5])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][6])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][4] == players[i][5])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][4] == players[i][6])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][4];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][5] == players[i][6])
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][4] == players[i][5])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][4] == players[i][6])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][5] == players[i][6])
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
		else {

		}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		if (players[i][6] == players[i][5])
		{
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

}

bool checkFullHouse(int players[][7], int i) { // done
	if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][6]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][0] == players[i][1])
			return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		if (players[i][1] == players[i][2])
			return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
		if (players[i][1] == players[i][2])
			return true;
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][1] == players[i][2])
			return true;
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][1] == players[i][2])
			return true;
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		if (players[i][2] == players[i][3])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][4])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][5])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][3] == players[i][6])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][4] == players[i][5])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][4] == players[i][6])
			return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		if (players[i][5] == players[i][6])
			return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][4] == players[i][5])
			return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][4] == players[i][6])
			return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		if (players[i][5] == players[i][6])
			return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		if (players[i][6] == players[i][5])
			return true;
	return false;
}

bool checkStraightFlush(int players[][7], int suits[][7], int i) { // done

	if (checkStraight(players, i))
		if (checkFlush(suits, i))
			return true;

	return false;

}
void checkStraightFlushVoid(int players[][7], int suit[][7], int i) { // done
	int temp[5], tempSuit[5];

	if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]))
	{
		if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4])) {

			players[i][5] = -1;
			players[i][6] = -1;
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}

	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]))
	{

		if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {

			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6]))
	{
		if ((players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {


			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
			temp[0] = players[i][0];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][0] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][0];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][1];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][1];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		if ((players[i][2] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][0];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][0];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][0];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][0];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][1];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][1];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][2];
			temp[1] = players[i][1];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
	else if ((suit[i][1] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		if ((players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
			temp[0] = players[i][1];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}
}


void checkThreeKindVoid(int players[][7], int suit[][7], int i) { // 35 done
	int temp[5], tempSuit[5];
	if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}

	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][4];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][5]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][4])) {
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][5]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][5]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}

}
bool checkThreeKind(int players[][7], int i) { // 35 done
	if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else
		return false;
}

bool checkFourKind(int players[][7], int i) { // 32
	if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
		return true;
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
		return true;
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
		return true;
	else
		return false;
}
void checkFourKindVoid(int players[][7], int suit[][7], int i) { // 32
	int temp[5], tempSuit[5];
	if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][3]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][3];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;

		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][3];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][4];
		temp[2] = players[i][5];
		temp[3] = players[i][6];
		temp[4] = players[i][3];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][5];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][3];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][4];
		temp[2] = players[i][5];
		temp[3] = players[i][6];
		temp[4] = players[i][3];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][5];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][3];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][4];
		temp[2] = players[i][5];
		temp[3] = players[i][6];
		temp[4] = players[i][3];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][4];
		tempSuit[2] = suit[i][5];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][3];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;



	}
	else if ((players[i][3] == players[i][4]) && (players[i][4] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][4]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][3]) && (players[i][3] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][4]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][1]) && (players[i][1] == players[i][2]) && (players[i][2] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][4]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2]) && (players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][5];
		temp[3] = players[i][6];
		temp[4] = players[i][4];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][5];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][4];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3]) && (players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][6]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][4]) && (players[i][4] == players[i][5]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][6]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2]) && (players[i][2] == players[i][3]) && (players[i][3] == players[i][5]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][4]) && (players[i][4] == players[i][6]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3]) && (players[i][3] == players[i][5]) && (players[i][5] == players[i][6]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}

}

bool checkOnePair(int players[][7], int i) { // 21 done
	
	if ((players[i][0] == players[i][1])) {
		return true;
	}
	if ((players[i][0] == players[i][2])) {
		return true;
	}
	if ((players[i][0] == players[i][3])) {
		return true;
	}
	if ((players[i][0] == players[i][4])) {
		return true;
	}
	if ((players[i][0] == players[i][5])) {
		return true;
	}
	if ((players[i][0] == players[i][6])) {
		return true;
	}
	if ((players[i][1] == players[i][2])) {
		return true;
	}
	if ((players[i][1] == players[i][3])) {
		return true;
	}
	if ((players[i][1] == players[i][4])) {
		return true;
	}
	if ((players[i][1] == players[i][5])) {
		return true;
	}
	if ((players[i][1] == players[i][6])) {
		return true;
	}
	if ((players[i][2] == players[i][3])) {
		return true;
	}
	if ((players[i][2] == players[i][4])) {
		return true;
	}
	if ((players[i][2] == players[i][5])) {
		return true;
	}
	if ((players[i][2] == players[i][6])) {
		return true;
	}
	if ((players[i][3] == players[i][4])) {
		return true;
	}
	if ((players[i][3] == players[i][5])) {
		return true;
	}
	if ((players[i][3] == players[i][6])) {
		return true;
	}
	if ((players[i][4] == players[i][5])) {
		return true;
	}
	if ((players[i][4] == players[i][6])) {
		return true;
	}
	if ((players[i][5] == players[i][6])) {
		return true;
	}
	return false;
}
void checkOnePairVoid(int players[][7], int suit[][7], int i) { // 21 done
	int temp[5], tempSuit[5];
	if ((players[i][0] == players[i][1])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][2])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][3])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][4])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][2])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][3])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][4])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][3])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][4])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][4])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][3] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][4] == players[i][5])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][4] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][5] == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}

}

bool checkRoyalFlush(int players[][7], int suits[][7], int i) { // done
	if ((players[i][0] == 0) && (players[i][1] == 9) && (players[i][2] == 10) && (players[i][3] == 11) && (players[i][4] == 12)) {

		if ((suits[i][0] == suits[i][1]) && (suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]))
			return true;
		
	}
	else if ((players[i][1] == 0) && (players[i][2] == 9) && (players[i][3] == 10) && (players[i][4] == 11) && (players[i][5] == 12)) {

		if ((suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]))
			return true;
		
	}
	else if ((players[i][2] == 0) && (players[i][3] == 9) && (players[i][4] == 10) && (players[i][5] == 11) && (players[i][6] == 12)) {

		if ((suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6]))
			return true;
	}
	return false;
}
void checkRoyalFlushVoid(int players[][7], int suit[][7], int i) { // done
	int temp[5], tempSuit[5];
	if ((players[i][0] == 0) && (players[i][1] == 9) && (players[i][2] == 10) && (players[i][3] == 11) && (players[i][4] == 12)) {

		if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]))
		{
			temp[0] = players[i][0];
			temp[1] = players[i][1];
			temp[2] = players[i][2];
			temp[3] = players[i][3];
			temp[4] = players[i][4];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][0];
			tempSuit[1] = suit[i][1];
			tempSuit[2] = suit[i][2];
			tempSuit[3] = suit[i][3];
			tempSuit[4] = suit[i][4];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;

		}


	}
	else if ((players[i][1] == 0) && (players[i][2] == 9) && (players[i][3] == 10) && (players[i][4] == 11) && (players[i][5] == 12)) {


		if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]))
		{
			temp[0] = players[i][1];
			temp[1] = players[i][2];
			temp[2] = players[i][3];
			temp[3] = players[i][4];
			temp[4] = players[i][5];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][1];
			tempSuit[1] = suit[i][2];
			tempSuit[2] = suit[i][3];
			tempSuit[3] = suit[i][4];
			tempSuit[4] = suit[i][5];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}

	}
	else if ((players[i][2] == 0) && (players[i][3] == 9) && (players[i][4] == 10) && (players[i][5] == 11) && (players[i][6] == 12)) {


		if ((suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6]))
		{
			temp[0] = players[i][2];
			temp[1] = players[i][3];
			temp[2] = players[i][4];
			temp[3] = players[i][5];
			temp[4] = players[i][6];
			players[i][0] = temp[0];
			players[i][1] = temp[1];
			players[i][2] = temp[2];
			players[i][3] = temp[3];
			players[i][4] = temp[4];
			players[i][5] = -1;
			players[i][6] = -1;
			tempSuit[0] = suit[i][2];
			tempSuit[1] = suit[i][3];
			tempSuit[2] = suit[i][4];
			tempSuit[3] = suit[i][5];
			tempSuit[4] = suit[i][6];
			suit[i][0] = tempSuit[0];
			suit[i][1] = tempSuit[1];
			suit[i][2] = tempSuit[2];
			suit[i][3] = tempSuit[3];
			suit[i][4] = tempSuit[4];
			suit[i][5] = -1;
			suit[i][6] = -1;
		}
	}


}

bool checkFlush(int suits[][7], int i) { // done
	if ((suits[i][0] == suits[i][1]) && (suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]))
		return true;
	else if ((suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]))
		return true;
	else if ((suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6]))
		return true;
	else if ((suits[i][0] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5])) {
		return true;
	}
	else if ((suits[i][0] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}
	else if ((suits[i][0] == suits[i][1]) && (suits[i][1] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5])) {
		return true;
	}
	else if ((suits[i][0] == suits[i][1]) && (suits[i][1] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}
	else if ((suits[i][0] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5])) {
		return true;
	}
	else if ((suits[i][0] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}
	else if ((suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][3]) && (suits[i][3] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}
	else if ((suits[i][1] == suits[i][2]) && (suits[i][2] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}
	else if ((suits[i][1] == suits[i][3]) && (suits[i][3] == suits[i][4]) && (suits[i][4] == suits[i][5]) && (suits[i][5] == suits[i][6])) {
		return true;
	}

	return false;
}
void checkFlushVoid(int players[][7], int suit[][7], int i) { // done
	int temp[5], tempSuit[5];
	if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]))
	{
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][3];
		temp[4] = players[i][4];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][3];
		tempSuit[4] = suit[i][4];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}

	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]))
	{
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		

	}
	else if ((suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6]))
	{
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][0] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][1];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][1];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((suit[i][0] == suit[i][1]) && (suit[i][1] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][3];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][3];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][0] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][6];
		temp[3] = players[i][5];
		temp[4] = players[i][0];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][6];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][0];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][3]) && (suit[i][3] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][1];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][1];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][1] == suit[i][2]) && (suit[i][2] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][1];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
	else if ((suit[i][1] == suit[i][3]) && (suit[i][3] == suit[i][4]) && (suit[i][4] == suit[i][5]) && (suit[i][5] == suit[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
		
	}
}


bool checkStraight(int players[][7], int i) { // done
	if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]))
		return true;
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]))
		return true;
	else if ((players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6]))
		return true;
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		return true;
	}
	else if ((players[i][0] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}
	else if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		return true;
	}
	else if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		return true;
	}
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}
	else if ((players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		return true;
	}

	return false;
}
void checkStraightVoid(int players[][7], int suit[][7], int i) { // done
	int temp[5], tempSuit[5];
	if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4])) {

		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][2];
		temp[3] = players[i][3];
		temp[4] = players[i][4];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][2];
		tempSuit[3] = suit[i][3];
		tempSuit[4] = suit[i][4];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;

	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][2];
		temp[1] = players[i][3];
		temp[2] = players[i][4];
		temp[3] = players[i][5];
		temp[4] = players[i][6];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][2];
		tempSuit[1] = suit[i][3];
		tempSuit[2] = suit[i][4];
		tempSuit[3] = suit[i][5];
		tempSuit[4] = suit[i][6];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][6];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][6];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][1]) && (players[i][1] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][1];
		temp[2] = players[i][6];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][1];
		tempSuit[2] = suit[i][6];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][0] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][0];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][6];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][0];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][3];
		temp[3] = players[i][6];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][6];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][6];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][6];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] + 1 == players[i][2]) && (players[i][2] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][2];
		temp[2] = players[i][6];
		temp[3] = players[i][3];
		temp[4] = players[i][4];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][2];
		tempSuit[2] = suit[i][6];
		tempSuit[3] = suit[i][3];
		tempSuit[4] = suit[i][4];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
	else if ((players[i][1] + 1 == players[i][3]) && (players[i][3] + 1 == players[i][4]) && (players[i][4] + 1 == players[i][5]) && (players[i][5] + 1 == players[i][6])) {
		temp[0] = players[i][1];
		temp[1] = players[i][6];
		temp[2] = players[i][3];
		temp[3] = players[i][4];
		temp[4] = players[i][5];
		players[i][0] = temp[0];
		players[i][1] = temp[1];
		players[i][2] = temp[2];
		players[i][3] = temp[3];
		players[i][4] = temp[4];
		players[i][5] = -1;
		players[i][6] = -1;
		tempSuit[0] = suit[i][1];
		tempSuit[1] = suit[i][6];
		tempSuit[2] = suit[i][3];
		tempSuit[3] = suit[i][4];
		tempSuit[4] = suit[i][5];
		suit[i][0] = tempSuit[0];
		suit[i][1] = tempSuit[1];
		suit[i][2] = tempSuit[2];
		suit[i][3] = tempSuit[3];
		suit[i][4] = tempSuit[4];
		suit[i][5] = -1;
		suit[i][6] = -1;
	}
}

/*
bool checkHighStraight(int players[][7], int i) {
	if ((players[i][0] == 0) && (players[i][1] == 9) && (players[i][2] == 10) && (players[i][3] == 11) && (players[i][4] == 12))
		return true;

	return false;
}*/