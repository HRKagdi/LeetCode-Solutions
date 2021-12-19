//https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
//1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp=num;
        for(int i=1;i<=k;i++){
            next_permutation(temp.begin(), temp.end());
        }
        int ans = 0;
        for(int i=0;i<num.size();i++)
        {
            if(num[i] != temp[i])
            {
               int j=i+1;
               for(;j<num.size();){
                   if(temp[j]!=num[i]) j++;
                   else break;
               }
               while(j>i){
                   ans++;
                   char ch=temp[j];
                   temp[j]=temp[j-1];
                   temp[j-1]=ch;
                   j--;
               }
            }
        }
        return ans;
    }
};
