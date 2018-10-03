//http://www.spoj.com/problems/STPAR/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
//======================================================
int main()
{
	int n,kt,flag, value;
	stack <int> a;
	while (1)
	{
		cin>>n;
		if (n == 0)
			return 0;
		kt = 1; flag =0 ;			
		while (!a.empty())
			a.pop();
		a.push(1001);
		for (int i = 0; i < n; i++)
		{
			cin>>value;
			if (value != 0)
			{
				if (value != kt)
				{
		  			while (a.top() == kt)
		  			{
		    			a.pop();
		    			kt++;
		  			}
		  			if (value <= a.top())
		  			 	a.push(value);
		  			else flag = 1;
		  		}
				else kt++;
			}
		}
		if (flag == 0)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
