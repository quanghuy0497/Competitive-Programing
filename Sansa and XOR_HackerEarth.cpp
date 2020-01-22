//https://www.hackerrank.com/challenges/sansa-and-xor/problem
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <int> x(n);
		for (int i = 0; i < n; i++)
			cin >> x[i];
		if (n % 2 == 0) cout << 0 << endl;
		else
		{
			int s = 0;
			for (int i = 0; i < n; i += 2)
				s ^= x[i];
			cout<<s<<endl;
		}
	}
	return 0;
}
