#include <map>
typedef pair<int, int> Pair;
bool cmp (const Pair& lhs, const Pair& rhs) {
    return lhs.second < rhs.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        vector<int> vRes;
        for(auto i: nums){
            myMap[i] ++;
        }
        vector<Pair> v(myMap.begin(), myMap.end());
        make_heap(v.begin(), v.end(), cmp);
        for(int i = 0; i < k; i++){
            pop_heap(v.begin(), v.end(), cmp);
            vRes.push_back( (v.back()).first );
            v.pop_back();
        }
        return vRes;
    }
};