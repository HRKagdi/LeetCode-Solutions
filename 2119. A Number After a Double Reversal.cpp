//https://leetcode.com/contest/weekly-contest-273/problems/a-number-after-a-double-reversal/
// 2119. A Number After a Double Reversal

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0) return true;
        vector<int> v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        return !(v[0]==0);
    }
};
