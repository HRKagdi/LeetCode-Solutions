//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
//1545. Find Kth Bit in Nth Binary String

class Solution {
public:
    string flip(string str){
        int l=str.size();
        for(int i=0;i<l;i++){
            str[i]=str[i]^1;
        }
        return str;
    }
    char findKthBit(int n, int k) {
        string str="0"; string ans="";
        for(int i=1;i<=n;i++){
            ans=str+"1"; string temp=flip(str);
            reverse(temp.begin(),temp.end());
            ans+=temp;
            str=ans;
        }
        return ans[k-1];
    }
};
