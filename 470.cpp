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
	int h, w, n;
	fin >> h >> w >> n;
	vector <vector <int>> sp;
	for (int i = 0; i < h; i++) {
		vector <int> prov(w);
		for (int j = 0; j < w; j++) {
			fin >> prov[j];
		}
		sp.push_back(prov);
	}
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		int answer = 0;
		fin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				answer += sp[j - 1][k - 1];
			}
		}
		fout << answer << endl;
	}

    return 0;
}