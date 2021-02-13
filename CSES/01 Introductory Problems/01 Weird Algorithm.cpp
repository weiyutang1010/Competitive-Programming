#include<bits/stdc++.h> 

#define ulli unsigned long long int
#define ll long long
#define ld long double

using namespace std; 
void solve(); 

int main() 
{ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t=1; 
    // cin>>t; 
    while(t--) 
    { 
      solve(); 
      cout<<"\n"; 
    } 

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

void solve() 
{ 
    ulli n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        (n & 1) ? (n = (n * 3) + 1) : (n /= 2); 
    }
    cout << 1 << "\n";
}
