class Solution:
    def countGroups(self, position: list[int], speed: list[int], distance: int) -> int:
        n = len(position)
        split = 0 
        for i in range(n-1, 0, -1):
            if speed[i] >= speed[i-1] and position[i] - position[i-1] > distance:
                split += 1
            else:
                speed[i-1] = speed[i] 

        return split + 1