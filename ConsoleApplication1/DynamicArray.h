#pragma once


typedef struct DynamicArrayManager
{
	void** dyn_array;
	int size;
	int capa;
}DynArrMan, *pDynArrMan;

int DynArrInit(void** dyn_arr_man, int length);
int DynArrAddNode(void* dyn_arr_man, int pos, void* data);
int DynArrPrint(void* dyn_arr_man, int(*PrintFun)(void*));
int DynArrDelPos(void* dyn_arr_man, int pos);
int DynArrFree(void* dyn_arr_man); 
int DynArrDelByValue(void* dyn_arr_man, void* data, int(*CompareFunc)(void* data1, void* data2));
int DynArrInsertHead(void* dyn_arr_man, void* data);
int DynArrInsertTail(void* dyn_arr_man, void* data);