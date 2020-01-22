//https://codeforces.com/problemset/problem/271/D
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
	string st, b;
	int k;
	cin >> st >> b >> k;
	unordered_set<uint64_t> result;
	for (int i = 0; i < st.size(); i++)
	{
		uint64_t hash = 0;
		for (int j = i, bad = 0; j >= 0; --j)
		{
			hash =  hash * 29 + st[j] - 'a' + 1;
			bad += (b[st[j] - 'a'] == '0');
			if (bad <= k)
				result.insert(hash);
			else break;
		}
	}
	cout << result.size();
	return 0;
}
