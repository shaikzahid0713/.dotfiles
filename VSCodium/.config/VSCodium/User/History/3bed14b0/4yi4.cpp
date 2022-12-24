#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << "[ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> bfs;
vector<int> dfs;



int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    depthFirstSearch(0);
    
    bts(dfs);
}