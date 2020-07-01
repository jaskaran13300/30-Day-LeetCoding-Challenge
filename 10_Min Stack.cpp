// c++ approach using two stacks

class MinStack {
    stack<int>s;
    stack<int>min;
public:
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            min.push(x);
        }
        else{
            s.push(x);
            int y=min.top();
            if(x<=y){
                min.push(x);
            }
        }
    }
    
    void pop() {
        if(s.empty() || min.empty()){
            return;
        }
        int x=s.top();
        int y=min.top();
        s.pop();
        min.pop();
        if(x!=y){
            min.push(y);
        }
    }
    
    int top() {
        int a=s.top();
        return a;
    }
    
    int getMin() {
        int m=min.top();
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 
 
 // using one stack
 // python
 
import sys
class MinStack:
    st=[]
    minn=9999999
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minn=sys.maxsize
        

    def push(self, x: int) -> None:
        if x<=self.minn:
            self.st.append(self.minn)
            self.minn=x
        self.st.append(x)

    def pop(self) -> None:
        
        t=self.st.pop()
        # self.st.append(t)
        # self.st.pop()
        if self.minn==t:
            self.minn=self.st.pop()
            # self.st.pop()
        

    def top(self) -> int:
        t=self.st.pop()
        self.st.append(t)
        return t

    def getMin(self) -> int:
        return self.minn



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
