int reverse(int x) {
    int target=0;
    int k[10];
    int i=-1;
    while(x!=0)
    {
    	i++;
    	target=target*10+x%10;  //核心
    	k[i]=x%10;
    	x=x/10;
    }
    if (x<0)
	    target=-1*target;
	int num=target;
	//判断是否和X反序一致，
	for (; num!=0; --i)
	{
		if (num%10!=k[i])
		{
			return 0;
		}
		num=num/10;
	}
    return target;
}


/////
int reverse(int x) {
    int res = 0;
    
    while (x != 0) {
        int digit = x % 10;
        int temp = res * 10 + digit;
        
        //****************************
        if ((temp - digit) / 10 != res)
            return 0;
        res = temp;
        x /= 10;
    }
    
    return res;
}