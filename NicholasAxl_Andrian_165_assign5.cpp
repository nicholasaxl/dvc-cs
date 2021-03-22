#include<iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
const int MIN  = 1;
const int MAX  = 9;

void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

int main()
{

   int magicArray[ROWS][COLS] = { {8, 1, 6},
                                  {3, 5, 7},
                                  {4, 9, 2} };



   int normalArray[ROWS][COLS] = { {4, 9, 2} ,
                                   {7, 5, 3} ,
                                   {6, 8, 1} };


   showArray(normalArray);
   showResult(normalArray);

   showArray(magicArray);
   showResult(magicArray);

   system("PAUSE");
   return 0;
}


void showResult(int values[][COLS])
{

   if (isMagicSquare(values))
   {

      cout << "This is a Lo Shu magic square.\n\n";
   }
   else
   {

      cout << "This is not a Lo Shu magic square.\n\n";
   }
}


void showArray(int values[][COLS])
{

   for (int row = 0; row < ROWS; row++)
   {
      for (int col = 0; col < COLS; col++)
      {
         cout << values[row][col] << " ";
      }

      cout << endl;
   }
}


bool isMagicSquare(int values[][COLS])
{
    //returns true if all the other conditions for a magic square is true
    if (checkRange(values) && checkUnique(values) && checkRowSum(values) && checkColSum(values) && checkDiagSum(values))
	{
	    return true;
	}
}

bool checkRange(int values[][COLS])
{
    //iterates through a 2 dimensional array
   for (int i = 0; i < ROWS; i++)
   {
       for (int j = 0; j < COLS; j++)
       {
            if (values[i][j] <= 9 && values[i][j] >= 0)
                {

                }
            else
                return false; //returns false if there is a value above or below the range of numbers
       }
   }
   return true; //returns true if the numbers are within the given range
}


bool checkUnique(int values[][COLS])
{
	for (int i = 0; i < (ROWS*COLS); i++) //alternate iteration of a 2d array (making it into a flat array)
        {
		for (int j = 0; j < i; j++) {
			if (values[i] != values[j])
            {
				return true; // return true when there is no repeating value
			}
			else {
				return false; //otherwise return false
			}
		}
	}

}

bool checkRowSum(int values[][COLS])
{
    //checks the sum of the first row
	int firstRowSum = 0;
	for(int j = 0; j < COLS; j++) {
		firstRowSum += values[0][j];
	}

	//compares the other rows to the first row to see if they all match
	for(int i = 1; i < ROWS; i++)
        {
		int rowSum = 0;
		for(int j = 0; j < COLS; j++) {
			rowSum += values[i][j];
		}

		if(rowSum != firstRowSum)
			return false; //otherwise, return false if one of them does not match
	}

	return true; //return true only if they all match the same number when added up
}


bool checkColSum(int values[][COLS])
{
        //basically the same logic as the rows one but with cols instead
        //checks the sum of the first column
        int topColSum = 0;
        for(int j = 0; j < ROWS; j++)
        {
            topColSum += values[j][0];
        }

        //compares the other columns to the first columns to see if they all match
        for(int i = 1; i < COLS; i++)
        {
            int colSum = 0;
            for(int j = 0; j < ROWS; j++)
            {
                colSum += values[j][i];
            }
            if(colSum != topColSum)
                return false; //otherwise, return false if one of them does not match
        }
        return true; //return true only if they all match the same number when added up
}


bool checkDiagSum(int values[][COLS])
{
          //creates the initial variable to hold the sum value
          int firstSum = 0;

          for(int j = 0; j < COLS; j++) //loop to iterate through the array
          {

            firstSum += values[j][j]; //adds the diagonal sum

          }

          //same as the above but with the 2nd set of values
          int secondSum = 0;

          int j = ROWS - 1;

          for(int i = 0; i < COLS; i++, j--)
          {

            secondSum += values[j][i];

          }

          //return the first sum if it is equal to the second sum
          if (firstSum == secondSum)
            return true;

}
