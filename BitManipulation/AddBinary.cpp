class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i=0; i < max(a.size(), b.size()); i++){
            int digitA = i < a.size() ? a[i] - '0' : 0;
            int digitB = i < b.size() ? b[i] - '0' : 0;

            int sum = digitA + digitB + carry;
            string ch = to_string(sum % 2);
            ans = ch + ans;

            carry = sum / 2;
        }

        if(carry == 1){
            ans = '1' + ans;
        }

        return ans;
    }
};
