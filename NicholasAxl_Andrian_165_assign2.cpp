#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROCK		= 1;
const int PAPER		= 2;
const int SCISSORS	= 3;
const int QUIT      = 4;

int getUserChoice();
int getComputerChoice();
void determineOutcome(int, int);
void displayChoice(int);

int main()
{
	int userChoice;
	int computerChoice;

	computerChoice = getComputerChoice();

	userChoice = getUserChoice();

	while (userChoice != QUIT)
	{

		cout << "\nYou selected: ";
		displayChoice(userChoice);
		cout << "The computer selected: ";
		displayChoice(computerChoice);

		determineOutcome(userChoice, computerChoice);
		cout<<endl;

		computerChoice = getComputerChoice();

		userChoice = getUserChoice();
	}

	system("PAUSE");
	return 0;
}


int getComputerChoice()
{
    int randomNumber; //placeholder to store the random number
    randomNumber = rand() % 3 + 1; //generates random number form 1 to 3
    switch (randomNumber) //
    {
        case 1:
            return 1;
            break;

        case 2:
            return 2;
            break;

        case 3:
            return 3;
            break;

    } //switch statements to return either r p or s
}


int getUserChoice()
{
    int userChoice; //placeholder for user choice
    do{
        cout << "1) Rock\n";
        cout << "2) Paper\n";
        cout << "3) Scissors\n";
        cout << "4) QUIT\n";      //Menu choices

        cin >> userChoice; //user input

        if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4)
        {
            cout << "ERROR! please only input either 1, 2, 3 or 4! \n"; //input validation block
        }
    }
    while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4);


    return userChoice; //returns the number for r p or s

}


void determineOutcome(int user, int computer) //determines the outcome and shows it back to the user
{
    if (user == computer)
    {
        cout << "Tie. No Winner. \n";
    }
    else if (user == 1 && computer == 2)
    {
        cout << "Computer wins! Paper beats rock! \n";
    }
    else if (user == 1 && computer == 3)
    {
        cout << "You win! Rock beats scissors! \n";
    }
    else if (user == 2 && computer == 1)
    {
        cout << "You win! Paper beats rock! \n";
    }
    else if (user == 2 && computer == 3)
    {
        cout << "Computer wins! Scissor beats paper! \n";
    }
    else if (user == 3 && computer == 1)
    {
        cout << "Computer wins! Rock beats scissors! \n";
    }
    else if (user == 3 && computer == 2)
    {
        cout << "You win! Scissor beats paper! \n";
    }
}


void displayChoice(int choice) //displays the the choices for both the user and the computer
{
    switch (choice)
    {
        case 1:
            cout << "Rock\n";
            break;
        case 2:
            cout << "Paper\n";
            break;
        case 3:
            cout << "Scissors\n";
            break;
    }
}

