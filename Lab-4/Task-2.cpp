#include <iostream>
#include <vector>
int max_len;
 
int search[200020][3];
using namespace std;
 
std::vector < pair <int, int> > temp; //second == 0 - left, second == 1 - right;
int flag = 0;
int deepsearch(int prev, int min, int max) {
    if(search[prev][0] <= min || search[prev][0] >= max){
        flag = -1;
        return -1;
    }
    if(search[prev][1] != 0){
        deepsearch(search[prev][1], min, search[prev][0]);
    }
    if(search[prev][2] != 0){
        deepsearch(search[prev][2],search[prev][0], max);
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    cin >> n;
    max_len = 0;
    if (n == 0) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> search[i + 1][0] >> search[i + 1][1] >> search[i + 1][2];
    }
    temp.push_back(make_pair(1, -1));
    deepsearch(1, -1000000000, 1000000000);
 
    flag == -1 ? cout <<"NO" << endl : cout << "YES" << endl;
 
}
