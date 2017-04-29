#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[100][100];
queue<pair<int, int>> q;
string way;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    char in;
    int startI, startJ, endI, endJ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in;
            if (in == 'S') {
                startI = i;
                startJ = j;
            }
            if (in == 'T') {
                endI = i;
                endJ = j;
            }
            if (in == '#') {
                graph[i][j] = -1;
            } else {
                graph[i][j] = 0;
            }
        }
    }

    graph[startI][startJ] = 1;
    //cout << startI << " " << startJ << endl;
    q.push(make_pair(startI, startJ));
    while (!q.empty()) {
        pair<int, int> temp;
        temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;
        if(i == endI && j == endJ){
            break;
        }
        if (i > 0 && graph[i - 1][j] == 0) {
            graph[i - 1][j] = graph[i][j] + 1;
            q.push(make_pair(i - 1, j));
        }
        if (j > 0 && graph[i][j - 1] == 0) {
            graph[i][j - 1] = graph[i][j] + 1;
            q.push(make_pair(i, j - 1));
        }
        if (j < m - 1 && graph[i][j + 1] == 0) {
            graph[i][j + 1] = graph[i][j] + 1;
            q.push(make_pair(i, j + 1));
        }
        if (i < n - 1 && graph[i + 1][j] == 0) {
            graph[i + 1][j] = graph[i][j] + 1;
            q.push(make_pair(i + 1, j));
        }

        /*cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    /*cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    int i = endI;
    int j = endJ;
    if(graph[i][j] == 0){
        cout << -1 << endl;
        return 0;
    }
    while (graph[i][j] != 1) {
        //cout << i << " " << j << "  " << graph[i][j] << endl;
        //cout << graph[i][j] << endl;
        if (i > 0 && graph[i - 1][j] < graph[i][j] && graph[i - 1][j] >0) {
            way += "D";
            i--;
            continue;
        }
        if (j > 0 && graph[i][j - 1] < graph[i][j] && graph[i][j - 1] > 0) {
            way += "R";
            j--;
            continue;
        }
        if (i < n && graph[i + 1][j] < graph[i][j] && graph[i + 1][j] > 0) {
            way += "U";
            i++;
            continue;
        }
        if (j < m && graph[i][j + 1] < graph[i][j] && graph[i][j + 1] > 0) {
            way += "L";
            j++;
            continue;
        }
    }
    cout << way.length() << endl;
    for (int i = way.length() - 1; i >= 0; i--) {
        cout << way[i];
    }
    cout << endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}