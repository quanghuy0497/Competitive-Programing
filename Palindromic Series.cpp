#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string c[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
//==================================================================================
bool check(string a)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != a[a.size() - i - 1])
		return false;
	return true;
}
//==================================================================================
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, count = 0;
		cin >> n;
		string st ="";
		while (n)
		{
			count += n % 10;
			st += c[n % 10];
			n /= 10;
		}
		reverse(st.begin(), st.end());
     	string st2;
     	int j = 0;
     	for (int i = 0; i < count; i++)
		{
          	if (j == st.size())
			  j = 0;
          	st2 += st[j++];
        }
        cout<<st2<<endl;
       	cout<<(check(st2)?"YES":"NO")<<endl;
	}
	return 0;
}
