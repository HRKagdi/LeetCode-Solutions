//https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
1508. Range Sum of Sorted Subarray Sums

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<unsigned int> sums;
        long long int mod=1e9+7;
        for(int i=1;i<=n;i++){
            unsigned int sum=0;
            for(int j=0;j<i;j++) sum+=nums[j];
            sums.push_back(sum);
            for(int j=i;j<n;j++){
                sum=sum-nums[j-i]+nums[j];
                sums.push_back(sum);
            }
        }   
        sort(sums.begin(),sums.end());
        unsigned int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans%mod+sums[i]%mod)%mod;
        }
        return ans%mod;
    }
};
