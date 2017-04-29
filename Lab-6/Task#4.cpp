#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<int>> graph;
vector <int> components;
int main() {
    int n,m;
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    cin >> n >> m;
    graph.resize(n);
    components.resize(n,0);
    int current = 1;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }
    for(int i = 0; i < n; i++){
        if(components[i] == 0){
            components[i] = current;
            queue<int> temp;
            temp.push(i);
            while(!temp.empty()){
                int v = temp.front();
                temp.pop();
                for(int i = 0; i < graph[v].size(); i++){
                    int to = graph[v][i];
                    if(components[to] == 0){
                        components[to] = current;
                        temp.push(to);
                    }
                }
            }
            current++;
        }
    }
    for(int i = 0; i < components.size(); i++){
        if(components[i] == 0){
            components[i] = current;
            current++;
        }
        //cout << components[i] << " ";
    }
    cout << current-1
         << endl;
    for(int i = 0; i < components.size(); i++){
        cout << components[i] << " ";
    }
    cout << endl;
    return 0;
}