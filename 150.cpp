#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include<queue>

using namespace std;

int sp[100][100], prov[100], k, n;

void dfs(int j) {
	if (prov[j]) {
		return;
	}
	prov[j] = 1;
	k++;
	for (int i = 0; i < n; ++i) {
		if (sp[j][i]) {
			dfs(i);
		}
	}
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int s;
	fin >> n >> s; 
	s--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> sp[i][j];
		}
	}
	prov[s] = 1;
	for (int j = 0; j < n; j++) {
		if (sp[s][j]) {
			dfs(j);
		}
	}
	fout << k;
    return 0;
}