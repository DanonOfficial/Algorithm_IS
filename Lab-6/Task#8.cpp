#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> graph[100001];
char color[100001];
vector<int> path;
int startCycle;
int endCycle;
int finishCycle = false;
bool isCycle = false;

void dfs(int a) {
    color[a] = 1;
    for(int i = 0; i < graph[a].size(); i++){
        int to = graph[a][i];
        if(color[to] == 0){
            path[to] = a;
            dfs(to);
            if(isCycle){
                return;
            }
        }else if(color[to] == 1){
            endCycle = a;
            startCycle = to;
            isCycle = true;
            return;
        }
    }
    color[a] = 2;
    return;

}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    path.resize(n,0);
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from-1].push_back(to-1);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && !isCycle) {
            path.erase(path.begin(), path.end());
            dfs(i);
        }
    }
    if(isCycle) {
        cout << "YES" << endl;
        vector<int> res;
        for(int i = endCycle; i != startCycle; i = path[i]){
            res.push_back(i);
        }
        res.push_back(startCycle);
        for(int i = res.size()-1; i>= 0; i--){
            cout << res[i] +1<< " ";
        }
        cout << endl;
    }else{
        cout <<"NO" << endl;
    }


}
