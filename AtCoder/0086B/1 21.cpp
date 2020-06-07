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
    string a, b;
    cin >> a >> b;

    string c = a+b; //Concatenate string
    float d = atoi(c.c_str());

    if (ceil(sqrt(d)) == floor(sqrt(d))) { //check if the square root of resulting number is an integer
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}