//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1186
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
//==========================================================================================
double Distance(pair<int, int> x, pair <int, int> &y)
{
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
//==========================================================================================
bool comparesecond (pair <int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}
//==========================================================================================
double Bruteforce(vector <pair<int, int> > &a, int left, int right)
{
	double mindist = 1e9;
	for (int i =  left; i < right; i++)
		for (int j = i + 1; j < right; j++)
			mindist = min(mindist, Distance(a[i], a[j]));
	return mindist;
}
//==========================================================================================
double stripClosest(vector <pair<int, int> > &point, int left, int right, int mid, double dist_min)
{
	vector <pair<int, int> > slpitted_point;
	
	for (int i = left; i < right; i++)
		if (abs(point[i].first - point[mid].first) <= dist_min)
			slpitted_point.push_back(point[i]);
			
	sort(slpitted_point.begin(),slpitted_point.end(), comparesecond);
	double smallest = 1e9;
	for (int i = 0; i < slpitted_point.size(); i++)
		for (int j = i + 1; j < slpitted_point.size() && (slpitted_point[j].second - slpitted_point[i].second) < dist_min; j++)
		{
			double d = Distance(slpitted_point[i], slpitted_point[j]);
			smallest = min(smallest, d);
		}
	return smallest;
}
//==========================================================================================
double closestUntil(vector <pair <int, int> > &point, int left, int right)
{
	if (right - left <= 3)
		return Bruteforce(point, left, right);	
	int mid = (left + right) / 2;
	double dist_left = closestUntil(point, left, mid);
	double dist_right = closestUntil(point, mid + 1, right);
	double dist_min = min (dist_left, dist_right);
	
	return min(dist_min, stripClosest(point, left, right, mid, dist_min));
}
//==========================================================================================
int main()
{
	int n;
	while (cin >> n, n!= 0)
	{
		vector <pair <int, int> > point;
		for (int i = 0, x, y; i < n; i++)
		{
			cin >> x >> y;
			point.push_back(make_pair(x, y));
		}
		sort(point.begin(), point.end());
		double ans = closestUntil(point, 0, n);
		if (ans < 10000)
			cout << fixed << setprecision(4) << ans << endl;
		else cout<<"INFINITY"<<endl;
	}
	return 0;
}
