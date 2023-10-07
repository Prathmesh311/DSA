class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map;

        map  = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
                        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string roman = "";

        for(auto p: map){
            int multiples = num / p.first;

            while(multiples != 0){
                roman = roman + p.second;
                multiples--;
            }

            num = num % p.first;
        }
    
        return roman;
    }
};
