//https://leetcode.com/contest/weekly-contest-264/problems/number-of-valid-words-in-a-sentence/
// 2047. Number of Valid Words in a Sentence

class Solution {
public:
    int countValidWords(string sentence) {
        int l=sentence.size(); int ans=0;
        for(int i=0;i<l;){
            string str="";
            while(i<l && sentence[i]==' '){i++;}
            while(i<l && sentence[i]!=' '){
                str+=sentence[i++];
            }
            while(i<l && sentence[i]==' '){
                i++;
            }
            bool b=true; int hyp=0; int punc=0;
            //cout<<str<<" ";
            for(int j=0;j<str.size();j++){
                if(str[j]=='-'){
                    hyp++;
                    if(j==0 || j==str.size()-1){
                        b=false; break;
                    }
                    if((0<=str[j-1]-'a' && 26>=str[j-1]-'a')&&(0<=str[j+1]-'a' && 26>=str[j+1]-'a')){
                        continue;
                    }
                    else{b=false; break;}
                    
                }
                else if(str[j]=='.' || str[j]=='!' || str[j]==','){
                    punc++;
                    if(j!=str.size()-1) {
                        b=false; break;
                    }
                }
                else if(0<=str[j]-'0' && 9>=str[j]-'0'){ b=false; break;}
                else{
                    if(0<=str[j]-'a' && 26>=str[j]-'a'){continue;}
                    else {b=false; break;}
                }
                
            }
            if(b && hyp<=1 && punc<=1) ans++;
        }
        return ans;
    }
};
