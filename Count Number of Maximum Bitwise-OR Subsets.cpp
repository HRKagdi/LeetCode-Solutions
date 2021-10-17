// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// 5904. Count Number of Maximum Bitwise-OR Subsets



class Solution {
public:

    void helper(int ind, vector<int>& v, vector<int>& arr, vector<vector<int>>&res){
        if(ind == v.size()){
            res.push_back(arr);
            return;
        }
        arr.push_back(v[ind]);
        helper(ind + 1, v, arr, res);
        arr.pop_back();
        helper(ind + 1, v, arr, res);
    }
    int subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        helper(0, nums, arr, res);
        map<long long int,int> m;
        for(int i=0;i<res.size();i++){
            if(res[i].size()==0) continue;
            long long int x=res[i][0];
            for(int j=1;j<res[i].size();j++){
                x|=res[i][j];
            }
            m[x]++;
        }
        map<long long int,int>::iterator it;
        long long int maxi=-1; int fans;
        for(it=m.begin();it!=m.end();it++){
           // cout<<it->first<<" "<<it->second<<endl;
            if(it->first>maxi){
                fans=it->second;
                maxi=it->first;
            }
        }
        return fans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        return subsets(nums);

    }
};
