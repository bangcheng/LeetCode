/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/
// 思路：可以利用dp思想，假设第i-1，i-2步台阶不同的路径数目已经已知，那么第i阶的数目为num[i-1]+num[i-2]
// 
int climbStairs(int n) {
	if(n==0)
		return 1;
    int num[n+1];
    num[0]=1;
    num[1]=1;
    for(int i=2;i<=n;i++)
    	num[i]=num[i-2]+num[i-1];
    return num[n];
}