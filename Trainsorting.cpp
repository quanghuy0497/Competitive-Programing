#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//====================================================================
void LIS(const vector <int> &a, vector <int> &result)
{
    vector<int> sub;
    sub.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        int pos = lower_bound(sub.begin(), sub.end(), a[i]) - sub.begin();
        if (pos == sub.size()) {
            sub.push_back(a[i]);
        } else {
            sub[pos] = a[i];
        }
        result[i] = pos + 1;
    }
}
//====================================================================
int main()
{
	int t,n;
	cin >> t;
	vector <int> a, asc, des;
	while (t--)
	{
		cin >> n;
		a.resize(n);
		asc.resize(n);
		des.resize(n);
		for (int x, i = 0; i < n; i++)
			cin >>a[i];
		LIS(a, asc);
		reverse(a.begin(), a.end());
		LIS(a, des);
		int result = 0;
		for (int i = 0; i < n;  i++)
			result = max(result, asc[i] + des[i] - 1);
		cout << result <<endl; 
	}
	return 0;
}
