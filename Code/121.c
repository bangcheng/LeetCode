/*
https://segmentfault.com/a/1190000003483697
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
*/
// 把数据转化为股票票价相对于前一天变动
// 问题转化求最大子数组和
int maxProfit(int* prices, int pricesSize) {
    if( pricesSize==0) return 0;
    for (int i = pricesSize-1; i > 0; --i)
    	prices[i]-=prices[i-1];
    int sum=0;
    int result=0;
    for (int i = 1; i < pricesSize; ++i)
    {
    	sum+=prices[i];
    	if(sum<0)
    		sum=0;
    	if(sum>result) result=sum;
    }
    return result;
}

// 双指针法
// 动态查找最大利润
int maxProfit(int* prices, int pricesSize) {
    int result=0;
    int min=INT_MAX;
    for (int i = 0; i < pricesSize; ++i)
    {
        if(prices[i]<min)
            min=prices[i];
        if (result<prices[i]-min)
            result=prices[i]-min;  
    }
    return result;
}



// 联想
// 如果两数相减，大数在前，小数在后
// 记录最大值，然后相减，这样动态找到最大值