#include <iostream>
#include <queue>

using namespace std;

int v, e;
vector<int> graph(10);
vector<int> visited(10);


int main() {
    freopen("input.txt", 'r', stdin);
    freopen("output.txt", 'w', stdout);
    
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    
}