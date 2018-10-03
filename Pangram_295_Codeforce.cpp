//http://codeforces.com/problemset/problem/520/A
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//=============================================
int main()
{
	int n;
	string st;
	cin>>n>>st;
	int a[ 30 ];
	for (int i = 0; i < 26; i++)
	  a[i] = 0;
	for (int i = 0; i < st.size(); i++)
	{
		char tmp = tolower(st[i]);
		a[tmp-97]++;
	}
	int kt = 0;
	for (int i = 0; i < 26; i++)
		if (a[i] == 0)
		{
			kt = 1;
			break;
		}
	if (kt == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
