#pragma once

typedef struct ArrayData
{
	int id;
	char name[50];
} ArrayData, *pArrayData;

int PrintArryData(void* ArrayData);
int CompareArrayDaya(void* data1, void* data2);
