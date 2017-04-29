#include <iostream>
#include <string>
#include <vector>

using namespace std;
int hash_value = 703;
vector<vector<int>> set(704);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string a;
    int temp;
    while (cin >> a) {
        if (a == "insert") {
            cin >> temp;
            int val = abs(temp) % 703;
            bool flag = 0;
            for (int i = 0; i < set[val].size(); i++) {
                if (set[val][i] == temp) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                set[val].push_back(temp);
            }
        }
        if (a == "delete") {
            cin >> temp;
            int val = abs(temp) % 703;
            for (int i = 0; i < set[val].size(); i++) {
                if (set[val][i] == temp) {
                    set[val].erase(set[val].begin()+i);
                    break;
                }
            }
        }
        if (a == "exists") {
            cin >> temp;
            int val = abs(temp) % 703;
            bool flag = 0;
            for (int i = 0; i < set[val].size(); i++) {
                if (set[val][i] == temp) {
                    flag = 1;
                }
            }
            flag == 0 ? cout << "false" << endl : cout << "true" << endl;
        }
    }
}
