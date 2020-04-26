#include <bits/stdc++.h>
using namespace std;
 
int main() {
	//Creating a set container S which will hold integers
	set <int> S;
	//Accepting 10 integers from the user and inserting them in the set S.
	for(int i=1; i<=10; i++)
	{
		int x;
		cin>>x;
		S.insert(x);
	}
	//Printing the size of the set S.
	cout<<S.size()<<endl;
	//Checking if set S is empty or not
	if(S.empty())cout<<"empty\n";
	/*Traversing the elements in set S and printing them.*/
	//Creating an iterator
	set <int> :: iterator it; //Refer to the tutorial on iterator if you do not understand this.
	for(it=S.begin(); it!=S.end(); ++it)
	cout<<*it<<" ";
	cout<<endl;
	//Printing the first element in S i.e the smallest element.
	cout<<*(S.begin())<<endl;
	//Printing the last element in S i.e the largest element
	cout<<*(S.rbegin())<<endl;
	//Erase the element 6 from set S
	S.erase(6);
	//Erase the element 8 from set S
	S.erase(8);
	return 0;
}