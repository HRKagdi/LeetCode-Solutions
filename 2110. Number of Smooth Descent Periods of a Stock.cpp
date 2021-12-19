//https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
// 2110. Number of Smooth Descent Periods of a Stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int currMax=1; long long int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1){
                currMax++;
            }
            else{
                ans+=(currMax*(currMax+1))/2; currMax=1;
            }
        }
        ans+=(currMax*(currMax+1))/2; 
        return ans;
    }
};
