class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int res = 0;
        if(len <= 3)
            return *max_element(nums.begin(), nums.end());
        vector<int> vDP(len, 0);
        vector<int> vDP2(len, 0);
        //从第1个开始
        vDP[0] = nums[0];
        vDP[1] = nums[1];
        vDP[2] = nums[0] + nums[2];
        for(int i = 3; i < len - 1; i++){
            vDP[i] = nums[i] + max(vDP[i-2], vDP[i-3]);
        }
        res = max(vDP[len-2], vDP[len-3]);
        //从最后1个开始
        reverse(nums.begin(), nums.end());
        vDP[0] = nums[0];
        vDP[1] = nums[1];
        vDP[2] = nums[0] + nums[2];
        for(int i = 3; i < len - 1; i++){
            vDP[i] = nums[i] + max(vDP[i-2], vDP[i-3]);
        }                                                                                                                                                                                       
        res = max(res, max(vDP[len-2], vDP[len-3]) );
        return res;
    }
};