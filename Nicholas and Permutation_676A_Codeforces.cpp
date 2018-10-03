//http://codeforces.com/problemset/problem/676/A 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, d, value, pos_max=0, pos_min=0;
	vector <long> a;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>value;
		a.push_back(value);
	}
	for(int i = 0; i < n; i++)
	{
		if (a[pos_max] < a[i]) pos_max = i;
		if (a[pos_min] > a[i]) pos_min = i;
	}
	if (pos_min < pos_max)
		cout<<max(n - min - 1, max); 		//chi co the hoan vi giua min/max (tuy thuoc ben nao nho hon) voi 2 vi tri dau hoac cuoi day ma thoi
	else 
		cout<<max(n - max - 1, min);
	return 0;
}

