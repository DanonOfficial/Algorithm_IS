#include <iostream>
 
using namespace std;
 
int main() {
    freopen("queuemin.in", "r", stdin);
    freopen("queuemin.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int *p = new int[n + 1];
    char temp;
    int head = 0;
    int tail = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == '+') {
            cin >> p[tail];
            tail++;
        }
        if (temp == '-') {
            head++;
        }
        if (temp == '?') {
            int min = p[head];
            for (int i = head + 1; i < tail; i++) {
                if (p[i] < min) {
                    min = p[i];
                }
            }
            cout << min << endl;
        }
    }
    return 0;
}
