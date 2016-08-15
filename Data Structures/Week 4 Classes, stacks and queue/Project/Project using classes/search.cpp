#include "search.h"
using namespace std;

void searcher::searching(string searchItem)
{
candidates *nextNode = head;
int first = 0, votes = 0, counter=0, last, mid, a;


while(nextNode != NULL)
{
    counter++;
	nextNode = nextNode->next;
}


nextNode = head;
last = counter - 1;

while(first <= last && !found){
		mid = (first + last) /2;

    for(a=0; a<mid;a++)
    {
        nextNode = nextNode->next;
    }


    if(nextNode->name == searchItem){
        found = true;
        cout<<"What is the updated vote count?\n";
        cin>>votes;

        if(votes <= 0 || cin.fail()){
            do{
                cin.clear();
                cin.ignore();
                cout<<"** Invalid **\n";
                cout<<"What is the updated vote count?\n";
                cin>>votes;
            }while(votes <= 0 || cin.fail());
        }

        nextNode->votes = votes;
    }
    else if(nextNode->name > searchItem)
    {
        nextNode = head;
        last = mid - 1;
    }
    else
    {
        nextNode = head;
        first = mid + 1;
    }
}
}
