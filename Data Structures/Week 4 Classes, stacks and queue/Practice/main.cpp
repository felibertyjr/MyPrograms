#include "numberlist.h"
using namespace std;

int main()
{
    numberlist lister;

    lister.add(2.5);
    lister.add(7.9);
    lister.add(12.6);
    lister.displayList();
    cout<<endl;
    return 0;

}
