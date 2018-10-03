//http://codeforces.com/problemset/problem/224/B
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,k, value, dem = 0;
	cin >>n >>k;
	vector <int> a;
	for (int i = 0; i < n; i++)
	{
		cin>>value;
		a.push_back(value);
	}
	int count[1000000];
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
		if (count[a[i]] == 1)
		  dem ++;
		if (dem == k)
		  for (int j = 0; j <= i; j++)
		  {
		  	count[a[j]] --;
		  	if (count[a[j]] == 0)
		  	{
			  cout<< j + 1<<" "<<i + 1;
		  	   return 0;
		  	}
		  }
	}
	cout <<-1 <<" " <<-1;
	return 0;
}
