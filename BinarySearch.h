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