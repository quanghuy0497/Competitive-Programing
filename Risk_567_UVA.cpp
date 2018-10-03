//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <vector <int> > dist;
int n;
//======================================================================
int main()
{
	int d = 0;
	int k;
	//while (scanf("%d",&k) != EOF)
	while (cin >>k)
	{
		dist = vector < vector <int> > (21, vector <int> (21, 99));
		dist[1][1] = 0;
		for (int i = 0; i < k; i++)
		{
			int value;
			cin>>value;
			dist[1][value] = 1;
			dist[value][1] = 1;
		}
		for (int i = 2; i <= 19; i++)
		{
			dist[i][i] = 0;
			int length, value;
			cin >> length;
			for (int j = 0; j < length; j++)
			{
				cin>>value;
				dist[i][value] = 1;
				dist[value][i] = 1;
			}
		}
		for (int k = 1; k <= 20; k++)
	      for (int i = 1; i <= 20; i++)
	        for (int j = 1; j <= 20; j++)
			  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int n; 
		cin >> n;
		d++;
		cout<<"Test Set #"<<d<<endl;
		for (int i = 0; i < n; i++)
		{
			int A, B;
			cin>> A >> B;
			if (A < 10) cout<<" "<<A;
			  else cout<<A;
			cout<<" to ";
			if (B < 10) cout<<" "<<B<<": ";
			  else cout<<B<<": ";
			cout<<dist[A][B]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
