//https://leetcode.com/contest/biweekly-contest-65/problems/check-whether-two-strings-are-almost-equivalent/
// 2068. Check Whether Two Strings are Almost Equivalent

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int> m1,m2;
        for(int i=0;i<word1.size();i++){m1[word1[i]]++;}
        for(int i=0;i<word2.size();i++){m2[word2[i]]++;}
        map<char,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++){
            if(abs(it->second-m2[it->first])>3){
                return false;
            }
        }
        for(it=m2.begin();it!=m2.end();it++){
            if(abs(it->second-m1[it->first])>3){
                return false;
            }
        }
        return true;
    }
};
