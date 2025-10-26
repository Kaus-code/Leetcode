class Bank {
    vector<long long> temp;
    int n;
public:
    Bank(vector<long long>& balance) {
        temp=balance;
        n=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>0 && account2>0 && account1<=n && account2 <=n && temp[account1-1]>=money)
        {
            temp[account1-1]-=money;
            temp[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<0 || account>n)
        return  false;
       
        temp[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>=0 && account<=n && temp[account -1]>=money)
        {
            temp[account-1]-=money;
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