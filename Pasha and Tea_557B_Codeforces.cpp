//http://codeforces.com/problemset/problem/557/B
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
//==============================================
int main()
{
	long long n, w, value;
	vector <long long> c;
	cin >> n >> w;
	for(int i = 0 ; i < 2 * n; ++i)
	{
		cin >> value;
		c.push_back(value);
	}
	sort(c.begin(), c.end());
	printf("%lf\n", min(1.0 * w, 3.0 * n * min(1.0 * c[0], c[n] / 2.0) ));
	//xet lay truong hop toi uu nhat la nam cam tach tra dung tich nho nhat và nu cam tach tra dung tich nho nhat dem so sanh
}
