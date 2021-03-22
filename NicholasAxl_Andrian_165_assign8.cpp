#include <iostream>
using namespace std;

int getMode(int*, int);
int* makeArray(int);

// main has been completed for you

int main()
{
	const int SIZE = 5;
	int test[SIZE] = {1, 1, 1, 2, 3};
	int mode;

	mode = getMode(test, SIZE);

	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: "
		     << mode << endl;

    system("PAUSE");
	return 0;
}

int getMode(int *array, int size)
{

	// frequencies will point at a dynamically allocated array
	// in this assignment pointer notation (i.e., using the *) should always be used instead of
	// bracket/subscript notation (i.e., using the []).

	int* frequencies = makeArray(size);

    int sum = 0; //declaration for the variable that will hold the sum of frequencies
    int mode; //variable declaration to hold the mode number
    int modeCount; //variable declaration to hold the mode's frequency

	for (int i = 0; i < size; i++) //for loop to iterate through parallel arrays
    {
        *(frequencies+i) = 0; //declare the first value's frequency to 0
        for (int j = 0; j < size; j++)
        {
            if(*(array+i) == *(array+j)) //condition for when the same number is found within the array
                sum++;
        }
        *(frequencies+i) += sum; //link the first frequency to the amount of times that number within the i is displayed
        sum = 0; //redeclare sum to 0 for another usage
    }

    modeCount = *(frequencies+0); //initial value of modeCount

    for (int i = 0; i < size; i++)
    {
        if ((*(frequencies+i)) > modeCount)
        {
            modeCount = *(frequencies+i); //reassigns modeCOunt to a value that is bigger whenever found
        }
    }


    for (int i = 0; i < size; i++)
    {
        if ((*(frequencies+i)) >= modeCount)
        {
            mode = (*(array+i)); //assigns the value of mode as the number with the highest frequency through parallel arrays
        }

    }


    if (modeCount == 1) //return -1 if the highest frequency is only 1
    {
        return -1;
    }
    else
    {
        return mode;
    }








	delete[] frequencies; // Do NOT remove this -- this needs to be at the end of the function
	                       // to remove the dynamically allocated frequencies array from memory
	                       // when it is no longer needed.

}



// makeArray has been completed for you

int* makeArray(int size)
{
	return new int[size];
}





