//http://codeforces.com/problemset/problem/518/A
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, t;
	getline(cin, s);
	getline(cin, t);
	string st=s;
	for (int i = s.size() - 1; i >= 0; --i)
	  if (s[i]=='z')
	  	st[i]='a';
	  else 
	  {
	    st[i]= s[i] + 1;
	    break;
	  }
	if (st<t)
	  cout<<st;
	else
	  cout<<"No such string";
}
