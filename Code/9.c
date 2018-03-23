// 不用考虑溢出情况
bool isPalindrome(int x) {
	if(x<0)
		return false;
	int k=x; 
	int temp=0;
	// int tar=0;
	while(k!=0)
	{
		// int i;
		// i=k%10;
		temp=temp*10+k%10;
		// if ((temp-i)/10!=tar)
		// {
		// 	return false;
		// }
		// tar=temp;w
		k=k/10;
	}
	if (temp==x)
		return true;
	return
		false;
}


//已知最优，只反转一半数字
bool isPalindrome(int x) {
    int i = 0, j;
    int y = 0;
    int tmp, tmp2;
    
    if(x < 0)
        return false;
    
    for(tmp = x; tmp != 0; tmp /= 10, i++);  //获取数字的位数
    
    tmp = (i % 2) == 1;
    tmp2 = i / 2 + 1;
    j = i;
    while(j > (i/2))
    {
        if(tmp && j == tmp2)
        {
            x /= 10;
            break;
        }
        
        y = y * 10 + x % 10;
        x /= 10;
        j--;
        
    }
    return x == y;
}