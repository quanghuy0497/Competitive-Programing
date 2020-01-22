#include <iostream>
#include <math.h>
#include  <algorithm>
using namespace std;
const int n = 8;
int board[n][n], boardj[n][n];
int result;
//===========================================================================================
bool check(int board[n][n], int row, int col)
{
	for (int i = 0; i < row; i++)
		if (board[i][col])
			return false;
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (int i = row, j = col; j < n && i >= 0; i--, j++)
		if (board[i][j])
			return false;
	return true;
}
//===========================================================================================
int cal()
{
	int summ = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j])
				summ += boardj[i][j];
	return summ;
}
//===========================================================================================
void Queenn(int board[n][n], int row)
{
	if (row == n)
	{
		result = max(result, cal());
	}
	for (int j = 0; j < n; j++)
		if (check(board, row, j) ==  true)
		{
			board[row][j] = 1;
			Queenn(board, row + 1);
			board[row][j] = 0;
		}
}
//===========================================================================================
int main()
{
	int k;
	cin >> k;
	while (k --)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin>>boardj[i][j];
				board[i][j] = 0;
			}
		result  = 0;
		Queenn(board, 0);
		cout<<result<<endl;
	}
	return 0;
}
