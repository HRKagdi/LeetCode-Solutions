//https://leetcode.com/problems/counting-bits/
//338. Counting Bits

class Solution {
public:
    int count(int n){
        int count=0;
        while(n>0){
            if(n%2==1) count++;
            n/=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        for(int i=0;i<=n;i++){
            v[i]=count(i);
        }     
        return v;
    }
};
