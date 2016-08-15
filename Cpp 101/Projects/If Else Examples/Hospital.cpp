#include <iostream>
using namespace std;

int main()
{

string room;
int roomType, days, ammen;

float priv = 125.00, semi = 95.00, ward = 75.00, tele = 3.50, phone = 1.75, tvTotal, phoneTotal, total, extraTotal;

cout<<"how many days will you be staying for?"<<endl;
cin>>days;

cout<<"What type of room would you like?\n";
cout<<"Choose 1 for Private Room\n";
cout<<"Choose 2 for SemiPrivate Room\n";
cout<<"Choose 3 for Ward\n";
cin>>roomType;

cout<<"Would you like a TV and/or phone?\n";
cout<<"Choose 1 for a TV\n";
cout<<"Choose 2 for a phone\n";
cout<<"Choose 3 for both\n";
cout<<"Choose 4 for none\n";
cin>>ammen;


if (roomType == 1)
    {


        total = priv * days;
        room = "Private";

            if (ammen == 1)
                {
                tvTotal = tele * days;
                phoneTotal = 0.00;
                }
            else if (ammen == 2)
                {
                phoneTotal = phone * days;
                tvTotal = 0.00;
                }
            else if (ammen == 3)
                extraTotal = (phone + tele) * days;
            else
                extraTotal = 0.00;
    }

else if (roomType == 2)
    {


        total = semi * days;
        room = "Semi-Private";

            if (ammen == 1)
                {
                tvTotal = tele * days;
                phoneTotal = 0.00;
                }
            else if (ammen == 2)
                {
                phoneTotal = phone * days;
                tvTotal = 0.00;
                }
            else if (ammen == 3)
                extraTotal = (phone + tele) * days;
            else
                extraTotal = 0.00;
    }

else if (roomType == 3)
    {

        total = ward * days;
        room = "Ward";

            if (ammen == 1)
                {
                tvTotal = tele * days;
                phoneTotal = 0.00;
                }
            else if (ammen == 2)
                {
                phoneTotal = phone * days;
                tvTotal = 0.00;
                }
            else if (ammen == 3)
                extraTotal = (phone + tele) * days;
            else
                extraTotal = 0.00;
    }
else
    cout<<"You didn't choose any of the choice available"<<endl;



cout<<"Number of days in the hospital: "<<days<<endl;

cout<<"Type of Room: "<<room<<endl;

cout<<"Telephone Charge: "<<phoneTotal<<endl;

cout<<"TV charge: "<<tvTotal<<endl;

cout<<"Total Due: "<<total + tvTotal + phoneTotal <<endl;

return 0;

}
