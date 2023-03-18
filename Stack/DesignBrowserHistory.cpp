class BrowserHistory {
public:
    stack<string> backStack;
    stack<string> forwardStack;
    string currSite = "";

    BrowserHistory(string homepage) {
        currSite = homepage;
    }
    
    void visit(string url) {
        backStack.push(currSite);
        currSite = url;
        while(!forwardStack.empty()){
            forwardStack.pop();
        }
    }
    
    string back(int steps) {
        string currURL = "";
        while(steps > 0 && !backStack.empty()){
            currURL = backStack.top();
            forwardStack.push(currSite);
            currSite = currURL;
            backStack.pop();
            steps--;
        }
        
        if(currURL == ""){
            return currSite;
        }
        return currURL;
    }
    
    string forward(int steps) {
        string currURL = "";
        while(steps > 0 && !forwardStack.empty()){
            currURL = forwardStack.top();
            backStack.push(currSite);
            currSite = currURL;
            forwardStack.pop();
            steps--;
        }

        if(currURL == ""){
            return currSite;
        }
        return currURL;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
