class Solution:
    def merge(self, intervals):
        intervals.sort()
        
        merged = []
        
        for s, e in intervals:
            if not merged or merged[-1][1] < s:
                merged.append([s, e])
            else:
                merged[-1][1] = max(merged[-1][1], e)
        
        return merged