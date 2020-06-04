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

void solve() {
    string word;
    cin >> word;

    //Count how many capital letters there are
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < (int)word.size(); i++) {
        if (word[i] >= 97 && word[i] <= 122) {
            count1++;
        } else {
            count2++;
        }
    }

    //If more captial letters then convert all into upper case. Vice versa.
    for (int i = 0; i < (int)word.size(); i++) {
        if (count1 < count2 && word[i] >= 97 && word[i] <= 122) {
            word[i] = word[i] - 32;
        } else if (count1 >= count2 && word[i] >= 65 && word[i] <= 90) {
            word[i] = word[i] + 32;
        }
    }

    cout << word << "\n";
}