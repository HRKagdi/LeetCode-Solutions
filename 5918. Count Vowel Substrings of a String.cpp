//https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// 5918. Count Vowel Substrings of a String

class Solution {
public:
    void subString(string str, int n,vector<string>& ans)
    {
        for (int len = 1; len <= n; len++)
        {   
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;    string x="";       
                for (int k = i; k <= j; k++)
                    x+=str[k];
             
                ans.push_back(x);
            }
        }
    }
    int countVowelSubstrings(string word) {
        set<char> s;  int res=0;
        s.insert('a'); s.insert('e'); s.insert('i'); s.insert('o'); s.insert('u');
        for(int i=0;i<word.size();i++){
            if(s.find(word[i])!=s.end()){
                 string p=""; p+=word[i]; i++;
                while(i<word.size() && s.find(word[i])!=s.end()){
                    p+=word[i];
                    i++;
                }
                vector<string> temp; subString(p,p.size(),temp);
                for(int a=0;a<temp.size();a++){
                    map<char,int> m;
                    for(int b=0;b<temp[a].size();b++){
                        m[temp[a][b]]++;
                    }
                    if(m.size()==5) res++;
                }
            }
            
        }
        return res;
    }
};
