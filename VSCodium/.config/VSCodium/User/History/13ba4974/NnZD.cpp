#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <deque>
#include <queue>


using namespace std;

void run_tests() {
    int n;
    cin >> n;
    deque<int> temp;
    priority_queue<int> pq;
    unordered_set<int> us;
    set<int> os;

    
    while (n-- > 0) {
        int x; cin >> x;
        temp.emplace_front(x);
        pq.emplace(x);
        us.emplace(x);
        os.emplace(x);
    }
    
    cout << "DEQUE: \n";
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop_front();
        cout << temp.back() << " ";
        temp.pop_back();
    }
    
    cout << "\n";
    cout << "\nPriority Queue: \n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
  
    cout << "\n";
    cout << "\nUnordered Set: \n";
    for (auto x : us)
        cout << x << " ";
    cout << "\n";


    cout << "\nOrdered Set: \n";
    for (auto x : os)
        cout << x << " ";
    cout << "\n";

}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("../../input.txt",  "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt",  "w", stderr);
    #endif

    int tests = 1;
    // cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/