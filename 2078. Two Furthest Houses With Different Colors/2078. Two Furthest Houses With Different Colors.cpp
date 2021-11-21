//https://leetcode.com/problems/two-furthest-houses-with-different-colors/
2078. Two Furthest Houses With Different Colors

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=INT_MIN;
        for(int i=0;i<colors.size()-1;i++){
            for(int j=i+1;j<colors.size();j++){
                if(colors[i]!=colors[j]){
                    ans=max(ans,(j-i));
                }
            }
        }
        return ans;
    }
};
