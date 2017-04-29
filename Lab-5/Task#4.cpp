


#include<string>
#include <vector>
#include <iostream>

using namespace std;

struct element {
    string key, value;
};

vector<vector<pair<string, string>>> map(3000000, vector<pair<string, string>>());
const int hash_value = 703;

int hashing(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += 31 * ans + s[i];
        ans %= hash_value;
    }
    return ans;
}


int found(string key, string value) {
    int hash = hashing(key);
    if (map[hash].size() != 0) {
        for (int i = 0; i < map[hash].size(); i++) {
            if (map[hash][i].first == key && map[hash][i].second == value) {
                return i;
            }
        }
    }
    return -1;
}


void insert(string key, string value) {
    int i = found(key, value);
    int hash = hashing(key);
    if (i != -1) {
        return;
    } else
        map[hash].push_back(make_pair(key, value));
    return;
}


void del(string key, string value) {
    int hash = hashing(key);
    int i = found(key, value);
    if (i != -1) {
        map[hash].push_back(make_pair("", ""));
        for (int j = i; j < map[hash].size() - 1; j++) {
            map[hash][j] = map[hash][j + 1];
        }
        map[hash].pop_back();
        map[hash].pop_back();
    }
}

void delall(string key) {
    int hash = hashing(key);
    vector<pair<string, string> > a;
    for (int i = 0; i < map[hash].size(); i++) {
        if (map[hash][i].first != key)
            a.push_back(map[hash][i]);
    }
    map[hash] = a;
}

void get(string key) {
    int hash = hashing(key);
    int count = 0;
    for (int i = 0; i < map[hash].size(); i++)
        if (map[hash][i].first == key)
            count++;
    cout << count;
    for (int i = 0; i < map[hash].size(); i++)
        if (map[hash][i].first == key)
            cout << " " << map[hash][i].second;
    cout << endl;
}


int main() {
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    string in;
    string key, value;
    while (cin >> in) {

        if (in == "put") {
            cin >> key >> value;
            insert(key, value);
        } else if (in == "delete") {
            cin >> key >> value;
            del(key, value);
        } else if (in == "deleteall") {
            cin >> key;
            delall(key);
        } else {
            cin >> key;
            get(key);
        }
    }
    return 0;
}