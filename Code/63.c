/*
63. Unique Paths II
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int m= obstacleGridRowSize;
    int n= obstacleGridColSize;
    if(m==0||n==0)
		return 0;
	int arr[m][n];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j]=0;
	// i、j为实际坐标减一
    for (int i = m-1; i >= 0; --i)       //行
    {
    	for (int j = n-1; j >= 0; --j)  //列
    	{
            //if(*((int *)obstacleGrid+n*i+j)==1)
             if(obstacleGrid[i][j]==1)
            {
                arr[i][j]=0;
                continue;
            }
            if(i==m-1&&j==n-1)
    			arr[i][j]=1;
    		if(i+1<m)
    			arr[i][j]+=arr[i+1][j];
    		if(j+1<n)
    			arr[i][j]+=arr[i][j+1];
    	}
    }
    return arr[0][0];
}
