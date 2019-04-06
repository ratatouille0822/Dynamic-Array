#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DynamicArray.h"
#include "UserFunctions.h"


int main(void)
{
	pDynArrMan my_dynamic_array = NULL;
	DynArrInit(&my_dynamic_array,10);

	ArrayData p1 = { 1,"Zhang, Fei" };
	ArrayData p2 = { 2, "Liu, Bei" };
	ArrayData p3 = { 3,"Guan, Yu" };
	ArrayData p4 = { 4,"Xu, Shu" };
	ArrayData p5 = { 5, "Wei, Yan" };
	ArrayData p6 = { 6, "Huang, Zhng" };

	DynArrAddNode(my_dynamic_array, 0, &p1);
	DynArrAddNode(my_dynamic_array, 0, &p2);
	DynArrAddNode(my_dynamic_array, 3, &p3);
	DynArrAddNode(my_dynamic_array, 5, &p4);
	DynArrAddNode(my_dynamic_array, 1, &p5);
	DynArrAddNode(my_dynamic_array, 2, &p6);

	DynArrPrint(my_dynamic_array, PrintArryData);
	printf("--------------------------------------------1\n");

	DynArrDelPos(my_dynamic_array, 3);

	DynArrPrint(my_dynamic_array, PrintArryData);
	printf("--------------------------------------------2\n");

	DynArrDelPos(my_dynamic_array, 0);

	DynArrPrint(my_dynamic_array, PrintArryData);
	printf("--------------------------------------------3\n");
	DynArrDelByValue(my_dynamic_array, &p1, CompareArrayDaya);
	DynArrPrint(my_dynamic_array, PrintArryData);
	printf("--------------------------------------------4\n");
	DynArrDelByValue(my_dynamic_array, &p5, CompareArrayDaya);
	DynArrPrint(my_dynamic_array, PrintArryData);
	printf("--------------------------------------------5\n");
	DynArrInsertHead(my_dynamic_array, &p1);
	DynArrInsertTail(my_dynamic_array, &p2);
	DynArrPrint(my_dynamic_array, PrintArryData);

	DynArrFree(my_dynamic_array);
	printf("\n");
	system("pause");
	return 0;
}
