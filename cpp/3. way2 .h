
// 采用滑动窗口（双指针方式）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        vector<int> vPos(256, -1);
        int begin = 0, end;
        int max_len = 1;
        vPos[s[0]] = 0;
        for(end = 1; end < s.size(); end++){
            char c = s[end];
            if(vPos[c] < 0)
                max_len = max(max_len, end - begin + 1);
            else{
                int next_begin = vPos[c] + 1;
                for(int i = begin; i <= vPos[c]; i++)
                     vPos[s[i]] = -1;
                begin = next_begin;
            }
            vPos[c] = end;
        }
        return max_len;
    }
};