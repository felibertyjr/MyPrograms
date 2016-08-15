#include <iostream>
using namespace std;

int main()
{
//Get highest score and lowest score. AVG. for 8 scores

int scores[8], counter=0,tests,a,b,t;
float sum=0;

cout<<"How many tests did the student take"<<endl;
cin>>tests;

    do
    {
        cout<<"Please enter score for test#"<<counter + 1<<endl;
        cin>>scores[counter];

        sum = sum + scores[counter];

        counter = counter++;
    } while(counter < tests);


    for(a = 0; a < tests; a++)
    {
        for(b = tests - 1 ;b >= a;b--)
        {
            if(scores[b-1] >= scores[b])
            {
                t= scores[b-1];
                scores[b-1]= scores[b];
                scores[b]=t;
                //cout<<scores[b-1]<<scores[b]<<endl;
            }
        }
    }



sum = sum - (scores[tests-1] + scores[0]);

cout<<"The highest score is: "<<scores[tests-1]<<endl;


cout<<"The lowest score is: "<<scores[0]<<endl;

cout<<"The average for your student is: "<<sum/(tests-2)<<endl;

return 0;
}
