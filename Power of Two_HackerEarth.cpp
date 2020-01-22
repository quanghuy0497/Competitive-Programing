//https://www.hackerearth.com/challenges/competitive/thoughtworks-singapore-codeathon-2015/algorithm/power-of-two-4/
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
		bool check = false;
		for (int i = 0; i < 30; i++)	//2^30 ~ 10^9
		{
			int test = 0xffffffff;
			for (int j = 0; j < n; j++)
				if (((x[j] >> i) & 1) == 1)
					test &= x[j];
			if (test == (1 << i)) 
			{
				check = true;
				break;
			}
		}
		if (check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
