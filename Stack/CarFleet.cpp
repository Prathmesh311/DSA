class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        for(int i=0; i < position.size(); i++){
            car.push_back({position[i], speed[i]}); 
        }

        //sort cars according to position in decrasing order
        sort(car.begin(), car.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first > b.first;
        });
      
        int fleets = 0;
        double diff = 0;

        for(int i=0; i < car.size(); i++){
            double currDiff = double(target - car[i].first) / car[i].second;
            
            //If time taken by car to reach target is grater than current fleet. create new fleet
            if(currDiff > diff){
                diff = currDiff;
                fleets++;
            }
        }

        return fleets;
    }
};
