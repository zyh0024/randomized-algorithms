#pragma once

const int NUM = 12; // number of hash functions
const int BAND = 4;

vector<vector<int>> signature(vector<vector<int>> data, unordered_set<int> vals)
{
    int n = data.size();
    int n1 = vals.size();
    vector<vector<int>> ret(n, vector<int>(NUM));
    vector<int> rnd(vals.begin(), vals.end());
    for (int k = 0; k < NUM; k++) {
        shuffle(rnd.begin(), rnd.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        for (int i = 0; i < n; i++) {
            for (int i1 = 0; i1 < n1; i1++) {
                if (find(data[i].begin(), data[i].end(), rnd[i1]) != data[i].end()) {
                    ret[i][k] = i1;
                    break;
                }
            }
        }
    }
    return ret;
}

void minHash(vector<vector<int>> sig, float c)
{
    int n = sig.size();
    int res = 0;
    clock_t begin = clock();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < NUM; k++) {
                if (sig[i][k] == sig[j][k]) {
                    cnt++;
                }
            }
            if (cnt >= c * NUM) {
                res++;
            }
        }
    }
    clock_t end = clock();
    cout << "minhashing" << endl
         << "result: " << res << endl
         << "time(ms): " << end - begin << endl;
}

void lsh(vector<vector<int>> sig, float c)
{
    int n = sig.size();
    int res = 0;
    clock_t begin = clock();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int b = 0; b < BAND; b++) {
                cnt++;
                for (int k = b * NUM / BAND; k < NUM && k < (b + 1) * NUM / BAND; k++) {
                    if (sig[i][k] != sig[j][k]) {
                        cnt--;
                        break;
                    }
                }
            }
            if (cnt >= c * BAND) {
                res++;
            }
        }
    }
    clock_t end = clock();
    cout << "lacality sensitive hashing" << endl
         << "result: " << res << endl
         << "time(ms): " << end - begin << endl;
}
