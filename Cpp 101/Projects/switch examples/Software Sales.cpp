#include <iostream>
using namespace std;

int main()
{
int packages;

cout<<"How many copies of our software would you like to purchase?\n";
cin>>packages;

if (packages > 0 && packages < 10)
    cout<<"The total for your purchase will be:"<<packages * 99.00<<endl;
else if (packages >= 10)
    {
        switch (packages / 10)
            {
                case 1: cout<<"The total for your purchase will be: $"<<packages * 99.00<<endl;
                        cout<<"But we will give you a discounted rate and your new total is: $" <<((packages * 99.00) * (.80))<<endl;
                        cout<<"Saving you: $" <<(packages * 99.00) - ((packages * 99.00) * (.80))<<endl;
                        break;
                case 2:
                case 3:
                case 4: cout<<"The total for your purchase will be: $"<<packages * 99.00<<endl;
                        cout<<"But we will give you a discounted rate and your new total is: $" <<((packages * 99.00) * (.70))<<endl;
                        cout<<"Saving you: $" <<(packages * 99.00) - ((packages * 99.00) * (.70))<<endl;
                        break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9: cout<<"The total for your purchase will be: $"<<packages * 99.00<<endl;
                        cout<<"But we will give you a discounted rate and your new total is: $" <<((packages * 99.00) * (.60))<<endl;
                        cout<<"Saving you: $" <<(packages * 99.00) - ((packages * 99.00) * (.60))<<endl;
                        break;
                default: cout<<"The total for your purchase will be: $"<<packages * 99.00<<endl;
                        cout<<"But we will give you a discounted rate and your new total is: $" <<((packages * 99.00) * (.50))<<endl;
                        cout<<"Saving you: $" <<(packages * 99.00) - ((packages * 99.00) * (.50))<<endl;
                        break;

            }
    }
else
    cout<<"WARNING: What you entered is not a valid quantity!\n";
return 0;
}
