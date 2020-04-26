#include <bits/stdc++.h>
using namespace std;
 
int main() {
	//Creating a map container
	/* map <key data type , mapped value data type > name; */
	map <string , int> M;
	//Inputting 10 strings.
	for(int i=1; i<=10; i++)
	{
		string s;
		cin>>s;
		M[s]++;
	}
	//Printing the size of the map
	cout<<M.size()<<endl;
	/*Let us answer 5 queries now*/
	for(int i=1; i<=5; i++)
	{
		string s;
		cin>>s;
		/*Let us first check whether at all s was entered or not. If s was not entered then trying to print
		M[s] would throw an error. The find() and end() helps us to check this*/
		if(M.find(s)==M.end())cout<<"0\n";
		else cout<< M[s]<<endl;
	}
	//Suppose you want to erase the element having key "IOI"
	M.erase("IOI");
	//Traversing the elements in the map and printing the key and mapped values
	map <string , int> :: iterator it;
	for(it=M.begin(); it!=M.end(); ++it)
	{
 
		string a= it->first;
		int b= it->second;
		cout<<"Key: "<<a<<" Mapped value= "<<b<<endl;
	}
	return 0;
}