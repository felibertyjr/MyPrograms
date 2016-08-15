#include <iostream>
using namespace std;

int main()
{
int checks;

cout<<"How many checks did you issue this month?\n";
cin>>checks;

if (checks > 0)
    {
        switch(checks / 10)
        {
            case 0:
            case 1: cout<<"The fees for the month are: $"<<checks * (.10);
                    break;
            case 2:
            case 3: cout<<"The fees for the month are: $"<<checks * (.08);
                    break;
            case 4:
            case 5: cout<<"The fees for the month are: $"<<checks * (.06);
                    break;

            default: cout<<"The fees for the month are: $"<<checks * (.04);
                break;

        }
    }
else
    cout<<"WARNING: What you entered is NOT a valid number of checks";

return 0;
}
