#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int arr[] = {2, 3 , 4 , 5 , 6 , 6 , 7 , 8 , 9 } ;
vector<int> V( arr , arr + 9 ) ; // note that the vector is sorted .
int main ( )
{
    cout<<lower_bound(V. begin(), V. end(), 5) - V. begin()<<endl;

    // this will out put 2 since 5(>= 5) occurs first at index 2 .
}
