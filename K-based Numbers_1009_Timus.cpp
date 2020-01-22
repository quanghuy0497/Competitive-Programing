//http://acm.timus.ru/problem.aspx?num=1009
#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int result[n + 1];
	result[0] = 1;
	result[1] = k - 1;
	for (int i = 2; i <= n; i++)
		result[i] = (k - 1) * (result[i - 1] + result[i - 2]);
	cout << result[n] << endl;
	return 0;
}
