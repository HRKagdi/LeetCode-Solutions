//https://leetcode.com/problems/reverse-string/
//344. Reverse String

class Solution {
public:
    void helper(vector<char>&s,int l,int r){
        if(l>=r) return;
        char ch=s[l]; s[l]=s[r]; s[r]=ch;
        helper(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};
