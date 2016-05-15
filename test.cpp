#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearch.h"

int main()
{
	int Num[] = { 1,3,4,6,8,9,23,65,68,89,234,678,890 };
	int ret = 0;
	int size = 0;
	ret = BinarySearch(Num,25,sizeof(Num)/sizeof(Num[0]));
	if (ret < 0)    //也就是返回 -1 ,表示没有找到
	{  
		printf("This value is inexistence!\n");
	}
	else    //找到的直接返回其数值
	{
		printf("ret = %d\n", ret);
	}
	system("pause");
	return 0;
}