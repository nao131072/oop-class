#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int col1, row1;
	int col2, row2;
	vector<vector<int>> mat1;
	vector<vector<int>> mat2;
	vector<vector<int>> matR;

	cin >> row1 >> col1 >> row2 >> col2;

	if (col1 == row2)
	{
		for (int i = 0; i < row1; i++)
		{
			vector<int> vt;
			for (int j = 0; j < col1; j++)
			{
				int t;
				cin >> t;
				vt.push_back(t);
			}
			mat1.push_back(vt);
		}
		for (int i = 0; i < row2; i++)
		{
			vector<int> vt;
			for (int j = 0; j < col2; j++)
			{
				int t;
				cin >> t;
				vt.push_back(t);
			}
			mat2.push_back(vt);
		}
		for (int i = 0; i < row1; i++)
		{
			vector<int> vt;
			for (int j = 0; j < col2; j++)
			{
				vt.push_back(0);
			}
			matR.push_back(vt);
		}

		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				int sum = 0;
				for (int g = 0; g < row2; g++)
				{
					sum += mat1[i][g] * mat2[g][j];
				}
				matR[i][j] += sum;
			}
		}

		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				cout << matR[i][j];
				if (j < col2 - 1)
				{
					cout << " ";
				}
			}
			if (i < row1 - 1)
			{
				cout << endl;
			}
		}

	}
	else
	{
		cout << "Matrix multiplication failed." << endl;
	}
}