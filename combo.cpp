/*
ID: jiefish1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
using namespace std;

int check(int v, int x, int count)
{
	int a = abs(v - x);
	int b = abs(count - x) + v;
	if (a <= 2 || b <= 2)
	{
		return 1;
	}
	 a = abs(v - x);
	 b = abs(count - v) + x;
	if (a <= 2 || b <= 2)
	{
		return 1;
	}
	return 0;
}
bool validcombo(int v[], int x, int y, int z,int count);
bool validcombo(int v[], int x, int y, int z, int count)
{
	

	if (check(v[0] , x,count)  
		&& check(v[1] , y,count)  
		&& check(v[2] , z,count) )
	{
		return true;
	}
	return false;
}

int main()
{
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	int farm[3], master[3];
	int i, j, k;
	int count = 0;
	fin >> count;
	for (i = 0; i < 3; i++)
	{
		fin >> farm[i];
	}
	for (i = 0; i < 3; i++)
	{
		fin >> master[i];
	}
	int sum = 0,p,q,r;
	for (i = 1; i <= count; i++)
	{
		for (j = 1; j <= count; j++)
		{
			for (k = 1; k <= count; k++)
			{
				p = i;
				
				q = j;
				
				r = k;
				if (validcombo(farm, p, q, r,count)
					|| validcombo(master, p, q, r,count))
				{
					sum++;
					//cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	fout << sum << endl;
}
	