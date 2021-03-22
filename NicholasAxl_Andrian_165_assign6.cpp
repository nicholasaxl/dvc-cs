#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;


	int testArray[ROWS][COLS] =
					{{ 2,  4,  6, 8, 10  },
					{  12,  14,  16, 18, 20 },
					{  22,  24,  26, 28, 30 },
					{  32,  34,  36, 38, 40 } };


	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;


	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;


	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;


	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;


	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;


	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;

    system("PAUSE");
	return 0;
}


int getTotal(int array[][COLS], int rows)
{
    int total = 0; //initial declaration for the variable to hold the total value
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++) //for loop to iterate through a 2d array
        {
            total += array[i][j]; //adds the value of each member of the array to the total
        }
    }
    return total; //return the total value
}


double getAverage(int array[][COLS], int rows)
{
    double total = 0; //initial declaration for the variable to hold the total value
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++) //for loop to iterate through a 2d array
        {
            total += array[i][j]; //adds the value of each member of the array to the total
        }
    }
    return total/((COLS)*(rows)); //return the total value divided by the total amount of elements to get the average

}


int getRowTotal(int array[][COLS], int rowToTotal)
{
    int total = 0; //initial declaration for the variable to hold the total value
    for(int j = 0; j < COLS; j++) //iterate through the row
    {
        total += array[rowToTotal][j]; //add the elements in the row
    }
    return total; //return the total value
}


int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
    int total = 0; //initial declaration for the variable to hold the total value
    for(int i = 0; i < rows; i++) //iterate through the column
    {
        total += array[i][colToTotal]; //add the elements in the column
    }
    return total; //return the total value
}


int getHighestInRow(int array[][COLS], int rowToSearch)
{
    int highest = array[rowToSearch][0]; //initial the highest value to the first element of the array
    for(int j = 0; j < COLS; j++) //iterate through the row
    {
        if (highest < array[rowToSearch][j]) //if statement for when the compared value is higher
        {
            highest = array[rowToSearch][j]; //reassign highest to the higher value
        }
    }
    return highest; //return that highest value
}


int getLowestInRow(int array[][COLS], int rowToSearch)
{
    int lowest = array[rowToSearch][0]; //initial the lowest value to the first element of the array
    for(int j = 0; j < COLS; j++) //iterate through the row
    {
        if (lowest > array[rowToSearch][j])  //if statement for when the compared value is lower
        {
            lowest = array[rowToSearch][j]; //reassign highest to the lower value
        }
    }
    return lowest; //return that lowest value
}

