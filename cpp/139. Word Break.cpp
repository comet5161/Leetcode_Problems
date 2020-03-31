class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        set<int> setLen;
        int len = s.length();
        vector<bool> vFlag(len, false);
        for(auto i: wordDict){
            m.insert(i);
            setLen.insert(i.length());
        }
        vector<int> vLen(setLen.begin(), setLen.end());
        for(int i = 0; i < len; i++){
            if(i == 0 || vFlag[i-1] )
                for(auto j : vLen){
                    if(i + j > len)
                        break;
                    if(m.find( s.substr(i, j) ) != m.end())
                        vFlag[i + j - 1] = i == 0 ? true : vFlag[i-1];
                }
        }
        return vFlag[len-1];
    }
};