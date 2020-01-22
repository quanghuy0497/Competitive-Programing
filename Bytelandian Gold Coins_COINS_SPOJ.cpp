//https://www.spoj.com/problems/COINS/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, long long> result;
//=================================================================
long long dp(long long n)
{
	if (n < 3)
		return n;
	if (result.find(n) != result.end())
		return result[n];
	return result[n] = max(n, dp(n/2) + dp(n/4) + dp(n/3));
}
//=================================================================
int main()
{
	long long n;
	while (cin >> n)
	{
		cout<<dp(n)<<endl;
	}
	return 0;
}
