#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
 
using namespace std;
 
void sum_of_round_number(const string& num) {
    vector<float> result;
    int counter = 0;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != '0') {
            counter++;
            int temp = num[i] - 48;
            result.push_back(temp * pow(10, (num.size() - i - 1)));
        }
    }
    cout << counter << "\n";
    for (int i = 0; i < counter; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    int n;
    cin >> n;
    
    string j;
    for (int i = 0; i < n; i++) {
        cin >> j;
        sum_of_round_number(j);
    }
}