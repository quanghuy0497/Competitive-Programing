//http://codeforces.com/problemset/problem/551/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Student
{
	int place;
	int rating;
	int rank;

};
//====================================================
bool ratingsort (const Student& A, const Student& B)
{
	if (A.rating > B.rating)
			return true;
	return false;
}
//====================================================
bool placesort (const Student& A, const Student& B)
{
	if (A.place < B.place)
			return true;
	return false;
}
//====================================================
int main()
{
	int n;
	vector <Student> a;
	cin>> n;
	for(int i = 0; i < n; ++i)
	{
		Student value;
		cin >> value.rating;
		value.place = i + 1;
		a.push_back(value);
	}	
	sort(a.begin(), a.end(), ratingsort);
	a[0].rank = 1;
	for (int i = 1; i < n; ++i)
	  if (a[i].rating == a[i-1].rating)
			a[i].rank = a[i-1].rank;
		else 
	  		a[i].rank = i+1;
	sort(a.begin(), a.end(), placesort);
	//luu vi tri cua cac phan tu ban dau, sau do sap xep theo diem de tinh thu hang, cuoi cung sap xep lai nhu ban dau de co ban xep hang
	for (int i = 0; i < n; ++i)
	  cout<<a[i].rank<<" ";
	return 0;
}
