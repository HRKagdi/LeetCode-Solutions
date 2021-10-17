//https://leetcode.com/problems/simple-bank-system/
// 5903. Simple Bank System

class Bank {
public:
    vector<long long> arr;
    Bank(vector<long long>& balance) {
        arr.push_back(0);
         for(int i=0;i<balance.size();i++){
             arr.push_back(balance[i]);
         }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1==0 || account2==0) return false;
        if(account1>=arr.size() || account2>=arr.size()) return false;
        if(arr[account1]>=money) {
            arr[account1]-=money; arr[account2]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account==0) return false;
        if(account>=arr.size()) return false;
        arr[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account==0) return false;
        if(account>=arr.size()) return false;
        if(arr[account]>=money) {
            arr[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
