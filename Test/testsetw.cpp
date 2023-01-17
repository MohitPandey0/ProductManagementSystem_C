#include <iostream>

#include<iomanip>

using namespace std;

int main()

{

    int n;

    cout<<"Enter number of seats you want to book\n";

    cin>>n;

    int p;

    cout<<"How many people are present?\n";

    cin>>p;

    int a = n-p;

    cout<<setw(n)<<string(a,'x')+string(p,'|');

    cout<<"\n";

    cout<<"There is place for "<<a<<" people";

}