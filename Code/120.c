/*
Given a triangle, find the minimum path sum from top to bottom.
 Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
\*/
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
	if(triangleRowSize==0)
		return 0;
    int n=triangleRowSize;
    //int n=triangleColSizes[m-1];  
    //最大列数    不需要，最大列数等于行数
    int arr[n];
    for(int i=0;i<n;i++)
    	arr[i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
    	for(int j = 0;j<=i;j++)
    	{
    		if(arr[j]>arr[j+1])
    			arr[j]=triangle[i][j]+arr[j+1];
    		else
    			arr[j]=triangle[i][j]+arr[j];
    	}
    }
    return arr[0];
}