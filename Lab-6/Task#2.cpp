#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    graph.resize(n, vector<int>(n,0));
    int from, to;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           cin >> graph[i][j];
        }
    }
    //cout <<"kek" << endl;
    bool isNonOr = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                if(graph[i][j] == 1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else {
                if (graph[i][j] != graph[j][i]) {
                    cout <<"NO" << endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}