#include <iostream>
using namespace std;
int main()
{
	int n,d=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if (!x) d++;
	}
	if ((n==1) && (d==0)) cout<<"YES"<<endl;
	else  if ((n !=1) && (d==1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
}
