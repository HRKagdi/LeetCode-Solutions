//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
//1347. Minimum Number of Steps to Make Two Strings Anagram

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        int ans=0;
        for(auto it:m1){
            if(it.second>m2[it.first]){
                ans+=it.second-m2[it.first];
            }
        }
        return ans;
    }
};
