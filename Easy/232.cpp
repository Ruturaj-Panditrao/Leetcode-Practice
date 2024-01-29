// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans;
        if(s2.empty()==true)
        {
        while(!s1.empty())
        {
            int t = s1.top();
            s1.pop();
            s2.push(t);
        }
        ans = s2.top();
        s2.pop();
        }
        else
        {
            int po = s2.top();
            s2.pop();
            ans = po;
        }
        return ans;
    }
    
    int peek() {
        if(s2.size()==0)
        {
        while(!s1.empty())
        {
            int t = s1.top();
            s1.pop();
            s2.push(t);
        } 
        }
        return s2.top();
    }
    
    bool empty() {
       if(s1.empty()==true && s2.empty()==true) return true;
       else return false; 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
