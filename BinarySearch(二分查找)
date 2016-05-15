#pragma once

#include <assert.h>

//左闭右闭式
int BinarySearch(int *Array, int x,size_t size)
{
	assert(Array);
	int left = 0;
	int right = size - 1;
	
	while (left <= right)
	{
		int mid = left + (right - left) / 2;  
		//没有写成mid = (left + right) / 2是为了防止整数溢出
		if (x < Array[mid])
		{
			right = mid - 1;
		}
		else if (x > Array[mid])
		{
			left = mid + 1;
		}
		else
		{
			return Array[mid];
		}
	}
	return -1;   //返回 -1 表示没有找到
}

//左闭右开式
int BinarySearch(int *Array, int x, size_t size)
{
	assert(Array);

	int left = 0;
	int right = size;

	while (left < right)
	{
		int mid = left + (right - left) / 2;   
		//没有写成mid = (left + right) / 2是为了防止整数溢出
		if (x < Array[mid])
		{
			right = mid;
		}
		else if (x > Array[mid])
		{
			left = mid + 1;
		}
		else
		{
			return Array[mid];
		}
	}
	return -1;   //返回 -1 表示没有找到
}

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
