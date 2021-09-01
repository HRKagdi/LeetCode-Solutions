//https://leetcode.com/problems/power-of-two/
//231. Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%2!=0) return false;
        return isPowerOfTwo(n/2);
        
    }
};
