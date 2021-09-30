//https://leetcode.com/problems/reshape-the-matrix/submissions/
//566. Reshape the Matrix


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(); int n=mat[0].size();
        if(m*n!=r*c){return mat;}
        vector<vector<int>> ans;
        int a=0; int b=0;
        for(int i=0;i<r;i++){
            vector<int> temp;
            for(int j=0;j<c;j++){
                if(b==n){ a++; b=0;}
                    temp.push_back(mat[a][b++]);
                }
                ans.push_back(temp);
        }
        return ans;
    }
};
