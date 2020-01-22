//https://codeforces.com/problemset/problem/515/B
#include <iostream>
#include <vector>
using namespace std;
//================================================================================================
bool check (vector <bool> a)
{
	for (int i = 0; i < a.size(); i++)
		if (!a[i]) return false;
	return true;
}
//================================================================================================
int main()
{
	int n, m, k;
	cin >> n >> m;
	vector <bool> boy(n, false);
	vector <bool> girl(m, false);
	cin >> k;
	for (int x, i = 0; i < k; i++)
	{
		cin >> x;
		boy[x] = true;
	}
	cin >> k;
	for (int x, i = 0; i < k; i++)
	{
		cin >> x;
		girl[x] = true;
	}
	for (int i = 0; i < 100000; i++)
		if (boy[i % n]  || girl[i % m])
		{
			girl[i % m] = true;
			boy[i % n] = true;
		}
	if (check(boy) && check(girl)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
