class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int size = nums.size();
        int maxElement;
        vector<int> appearances;
        unordered_map<int, int> map;
        
        for(int i=0; i < size; i++){          //count occurances
            map[nums[i]] += 1;
        }
        
        int maxOccurances = 0;
        for(auto p : map){                    //find number with max occurances
            int num = p.first;
            int occurances = p.second;
            
            if(occurances > maxOccurances){
                maxOccurances = occurances;
                maxElement = num;
            }
        }
        
        
        int occurances = 0;
        for(int i=0; i < size; i++){          //keep track of that number occurances till index i
            if(nums[i] == maxElement){
                occurances++;
                appearances.push_back(occurances);
            }else{
                appearances.push_back(occurances);
            }
        }
        
        
        for(int i=0; i < appearances.size(); i++){         //check if splited array is valid   
            int firstLen = i+1;
            int firstAmount = appearances[i] * 2;
            
            int secondLen = size - (i+1);
            int secondAmount = (maxOccurances - appearances[i]) * 2;
            
            if(firstAmount > firstLen && secondAmount > secondLen){
                return i;
            }
            
            if(maxOccurances <= appearances[i]){
                break;
            }
        }
      
        return -1;  
    }
};
