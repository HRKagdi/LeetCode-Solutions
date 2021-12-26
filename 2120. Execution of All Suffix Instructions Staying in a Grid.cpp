//https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
// 2120. Execution of All Suffix Instructions Staying in a Grid

class Solution {
public:
    int helper(string s, vector<int>&temp,int n){
        int ans=0; vector<int> start=temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                if(start[1]!=0) {ans++; start[1]--;}
                else break;
            }
            else if(s[i]=='R'){
                if(start[1]!=(n-1)) { ans++; start[1]++;}
                else break;
            }
            else if(s[i]=='U'){
                if(start[0]!=0) {ans++; start[0]--;}
                else break;
            }
            else if(s[i]=='D'){
                if(start[0]!=(n-1)) {ans++; start[0]++;}
                else break;
            }
        }
        return ans;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans(s.size());
        for(int i=0;i<s.size();i++){
            string temp=s.substr(i);  
            ans[i]=helper(temp,startPos,n);
        }
        return ans;
    }
};
