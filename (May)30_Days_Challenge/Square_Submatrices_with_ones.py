# Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
matrix = [[1, 1, 1],[1, 1, 1],[1, 1, 1]]
class Solution:
    def countSquares(self, matrix) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dp = [[0 for x in range(305)] for y in range(305)]
        sumval = 0
        for i in range(n):
            dp[i][0] = matrix[i][0]
            sumval += dp[i][0]
            
        for i in range(1, m):
            dp[0][i] = matrix[0][i]
            sumval += dp[0][i]
        
        for i in range(1, n):
            for j in range(1, m):
                if(matrix[i][j] == 1):
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1
                    sumval += dp[i][j]
                else:
                    dp[i][j] = 0
        return sumval