#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//The purpose of this program is a lottery game. Pick 5 random numbers then compare with what the user chooses.

int main()
{

int lottoNumbers[5], guess[5], choice, i, index, beginning, searching,temporary;
string result;

do{
    //This is to initialize the rand function.
    srand (time(NULL));

    //for loop to get 5 numbers that range from 1-40 and store it in the array
    for(i=0;i<5;i++){
        lottoNumbers[i] = rand() % 40 + 1;
        //  v-- for debug --v
        //cout<<lottoNumbers[i]<<endl;
    }



//-------------------------------------

    //Selection sort for the scores given
    //Start with the first position of the array
    for(index = 0;index < 5; index++)
    {
        //then assign that left most position to a variable "beginning"
        beginning = index;

        //This part of the loop starts sorting the array from least to greatest
        for(searching = index + 1; searching < 5; searching++)
        {
            //checks to see if the element at a higher index position in the array is less than the lower index position specified. If not increments the higher index by one more.
            if(lottoNumbers[searching] < lottoNumbers[beginning])
                beginning = searching;
        }
    //variable used to temp store our lowest value found that should be moved to a lower index position
    temporary = lottoNumbers[beginning];
    //This replace the higher number stored in that index into a higher index position. Increasing
    lottoNumbers[beginning] = lottoNumbers[index];
    //This replaces our current "low" index value with a low value number. Decreasing part
    lottoNumbers[index] = temporary;
    }

//----------------------------------------
//This section asks the client to guess the lotto numbers

    int pick;

    //This section of code is to ask the user for the 5 numbers
    cout<<"Try your luck and pick 5 numbers from 1-40\n";

    //This is the loop to get the 5 numbers w/ input validation.
    for(pick = 0;pick < 5; pick++){
        cin>>guess[pick];

        if(guess[pick]< 1 || guess[pick] >40){
            do{
                cout<<"**Please Enter a valid choice**"<<endl;
                cout<<"Try your luck and pick 5 numbers from 1-40\n";
                cin>>guess[pick];
            } while(guess[pick] < 1 || guess[pick] > 40);

        }

    }

//-----------------------------------------
//This section is to check if the users numbers match the lotto numbers

    int start = 0, lastPick = 4, mid, counter;
    bool found = false;

    do{
        while(start <= lastPick && !found){
            mid = (start + lastPick)/2;
            counter = 0;
            if(lottoNumbers[mid] == guess[counter])
                found = true;
            else if(lottoNumbers[mid] > guess[counter])
                lastPick = mid - 1;
            else
                start = mid + 1;

            counter = counter++;
        }
    }while (counter > 0 && found);

    if (found == false)
        cout<<"You lose!\n";
    else{
        cout<<"You win!\n";
    }

//------------------------------------------
//This section asks if the user would like to play again

    cout<<"Would you like to play again?"<<endl;
    cout<<"Enter 1) for YES"<<endl;
    cout<<"Enter 2) for NO"<<endl;
    cin>>choice;

    if(choice < 1 || choice > 2 )
    {
        do
        {
            cout<<"**Please Enter a valid choice**"<<endl;
            cout<<"Would you like to play again?"<<endl;
            cout<<"Enter 1) for YES"<<endl;
            cout<<"Enter 2) for NO"<<endl;
            cin>>choice;
        }while(choice < 1 || choice > 2 );
    }
} while (choice != 2);
return 0;




}
