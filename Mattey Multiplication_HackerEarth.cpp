//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/mattey-multiplication-6/
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long m, n, count = 0;
		cin >> n >> m;
		while (m != 0)
		{
			long long x = 1;
			int tmp = 0;
			while ( x << 1 <= m )
			{
				x <<= 1;
				tmp++;
			}
			if (count > 0) cout<<" + ";
			cout<<"("<<n<<"<<"<<tmp<<")";
			m -= x;	
			count++;
		}
		cout<<endl;
	}
	return 0;
}
