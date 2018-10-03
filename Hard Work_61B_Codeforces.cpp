//http://codeforces.com/problemset/problem/61/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//================================================================
void normalization(string &value)
{
	string st;
	for (int i = 0; i <= value.size(); ++i)
		if (isalpha(value[i]))
			st += tolower(value[i]);
	value = st;
}
//================================================================
int main()
{
	string a, b, c, value;
	int n;
	cin>>a;
	normalization(a);
	cin>>b;
	normalization(b);
	cin>>c;
	normalization(c);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>value;
		normalization(value);
		if ((value == a + b + c) || (value == a + c + b) || (value == b + a + c) || (value == b + c + a) || (value == c + a + b) || (value == c + b + a))
			cout<<"ACC";
		else cout<<"WA";
		if (i != n - 1) cout<<endl;
	}
	return 0;
}
