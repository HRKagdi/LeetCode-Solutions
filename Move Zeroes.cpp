//https://leetcode.com/problems/move-zeroes/submissions/
//283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) c++;
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[x++]=nums[i];
            }
        }
        for(int i=nums.size()-c;i<nums.size();i++){
            nums[i]=0;
        }
    }
};
