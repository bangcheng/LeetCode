/*
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/



// 动态规划
// 问题简化为当机器人位于数组的第i行、j列时，这时的总情况为arr[i][j+1]+arr[i+1][j]的和
// arr[i][j]数组为第i行，j列的可能情况
// 以下为自底向上的动态规划算法
int uniquePaths(int m, int n) {
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
// 可优化，只用一个一维数组
// Java
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> temp(m + 1, 0);
        temp[m-1] = 1;
        for (int j = n - 1; j >= 0; j--) {
            for (int i = m - 1; i >= 0; i--) {
                if (obstacleGrid[i][j]) temp[i] = 0;
                else temp[i] += temp[i+1];
            }
        }
        return temp[0];
    }
};




// 自顶向下
// 未实现




// 公式法
// 运用概率论的知识解决问题
// 核心：一共需要走m-1+n-1这么多步，在m+n-2步中选择m-1步向下，其他向右
// 总的路径数量为：C(m+n-2,m-1)
// 过大会发生溢出
// 有问题    ------个别情况会出现差一个的情况  出现误差
int uniquePaths(int m, int n) {
	if(m==0||n==0)
		return 0;
	double res=1;
	for (int i = 1; i <=n-1 ; ++i)
	{
		res*=(double)(m+i-1)/(double)i;
	}
	return (int)res;
}


// 自底向上的动态优化方法的优化
// 第m行或第n列的值都为1
int uniquePaths(int m, int n) {
    int path[100][100];
    for(int i = 0; i < m ; i++){
        path[i][0] = 1;
    }
    for(int j = 0; j < n ; j++){
        path[0][j] = 1;
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            path[i][j] = path[i][j-1] + path[i-1][j];
        }
    }
    return path[m-1][n-1];
}