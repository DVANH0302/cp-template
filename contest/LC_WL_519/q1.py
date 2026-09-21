class Solution:
    def cyclicShift(self, n: int, grid: list[list[int]], rowShift: list[int], colShift: list[int]) -> list[list[int]]:
        def display(res):
            for i in range(n):
                for j in range(n):
                    print(res[i][j], end = " ")
                print()
            print('#')        
        
        rowRes = [[0] * n for _ in range(n)]

        for i in range(n):
            for j in range(n):
                k = rowShift[i]
                nj = (j - k + n) % n 
                rowRes[i][nj] = grid[i][j]
        
        colRes = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(n):
                k = colShift[j]
                ni = (i - k + n) % n 
                colRes[ni][j] = rowRes[i][j]
        return colRes

n = 2; grid = [[1,2],[3,4]]; rowShift = [1,0]; colShift = [0,1]
print(Solution().cyclicShift(n, grid, rowShift, colShift))