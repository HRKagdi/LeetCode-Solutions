//https://leetcode.com/problems/watering-plants/
//2079. Watering Plants

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0; int temp=capacity;
        for(int i=0;i<plants.size();i++){
            if(plants[i]<=capacity){
                capacity-=plants[i];
                ans++;
            }
            else{
                ans+=2*i+1;
                capacity=temp;
                capacity-=plants[i];
            }
            //cout<<ans<<" "<<capacity<<endl;
        }
        return ans;
    }
};
