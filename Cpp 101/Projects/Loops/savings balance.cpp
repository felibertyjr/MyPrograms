#include <iostream>
using namespace std;

int main()
{

float inBalance, interest, sumDeposit = 0.0, deposit = 0.0, withdraw = 0.0,withSum = 0.0, monthInt, sum = 0.0, finInt = 0.0, newBalance, totalInt = 0.0, validation = 0;
int month = 1, number = 0;

do
{
if (number < 0)
    {
    cout<<"Please Enter a valid quantity\n";
    cout<<"How many customers will we be calculating today?\n";
    cin>>number;
    }
else
    {
    cout<<"How many customers will we be calculating today?\n";
    cin>>number;
    }
} while(number < 0);

for (number; number > 0; number-=1)
{

do{
if (inBalance < 0)
    {
    cout<<"Please Enter a valid quantity\n";
    cout<<"What is the starting balance?\n";
    cin>>inBalance;
    }
else
    {
    cout<<"What is the starting balance?\n";
    cin>>inBalance;
    }
} while(inBalance < 0);

do{
if (interest < 0)
    {
    cout<<"Please Enter a valid quantity\n";
    cout<<"What is the annual interest rate?\n";
    cin>>interest;
    }
else
    {
    cout<<"What is the annual interest rate?\n";
    cin>>interest;
    }
} while (interest < 0);

monthInt = (interest/100.0) / 12.0;

do
{
    do
    {
    if (deposit < 0)
        {
        cout<<"Please enter a valid quantity!\n";
        cout<<"How much did you deposit during month "<<month<<"?"<<endl;
        cin>>deposit;
            if (deposit >= 0)
                sumDeposit+=deposit;
            else
               cout<<"WARNING: What you entered is not a valid number!\n";
        }
    else
        {
        cout<<"How much did you deposit during month "<<month<<"?"<<endl;
        cin>>deposit;
            if (deposit >= 0)
                sumDeposit+=deposit;
            else
               cout<<"WARNING: What you entered is not a valid number!\n";
        }
    }while (deposit<0);

if (month == 1)
    validation = deposit + inBalance;
else
    validation = deposit + sum;

do{
    if (withdraw < 0 && withdraw > validation)
        {
        cout<<"Please enter a valid quantity!\n";
        cout<<"How much did you withdraw during month "<<month<<"?"<<endl;
        cin>>withdraw;
            if (withdraw >= 0 && withdraw <= validation)
                withSum+=withdraw;
            else
                cout<<"WARNING: What you entered is not a valid number!\n";
        }
    else
        {
        cout<<"How much did you withdraw during month "<<month<<"?"<<endl;
        cin>>withdraw;
            if (withdraw >= 0 && withdraw <= validation)
                withSum+=withdraw;
            else
                cout<<"WARNING: What you entered is not a valid number!\n";
        }
}while (withdraw < 0 && withdraw > validation);



if (month == 1)
    {
    finInt = (monthInt * ((inBalance + (deposit - withdraw))/2));
    totalInt +=  finInt;
    sum += inBalance + finInt + (deposit - withdraw);
    }
else
    {
    finInt = (monthInt * ((sum + (deposit - withdraw))/2));
    totalInt +=  finInt;
    sum += finInt + (deposit - withdraw);
    }


month++;

}while (month != 4);

cout<<"Your starting balance is: $"<<inBalance<<endl;
cout<<"Your total deposits: $"<<sumDeposit<<endl;
cout<<"Your total withdrawals: $"<<withSum<<endl;
cout<<"Total interest: $"<<totalInt<<endl;
cout<<"Final Balance: $"<<sum<<endl;
}

return 0;
}
