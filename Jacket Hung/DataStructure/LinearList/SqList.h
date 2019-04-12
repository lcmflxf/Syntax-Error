/***顺序线性表***/
//#ifndef __SQLIST_H
//#define __SQLIST_H
#include "chead.h"
#define SQLIST_INIT_SIZE 10 //线性表储存空间大小的初始分配量
#define SQLIST_INCREMENT 2  //线性表存储空间大小的分配增量

struct SqList
{
    ElemType * elem;//数据存储空间
    int length;//数据长度
    int listsize;//表长
};

int    SqListLength(SqList SqL);//获取顺序线性表数据长度
int    LocateSqList(SqList SqL, ElemType num, Status(* compare(ElemType, ElemType)));
void   InitSqList(SqList &SqL);//创建顺序线性表
void   DeleteSqList(SqList &SqL);//删除顺序线性表
void   ClearSqList(SqList &SqL);//清空顺序线性表
void   SqListPreTraverse(SqList SqL, void (*visit(ElemType&)));//正序遍历
void   SqListBacTraverse(SqList SqL, void (*visit(ElemType&)));//反序遍历
Status SqListEmpty(SqList SqL);//判断顺序线性表是否为空
Status InsertSqList(SqList &SqL, int index, ElemType num);//在顺序线性表中第index位前插入num
Status GetSqElem(SqList SqL, int index, ElemType &num);//获取顺序线性表第index位的数据,并赋给num
Status RemoveSqList(SqList &SqL, int index, ElemType &num);//删除顺序线性表第index位的数据，并把该数据赋给num
Status PriorSqElem(SqList SqL, ElemType cur_num, ElemType &pre_num);//查询顺序线性表第一个值为cur_num的前一位数据
Status NextSqElem(SqList SqL, ElemType cur_num, ElemType &next_num);//查询顺序线性表第一个值为cur_num的后一位数据
//#endif
