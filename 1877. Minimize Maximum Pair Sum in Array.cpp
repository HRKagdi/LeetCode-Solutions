//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
//1877. Minimize Maximum Pair Sum in Array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int ans=INT_MIN; int l=nums.size();
            for(int i=0;i<l/2;i++){
                ans=max(ans,nums[l-i-1]+nums[i]);
            }
            return ans;
    }
};
