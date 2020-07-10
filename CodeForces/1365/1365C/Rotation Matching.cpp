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
 
//Explanation: Find the distance between element in new and old array. Count towards the right side.
//             Find the max count of element that has the same distance. It means we can rotate the array
//             and those will match.
void solve() {
    int n;
    cin >> n;
 
    int temp;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] = i; //store the element and its distance
    }
 
    unordered_map<int, int> ans;
    int max_n = -1;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        int num = m[temp];
        int distance = (num >= i) ? num - i: (n - i) + num; //calculate the distance between element in old and new array
        v.push_back(distance); //store the distance between original and new array
        ans[distance]++; //increase count
        max_n = max(max_n, ans[distance]); //keep track of which distance has most count
    }
    
    cout << max_n << "\n";
}