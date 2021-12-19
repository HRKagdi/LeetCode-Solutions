//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
//2108. Find First Palindromic String in the Array

class Solution {
public:
    bool isPalindrome(string str){
        string rev=str;
        reverse(str.begin(),str.end());
        return (str==rev);
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};
