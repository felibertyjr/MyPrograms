#include "sorter.h"

void sorter::bubbleSort()
{
candidates *nextNode = head;
string tempName;
int tempVotes;
float tempPercent;
int b,counter = 0;

while(nextNode)
{
 counter++;
 nextNode = nextNode->next;
}

nextNode = head;

while(nextNode->next != NULL)
{
    for(b = 0; b <= counter; b++)
    {

        if(nextNode->votes < nextNode->next->votes)
        {

            tempName =  nextNode->next->name;
            tempVotes = nextNode->next->votes;
            tempPercent = nextNode->next->percent;



            nextNode->next->name = nextNode->name;
            nextNode->next->votes = nextNode->votes;
            nextNode->next->percent = nextNode->percent;



            nextNode->name = tempName;
            nextNode->votes = tempVotes;
            nextNode->percent = tempPercent;
        }
    }

nextNode = nextNode->next;
 }

}

void sorter::bubbleSortNames()
{
candidates *nextNode = head;
string tempName;
int tempVotes;
float tempPercent;
int b,counter = 0;

while(nextNode)
{
 counter++;
 nextNode = nextNode->next;
}

nextNode = head;

while(nextNode->next != NULL)
{
    for(b = 0; b <= counter; b++)
    {

        if(nextNode->name > nextNode->next->name)
        {

            tempName =  nextNode->name;
            tempVotes = nextNode->votes;
            tempPercent = nextNode->percent;



            nextNode->name = nextNode->next->name;
            nextNode->votes = nextNode->next->votes;
            nextNode->percent = nextNode->next->percent;



            nextNode->next->name = tempName;
            nextNode->next->votes = tempVotes;
            nextNode->next->percent = tempPercent;
        }
    }

nextNode = nextNode->next;
 }
}
