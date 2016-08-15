#include <iostream>
using namespace std;

int main()
{
//Get highest score and lowest score. AVG. for 8 scores

int scores[8], counter=0, low=100, high=0;
float sum=0;

cout<<"Please enter the score for the student"<<endl;

do
{
cin>>scores[counter];


if (scores[counter]< low)
{
    low = scores[counter];
    sum = sum + scores[counter];
}
else if (scores[counter] > high)
{
    high = scores[counter];
    sum = sum + scores[counter];
}

else
    sum = sum + scores[counter];

counter = counter++;
} while(counter < 8);

sum = sum - (high + low);

cout<<"The highest score is: "<<high<<endl;


cout<<"The lowest score is: "<<low<<endl;

cout<<"The average for your student is: "<<sum/6<<endl;

return 0;
}
