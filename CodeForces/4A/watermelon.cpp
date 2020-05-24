#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
 
bool watermelon(const int& num) {
    for (int i = 1; i <= num/2; i++) {
        if ((i %2 == 0)&& ((num-i) %2 == 0)) {
            return true;
        }   
    }
    return false;
}
 
int main() {
    int n;
    cin >> n;
    
    cout << (watermelon(n) ? "YES" : "NO") << "\n";
    return 0;
}