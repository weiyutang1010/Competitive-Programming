class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pt1 = 0, pt2 = 0;
        for (int pt1 = 0; pt1 < (int)name.size(); pt1++) {
            int count1 = 1, count2 = 0;
            bool found = false;
            while (pt1 < (int)name.size() - 1 && name[pt1] == name[pt1 + 1]) {
                pt1++;
                count1++;
            }
            
            while (pt2 < (int)typed.size() && name[pt1] == typed[pt2]) {
                pt2++;
                count2++;
            }
            
            if (count2 < count1) {
                return false;
            }
        }
        
        if (pt2 < typed.size()) {
            return false;
        }
        
        return true;
    }
};