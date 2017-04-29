#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int graph[100][100];
int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    cin >> n >> m;
    bool flag= false;
    int from ,to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        if(graph[to-1][from-1] == 1){
            cout <<"YES" << endl;
            return 0;
        }
        graph[from-1][to-1] = 1;
        graph[to-1][from-1] = 1;

    }
    cout <<"NO"<< endl;
    return 0;
}