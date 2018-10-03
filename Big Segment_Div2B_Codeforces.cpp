//http://codeforces.com/problemset/problem/242/B
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,d,valuea,valueb;
	vector <long> l,r;
	long min=1e9, max=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>valuea>>valueb;
		l.push_back(valuea);
		r.push_back(valueb);
		if (min>valuea) min=valuea;
		if (max<valueb) max=valueb;
	}
	for (int i=0;i<n;i++)
	  if ((l[i]==min) &&(r[i]==max))	//kt xem segment thu i [Li;Ri] co bang [Lmin;Rmax] ko; nghia khoang bao trum tat ca cac segment
	  {
	  	cout<<i+1;
	  	return 0;
	  }
	cout<<-1;
	return 0;
}
