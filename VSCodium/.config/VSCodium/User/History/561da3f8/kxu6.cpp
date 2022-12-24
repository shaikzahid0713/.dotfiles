#include <iostream>
#include <vector>

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << " [ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

using namespace std;

vector<int> primeNumbers;


void seiveOfEratosthenes() {
    
}


int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int n; cin >> n;
    vector<bool> primeSeive(n, 0);
    
    seiveOfEratosthenes();
    
}