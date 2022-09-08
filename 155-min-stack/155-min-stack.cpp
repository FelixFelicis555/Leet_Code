class MinStack {
public:
    long long int min_val=INT_MAX;
    stack<long long int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(0);
            min_val=val;
        } 
        else
        {
            st.push((long long int)val-min_val);
            if(val<min_val)
             min_val=val;   
            
        }
    }
    
    void pop() {
        long long int k=st.top();
        if(k<0)
        {
            min_val=min_val-k;
        }  
        st.pop();
    }
    
    int top() {
       long long int k=st.top();
        if(k<0){
            return min_val;
        }
        else{
            return min_val+k;
        } 
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */