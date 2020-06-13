# Design a data structure that supports all following operations in average O(1) time.
# insert(val): Inserts an item val to the set if not already present.
# remove(val): Removes an item val from the set if present.
# getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

import random

class RandomizedSet:

    def __init__(self):
        self.d = {}
        self.v = []
        

    def insert(self, val: int) -> bool:
        if val in self.d:
            return False
        else:
            self.v.append(val)
            self.d[val] = len(self.v)-1
            return True
        

    def remove(self, val: int) -> bool:
        if val in self.d:
            temp = self.v[len(self.v)-1]
            self.d[temp] = self.d[val]
            self.v[self.d[temp]] = temp
            self.v.pop()
            del self.d[val]
            return True
        else:
            return False
        

    def getRandom(self) -> int:
        return self.v[random.randint(0, len(self.v)-1)]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()