/*
123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

*/


// 思路一   双向动态规划
// 可把数组分为两半，prices[0,i] prices[i,n-1],分别计算两半的最大值
// 如果两部分的交易都包括了i，说明只有一次交易，而且这次交易包含了第i天 ,因此不是prices[0,i] prices[i-1,n-1]
// 然后把这两值相加，遍历i从0到n-1找到最大的即为最后解
// 在该过程中使用动态规划降低时间复杂度
// 
// 和动态规划切钢材问题对比
// 
// 
int maxProfit(int* prices, int pricesSize) {
    int result=0;
    int min=INT_MAX;  //在limits.h文件里
    int left[pricesSize]; //从左向右
    int right[pricesSize]; //从右向左

    for (int i = 0; i < pricesSize; ++i)
    {
    	if(prices[i]<min) min=prices[i];
    	if(prices[i]-min>result) result=prices[i]-min;
    	left[i]=result;
    }

    // min=INT_MIN;
    // result=0;
    // 有问题 
    // 和从左到右思路不一样
    // for (int i = pricesSize-1; i >= 0; --i)
    // {
    // 	if(prices[i]<min) min=prices[i];
    // 	if(prices[i]-min>result) result=prices[i]-min;
    // 	right[i]=result;
    // }    
    int max=INT_MIN;
    result=0;
    for (int i = pricesSize-1; i >= 0; --i)
    {
    	if(prices[i]>max) max=prices[i];
    	if(max-prices[i]>result) result=max-prices[i];
    	right[i]=result;
    } 

    result=0;
    // 找到最大利润
    for (int i = 0; i < pricesSize; ++i)
    {
    	if(left[i]+right[i]>result) result=left[i]+right[i];
    }

    return result;
}