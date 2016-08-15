#ifndef SORTER_H
#define SORTER_H
#include "election.h"

class sorter : public election//CHILD OF THE ELECTION CLASS
{
public:
    void bubbleSort();//SORTS THE LINKED LIST FROM HIGHEST VOTE COUNT TO LOWEST
    void bubbleSortNames();//SORTS THE LINKED LIST FROM HIGHEST Name TO LOWEST
};

#endif // SORTER_H
