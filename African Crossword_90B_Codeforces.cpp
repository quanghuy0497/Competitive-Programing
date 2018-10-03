//http://codeforces.com/problemset/problem/90/B 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char st[102][102];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		cin>>st[i][j];
	for (int i = 0; i < n; ++i)
	  for (int j = 0; j< m; ++j)
	  {
	  	int kt = 1;
	  	for (int k = 0;k < m; ++k)
		  if ((st[i][j] == st[i][k]) && (k != j))
	  	  {
	  	  	kt = 0;
	  		break;
		  }
		for (int k = 0;k < n; ++k)
		  if ((st[i][j] == st[k][j]) && (k != i))
		  {
			kt = 0;
			break;
		  }
		if (kt == 1) cout<<st[i][j];
		//duyet cung hang cot de kt xem co phan tu nao giong voi phan tu ta dang xet ko, neu ko thi xuat ra
	}
	return 0;
}
