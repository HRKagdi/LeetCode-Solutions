//https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/
//350. Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<nums1.size();i++) m1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) m2[nums2[i]]++;
        unordered_map<int,int>::iterator it;
        vector<int> ans;
        for(it=m1.begin();it!=m1.end();it++){
            int temp=min(it->second,m2[it->first]);
            for(int i=1;i<=temp;i++) ans.push_back(it->first);
        }
        return ans;
    }
};
