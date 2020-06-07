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
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
//Explanation: Two condition to look for: is the array already sorted and are all the elements the same type
//             If array is not sorted and at least one type is not the same, we can sort the entire array
//             by only swapping item with different type

void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    vector<int> b(n);
 
    int count = 0;
    int temp1 = 0;
    int temp2 = 0;
    bool sorted = true;
    for (int &x: a) { //Check if array is already sorted
        cin >> x;
        temp2 = x;
        if (count > 0 && temp2 < temp1) { //Compare last element to current element
            sorted = false;
        }
        temp1 = x;
        count++;
    }
 
    count = 0;
    bool same = true;
    for (int &x: b) { //Check if all the element type is the same
        cin >> x;
        temp2 = x;
        if (count > 0 && temp2 != b[0]) same = false; 
        count++;
    }
 
 
 
    if (sorted) { //return true if it is sorted already
        cout << "Yes\n";
        return;
    } 
    
    if (same) { //if not sorted, check if all the element type is the same
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}