//https://www.spoj.com/problems/SUFEQPRE/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
const long long mod = 1e9 + 7;
const int maxx = 1e6 + 1;
unsigned long long f[maxx];
unsigned long long mul[maxx];
using namespace std;
//=================================================================================
void PolyHash(string st)
{
	unsigned long long value = 0;
	for (int i = 0; i < st.size(); i++)
	{
		value = (st[i] - 'a' + (26 * value) % mod) % mod;
		f[i + 1] = value;
	}
}
//=================================================================================
int main()
{
	int t;
	string st;
	cin >> t;
	mul[0] = 1;
	for (int i = 1; i < maxx; i++)
		mul[i] = (mul[i - 1] * 26) % mod;
	for (int a = 1; a <= t; a++)
	{
		cin >> st;
		f[0] = 0;
		PolyHash(st);
		int res = 0, len = 1;
		while (len < st.size())
		{
			if (f[len] == ((f[st.size()] - (f[st.size() - len] * mul[len]) % mod) + mod) % mod)
                res++;
            len++;
		}
		cout<<"Case "<< a <<": "<<res<<endl;
	}
	return 0;
}
