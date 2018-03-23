/*
322. Coin Change
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/



// 能AC 超时
// [429,171,485,26,381,31,290]
// 8440
int coinChange(int* coins, int coinsSize, int amount) {
	if(amount==0)
		return 0;
    int count[amount+1];    //dp数组
    for(int i=0 ;i<amount+1;i++)
    	count[i]=-1;

    // 初始化，剔除无用硬币数字
    for(int i=0; i<coinsSize ;i++)
		if (coins[i]<=amount)
		{
			count[coins[i]]=1;
		}


    for (int i = 1; i <= amount; ++i)
    {
    	for (int j = 1; j <= i/2; ++j)
    		if (count[j]!=-1&&count[i-j]!=-1)
    		{
    			if(count[i]==-1)
    				count[i]=count[j]+count[i-j];
    			else if(count[i]>count[j]+count[i-j])
    				count[i]=count[j]+count[i-j];
    		}
    }
    return count[amount];
}



//   AC
// 优化为o(amount*coinsSize)
int coinChange(int* coins, int coinsSize, int amount) {
	if(amount==0)
		return 0;
    int count[amount+1];
    for(int i=0 ;i<amount+1;i++)
    	count[i]=-1;
    for(int i=0; i<coinsSize ;i++)
		if (coins[i]<=amount)
		{
			count[coins[i]]=1;
		}

    
    for (int i = 1; i <= amount; ++i)
    {
    	for (int j = 0; j < coinsSize; ++j)
	    	if (count[i-coins[j]]!=-1)
	    	{
    			if(count[i]==-1)
    				count[i]=count[coins[j]]+count[i-coins[j]];
    			else if(count[i]>count[coins[j]]+count[i-coins[j]])
    				count[i]=count[coins[j]]+count[i-coins[j]];
	    	}
    		
    }
    return count[amount];
}