#include <iostream>
using namespace std;

int main()
{
//Get highest score and lowest score. AVG. for 8 scores 5/23/16
//Now use a selection sort 5.25

int counter=0,tests,a,b,t,beginning,index, searching,what;
float sum=0;

//Ask user for test scores
cout<<"How many tests did the student take?"<<endl;
cin>>tests;

//Ask for the amount of tests w/ validation
if (tests<0)
{
    do
    {
        cout<<"**Please enter a valid number of tests**"<<endl;

        cout<<"How many tests did the student take?"<<endl;
        cin>>tests;

    }while(tests<0 || tests>100);
}

//makes the array of the specific length of the amount of tests.
int scores[tests];

//ask for the individual scores for each test and store them w/ validation.
do
{
    cout<<"Please enter score for test#"<<counter + 1<<endl;
    cin>>scores[counter];

        if(scores[counter] < 0 || scores[counter] > 100)
        {
            do
            {
                cout<<"**Please enter a valid test score**"<<endl;
                cout<<"Please enter score for test#"<<counter + 1<<endl;
                cin>>scores[counter];
            }while(scores[counter] < 0 || scores[counter] > 100);
        }

    //Sum up all scores given so we can use later for avg
    sum = sum + scores[counter];

    //our flow controller
    counter = counter++;
} while(counter < tests);

//Selection sort for the scores given
//Start with the first postion of the array
    for(index = 0;index < tests; index++)
    {
        //then assign that left most position to a variable "beginning"
        beginning = index;

        //This part of the loop starts sorting the array from least to greatest
        for(searching = index + 1; searching < tests; searching++)
        {
            //checks to see if the element at a higher index position in the array is less than the lower index position specified. If not increments the higher index by one more.
            if(scores[searching] < scores[beginning])
                beginning = searching;
        }
    //variable used to temp store our lowest value found that should be moved to a lower index position
    t = scores[beginning];
    //This replace the higher number stored in that index into a higher index position. Increasing
    scores[beginning] = scores[index];
    //This replaces our current "low" index value with a low value number. Decreasing part
    scores[index] = t;
    }
//for debug
for(what = 0; what < tests; what++)
cout<<scores[what];

//Removes our lowest and highest grades given from our sum
sum = sum - (scores[tests-1] + scores[0]);


cout<<"The highest score is: "<<scores[tests-1]<<endl;

cout<<"The lowest score is: "<<scores[0]<<endl;

cout<<"The average for your student is: "<<sum/(tests-2)<<endl;

return 0;
}
