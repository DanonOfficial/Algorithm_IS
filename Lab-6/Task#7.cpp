#include <iostream>
#include <vector>
#include <stack>
//Поиск в глубину по компонентам с чеком на наличие цикла
using namespace std;
int n,m;
vector<vector<int> > graph;
vector<int> color;//0 - white, 1- grey, 2 - black
stack<int> res;
bool isCycle = false;

void dfs(int a) {
    color[a] = 1;
    for (int i = 0; i < graph[a].size(); i++) {
        if(color[graph[a][i]] == 1){
            isCycle = true;
        }
        if (color[graph[a][i]] == 0) {
            //isCycle = false;
            dfs(graph[a][i]);
        }
    }
    //cout <<"kek" << endl;
    res.push(a);
    color[a] = 2;
}
void topologicalSort(){
    for(int i = 0; i < n; i++){
        if(isCycle){
            break;
        }
        if(color[i] == 0){
            dfs(i);
        }
    }
}
int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    cin >> n >> m;
    graph.resize(n);
    color.resize(n, 0);
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    topologicalSort();
   // cout << res.size() << endl;
    if (!isCycle) {
        while(!res.empty()){
            cout << res.top()+1 << " ";
            res.pop();
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}