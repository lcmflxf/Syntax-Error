/***线性表通用表头***/
//#ifndef __CHEAD_H
//#define __CHEAD_H
#include<stdio.h>//标准输入输出头文件
#include<math.h>//数学函数头文件
#include<malloc.h>
#include<memory.h>
#include<io.h>
#include<ctype.h>//字符函数头文件
#include<string.h>//字符串函数头文件
#include<limits.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include<stdarg.h>

/***函数结果状态查询代码***/
#define DONE 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

/***ElemType类型定义***/
#define ElemInt

typedef int Status;
typedef int Boolean;

#ifdef ElemInt
typedef int ElemType
#endif

#ifdef ElemDbl
typedef double ElemType
#endif
//#endif