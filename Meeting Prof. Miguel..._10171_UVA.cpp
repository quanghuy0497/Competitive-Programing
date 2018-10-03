//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int> > distY, distM;
int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		int max = 0;
		distY = vector < vector <int> > (27, vector <int> (27, 1e9));
		distM = vector < vector <int> > (27, vector <int> (27, 1e9));
	
		while (n--)
		{
			char age, road, cityA, cityB;
			int value;
			cin >>age >>road >>cityA >>cityB >>value;
	
			distY[cityA - 65][cityA - 65] = distM[cityA - 65][cityA - 65] = 0;
			distY[cityB - 65][cityB - 65] = distM[cityB - 65][cityB - 65] = 0;
			if (max < cityA - 65) max = cityA - 64;
			if (max < cityB - 65) max = cityB - 64;
	
			if (road == 'B')
				if (age == 'Y')
					distY[cityA - 65][cityB - 65] = distY[cityB - 65][cityA - 65] = min(distY[cityA - 65][cityB - 65],value);
				else
					distM[cityA - 65][cityB - 65] = distM[cityB - 65][cityA - 65] = min(distM[cityA - 65][cityB - 65],value);
			else
				if (age == 'Y')
					distY[cityA - 65][cityB - 65] = min(distY[cityA - 65][cityB - 65],value);
				else
					distM[cityA - 65][cityB - 65] = min(distM[cityA - 65][cityB - 65],value);
		}
	
		for (int k = 0; k < max; k++)
	      for (int i = 0; i < max; i++)
	        for (int j = 0; j < max; j++)
	        {
	        	distY[i][j] = min(distY[i][j], distY[i][k] + distY[k][j]);
				distM[i][j] = min(distM[i][j], distM[i][k] + distM[k][j]);
			}
	
		char begin, end;
		cin >>begin >>end;
	
		int kt = 1e9;
		for (int i = 0; i < max; i++)
		  kt = min(kt, distY[begin - 65][i] + distM[end - 65][i]);
	
		if (kt == 1e9)
		  cout<<"You will never meet."<<endl;
		else
		{
			cout<< kt;
			for (int i = 0; i < max; i++)
			if (kt == distY[begin - 65][i] + distM[end - 65][i])
				cout<<" "<<(char) (i + 'A');
			cout<<endl;
		}
	}
	return 0;
}
