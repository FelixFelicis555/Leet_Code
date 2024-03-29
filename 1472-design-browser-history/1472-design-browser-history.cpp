class BrowserHistory {
public:
    BrowserHistory(string homepage) {
      visit(homepage);  
    }
    
    void visit(string url) {
        if(++index<urls.size())
            urls[index]=url;
        else
            urls.push_back(url);
        lastIndex=index;
    }
    
    string back(int steps) {
       index=max(0,index-steps);
        return urls[index];
    }
    
    string forward(int steps) {
        index=min(lastIndex,index+steps);
        return urls[index];
    }
    private:
    int index=-1;
    vector<string>urls;
    int lastIndex=-1;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */