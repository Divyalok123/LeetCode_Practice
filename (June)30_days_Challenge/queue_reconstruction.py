'''
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.
'''

class Solution(object):
    def reconstructQueue(self, people):
        people.sort(key = lambda h, k: (-h, k))
        print(people)
        queue = []
        for p in people:
            queue.insert(p[1], p)
            print(queue)
        return queue
        