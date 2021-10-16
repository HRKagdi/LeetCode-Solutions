// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
//  2038. Remove Colored Pieces if Both Neighbors are the Same Color

class Solution {
public:

    bool winnerOfGame(string colors) {
        int l=colors.size();
        vector<pair<int,int>> va,vb;
        for(int i=0;i<l;){
            if(colors[i]=='A'){
                int x=0; int index=i;
                while(i<l && colors[i]=='A'){i++; x++;}
                va.push_back(make_pair(index,x));
                
            }
            else{
                int x=0; int index=i; 
                while(i<l && colors[i]=='B'){i++; x++;}
                vb.push_back(make_pair(index,x));
            }
        }
        bool b=true;
        int x,y; x=y=0; 
        if(va.size()==0 && colors.size()>=3) return false;
        if(vb.size()==0 && colors.size()>=3) return true;

        while(x<va.size() && y<vb.size()){
            if(b){
                if(va[x].second>=3){
                    b=false; va[x].second--; 
                }
                else{
                    x++;
                }
            }
            else{
                if(vb[y].second>=3){
                    b=true; vb[y].second--;
                }
                else{
                    y++;
                }
            }
            if(x>=va.size() && b){ return false;}
            if(y>=vb.size() && !b){ return true;}
        }
        return !b;
    }
};
