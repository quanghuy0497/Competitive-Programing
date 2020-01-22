//https://www.spoj.com/problems/ACODE/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st;
	while (cin >>st, st != "0")
	{
		int n = st.size();
		long long result[5005];
		for (int i = 1; i < 5005; i++)
			result[i] = 0; 
		result[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (st[i - 1] != '0')
				result[i] = result[i - 1];
			if	(i > 1 && st[i - 2] != '0' )
				if (((st[i -2] - '0') * 10 + st[i - 1] - '0') <= 26)
					result[i] += result[i - 2];	
		}
		cout << result[n] << endl;
	}
	return 0;
}
