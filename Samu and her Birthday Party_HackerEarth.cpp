//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/samu-and-her-birthday-party-1/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//===================================================================================
bool test(int a, vector <string> &st, int k, int n)
{
	vector <bool> served(n, false);
	for (int i = 0; i < k; i++)
		if (((a >> i) & 1) == 1)
			for (int j = 0; j < n; j++)
				if (st[j][i] == '1')
					served[j] = true;
	for (int i = 0; i < n; i++)
		if (!served[i]) 
			return false;
	return true;
}
//===================================================================================
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector <string> st (n);
		for (int i = 0; i < n; i++)
			cin >> st[i];
		int result = k;
		for (int i = 1; i <= ((1 << k) - 1); i++)
			if (test(i, st, k, n))
			{
				int count = 0, tmp = i;
				while (tmp > 0)
				{
					count += (tmp & 1);
					tmp = tmp >> 1;
				}
				result = min(result, count);
			}
		cout<<result<<endl;
	}
	return 0;
}
