#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main()
{
	double score1;
	double score2;
	double score3;
	double score4;
	double score5;

    //function call for the 5 scores
	getJudgeData(score1); //judge data for the first score
    getJudgeData(score2); //judge data for the second score
    getJudgeData(score3); //judge data for the third score
    getJudgeData(score4); //judge data for the fourth score
    getJudgeData(score5); //judge data for the fifth score


    calcScore(score1, score2, score3, score4, score5); //function call with the pass by reference updated scores

	system("PAUSE");
    return 0;
}

void getJudgeData(double &score)
{
    cout << "Enter a judge's score: "; //instructions for user
    cin >> score; //user input for score
    while (score > 10 || score < 0) //while loop for input validation
    {
        cout << "The score must be between 0.0 and 10.0" << endl;
        cout << "Enter a judge's score: ";
        cin >> score; //to reinput the score
    }
}

void calcScore(double score1, double score2, double score3, double score4, double score5)
{

    double lowestScore; //initial declaration to store lowest score
    double highestScore; //initial declaration to store highest score
    lowestScore = findLowest(score1, score2, score3, score4, score5); //function call to find the lowest score and then assigning it to the double variable
    highestScore = findHighest(score1, score2, score3, score4, score5); //function call to find the highest score and then assigning it to the double variable
    double totalScore = (score1 + score2 + score3 + score4 + score5 - lowestScore - highestScore)/3; //calculation for the average score (including dropping the highest and lowest value)

    cout << "After dropping the lowest and highest scores, the average score was: " << totalScore << endl; //final cout statement
}

double findLowest(double score1, double score2, double score3, double score4, double score5)
{
    int lowest = score1; //initial default declaration

    //if statements where if the current value is lower than the value compared,
    //the compared value will replace the current value for lowest value
    if (lowest < score2)
    {
        lowest = score2;
    }
    if (lowest < score3)
    {
        lowest = score3;
    }
    if (lowest < score4)
    {
        lowest = score4;
    }
    if (lowest < score5)
    {
        lowest = score5;
    }
    return lowest; //return the value for lowest

}

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
    int highest = score1; //initial default declaration

    //if statements where if the current value is higher than the value compared,
    //the compared value will replace the current value for highest value
    if (highest > score2)
    {
        highest = score2;
    }
    if (highest > score3)
    {
        highest = score3;
    }
    if (highest > score4)
    {
        highest = score4;
    }
    if (highest > score5)
    {
        highest = score5;
    }
    return highest; //return the value for highest

}
