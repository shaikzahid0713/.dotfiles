// AND, OR & XOR OPERATORS

#include <iostream>
#include <vector>


using namespace std;

bool isPowerOFTwo(unsigned int x) {
    return (!(x & (x - 1)));
}


int main() {

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);
    
    int x, y; 
    cin >> x >> y;

    int andOperator = x & y;
    int orOperator = x | y;
    int xorOperator = x ^ y;

    cout << "AND OPERATION " << andOperator << "\n";
    cout << "OR OPERATION " << orOperator << "\n";
    cout << "XOR OPERATION " << xorOperator << "\n";
    cout << endl; 
    
    int rightShift =  x >> 1;
    int leftShift = x << 1;
        
    cout << "Right Shift Operation " << rightShift << "\n";
    cout << "Left Shift Operation " << leftShift << "\n";
    

    unsigned int z; cin >> z;
    int negation = (~z);
    cout << "Negation Operation " << negation << "\n";
    
    unsigned int z;
    cin >> z;
    cout << "Z " << z << "\n";
    
    cout << isPowerOFTwo(z) << "\n";
    
}