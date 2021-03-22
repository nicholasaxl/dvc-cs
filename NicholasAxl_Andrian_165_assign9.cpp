#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int size = 5; //initial declaration for the size of the array

struct Drink //initial declaration of the structure
{
	string Drink_Name;
	double Cost;
	int Number_In_Machine;
};

void print_menu(Drink arr[]); //function prototype for printing the menu of the program
int get_user_choice(Drink arr[]); //function prototype that will initiate the interaction between the program and the user
                                  //the array is automatically passed by reference so we can directly edit the remaining drinks

int main()
{
    int userChoice; //declaration for the user choice
                    //also to be used as the condition statement for the loop later on
    Drink arr[size]; //declaration for the struct array
    //initialization of each of the arrays
    arr[0]={"Cola      ", .75, 20};
    arr[1]={"Root Beer ", .75, 20};
    arr[2]={"Lemon-Lime", .75, 20};
    arr[3]={"Grape Soda", .80, 20};
    arr[4]={"Cream Soda", .80, 20};
    //loop to print the menu over and over again until the user decided to input 6 to exit
    do{
        //function calls
        print_menu(arr);
        userChoice = get_user_choice(arr);

    }
    while (userChoice != 6); //condition for the program to end



    system("PAUSE");
	return 0;

}

void print_menu(Drink arr[])
{
    //for loop to iterate and print out the arrays from the structure
    for (int i = 0; i<size; i++)
    {
        cout << i+1 << ") ";
        cout << arr[i].Drink_Name << setw(10) << arr[i].Cost << endl;
    }
    //print out the remaining instructions
    cout << "6) Leave the drink machine." << endl;
    cout << " \n";
}

int get_user_choice(Drink arr[])
{
    int user; //declaration to hold the user input
    double money; //declaration to hold the inputted money
    cout << "Choose one: ";
    cin >> user;
    //ends the program if the user chooses 6
    if (user == 6)
    {
        return user;
    }

    //statements for the user to enter their money
    cout << "Enter an amount of money: ";
    cin >> money;

    //input validation for when the money is less than or more than the allowed amount
    while (money < arr[user-1].Cost || money > 1.00)
    {
        cout << "Enter at least " << arr[user-1].Cost << " and not more than 1 dollar: ";
        cin >> money;
    }

    cout << "Enjoy your beverage!" << endl;
    cout << " \n";

    //calculates the change and couts the information once again
    cout << "Change calculated: " << (money - arr[user-1].Cost) << endl;

    //if statement to only print out the money returned if there is change
    if ((money - arr[user-1].Cost) != 0)
    {
        cout << "Your change, " << (money - arr[user-1].Cost) << " has just dropped into the Change Dispenser." << endl;
    }

    cout << " \n";

    (arr[user-1].Number_In_Machine)--; //decrement the amount of beverages left
                                     //note that it is automatically passed by reference so it goes back to main

    cout << "There are " << arr[user-1].Number_In_Machine << " drinks of that type left." << endl; //cout statement for the remaining amount
    cout << " \n";


    return user; //returns the user choice
}
