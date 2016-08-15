#include "search.h"//IMPORT GRAND CHILD OF ELECTION.H AND CHILD OF SORTER.H
using namespace std;


int main()
{
int num, a, votes, change;
string name, searchItem;

searcher something;//an instance of our search class


//===================================================================//
//This section is to know how many times to add an item to the link list

cout<<"How many candidates do we have this election?\n";
cin>>num;

if(num <= 0 || cin.fail()){
    do{
        cin.clear();
        cin.ignore();
        cout<<"** Invalid **\n";
        cout<<"How many candidates do we have this election?\n";
        cin>>num;
    }while(num <= 0 || cin.fail());
}//END
//==================================================================//


//================================================================//
//THIS SECTION IS TO INPUT DATA INTO THE LINK LIST.
for(a = 0; a < num; a++)
{
    cout<<"Enter candidate "<<a+1<<"'s name\n";
    cin>>name;
        if(cin.fail()){
            do{
                cin.clear();
                cin.ignore();
                cout<<"** Invalid **\n";
                cout<<"Enter candidate"<<a+1<<"'s name\n";
                cin>>name;
            }while(cin.fail());
        }


    cout<<"How many votes did "<<name<<" receive?\n";
    cin>>votes;
        if(cin.fail()){
            do{
                cin.clear();
                cin.ignore();
                cout<<"** Invalid **\n";
                cout<<"How many votes did "<<name<<" receive?\n";
                cin>>votes;
            }while(cin.fail());
        }

        something.addCandidate(name,votes);//THIS IS THE FUNCTION TO ADD CANDIDATES
}//END
//=================================================================//

//PRINTS OUT THE OUTPUT OF OUR RESULTS USING FUNCTIONS
cout<<"This is the list unsorted\n";
something.printElectionResults();//THIS FUNCTIONS FROM ELECTION.H

cout<<"This is the sorted list from highest to lowest\n";
something.bubbleSort();//THIS FUNCTIONS FROM SORTER.H
something.printElectionResults();//THIS FUNCTIONS FROM ELECTION.H
something.printWinner();//THIS FUNCTIONS FROM ELECTION.H


//================================================================//
//THIS SECTION IS TO ASK IF ANY VOTES NEED TO BE UPDATED
do{
    cout<<"Do you have to update any of the votes?\n";
    cout<<"Enter 1) YES \nEnter 2) NO\n";
    cin>>change;
        if(change < 1 || change > 2 || cin.fail()){
            do{
                cin.clear();
                cin.ignore();
                cout<<"** Invalid **\n";
                cout<<"Do you have to update any of the votes?\n";
                cout<<"Enter 1) YES \n Enter 2) NO\n";
                cin>>change;
            } while(change < 1 || change > 2 || cin.fail());
        }

    if(change == 1){
        something.found = false;
        cout<<"What candidate would you like to change?\n";
        cin>>searchItem;

        something.bubbleSortNames();
        something.printElectionResults();//FOR DEBUG
        something.searching(searchItem);

        if(something.found == false || cin.fail()){
            do{
                cin.clear();
                cin.ignore();
                cout<<"** Invalid **\n";
                cout<<"What candidate would you like to change?\n";
                cin>>searchItem;
                something.searching(searchItem);
            }while(something.found == false || cin.fail());
        }
    }

}while(change != 2);//END

//PRINTS OUT THE OUTPUT OF OUR RESULTS USING FUNCTIONS
cout<<"This is the list unsorted\n";
something.printElectionResults();//THIS FUNCTIONS FROM ELECTION.H

cout<<"This is the sorted list from highest to lowest\n";
something.bubbleSort();//THIS FUNCTIONS FROM SORTER.H
something.printElectionResults();//THIS FUNCTIONS FROM ELECTION.H
something.printWinner();//THIS FUNCTIONS FROM ELECTION.H

return 0;
}
