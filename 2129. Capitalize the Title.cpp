//https://leetcode.com/problems/capitalize-the-title/
//2129. Capitalize the Title

class Solution {
public:
    string capitalizeTitle(string title) {
        string temp=""; vector<string> v;
        for(int i=0;i<title.size();i++){
            if(title[i]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp+=title[i];
            }
        }
        v.push_back(temp);
        string ans="";
        for(int i=0;i<v.size();i++){
            string str=v[i];
            if(v[i].size()<=2){
                    transform(str.begin(), str.end(), str.begin(),::tolower);
            }
            else{
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    str[0]=toupper(str[0]);
            }
            ans+=str+" ";
        }
        string fans=ans.substr(0,ans.size()-1);
        return fans;
    }
};
