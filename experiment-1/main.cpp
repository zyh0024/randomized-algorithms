#include <bits/stdc++.h>

using namespace std;

#include "min_hash.h"
#include "naive.h"
#include "read_data.h"

int main()
{
    float c = 0.8;
    unordered_set<int> vals;
    vector<vector<int>> data;
    getdata(data, vals);
    naive(data, c);
    vector<vector<int>> sig = signature(data, vals);
    minHash(sig, c);
    lsh(sig, c);
}
