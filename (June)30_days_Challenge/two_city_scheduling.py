# There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
# Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
from typing import List
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key = lambda x: x[0] - x[1])
        return sum(x[0] for x in costs[:len(costs)//2]) + sum(x[1] for x in costs[len(costs)//2:])