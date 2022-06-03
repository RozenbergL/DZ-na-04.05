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
	vector <int> answer = { 1, 0, 3, 0};
	for (int i = 4; i <= n; i++) {
		answer.push_back(4 * answer[i - 2] - answer[i - 4]);
	}
	fout << answer[n];
    return 0;
}