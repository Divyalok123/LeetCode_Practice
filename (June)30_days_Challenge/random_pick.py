from typing import List
import bisect
import random
class Solution:
    def __init__(self, w: List[int]):
        # self.arr.append(w[0])
        self.arr = [0]
        for i in w:
            self.arr.append(i + self.arr[-1])
        

    def pickIndex(self) -> int:
        ranm = random.randint(1, self.arr[-1])
        itr = bisect.bisect_right(self.arr, ranm)
        return itr-1
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()