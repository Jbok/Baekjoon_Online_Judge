#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	while (!cin.eof())
	{
		char temp[102];
		cin.getline(temp, 101, '\n');
		cout << temp << endl;
	}
}