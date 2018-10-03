//http://www.spoj.com/problems/EKO/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
long long n, pride;
//======================================================
long long Cut (vector <long long> &a, int n)
{
	int dem = 0;
	for (int i = 0; i < a.size(); i++)
	  if (a[i] > n) dem += a[i] - n; 
	return dem;
}
//======================================================
int BinarySearch(vector <long long> &a, int left, int right)
{
	int hight = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		long long logs = Cut(a, mid);
		if (logs > pride)
		{
			left = mid + 1;
			if (mid > hight) hight = mid;
		}
		else if (logs < pride)
		  	right = mid - 1;
		else
		{
		  	hight = mid;
			break;	
		} 
	}
	return hight;
}
//======================================================
int main()
{
	cin >>n >>pride;
	vector <long long> a;
	int value, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		if (max < value) max = value;
		a.push_back(value);
	}
	cout<<BinarySearch(a, 0, max);
	return 0;
}
