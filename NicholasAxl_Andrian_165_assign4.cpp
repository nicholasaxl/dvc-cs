#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    //cout instructions for user input
	cout << "Please enter the student's answers for each of the questions." << endl;
	cout << "Press enter after typing each answer." << endl;
	cout << "Please enter only an A, B, C, or D for each question." << endl;

	//array declaration and initialization for the list of correct answer
	char correctAns[20] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B'
	, 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
	//empty array declaration to store the user choices
    char studentAns[20];

    //for loop for user input
    for (int i=0; i<20; i++)
    {
        //user input for each question
        cout << "Question " << i+1 << ": ";
        cin >> studentAns[i];

        //input validation to only accept the input of A, B, C or D
        while (studentAns[i] != 'A' && studentAns[i] != 'B' &&
               studentAns[i] != 'C' && studentAns[i] != 'D')
        {
            cout << "Use only an A, B, C, or D!" << endl;
            cout << "Please try again." << endl;
            cin >> studentAns[i];
        }

    }

    //initial integer declaration to store the amount of correct answers
    int numCorrect = 0;
    //initial integer declaration to store the amount of incorrect answers
    int numWrong = 0;

    //for loop to count the amount of correct and incorrect answers
    for (int j=0; j<20; j++)
    {
        if (correctAns[j] == studentAns[j])
        {
            numCorrect++; //basically adds one to the numCorrect variable whenever the two are  the same
        }
        else if (correctAns[j] != studentAns[j])
        {
            numWrong++; //basically adds one to the numWrong variable whenever the two are not the same
        }

    }

    if (numCorrect >= 15)
    {
        //cout statement saying the user has passed when scoring 15 or above
         cout << "The student passed the exam." << endl;
    }
    else
    {
        //cout statement saying the user has failed when scoring below 15
         cout << "The student failed the exam." << endl << endl;
    }

    //cout statement to display the # of correct answers
    cout << "Correct Answers: " << numCorrect << endl;
    //cout statement to display the # of incorrect answers
    cout << "Inorrect Answers: " << numWrong << endl;
    //introductory cout statement to the list of questions answered incorrectly
    cout << "Questions that were answered incorrectly:" << endl;

    for (int k=0; k<20; k++) //for loop to iterate through both arrays
    {
        if (correctAns[k] != studentAns[k])
        {
            cout << k+1 << endl; //couts the question number when the answer is incorrect
        }

    }





    return 0; //in this case, ends the program

	/*
	for (int i=0; i<20; i++)
        cout << correctAns[i] << endl;
    */

}
