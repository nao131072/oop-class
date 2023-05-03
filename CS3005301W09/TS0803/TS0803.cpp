#include <iostream>
#include <vector>
using namespace std;

#define intSize 4
#define charSize 1
#define shortSize 2

void setChar(int pos, char c, vector<int> &memory);
void setInt(int pos, unsigned int n, vector<int> &memory);
void setShort(int pos, unsigned short s, vector<int> &memory);

int main()
{
	int memorySize;
	int totalCommand;
	int cmdCount = 0;
	cin >> dec >> memorySize;
	cin >> dec >> totalCommand;

	vector<int> memory;
	for (int i = 0; i < memorySize; i++)
	{
		memory.push_back(0x00);
	}
	
	while (cmdCount < totalCommand)
	{
		string action;
		cin >> dec >> action;
		int pos;
		cin >> dec >> pos;
		string type;
		cin >> dec >> type;
		if (action == "Set")
		{
			if (type == "char")
			{
				int c;
				cin >> c;
				setChar(pos, c, memory);
			}
			else if(type=="short")
			{
				unsigned short s;
				cin >> s;

				setShort(pos, s, memory);
			}
			else if (type == "int")
			{
				unsigned int i;
				cin >> i;

				setInt(pos, i, memory);
			}
			else if (type == "String")
			{
				string str;
				cin >> str;
				if (str.size() + pos > memory.size())
				{
					cout << "Violation Access." << endl;
					cmdCount++;
					continue;
				}
				

				for (int i = 0; i < str.size(); i++)
				{
					setChar(pos + i, str[i], memory);
				}
			}
		}
		else if (action == "Get")
		{
			if (pos >= memory.size())
			{
				cout << "Violation Access." << endl;
				cmdCount++;
				continue;
			}

			if (type == "char")
			{
				cout << memory[pos] << endl;
			}
			else if (type == "short")
			{
				if (pos + shortSize>= memory.size())
				{
					cout << "Violation Access." << endl;
					cmdCount++;
					continue;
				}

				unsigned short amount = 0;
				for (int i = 0; i < shortSize; i++)
				{
					if (pos + i < memorySize)
					{
						amount += (memory[pos + i]) << (8 * i);
					}
				}
				cout << amount << endl;
			}
			else if (type == "int")
			{
				if (pos + intSize >= memory.size())
				{
					cout << "Violation Access." << endl;
					cmdCount++;
					continue;
				}
				unsigned int amount = 0;
				for (int i = 0; i < intSize; i++)
				{
					if (pos + i < memorySize)
					{
						amount += (memory[pos + i]) << (8 * i);
					}
				}
				cout << amount << endl;
			}
			else if (type == "String")
			{
				int i = pos;
				while (i < memory.size())
				{
					if (memory[i] != '\0')
					{
						cout << char(memory[i]);
					}
					i++;
				}
				cout << endl;
			}

		}

		cmdCount++;
	}
}

void setChar(int pos, char c, vector<int> &memory)
{
	if (pos >= memory.size())
	{
		cout << "Violation Access." << endl;
		return;
	}

	memory[pos] = c;
}

void setInt(int pos, unsigned int n, vector<int> &memory)
{
	for (int i = intSize - 1; i >= 0; i--)
	{
		unsigned int digit;
		digit = (n >> (8 * i));
		//cout << digit << endl;
		n -= digit << (8 * i);
		if (pos + i >= memory.size())
		{
			cout << "Violation Access." << endl;
			continue;
		}
		memory[pos + i] = digit;
		//cout << pos + i << " " << hex << memory[pos + i] << " " << dec << memory[pos + i] << endl;
	}
}

void setShort(int pos, unsigned short s, vector<int> &memory)
{
	for (int i = shortSize - 1; i >= 0; i--)
	{
		long long int digit;
		digit = s >> (8 * i);
		s -= digit << (8 * i);
		if (pos + i >= memory.size())
		{
			cout << "Violation Access." << endl;
			continue;
		}
		memory[pos + i] = digit;
		
		//cout << pos + i <<" " << hex << memory[pos + i] << endl;
	}
}