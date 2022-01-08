//https://leetcode.com/problems/complement-of-base-10-integer/
//1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int temp=0; int t1=n;
        while(n>0){
            temp++; n/=2;
        }
        long long int x=pow(2,temp)-1;
        return x-t1;
    }
};
