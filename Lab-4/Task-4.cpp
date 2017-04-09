#include <iostream>
#include <vector>
 
using namespace std;
int p[100001];
int n;
 
int leftBinarySearch(int key) {
    int l = -1;
    int r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (p[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}
 
int rightBinarySearch(int key) {
    int l = -1;
    int r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (p[m] <= key) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int m;
    cin >> m;
    int key;
    for (int i = 0; i < m; i++) {
        cin >> key;
        int left = leftBinarySearch(key);
        int right = rightBinarySearch(key);
       // cout << left << " " << right << endl;
        if (p[left] != key) {
            cout << -1 << " " << -1 << endl;
        } else {
            if (left == right) {
                if (left == n || left == 0) {
                    cout << -1 << " " << -1 << endl;
                }
            } else {
                cout << left + 1 << " " << right << endl;
            }
        }
    }
    return 0;
}
