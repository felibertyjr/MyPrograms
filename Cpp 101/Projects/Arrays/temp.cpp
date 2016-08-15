#include <iostream>
#include <fstream>
using namespace std;

int main()
{

ifstream inputFile;

float temps[6], mini = 250, maxa = 0,sum = 0, sumAvg= 0;
int counter = 0;

inputFile.open("temp.txt");

do
{

inputFile>>temps[counter];//<<endl;

//For Debug
cout<<temps[counter]<<endl;
cout<<counter<<endl;

if (temps[counter] > maxa)
    maxa = temps[counter];

if (temps[counter] < mini)
    mini = temps[counter];


sum = temps[counter] + sum;

counter = counter++;

} while(counter < 7);

sumAvg = sum/counter;

cout<<"The average temperature is: "<< sumAvg<<endl;
cout<<"The High is: "<<maxa<<endl;
cout<<"The Low is: "<<mini<<endl;


inputFile.close();

return 0;

}
