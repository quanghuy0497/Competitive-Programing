//http://www.spoj.com/problems/SHPATH/en/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
//=================================================================================
#define MAX 10005
const int INF = 1e9;
vector <vector < pair<int, int> > > graph;
vector <int> dist (MAX, INF);
//=================================================================================
int Dijkstra(int s, int e)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(pair<int, int>(s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		pair <int, int> top = pq.top();
		pq.pop();
		for (int i = 0; i < graph[top.first].size(); ++i)
		{
			pair <int, int> neighbor = graph[top.first][i];
			if (top.second + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = top.second + neighbor.second;
				pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
			}
		}
	}
	return dist[e];
}
//=================================================================================
int main()
{
 	int s;
	cin>>s;
	while (s--)
	{
		int n,p;
		cin >> n;
		string name[MAX];
		graph = vector<vector<pair<int, int> > >(MAX, vector<pair<int, int> >() );
		for (int i = 1; i <= n; i++)
		{
			cin >> name[i];
			cin >> p;
			for (int j = 0; j < p; j++)
			{
				int a,w;
				cin >> a >> w;
				graph[i].push_back(pair<int, int> (a, w));
			}
		}
		cin>>p;
		while (p--)
		{
			dist = vector<int> (MAX, INF);
			string name1, name2;
			cin >> name1 >> name2;
			int a = 0, b = 0;
			for (int j = 1; j <= n; j++)
				if (name[j] == name1) a = j;
				else if (name[j] == name2) b = j;
			cout<<Dijkstra(a, b)<<endl;
		}
	}
	return 0;
}
