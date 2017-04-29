#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int hash_value = 703;
vector<pair<string, string>> set[hash_value+1];

int sum(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += 31 * ans + s[i];
        ans %= hash_value;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    string operation;
    string val, key;
    while (cin >> operation) {
        if (operation == "put") {
            cin >> key >> val;
            int temp = sum(key) % hash_value;
            bool isInSet = 0;
            for (int i = 0; i < set[temp].size(); i++) {
                if(set[temp][i].first == key){
                    set[temp][i].second = val;
                    isInSet = 1;
                }
            }
            if(isInSet == 0){
                set[temp].push_back(make_pair(key, val));
            }
        }
        if (operation == "delete") {
            cin >> key;
            int temp = sum(key) % hash_value;
            for (int i = 0; i < set[temp].size(); i++) {
                if(set[temp][i].first == key){
                    set[temp].erase(set[temp].begin()+i);
                }
            }
        }
        if (operation == "get") {
            cin >> key;
            int temp = sum(key) % hash_value;
            bool isInSet = 0;
            for (int i = 0; i < set[temp].size(); i++) {
                if(set[temp][i].first == key){
                    isInSet = 1;
                    cout << set[temp][i].second << endl;
                    break;
                }
            }
            if(isInSet == 0){
                cout << "none" << endl;
            }
        }
    }
}