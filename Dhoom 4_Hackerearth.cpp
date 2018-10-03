//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/description/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int startt, endd, n;
long long valuekey[100005];
//============================================================================
void BFS()
{
	queue <long long> q;
	int dist[100005];
	for (int i = 0; i <= 100000; ++i)
		dist[i] = -1;
	dist[startt] = 0;
	q.push(startt);
	while (!q.empty())
	{
		long long u = q.front();
		q.pop();
		for (int i = 0; i < n; ++i)
		if (dist[(u * valuekey[i]) % 100000] == -1)
		{
			dist[(u * valuekey[i]) % 100000] = dist[u] + 1;
			q.push((u * valuekey[i]) % 100000);
		}
	}
	cout<<dist[endd];
}
//============================================================================
int main()
{

	cin >>startt >> endd>> n;
	for (int i = 0; i < n; ++i)
		cin>>valuekey[i];
	BFS();
	return 0;
}
