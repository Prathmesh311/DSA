class NumberContainers {
public:
    unordered_map<int, int> indexTONumber;
    unordered_map<int, set<int>> numberTOIndex;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexTONumber.find(index) == indexTONumber.end() || indexTONumber[index] == number){
            indexTONumber[index] = number;
            numberTOIndex[number].insert(index); 
            return;
        }

        int prevNumber = indexTONumber[index];
        indexTONumber[index] = number;
        numberTOIndex[number].insert(index); 
        numberTOIndex[prevNumber].erase(index); 
        if(numberTOIndex[prevNumber].size() == 0){
            numberTOIndex.erase(prevNumber);
        }
    }
    
    int find(int number) {
        if(numberTOIndex.find(number) == numberTOIndex.end()){
            return -1;
        }

        int smallest = *numberTOIndex[number].begin();
        return smallest;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
