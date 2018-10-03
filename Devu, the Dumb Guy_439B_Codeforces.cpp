//http://codeforces.com/problemset/problem/439/B 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, x, value;
	vector <long long> c;
	cin>> n >> x;
	for(int i = 0; i < n; ++i)
	{
		cin >> value;
		c.push_back(value);
	}
	sort(c.begin(), c.end());
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	  if (x>1) 
	  {
	  	sum += c[i] * x;
	  	x--;
	  }
	  else sum += c[i];
	  //De co ket qua tot nhat thi sort mang tang dan va nhan len voi thoi gian hoc. 
	  //Chu yeu la kich thuoc bien can phai su dung long long de phu hop voi yeu cau bai toan
	cout<<sum;
}
