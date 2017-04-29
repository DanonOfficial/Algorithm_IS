#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    cin >> n >> m;

    graph.resize(n, vector<int>(n,0));
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        graph[from-1][to-1] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
