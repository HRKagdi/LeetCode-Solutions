//https://leetcode.com/problems/max-area-of-island/
//695. Max Area of Island

class Solution {
public:
    int dfs(vector<vector<int>>& board,vector<vector<bool>>& visited,int sx,int sy){
        visited[sx][sy]=true; int a1,a2,a3,a4; a1=a2=a3=a4=0;
        if(board[sx-1][sy]==1 && !visited[sx-1][sy]) a1=dfs(board,visited,sx-1,sy);
        if(board[sx][sy+1]==1 && !visited[sx][sy+1]) a2=dfs(board,visited,sx,sy+1);
        if(board[sx+1][sy]==1 && !visited[sx+1][sy]) a3=dfs(board,visited,sx+1,sy);
        if(board[sx][sy-1]==1 && !visited[sx][sy-1]) a4=dfs(board,visited,sx,sy-1);
        return 1+a1+a2+a3+a4;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int l=grid.size(); int m=grid[0].size();
        vector<vector<int>> board(l+2,vector<int> (m+2));
        for(int i=0;i<=l+1;i++){
            for(int j=0;j<=m+1;j++){
                if(i==0 | j==0 || i==l+1 || j==m+1) 
                    board[i][j]=0;
                else board[i][j]=grid[i-1][j-1];
            }
        }
        vector<vector<bool>> visited(l+2,vector<bool>(m+2,false));
        int ans=0;
        for(int i=0;i<=l+1;i++){
            for(int j=0;j<=m+1;j++){
                if(board[i][j]==1 && !visited[i][j]){
                    int temp=dfs(board,visited,i,j);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};

