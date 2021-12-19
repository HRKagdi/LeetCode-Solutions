//https://leetcode.com/problems/min-cost-climbing-stairs/
//746. Min Cost Climbing Stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l=cost.size();
        for(int i=2;i<l;i++){
            cost[i]=min(cost[i-1], cost[i-2])+cost[i];
        }
        return min(cost[l-1],cost[l-2]);
    }
};
