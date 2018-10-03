//http://codeforces.com/problemset/problem/731/A
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	string st;
	cin>>st;
	int dem=min(st[0] - 97, 123 - st[0]);
	for (int i=1;i<st.size();++i)
		dem += min(abs(st[i] - st[i - 1]), 26 - abs(st[i] - st[i - 1]));	
	cout<<dem;
	return 0;
}
