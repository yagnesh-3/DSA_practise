class CustomStack {
public:
    stack<int>st;
    stack<int>st2;
    int count;
    int maxcount;
    CustomStack(int maxSize) {
        count = 0;
        maxcount = maxSize;
    }
    
    void push(int x) {
        if(count<maxcount){
            st.push(x);
            count++;
        }
    }
    
    int pop() {
        int ret;
        if(count>0){
           ret =  st.top();
           st.pop();
            count--;
        }else return -1;
        return ret;
    }
    
    void increment(int k, int val) {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        
        for(int i=0;i<k&& i<count;i++){
            int temp = st2.top();
            st2.pop();
            st.push(temp+val);
        }
       while(!st2.empty()){
            int temp = st2.top();
            st2.pop();
            st.push(temp);
       }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */