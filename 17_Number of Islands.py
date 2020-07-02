class Solution:
    def makeZero(self,i,j,grid,row,col):
        if i<0 or j<0 or i>=row or j>=col or grid[i][j]=='0':
            return
        grid[i][j]='0'
        self.makeZero(i+1,j,grid,row,col)
        self.makeZero(i,j+1,grid,row,col)
        self.makeZero(i,j-1,grid,row,col)
        self.makeZero(i-1,j,grid,row,col)
    def numIslands(self, grid: List[List[str]]) -> int:
        row=len(grid)
        if row==0:
            return 0
        col=len(grid[0])
        ans=0
        for i in range(row):
            for j in range(col):
                if grid[i][j]=='1':
                    ans=ans+1
                    self.makeZero(i,j,grid,row,col)
        return ans
