#include "UserFunctions.h"
#include <stdio.h>

int PrintArryData(void* ArrayData)
{
	pArrayData p = (pArrayData)ArrayData;
	printf("ID = %d, Name is %s \n", p->id, p->name);

	return 0;
}

int CompareArrayDaya(void* data1, void* data2)
{
	if (NULL == data1 || NULL == data2)
	{
		perror("Data Error !\n");
		return -1;
	}
	pArrayData p1 = (pArrayData)data1;
	pArrayData p2 = (pArrayData)data2;

	if (strcmp(p1->name, p2->name) == 0)
	{
		return 0;
	}

	return -2;
}
