//https://leetcode.com/contest/weekly-contest-268/problems/range-frequency-queries/
// 2080. Range Frequency Queries

class RangeFreqQuery {
public:
    vector<int> v;
    map<int,vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            v.push_back(arr[i]);
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int a=lower_bound(m[value].begin(),m[value].end(),left)-m[value].begin();
        int b=upper_bound(m[value].begin(),m[value].end(),right)-m[value].begin();
        return b-a;
    }
};
