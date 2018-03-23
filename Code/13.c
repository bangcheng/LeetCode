/*
基本字符：

　　I、V、X、L、C、D、M

　　相应的阿拉伯数字表示为：

　　1、5、10、50、100、500、1000

　　(1)相同的数字连写，所表示的数等于这些数字相加得到的数，如： Ⅲ = 3；

　　(2)小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；

　　(3)小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；

　　(4)正常使用时连写的数字重复不得超过三次。（表盘上的四点钟--“IIII”，例外。）

　　(5)在一个数的上面画一条横线，表示这个数增值1000 倍，例如有：Ⅻ=12,000 。

编辑本段组数规则

　　有几条须注意掌握；

　　(1)基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。

　　(2)不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。

　　(3)V 和X 左边的小数字只能用Ⅰ。

　　(4)L 和C 左边的小数字只能用X。

　　(5)D 和M 左边的小数字只能用C 。

　　(6)在数字上加一横表示这个数字的1000倍
*/

int romanToInt(char* s) {
    int length=strlen(s);
    int num[length];
    int temp=0;
    for (int i = 0; i < length; ++i)
    {
    	switch(s[i])
    	{
    		case 'I':num[i]=1; break;   //需添加break
    		case 'V':num[i]=5; break;
    		case 'X':num[i]=10; break;
    		case 'L':num[i]=50; break;
    		case 'C':num[i]=100; break;
    		case 'D':num[i]=500; break;
    		case 'M':num[i]=1000; break;
    		default : break;
    	}
    }
    for (int i = 1; i < length; ++i)
    {
    	if (num[i]>num[i-1])
    	{
    		temp=temp +num[i]-num[i-1]*2;
    	}
    	else
    		temp+=num[i];
    }
    return temp;
}


// 最优
int letter_to_value(char letter)
{
        switch (letter) {
                case 'I':
                        return 1;
                case 'V':
                        return 5;
                case 'X':
                        return 10;
                case 'L':
                        return 50;
                case 'C':
                        return 100;
                case 'D':
                        return 500;
                case 'M':
                        return 1000;
                default:
                        return 0;
        }
}
/*
 * I'm assuming s ends with '\0'.
 */
int romanToInt(char *s)
{
        int n = 0;
        int value;

        for (int i = 0; s[i] != '\0'; i++) {

                value = letter_to_value(s[i]);

                switch (s[i]) {
                        /* 
                         * (from Wikipedia) these are the only letters that can
                         * be "subtracted" if they come first of a "bigger" one.
                         */
                        case 'I':
                        case 'X':
                        case 'C':
                                if (letter_to_value(s[i + 1]) > value) {
                                        n -= value;
                                        break;
                                }
                        default:
                                n += value;
                }
        }
        return n;
}