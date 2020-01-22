//Minimize Absolute Difference topcoder
#include <iostream>
#include <algorithm>
using namespace std;
//===========================================================================================
void check(int(&a)[5], int(&index)[5], long long(&minn)[2], int(&ans)[4]) 
{
    long long num = abs(a[index[0]] * a[index[3]] - a[index[1]] * a[index[2]]);
	long long denom = a[index[1]] * a[index[3]];
    if (num * minn[1] < denom * minn[0]) 
	{
        minn[0] = num;
        minn[1] = denom;
        for (int i = 0; i < 4; i++)
			ans[i] = index[i];
    }
}
//===========================================================================================
void backtracking (int (&a)[5], int (&index)[5], bool (&b)[5],  int j, long long (&minn)[2], int (&ans)[4])
{
	for (int i = 0; i < 5; i++)
		if (b[i])
		{
			index[j] = i;
			b[i] = false;
			if (j == 3)
				check(a, index, minn, ans);
			else backtracking(a, index, b, j + 1, minn, ans);
			b[i] = true;
		}
}
//===========================================================================================
int main()
{
	int a[5], index[5], ans[4];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	long long minn[2];
	minn[0] = 1e9, minn[1] = 1;
	for (int i = 0; i < 5; i++)
		index[i] = i;
	for (int i = 0; i < 4; i++)
		ans[i] = 0;
	bool b[5];
	for (int i = 0; i < 5; i++)
		b[i] = true;
	backtracking(a, index, b, 0, minn, ans);
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    return 0;
}
