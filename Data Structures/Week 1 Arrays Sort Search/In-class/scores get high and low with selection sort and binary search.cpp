#include <iostream>
using namespace std;

int main()
{
//Get highest score and lowest score to then take them out. Then take the AVG. for the scores given minus the 2 taken out. 5/23/16
//Now use a selection sort 5.25 to get highest and lowest grade. 5/25/16 part A
//Binary search used at the end to find the grade that needs replacing. 5/25/16 part B

int counter=0,tests,a,b,t,beginning,index, searching,what, wouldYou,cont,mid,searcher,extra,ending, start, curve;
float sum=0;
bool result = false;

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

    }while(tests<0);
}

//makes the array of the specific length of the amount of tests.
int scores[tests];

//ask for the individual scores for each test and store them w/ validation.
do
{
    cout<<"Please enter score for test# "<<counter + 1<<endl;
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
    counter = counter + 1;
} while(counter < tests);

//Selection sort for the scores given
//Start with the first position of the array
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
//for(what = 0; what < tests; what++)
//cout<<scores[what];

//Removes our lowest and highest grades given from our sum
sum = sum - (scores[tests-1] + scores[0]);


cout<<"The highest score is: "<<scores[tests-1]<<endl;

cout<<"The lowest score is: "<<scores[0]<<endl;

cout<<"The average for your student is: "<<sum/(tests-2)<<endl;

cout<<"Would you like to curve any of the grades?"<<endl;
cout<<"Enter 1) for YES"<<endl;
cout<<"Enter 2) for NO"<<endl;
cin>>curve;

if(curve < 1 || curve > 2 )
{
    do
    {
        cout<<"**Please Enter a valid choice**"<<endl;
        cout<<"Would you like to curve any of the grades?"<<endl;
        cout<<"Enter 1) for YES"<<endl;
        cout<<"Enter 2) for NO"<<endl;
        cin>>curve;
    }while(curve < 1 || curve > 2 );

}

if(curve == 1)
{
    do
    {
        cout<<"Which test score would you like to curve?"<<endl;
        cin>>searcher;

        if(searcher < 0 || searcher > 100)
        {
            do
            {
                cout<<"**Please enter a valid test score**"<<endl;
                cout<<"Please enter score for test#"<<counter + 1<<endl;
                cin>>searcher;
            }while(searcher < 0 || searcher > 100);
        }

        start = 0;
        ending = tests - 1;

//I need to fix this part so that it prints out an error if the score does not exist.
        while(start <= ending && !result)
        {
            mid = (start + ending) / 2;

            if(scores[mid] == searcher)
            {
                result = true;
                cout<<"The test exists"<<endl;
                cout<<"How many points would you like to increase the test by?"<<endl;
                cin>>extra;

                    if(extra < 1 || extra > scores[mid])
                    {
                        do
                        {
                            cout<<"**Please enter a valid amount of points to curve the test by**"<<endl;
                            cout<<"The test exists"<<endl;
                            cout<<"How many points would you like to increase the test by?"<<endl;
                            cin>>extra;
                        }while(extra < 1 || extra > scores[mid]);

                            scores[mid] = scores[mid] + extra;

                        cout<<"The new test score is"<<scores[mid]<<endl;

                    }

            }
            else if(scores[mid] > searcher)
            {
                ending = mid - 1;
            }
            else
                start = mid + 1;
        }

    cout<<"Would you like to change another test score?"<<endl;
    cout<<"Enter 1) for YES"<<endl;
    cout<<"Enter 2) for NO"<<endl;
    cin>>wouldYou;

    if(wouldYou < 1 || wouldYou > 2 )
    {
        do
        {
            cout<<"**Please Enter a valid choice**"<<endl;
            cout<<"Would you like to curve any of the grades?"<<endl;
            cout<<"Enter 1) for YES"<<endl;
            cout<<"Enter 2) for NO"<<endl;
            cin>>wouldYou;
        }while(wouldYou < 1 || wouldYou > 2 );

        cont = wouldYou;
    }

    } while (cont != 2);

counter = 0;
    do
    {

        sum = sum + scores[counter];

        //our flow controller
        counter = counter++;
    } while(counter < tests);

    //Selection sort for the scores given
    //Start with the first position of the array
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
    //for(what = 0; what < tests; what++)
    //cout<<scores[what];

    //Removes our lowest and highest grades given from our sum
    sum = sum - (scores[tests-1] + scores[0]);


    cout<<"The highest score is: "<<scores[tests-1]<<endl;

    cout<<"The lowest score is: "<<scores[0]<<endl;

    cout<<"The average for your student is: "<<sum/(tests-2)<<endl;

}

return 0;
}
