//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
         int temp=0; bool b=false;
        vector<int> pals;
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){
                if(mp[words[i]]>=1){
                    pals.push_back(mp[words[i]]);
                    mp[words[i]]=0;
                }
            }
            else{
                string str=words[i];
                char ch=str[0]; str[0]=str[1]; str[1]=ch;
                int freq=mp[str];
                temp+=min(mp[words[i]],freq);
                mp[words[i]]=mp[str]=0;
            }
        }
        int t1=0;
        sort(pals.begin(),pals.end());
        if(pals.size()<=2 && pals.size()>0){
            t1+=pals[pals.size()-1];
            if(pals.size()==2){
                if(pals[1]%2==0){
                    t1+=pals[0];
                }else{
                    if(pals[0]%2==1) t1+=pals[0]-1;
                    else t1+=pals[0];
                }
            }
        }
        else if(pals.size()>2){
            t1+=pals[pals.size()-1]; bool b=false;
            for(int i=0;i<pals.size()-1;i++){
                if(pals[i]%2==1){ t1+=pals[i]-1; b=true;}
                else t1+=pals[i];
            }
            if(pals[pals.size()-1]%2==0 && b) t1++;
        }
        //cout<<t1<<" "<<temp;
        return (t1*2+temp*4);
    }
};
