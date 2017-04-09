#include <iostream>
 
int max_len;
 
int search[200020][3];
 
using namespace std;
 
void deepsearch(int prev, int len) {
    if (max_len < len) {
        max_len = len;
    }
    if (search[prev][1] > 0) {
        deepsearch(search[prev][1], len + 1);
    }
    if (search[prev][2] > 0) {
        deepsearch(search[prev][2], len + 1);
    }
 
}
 
 
int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    cin >> n;
    max_len = 0;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> search[i + 1][0] >> search[i + 1][1] >> search[i + 1][2];
    }
    deepsearch(1, 1);
    cout << max_len << endl;
 
}
