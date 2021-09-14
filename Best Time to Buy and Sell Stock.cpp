//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size(); int max_till_now=INT_MIN; int maxIndex;
        int ans=0;
        for(int i=l-1;i>=0;i--){
            if(max_till_now<prices[i]){
                max_till_now=prices[i]; maxIndex=i;
            }
            if(prices[i]<max_till_now && i<maxIndex){
                ans=max(ans,max_till_now-prices[i]);
            }
        }
        return ans;
    }
};
