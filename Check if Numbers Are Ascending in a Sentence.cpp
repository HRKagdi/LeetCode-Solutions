//https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
// 5902. Check if Numbers Are Ascending in a Sentence


class Solution {
public:
    bool areNumbersAscending(string s) {
        int l=s.size(); 
        vector<int> v;
        for(int i=0;i<l;){
            if(0<=(int(s[i])-48) && (int(s[i])-48)<=9){
                int x=int(s[i])-48; i++;
                while(i<l && 0<=(int(s[i])-48) && (int(s[i])-48)<=9){
                    x=x*10+(int(s[i])-48);
                    i++;
                }
                v.push_back(x);
                
            }
            else i++;
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]) return false;
        }
        return true;
    }
};
