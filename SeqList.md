//SeqList.h

#pragma once

#include <assert.h>
#include <string.h>

#define MAX_SIZE 5
typedef int DataType;

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	size_t size;
}SeqList;

void InitSeqList(SeqList* pSeq);
void PushBack(SeqList* pSeq,DataType x);
void PopBack(SeqList* pSeq);
void PushFront(SeqList* pSeq,DataType x);
void PopFront(SeqList* pSeq);
void PrintSeqList(SeqList* pSeq);
void Insert(SeqList* pSeq, size_t pos, DataType x);
int Find(SeqList* pSeq, DataType x);
void Erase(SeqList* pSeq, size_t pos);
void Remove(SeqList* pSeq, DataType x);
void RemoveAll(SeqList* pSeq, DataType x);

void InitSeqList(SeqList* pSeq)
{
	assert(pSeq);
	memset(pSeq->array, 0, sizeof(DataType)*MAX_SIZE);
	pSeq->size = 0;
}

void PushBack(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		cout << "The SeqList is Full!" << endl;
		return;
	}
	pSeq->array[pSeq->size++] = x;
}

void PopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		cout << "The SeqList is Empty!" << endl;
		return;
	}
	pSeq->array[--pSeq->size] = 0;
}

void PushFront(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	DataType begin = pSeq->size - 1;
	if (pSeq->size >= MAX_SIZE)
	{
		cout << "The SeqList is Full!" << endl;
		return;
	}
	for (;begin >= 0;--begin)
	{
		pSeq->array[begin + 1] = pSeq->array[begin];
	}
	pSeq->array[0] = x;
	++pSeq->size;
}

void PopFront(SeqList* pSeq)
{
	assert(pSeq);
	DataType begin = 0;
	if (pSeq->size <= 0)
	{
		cout << "The SeqList is Empty!" << endl;
		return;
	}
	for (;begin <= pSeq->size;++begin)
	{
		pSeq->array[begin] = pSeq->array[begin + 1];
	}
	pSeq->array[pSeq->size] = 0;
	--pSeq->size;
}
void PrintSeqList(SeqList* pSeq)
{
	assert(pSeq);
	DataType i = 0;
	for (;i < pSeq->size;++i)
	{
		cout << pSeq->array[i]<<" ";
	}
	cout << endl;
}

void Insert(SeqList* pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	DataType begin = pSeq->size;
	if (pos >= pSeq->size)
	{
		cout << "The pos is wrong!" << endl;
		return;
	}
	if (pSeq->size >= MAX_SIZE)
	{
		cout << "The SeqList is Full!" << endl;
		return;
	}
	for (;begin >= pos;--begin)
	{
		pSeq->array[begin] = pSeq->array[begin - 1];
	}
	pSeq->array[pos - 1] = x;
	++pSeq->size;
}

int Find(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	for (;i < pSeq->size;++i)
	{
		if (pSeq->array[i] == x)
		{
			return i;
		}
	}
	return -1;    //表示没有找到x
}

void Erase(SeqList* pSeq, size_t pos)
{
	assert(pSeq);
	//DataType begin = pSeq->size -1;
	if (pos >= pSeq->size)
	{
		cout << "The pos is wrong!" << endl;
		return;
	}
	if (pSeq->size <= 0)
	{
		cout << "The SeqList is Empty!" << endl;
		return;
	}
	for (;pos < pSeq->size;++pos)
	{
		pSeq->array[pos] = pSeq->array[pos + 1];
	}
	--pSeq->size;
}

void Remove(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int pos = 0;
	pos = Find(pSeq, x);
	if (pos != -1)
	{
		Erase(pSeq, pos);
	}
}

void RemoveAll(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int pos = 0;
	pos = Find(pSeq, x);
	while (pos != -1)
	{
		Erase(pSeq, pos);
		pos = Find(pSeq, x);
	}
}


//Test.cpp

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include "SeqList.h"

void Test1()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);

	PrintSeqList(&seq);
}

void Test2()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushFront(&seq, 0);
	PushFront(&seq, -1);

	PrintSeqList(&seq);
	
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);

	PrintSeqList(&seq);
}

void Test3()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 4);
	PushBack(&seq, 5);

	Insert(&seq, 3, 3);
	PrintSeqList(&seq);
}

void Test4()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);

	int ret = Find(&seq, 2);
	cout << "pos:" << ret << endl;
	Erase(&seq, 3);
	PrintSeqList(&seq);
}

void Test5()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);

	Remove(&seq, 2);
	PrintSeqList(&seq);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	system("pause");
	return 0;
}
