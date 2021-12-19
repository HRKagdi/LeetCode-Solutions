//https://leetcode.com/problems/find-the-town-judge/
//997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> m1(n+1,0),m2(n+1,0);  
        for(int i=0;i<trust.size();i++){
            m1[trust[i][0]]++;
            m2[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(m1[i]==0 && m2[i]==(n-1)){
                ans=i;
            }
        }
        return ans;
    }
};
