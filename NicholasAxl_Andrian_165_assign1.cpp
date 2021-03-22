#include <iostream>
#include <string>
using namespace std;



int main()
{
    //declare the first few strings and doubles that will hold the data for the runner and their time taken
    string runner1, runner2, runner3;
    double time1, time2, time3;
    //instruction output for the user
    cout << "Enter the name of three runners and their finishing times. \n";
    cout << "I will tell you who came in first, second, and third. \n";
    //input the first runner's name
    cout << "Name of Runner 1: ";
    getline(cin, runner1);
    //input the first runner's time taken
    cout << "Runner 1's finishing time: " ;
    cin >> time1;
    //input validation for when the user inputs a negative value for the time taken
    if (time1 < 0)
    {
        cout << "ERROR\nTIME TAKEN CANNOT BE NEGATIVE";
        return 0;
    };
    //to prevent whitespace and newline from flowing down
    cin.ignore();

    //same explanation as that from runner 1
    cout << "Name of Runner 2: ";
    getline(cin, runner2);
    cout << "Runner 2's finishing time: " ;
    cin >> time2;
    if (time2 < 0)
    {
        cout << "ERROR\nTIME TAKEN CANNOT BE NEGATIVE";
        return 0;
    };
    cin.ignore();


    //same explanation as that from runner 2
    cout << "Name of Runner 3: ";
    getline(cin, runner3);
    cout << "Runner 3's finishing time: " ;
    cin >> time3;
    if (time3 < 0)
    {
        cout << "ERROR\nTIME TAKEN CANNOT BE NEGATIVE";
        return 0;
    };
    cin.ignore();




    //second set of string declarations used to store the final placements of each runner
    string first,second,third;


    //logic gates for each runner to be able to win first
    if (time1<time2 && time1<time3)
    first = runner1;
    else if (time2<time1 && time2<time3)
    first = runner2;
    else
    first = runner3;


    //logic gates for each runner to be able to win second
    if ((time1<time2 && time1>time3)||(time1<time3 && time1>time2))
    second = runner1;
    else if ((time2<time1 && time2>time3)||(time2<time3 && time2>time1))
    second = runner2;
    else
    second = runner3;


    //logic gates for each runner to be able to win third
    if (time1>time2 && time1>time3)
    third = runner1;
    else if (time2>time1 && time2>time3)
    third = runner2;
    else
    third = runner3;

    //final line of code to output the final placements for each runner
    cout << first + " came in first place!\n";
    cout << second + " came in second place!\n";
    cout << third + " came in third place!\n" <<;

    return 0; //just to properly end the program
}




