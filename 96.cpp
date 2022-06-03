#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    int x, y;
    fin >> x >> y;
    vector <vector <int>> bool_sp;
    for (int i = 0; i < n; i++) {
        vector <int> bool_prov(m);
        for (int j = 0; j < m; j++) {
            bool_prov[j] = 0;
        }
        bool_sp.push_back(bool_prov);
    }
    bool_sp[0][0] = 1;
    int x0 = 0;
    int y0 = 0;
    int flag = 0;
    int flag2 = 0;
    while (true) {
            if (flag == 0) {
                while (y0 < m - 1) {
                    if (x0 == x - 1 && y0 == y - 1) {
                        flag2 = 1;
                        break;
                    }
                    if (bool_sp[x0][y0 + 1] == 0) {
                        bool_sp[x0][y0 + 1] = 1;
                        y0++;
                    }
                    else {
                        break;
                    }
                }
                flag = (flag + 1) % 4;
            }
            //cout << x0 << " " << y0 << endl;
            if (flag == 1) {
                while (x0 < n - 1) {
                    if (x0 == x - 1 && y0 == y - 1) {
                        flag2 = 1;
                        break;
                    }
                    if (bool_sp[x0 + 1][y0] == 0) {
                        bool_sp[x0 + 1][y0] = 1;
                        x0++;
                    }
                    else {
                        break;
                    }
                }
                flag = (flag + 1) % 4;
            }
            //cout << x0 << " " << y0 << endl;
            if (flag == 2) {
                while (y0 > 0) {
                    if (x0 == x - 1 && y0 == y - 1) {
                        flag2 = 1;
                        break;
                    }
                    if (bool_sp[x0][y0 - 1] == 0) {
                        bool_sp[x0][y0 - 1] = 1;
                        y0--;
                    }
                    else {
                        break;
                    }
                }
                flag = (flag + 1) % 4;
            }
            //cout << x0 << " " << y0 << endl;
            if (flag == 3) {
                while (x0 > 0) {
                    if (x0 == x - 1 && y0 == y - 1) {
                        flag2 = 1;
                        break;
                    }
                    if (bool_sp[x0 - 1][y0] == 0) {
                        bool_sp[x0 - 1][y0] = 1;
                        x0--;
                    }
                    else {
                        break;
                    }
                }
                flag = (flag + 1) % 4;
            }
            //cout << x0 << " " << y0 << endl;
            if (flag2 == 1) {
                break;
            }
        }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bool_sp[i][j] == 1) {
                answer++;
            }
        }
    }
    fout << answer;
    return 0;
}