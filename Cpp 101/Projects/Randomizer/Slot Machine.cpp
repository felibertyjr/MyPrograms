#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
int thing;
do
{

string images[6] = {"Cherries", "Oranges", "Plums", "Bells", "Melons", "Bars"};
int x = 0, amount;

cout<<"This is a slot machine game"<<endl;
std::cout << std::endl << "Press any key to continue...";
    getchar();


int first, second, third;

do
{

cout<<"How much money do you want to gamble with?\n";
cin>>amount;

} while (amount < 0);

std::cout << std::endl << "Press any key to continue...\n";
getchar();

srand (time(NULL));
do
{
int pos = rand() % 5;

cout<<images[pos]<<endl;
if (x == 0)
    first = pos;
else if (x == 1)
    second = pos;
else
    third = pos;
//For debugging purposes
//cout<<pos;
x++;
} while (x < 3);

if (first == second && first == third)
    cout<<"You won Three times what you deposited: $"<< amount * 3<< endl;
else if (first == second || first == third)
    cout<<"You won two times what you deposited: $"<< amount * 2<< endl;
else if (second == third || second == first)
    cout<<"You won two times what you deposited: $"<< amount * 2<< endl;
else if (third == first || third == second)
    cout<<"You won two times what you deposited: $"<< amount * 2<< endl;
else
    cout<<"You won nothing: $ 0"<< endl;

std::cout << std::endl << "Press any key to continue...\n";
    getchar();

do{
cout<<"Would you like to play again?\n Enter 1 for YES \n Enter 2 for NO \n";
cin>>thing;
}while (thing < 0 && thing > 2);

}while (thing != 2);
return 0;
}
