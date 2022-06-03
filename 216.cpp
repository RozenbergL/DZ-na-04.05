#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include<queue>

using namespace std;


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
    int summa = 0;
    int maxi = 0;
    int current;
    for (int i = 0; i < n; ++i)
    {
        fin >> current;
        summa += current;
        maxi = max(maxi, current);
    }

    fout << min(summa / 2, summa - maxi);

    return 0;
}