//https://leetcode.com/problems/flood-fill/
//733. Flood Fill

class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        int oldColor=image[sr][sc];
        image[sr][sc]=newColor;
        if(sr-1>=0 && image[sr-1][sc]==oldColor){
            helper(image,sr-1,sc,newColor);
        }
        if(sr+1<image.size() && image[sr+1][sc]==oldColor){
            helper(image,sr+1,sc,newColor);
        }
        if(sc-1>=0 && image[sr][sc-1]==oldColor){
            helper(image,sr,sc-1,newColor);
        }
        if(sc+1<image[0].size() && image[sr][sc+1]==oldColor){
            helper(image,sr,sc+1,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        helper(image,sr,sc,newColor);
        return image;
    }
};
