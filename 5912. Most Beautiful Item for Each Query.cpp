//https://leetcode.com/contest/biweekly-contest-65/problems/most-beautiful-item-for-each-query/
// 5912. Most Beautiful Item for Each Query

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> v;
        for(int i=0;i<items.size();i++){
            v.push_back(make_pair(items[i][0],items[i][1]));
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> t1;
        for(int i=0;i<v.size()-1;i++){
            if(v[i].first!=v[i+1].first){
                t1.push_back(v[i]);
            }
        }
        t1.push_back(v[v.size()-1]);
        int maxi=INT_MIN;
        for(int i=1;i<t1.size();i++){
            if(t1[i].second<t1[i-1].second){
                t1[i].second=t1[i-1].second;
            }
        }maxi=t1[t1.size()-1].second;
        vector<int> ans; 
        for(int i=0;i<queries.size();i++){
            pair<int,int> p=make_pair(queries[i],0);
            int index=lower_bound(t1.begin(),t1.end(),p)-t1.begin();
            if(index==t1.size()){ans.push_back(maxi); continue;}
            if(t1[index].first==queries[i]){
                ans.push_back(t1[index].second);
            }
            else if(index>0){
                index--;
                ans.push_back(t1[index].second);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
