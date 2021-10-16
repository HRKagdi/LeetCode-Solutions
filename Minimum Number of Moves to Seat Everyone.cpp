//https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
//2037. Minimum Number of Moves to Seat Everyone


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int l=seats.size();
        int ans=0;
        for(int i=0;i<l;i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }
};
