//https://codeforces.com/problemset/problem/835/B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	cin >> k;
	string n;
	cin >> n;
	int count = 0;
	for (int i = 0;  i < n.size(); i++)
		count += n[i] - '0';
	sort(n.begin(), n.end());
	int result = 0;
	while (count < k)
	{
		count += '9' - n[result];
		result++;
	}
	cout << result << endl;
	return 0;
}
