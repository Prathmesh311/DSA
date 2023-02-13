class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> map;

        for(int i=0; i < s.size(); i++){        //storing no. of occurances of chars in hashmap
            if(map.find(s[i]) == map.end()){
                map.insert(make_pair(s[i], 1));
            }
            else{
                map[s[i]] = map[s[i]]+1;
            }
            
        }

        int longestPali = 0;
        int maxOdd = 0;
        bool odd = false;

        for(auto pair : map){
            if(pair.second % 2 == 0){
                longestPali = longestPali + pair.second;  //add all even occurances
            }
            else{
                longestPali += pair.second - 1;           // add all posible no. of char from odd occurance
                odd = true;
            }
        }

        if(odd){
            longestPali++;        //add 1  for largest odd number 
        }

        return longestPali;
    }
};
