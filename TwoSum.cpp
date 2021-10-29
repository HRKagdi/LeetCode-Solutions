//https://leetcode.com/problems/two-sum/
//1.Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(m[target-nums[i]]>i){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
            }
        }
        return ans;
    }
};
