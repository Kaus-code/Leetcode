class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int i =0;
    StockSpanner() {

    }
    int next(int price) {
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int res  = st.empty() ? -1:st.top().second;
        st.push({price,i});
        i+=1;
        return (i-res-1);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */