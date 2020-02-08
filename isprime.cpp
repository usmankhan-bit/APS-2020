#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n)
{
    int flag=0;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return false;
    else
        return true;
}

int main()
{
    int n;
    cin>>n;
    cout<<isPrime(n)<<endl;
}