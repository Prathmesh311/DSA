queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()){          //First add to stack
        int front = q.front();
        q.pop();
        s.push(front);
    }
    
    while(!s.empty()){          //pop from stack and push to queue
        int num = s.top();
        s.pop();
        q.push(num);
    }
    
    return q;
}
