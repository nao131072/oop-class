#include <iostream>
using namespace std;

string strNum1;
string strNum2;

void align()
{
	while (strNum1.length() < strNum2.length())
	{
		strNum1 = '0' + strNum1;
	}
	while (strNum1.length() > strNum2.length())
	{
		strNum2 = '0' + strNum2;
	}
}

string add(string strNumA, string strNumB)
{
	string result="";
	strNumA = '0' + strNumA;
	strNumB = '0' + strNumB;
	for (int i = strNumA.length() - 1; i >= 0; i--)
	{
		int c = strNumA[i] - '0' + strNumB[i] - '0';
		if (c >= 10)
		{
			strNumA[i - 1] += 1;
			c -= 10;
		}
		c += '0';
		result = char(c) + result;
	}
	return result;
}

bool check()
{
	for (int i = 0; i < strNum1.length(); i++)
	{
		if (strNum1[i] < '0' || strNum1[i]>'9')
		{
			return 0;
		}
	}

	for (int i = 0; i < strNum2.length(); i++)
	{
		if (strNum2[i] < '0' || strNum2[i]>'9')
		{
			return 0;
		}
	}

	return 1;
}

string clear(string result)
{
	if (result[0] == '0')
	{
		result.erase(0, 1);
	}

	return result;
}

int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> strNum1;
			cin >> strNum2;
			if (check())
			{
				align();
				string r;
				r = add(strNum1, strNum2);
				r = clear(r);
				cout << r << endl;
			}
			else
			{
				cout << "Not a valid number, please try again.\n";
			}
		}
	}
}