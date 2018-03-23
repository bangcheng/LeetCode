/*
122. Best Time to Buy and Sell Stock II

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/
int maxProfit(int* prices, int pricesSize) {
    for (int i = pricesSize-1; i > 0; --i)
    	prices[i]-=prices[i-1];
    int result=0;
    for (int i = 1; i < pricesSize; ++i)
    	if(prices[i]>0) result+=prices[i];
    return result;
}