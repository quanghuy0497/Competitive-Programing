//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1614
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long x, k;
		cin >> x >> k;
		if (x % k != 0)
			cout << 1 + ((long long) (x / k)) - x<<" "<< x - ((long long) (x / k)) << endl;
		else cout << 0 <<" "<< k<<endl;
	}
	return 0;
}
