//http://codeforces.com/problemset/problem/546/A
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//=============================================
int main()
{
	int k, n, w, s = 0;
	cin>>k>>n>>w;
	for (int i = 1; i <= w; i++)
		s = s + i*k;
	if (n < s)
	  cout<< s - n << endl;
	else cout<< 0 <<endl;
	return 0;
}
