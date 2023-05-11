class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int num = 0;
        int n = digits.size();
        
        int carry = 1;
        for(int i= n-1; i >= 0; i--){
            if(digits[i] == 9 && carry == 1){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }

        if(carry == 1){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
