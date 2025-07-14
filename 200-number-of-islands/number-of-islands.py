class Solution:
    def dfs(self,p :int, q:int,grid: List[List[str]] ):
        grid[p][q] = "0"
        rows = [ 1,-1,0,0]
        cols = [ 0,0,1,-1]
        for i in range(4):
            nr = p + rows[i]
            nc = q + cols[i]
            if nr >= 0 and nc >=0 and nr < len(grid) and nc<len(grid[0]) and grid[nr][nc]=="1":
                self.dfs(nr,nc,grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        cnt = 0 
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    self.dfs(i,j,grid)
                    cnt +=1 
                    
        return cnt

