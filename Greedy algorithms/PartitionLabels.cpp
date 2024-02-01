class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitions;
        map<char, int> lastOcc;

        for(int i = 0 ; i < s.size(); i++){
            lastOcc[s[i]] = i;             //Store last occurance of char in string
        }

        for(int i=0; i < s.size(); i++){
            int counter = 0;
            int lastPosition = lastOcc[s[i]];

            //expand string untill lastOccurnace of any char in curr String
            for(int j=i; j < s.size() && j <= lastPosition; j++){  
                counter++;
                lastPosition = max(lastPosition, lastOcc[s[j]]);   //update last position untill we need to expand string
                i++;
            }
            i--;
            partitions.push_back(counter);  //push parition len to ans
        }

        return partitions;
        
    }
};
