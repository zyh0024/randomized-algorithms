#pragma once

const string FILE_NAME = "E1_kosarak_100k.txt";

void getdata(vector<vector<int>>& data, unordered_set<int>& vals)
{
    ifstream infile;
    infile.open(FILE_NAME);
    string s;
    unordered_map<int, int> val2idx;
    while (getline(infile, s)) {
        int pos = s.find('\t');
        int x = stoi(s.substr(0, pos));
        int y = stoi(s.substr(pos + 1));
        vals.emplace(y);
        if (val2idx.find(x) == val2idx.end()) {
            val2idx[x] = data.size();
            data.emplace_back(vector<int>({ y }));
        } else {
            vector<int> &a=data[val2idx[x]];
            //remove duplicates
            if(find(a.begin(),a.end(),y)==a.end()){
                a.emplace_back(y);
            }
        }
    }
    infile.close();

    for (auto& v : data) {
        sort(v.begin(), v.end());
    }
}
