#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack<int> s;
        
        for(int i=0;i <n; i++){    //push all lements to stack
            s.push(i);
        }
        
        while(s.size() != 1){
            int num1 = s.top();   //everytime pop 2 elements from stack
            s.pop();
            int num2 = s.top();
            s.pop();
            
            if(M[num1][num2] == 1){      //compare both elements and push non-celebrity element back to stack
                s.push(num2);
            }
            else{
                s.push(num1);
            }
        }
        
        int celebrity = s.top();       //potential celebrity
        
        for(int i=0;i < n; i++){       //check if element is celebrity or not
            if(i == celebrity){
                continue;
            
            }
            if(M[i][celebrity] != 1){  
                return -1;
            }
            if(M[celebrity][i] != 0){
                return -1;
            }
        }
        
        return celebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
