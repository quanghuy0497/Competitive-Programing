//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2078
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector <int> coin;
	vector <long long> result(10000 + 1);
	result[0] = 1;
	for (int i = 1; i < 27; i++)
		coin.push_back(i*i*i);
	for (int i = 0; i < 26; i++)
		for (int j = coin[i]; j <= 10000; j++)
			result[j] += result[j - coin[i]];
	while (cin >> n)
		cout<<result[n]<<endl;
	return 0;
}
