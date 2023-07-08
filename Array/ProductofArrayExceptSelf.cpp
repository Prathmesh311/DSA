class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;

        int productprefix = 1;
        product.push_back(1);

        for(int i=1; i < nums.size(); i++){            //store the prefix product in product vector
            productprefix = nums[i-1] * productprefix;
            product.push_back(productprefix);
        }

        int productsuffix = 1;
        for(int i = nums.size()-1; i > 0; i--){        //counts suffix product and multiply it with prefix product to get ans for pos
            productsuffix = nums[i] * productsuffix;
            product[i-1] = product[i-1] * productsuffix;
        }

        return product;
    }
};
