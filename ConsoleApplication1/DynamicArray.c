#include "DynamicArray.h"
#include <stdio.h>

int DynArrInit(void** dyn_arr_man, int length)
{
		
	pDynArrMan temp = (pDynArrMan)malloc(sizeof(DynArrMan));
	temp->dyn_array = (void** )malloc(length * sizeof(void*));
	if (NULL == temp->dyn_array)
	{
		perror("Error allocate mem!\n");
		return -1;
	}

	temp->capa = length;
	temp->size = 0;

	*dyn_arr_man = temp;
	return 0;
}

int DynArrAddNode(void* dyn_arr_man, int pos, void* data)
{
	if (dyn_arr_man == NULL || data == NULL)
	{
		perror("Something Wrong!\n");
		return -1;
	}
	
	pDynArrMan temp = (pDynArrMan)dyn_arr_man;

	if (temp->size == temp->capa)
	{
		temp->dyn_array = realloc(temp->dyn_array,sizeof(void*) * temp->size * 2);
		temp->capa *= 2;
	}
	if (pos >= temp->size && pos != 0)
	{
		pos = temp->size;
	}
	for (int i = temp->size-1;i>=pos;i--)
	{

		temp->dyn_array[i + 1] = temp->dyn_array[i];
	}
	temp->dyn_array[pos] = data;
	temp->size += 1;
	dyn_arr_man = temp;
	return 0;
}

int DynArrPrint(void* dyn_arr_man, int(*PrintFun)(void*))
{
	if (NULL == dyn_arr_man)
	{
		perror("NULL Failed !\n");
		return -1;
	}

	pDynArrMan temp = (pDynArrMan)dyn_arr_man;

	if (NULL == temp->dyn_array)
	{
		perror("Empty!\n");
		return -2;
	}

	for (int i = 0; i < temp->size; i++)
	{
		PrintFun(temp->dyn_array[i]);
	}

	return 0;
}

int DynArrDelPos(void* dyn_arr_man, int pos)
{
	pDynArrMan temp = (pDynArrMan)dyn_arr_man;
	if (dyn_arr_man == NULL || pos > temp->size - 1)
	{
		perror("Error !\n");
		return -1;
	}
	for (int i = pos ;i<temp->size -1;i++)
	{
		temp->dyn_array[i] = temp->dyn_array[i + 1];
	}

	temp->size -= 1;
	dyn_arr_man = temp;
	return 0;

}

int DynArrDelByValue(void* dyn_arr_man, void* data, int (*CompareFunc)(void* data1, void* data2))
{
	if (NULL == dyn_arr_man || NULL == data)
	{
		perror("Error !\n");
		return -1;
	}
	pDynArrMan temp = (pDynArrMan)dyn_arr_man;
	int flag = 0;
	for (int i = 0; i < temp->size; i++)
	{
		if (CompareFunc(data, temp->dyn_array[i]) == 0)
		{
			DynArrDelPos(temp, i);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("nothing match !\n");
		return -1;
	}
	dyn_arr_man = temp;
	return 0;
}

int DynArrInsertHead(void* dyn_arr_man, void* data)
{
	return DynArrAddNode(dyn_arr_man, 0, data);
}

int DynArrInsertTail(void* dyn_arr_man, void* data)
{
	pDynArrMan temp = dyn_arr_man;
	return DynArrAddNode(dyn_arr_man, temp->size, data);

}

int DynArrFree(void* dyn_arr_man)
{
	pDynArrMan temp = (pDynArrMan)dyn_arr_man;
	free(temp->dyn_array);
	free(temp);
	printf("Auf Wiedersehen!\n");
	return 0;
	
}




