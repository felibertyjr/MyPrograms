#include <iostream>
using namespace std;

int main()
{
char choice,fuel;

float gallons, regular = 2.89, plus = 3.09, super = 3.39, carWash, fuelTotal ,  totalCost;

cout<<"Enter number of gallons sold:";
cin>>gallons;

cout<<"What type of fuel was purchased(R,P,S or N)?";
cin>>fuel;

cout<<"Enter Y or N if they wanted a car wash:";
cin>>choice;


//This is the calculation part:
if (fuel == 'r' || fuel == 'R')
    {
        fuelTotal = gallons * regular;
            if (fuelTotal >= 10 && choice == 'y' || choice == 'Y')
                carWash = 1.25;
            else
                if (fuelTotal <= 10 && choice == 'y' || choice == 'Y')
                    carWash = 3.00;
                else
                    carWash = 0.00;
    }

    else if (fuel == 'p' || fuel == 'P')
    {
        fuelTotal = gallons * plus;

            if (fuelTotal >= 10 && choice == 'y' || choice == 'Y')
                carWash = 1.25;
            else
                if (fuelTotal <= 10 && choice == 'y' || choice == 'Y')
                    carWash = 3.00;
                else
                    carWash = 0.00;
    }

    else if (fuel == 's' || fuel == 'S')
    {
        fuelTotal = gallons * super;

            if (fuelTotal >= 10 && choice == 'y' || choice == 'Y')
                carWash = 1.25;
            else
                if (fuelTotal <= 10 && choice == 'y' || choice == 'Y')
                    carWash = 3.00;
                else
                    carWash = 0.00;
    }
    else
    {

        fuelTotal = 0;
        carWash = 0.00;
    }




cout<<"Amount of Gas purchased is:"<<gallons<<endl;


cout<<"Price per Gallon is: $"<<fuelTotal / gallons<<endl;


cout<<"Total fuel cost is:"<<fuelTotal<<endl;


cout<<"Car wash cost is:"<<carWash<<endl;

cout<<"Total due is:"<<fuelTotal + carWash<<endl;


return 0;

}
