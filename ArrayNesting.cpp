//https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=0; vector<bool> visited(n,false);
        for(int i=0;i<nums.size();i++){
            if(!visited[nums[i]]){
                unordered_set<int> s; s.insert(nums[i]); int index=nums[i];
                int x=1;
                while(true){
                    s.insert(nums[index]);
                    index=nums[index];
                    if(s.size()!=x+1) break;
                    x++;
                    visited[nums[index]]=true;
                }
                if(s.size()>ans) ans=s.size();
            }
        }
        return ans;
        
    }
};
