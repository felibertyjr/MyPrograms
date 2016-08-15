#include <iostream>
using namespace std;

string servType;
int service;
int minutesR, minutesN = 0, totalDay = 0, totalNight = 0;

int main()
{
cout<<"What type of service does the customer have?\n";
cout<<"Please type 1 for regular or 2 for premium\n";
cin>>service;


//I should rewrite this to use an int as my choice like choice 1 or choice 2 instead of having to use a char because I have to use an "or"
if (service == 1)
    {
        servType = "Regular"
        cout<<"How many minutes were used?";
        cin>>minutesR;
            if (minutesR >= 0 && minutesR < 51)
                cout<<"Your total is $10.00";
            else if (minutesR > 50)
                cout<<"Your total is: $"<<10.00 + (minutesR * .20);
            else
                cout<<"You did not enter a valid quantity\n";

    }
else if (service == 2)
    {
        servType = "Premium"
        cout<<"How many minutes were used between 0600 - 1400?";
        cin>>minutesR;
            if (minutesR >= 0 && minutesR < 76)
                totalDay = 0;
            else if (minutesR > 75)
                totalDay = (minutesR * .20);
            else
                cout<<"You did not enter a valid quantity\n";


        cout<<"How many minutes were used between 1401 - 0599?";
        cin>>minutesN;
            if (minutesN >= 0 && minutesN < 101)
                totalNight = 0;
            else if (minutesN > 100)
                totalNight = (minutesN * .05);
            else
                cout<<"You did not enter a valid quantity\n";
    }
else
    {cout<<"You did not make a valid selection"<<endl;
    return 0;
    }

cout<<"The service type you selected is: "<<servType<<endl;
cout<<"The amount of minutes used are: "<<minutesN + minutesR<<endl;
cout<<"The total amount due is: $"<<servType<<endl;

return 0;
}
