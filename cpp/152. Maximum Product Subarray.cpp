class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1, right = 1, res = INT_MIN;
        int len = nums.size();
        for(int i = 0, j = len-1; i < len; i++, j--){
            left *= nums[i];
            right *= nums[j];
            res = max(res, max(left, right));
            if(left == 0)
                left = 1;
            if(right == 0)
                right = 1;
        }
        return res;
    }
};