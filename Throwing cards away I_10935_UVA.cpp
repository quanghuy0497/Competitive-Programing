//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n=1	;
	while (n!=0)
	{
	  cin>>n;
	  if (n == 0) return 0;
	  queue <int> a;
	  for (int i = 1; i <= n; ++i)
	    a.push(i);
	  int d=0;
	  cout<<"Discarded cards: ";
	  while (a.size() > 1)
	  {
		d++;
		int value=a.front();
		a.pop();
		if (d%2 != 0)
		  if (d != 1)
			cout<<", "<<value;
		  else cout<<value;
		else a.push(value);
	  }
	  cout<<endl<<"Remaining card: "<<a.front()<<endl;
	  }
	return 0;
}
