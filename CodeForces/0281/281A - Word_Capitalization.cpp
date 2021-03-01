#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

// Fairly straightforward, use ASCII table to check if the first letter is capitalized
// If not, subtract it from 32 to find its corressponding upper case letter

void solve() {
    string word;
    cin >> word;

    if (word[0] >= 97 && word[0] <= 122) {
        word[0] = word[0] - 32;
    }
    cout << word << "\n";
}