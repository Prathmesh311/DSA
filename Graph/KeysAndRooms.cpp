class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> q;
        int visited[1001] = {false};
        
        //Setting source 0 as visited
        visited[0] = true;
        
        //Adding elements adjacent to source in queue
        for(int i: rooms[0]){
            q.push(i);
            visited[i] = true;
        }
        
        while(!q.empty()){
            
            int currRoom = q.front();
            q.pop();

            for(int i : rooms[currRoom]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        //Checking if all elements visited or not
        for(int i=0; i < rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        
        return true;
        
    }
};
