// Explanation: we start assigning people with smallest height
//              everyone else must have greater height
//              so if the smallest person has 2 people in front, he must be the 3rd person
//              we assign placement for each people from smallest to tallest

#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        vector<vector<int>> ans(people.size()); //Sort the people by height
        
        for (int i = 0; i < ans.size(); i++) {
            ans[i].resize(2);
            ans[i][0] = INT_MAX; //Set initial value to INT_MAX
        }
        
        int counter = 0;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                if (people[i][0] <= ans[j][0]) { //Check how many people (greater or equal in height) is in front
                    counter++;
                }
                
                if (counter > people[i][1]) { //If enough people insert element at that position
                    ans[j] = people[i];
                    break;
                }
            }
            counter = 0;
        }
        
        
        
        return ans;
    }
};