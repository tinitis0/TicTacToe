#include <iostream>
using namespace std;

char Field[10] = { 'o','1','2','3','4','5','6','7','8','9' };// this array of numbers for the board which is set up as 3 by 3

int wincond(); // integer to check win condition
void board();

int main()
{
	int player = 1, i, choice;

	char mark;
	do
	{
		board();
		player = (player % 2) ? 1 : 2; // alternates between player one and player 2 once the move has been made

		cout << "Player " << player << ", enter a number:  "; // displays which players turn it is
		cin >> choice; // allows player to enter number between 1 and 9 for their turn.

		mark = (player == 1) ? 'X' : '0'; // player 1 is X and player 2 is 0.
		// once the number on the board is slecected then the assigned field to the number changes to player symbol(X or 0)
		if (choice == 1 && Field[1] == '1')

			Field[1] = mark;
		else if (choice == 2 && Field[2] == '2')

			Field[2] = mark;
		else if (choice == 3 && Field[3] == '3')

			Field[3] = mark;
		else if (choice == 4 && Field[4] == '4')

			Field[4] = mark;
		else if (choice == 5 && Field[5] == '5')

			Field[5] = mark;
		else if (choice == 6 && Field[6] == '6')

			Field[6] = mark;
		else if (choice == 7 && Field[7] == '7')

			Field[7] = mark;
		else if (choice == 8 && Field[8] == '8')

			Field[8] = mark;
		else if (choice == 9 && Field[9] == '9')
			// if the field is taken or and invalid number/character is inputed then the system desplays an error message
			Field[9] = mark;
		else
		{
			cout << "Invalid move "; // error message

			player--;
			cin.ignore();
			cin.get();
		}
		i = wincond(); // checks the win conditions after each move

		player++; // changes player after each turn
	} while (i == -1);
	board();// if the win conditions are met then the victory message is desplayed
	if (i == 1)

		cout << "Player " << --player << " wins";
	else // if there is no winner then the draw message is desplayed
		cout << "Game draw";

	cin.ignore();
	cin.get();
	return 0;
}




void board() // board for the game
{
	system("cls"); // this makes sure that the game is not reprinted after each turn

	cout << " Welcome to Tic Tac Toe\n"; // title

	cout << "------------------------------" << endl; // seperate the board from text so it stands out

	cout << endl;
	// board for the game with lines saparating each field to make it look better and easier to understand
	cout << "     |     |     " << endl;
	cout << "  " << Field[1] << "  |  " << Field[2] << "  |  " << Field[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << Field[4] << "  |  " << Field[5] << "  |  " << Field[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << Field[7] << "  |  " << Field[8] << "  |  " << Field[9] << endl;

	cout << "     |     |     " << endl << endl;

	cout << "Player 1 (X)  -  Player 2 (0)" << endl << endl; // displays which players turns it is.
	cout << "------------------------------" << endl;
}

int wincond() //win conditions for the game
{
	if (Field[1] == Field[2] && Field[2] == Field[3]) // if field 1 2 3 are same then there is a winner

		return 1;
	else if (Field[4] == Field[5] && Field[5] == Field[6])// if field 4 5 6 are same then there is a winner

		return 1;
	else if (Field[7] == Field[8] && Field[8] == Field[9])// if field 7 8 9 are same then there is a winner

		return 1;
	else if (Field[1] == Field[4] && Field[4] == Field[7])// if field 1 4 7 are same then there is a winner

		return 1;
	else if (Field[2] == Field[5] && Field[5] == Field[8])// if field 2 5 8 are same then there is a winner

		return 1;
	else if (Field[3] == Field[6] && Field[6] == Field[9])// if field 3 6 9 are same then there is a winner

		return 1;
	else if (Field[1] == Field[5] && Field[5] == Field[9])// if field 1 5 9 are same then there is a winner

		return 1;
	else if (Field[3] == Field[5] && Field[5] == Field[7])// if field 3 5 7 are same then there is a winner

		return 1;
	// if the fields are not  in victory condition then its a draw
	else if (Field[1] != '1' && Field[2] != '2' && Field[3] != '3'
		&& Field[4] != '4' && Field[5] != '5' && Field[6] != '6'
		&& Field[7] != '7' && Field[8] != '8' && Field[9] != '9')

		return 0;
	else // if there is no draw or victory game carries on until one of the conditions are met
		return -1;
	// 1 is for victory
	// 0 is for draw 
	// -1 is when game is not over. (1 or 0 not met)
}

