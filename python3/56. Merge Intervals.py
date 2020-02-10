class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        s = sorted(intervals, key = lambda x: x[0] )
        n = len(intervals)
        if(n == 0):
            return []
        out = []
        out.append(s[0])
        for i in s[1:n]:
            if(out[-1][1] >= i[0]):
                out[-1][1] = max(out[-1][1], i[1])
            else:
                out.append(i)
        return out