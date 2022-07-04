#pragma once

void naive(vector<vector<int>> data, float c)
{
    int x = 0;
    clock_t begin = clock();
    for (unsigned i1 = 0; i1 < data.size() - 1; i1++) {
        for (unsigned i2 = i1 + 1; i2 < data.size(); i2++) {
            int cnt = 0;
            for (unsigned j1 = 0, j2 = 0; j1 < data[i1].size() && j2 < data[i2].size();) {
                if (data[i1][j1] == data[i2][j2]) {
                    cnt++;
                    j1++;
                    j2++;
                } else if (data[i1][j1] < data[i2][j2]) {
                    j1++;
                } else {
                    j2++;
                }
            }
            if (cnt >= c * (data[i1].size() + data[i2].size() - cnt)) {
                x++;
            }
        }
    }
    clock_t end = clock();
    cout << "naive" << endl
         << "result: " << x << endl
         << "time(ms): " << end - begin << endl;
}
