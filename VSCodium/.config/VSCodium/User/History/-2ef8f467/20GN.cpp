#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> bfsVisited(10);
vector<int> dfsVisited(10);
vector<int> distance(10);
vector<int> bfs;
vector<int> dfs;

void depthFirstSearch(int current) {
    dfsVisited[current] = 1;
    dfs.emplace_back(current);
    for (auto next : graph[current]) {
        if (!dfsVisited[next]) 
            depthFirstSearch(next);
    }
}

void breadthFirstSearch(int current) {
    queue<int> bfsQueue;
    bfsQueue.emplace(current);
    bfs.emplace_back(current);
    bfsVisited[current] = 1;
    
    while(!bfsQueue.empty()) {
        int parent = bfsQueue.front();
        bfsQueue.pop();
        // distance[parent] = 1;
        for (auto child : graph[parent]) {
            if (!bfsVisited[child]) {
                bfsVisited[child] = 1;
                bfsQueue.emplace(child);
                bfs.emplace_back(child);
                // distance[child] = distance[parent] + 1;
            }
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y; 
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    breadthFirstSearch(0);
    
    cout << "Breadth First Search\n";
    for (auto x : bfs) 
        cout << x << " ";
    cout << "\n";
    
    depthFirstSearch(0);

    cout << "Depth First Search\n";
    for (auto y : dfs)
        cout << y << " ";
    cout << "\n";

}

