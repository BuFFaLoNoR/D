#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m, int r1, int r2, int c1, int c2)
{
    // your code here
    vector<vector<int>> ans;
    for (int i=0; i<m.size(); i++) {
        vector<int> row;
        if (i < r1 || i > r2) {
            if (c2>c1) {
                for (int j=0; j<m[i].size(); j++) {
                    if (j < c1 || j > c2) {
                        row.push_back(m[i][j]);
                    } else {
                        continue;
                    }
                }
            } else if (c1>c2)   {
                    row = m[i];
            } else {
                for (int j=0; j<m[i].size(); j++) {
                    if (j!=c1) {
                        row.push_back(m[i][j]);
                    } else {
                        continue;
                    }
                }
            }
        } else {
            continue;
        }
        if (!row.empty()) {
            ans.push_back(row);
        }
    }
    m = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> m;
    int r, c, r1, r2, c1, c2;
    cin >> r >> c;
    cin >> r1 >> r2 >> c1 >> c2;
    m.resize(r);
    for (int i = 0; i < r; i++)
    {
        m[i].resize(c);
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }
    cross_2d(m, r1, r2, c1, c2);
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}