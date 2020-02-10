class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> setChar;
		int max = 0;
		bool hash[256];
		memset(hash, false, 256);
		int left = 0,  right = 0;
		char c;
		s.push_back(*s.rbegin());
		for (left = 0; left < s.size(); ++left)
		{
			for (right = left; right < s.size(); ++right)
			{
				c = s[right];
				if (hash[c]){
					int count = right - left;
					if (max < count)
						max = count;
					int temp = left;
					if (s[right] == s[right - 1])
						left = right-1;
					while (right >= temp){
						c = s[right--];
						hash[c] = false;
					}
					
					break;
				}
				hash[c] = true;
			}
		}
		return max;
	}
};