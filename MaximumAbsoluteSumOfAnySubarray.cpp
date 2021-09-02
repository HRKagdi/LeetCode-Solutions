//https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
//1749. Maximum Absolute Sum of Any Subarray

class Solution {
public:
    int kadanes(vector<int>& arr){
        int meh,msf; meh=0; msf=INT_MIN;
        for(int i=0;i<arr.size();i++){
            meh+=arr[i];
            if(arr[i]>meh) meh=arr[i];
            if(msf<meh) msf=meh;
        }
        return msf;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int a1=kadanes(nums);
        for(int i=0;i<nums.size();i++) nums[i]*=-1;
        int a2=kadanes(nums);
        return max(a1,a2);
        
    }
};
