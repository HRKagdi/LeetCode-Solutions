//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// 2114. Maximum Number of Words Found in Sentences

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        set<string> str; int fans=INT_MIN;
        for(int i=0;i<sentences.size();i++){
            int j=0; int ans=1;
            while(j<sentences[i].size()){
                if(sentences[i][j]==' '){
                    ans++; 
                }
                j++;
            }
            fans=max(ans,fans);
        }
        return fans;
    }
};
