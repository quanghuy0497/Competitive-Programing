//http://acm.timus.ru/problem.aspx?space=1&num=2002
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map <string, string> regis, login;
	while (n--)
	{
		string type, acc, pass;
		cin >>type >>acc;
		if (type != "logout") cin>>pass;
		if (type == "register")
			if (regis[acc] == "")
			{
				regis[acc] = pass;
				cout<<"success: new user added"<<endl;
			}
			else
				cout<<"fail: user already exists"<<endl;
		else if (type == "login")
			if (regis[acc] =="")
				cout<<"fail: no such user"<<endl;
			else if (regis[acc] != pass)
				cout<<"fail: incorrect password"<<endl;
			else if (login[acc] == "")
				{
					cout<<"success: user logged in"<<endl;
					login[acc] = pass;
				}
			else  cout<<"fail: already logged in"<<endl;
		else
			if (regis[acc]=="")
				cout<<"fail: no such user"<<endl;
			else if (login[acc]=="")
			  cout<<"fail: already logged out"<<endl;
			else
			{
				login.erase(acc);
				cout<<"success: user logged out"<<endl;
			}
	}
}
