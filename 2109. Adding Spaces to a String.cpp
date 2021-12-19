//https://leetcode.com/problems/adding-spaces-to-a-string/
// 2109. Adding Spaces to a String

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && spaces[j]==i){
                answer+=" "; j++; i--;
            }
            else{
                answer+=s[i];            
            }
        }
        return answer;
    }
};
