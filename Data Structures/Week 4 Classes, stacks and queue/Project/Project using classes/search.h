#ifndef SEARCH_H
#define SEARCH_H

#include "sorter.h"
using namespace std;

class searcher : public sorter//Grand child of election and child of sorter
{
public:
    bool found;//PUBLIC VARIABLE
    searcher(){found = false;};//CONSTRUCTOR TO GIVE A DEFAULT VALUE TO "FOUND" VARIABLE
    void searching(string searchItem);//SEARCHES THE LINK LIST TO SEE IF THE CANDIDATE EXISTS IN LINK LIST

#endif // SEARCH_H
