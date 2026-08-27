class MinStack
{
public:
    MinStack() = default;
    
    void push(int val)
    {
        values_.push(val);
        mins_.push(mins_.empty() ? val : std::min(val, mins_.top()));
    }
    
    void pop()
    {
        values_.pop();
        mins_.pop();
    }
    
    int top()
    {
        return values_.top();        
    }
    
    int getMin()
    {
        return mins_.top();
    }

private:
    std::stack<int> mins_;
    std::stack<int> values_;
};
