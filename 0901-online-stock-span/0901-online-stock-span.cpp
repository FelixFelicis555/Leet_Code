class StockSpanner {
public:
    stack<vector<int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int index=0;
        int ans;
        if(!s.empty())
            index=s.top()[1]+1;
        while(!s.empty() && s.top()[0]<=price)
        {
            s.pop();
        }
        if(s.empty())
            ans=index+1;
        else
            ans=index-s.top()[1];
        s.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */