/***顺序线性表***/
#include "SqList.h"

/***顺序线性表函数定义***/

/**获取顺序线性表数据长度**/
int    SqListLength(SqList SqL){
	return SqL.length;
}

int    LocateSqList(SqList SqL, ElemType num, Status(* compare(ElemType, ElemType))){
    int index = 1;
    ElemType *point = SqL.elem;

    while(index <= SqL.length && !compare(*point++, num))
        index++;
    if(index <= SqL.length)
        return index;
    else
        return 0;

}   

/***创建顺序线性表***/
void   InitSqList(SqList &SqL){
	SqL.elem = (*ElemType)malloc(SQLIST_INIT_SIZE * sideof(ElemType));
	if(!SqL.elem)
		exit(OVERFLOW);
	SqL.length   = 0;
	SqL.listsize = 0;
}

/***删除顺序线性表***/
void   DeleteSqList(SqList &SqL){
	free(SqL.elem);
	SqL.elem = NULL;
	SqL.length   = 0;
	SqL.listsize = 0;
}

/***清空顺序线性表***/
void   ClearSqList(SqList &SqL){
	SqL.length = 0;
}

void   SqListPreTraverse(SqList SqL, void (*visit(ElemType&))){
    ElemType *point = SqL.elem;
    for(int index = 0; index < SqL.length; i++)
        visit(*point++);
    printf("\n");
}

void   SqListPreTraverse(SqList SqL, void (*visit(ElemType&))){
    ElemType *point = SqL.elem + SqL.length - 1;
    for(int index = 0; index < SqL.length; i++)
        visit(*point--);
    printf("\n");
}

/***判断顺序线性表是否为空***/
Status SqListEmpty(SqList SqL){
	return SqL.length? TRUE: FALSE;
}

/***在顺序线性表中第index位前插入num***/
Status InsertSqList(SqList &SqL, int index, ElemType num){
    ElemType *point, *newbase, *insert; 
    if(index < 1 || index > SqL.length + 1)
        return ERROR;
    if(SqL.length == SqL.listsize){//若当前储存空间已满，则增加分配
        newbase = (*ElemType)realloc(SqL.elem, (SqL.listsize + SQLIST_INCREMENT) * sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        SqL.elem = newbase;
        SqL.listsize += SQLIST_INCREMENT;
    }

    insert = SqL.elem + index - 1;
    for(point = SqL.elem + SqL.length - 1; point >= insert; --point)//将插入空间之后的数据统统往后移一格
        *(point + 1) = *point;
    *insert = num;
    SqL.length++;

    return DONE;
}

/***获取顺序线性表第index位的数据,并赋给num***/
Status GetSqElem(SqList SqL, int index, ElemType &num){
    if(index < 1 || index > SqL.length)
        return ERROR;

    num = *(SqL.elem + index - 1);

    return DONE;
}

/***删除顺序线性表第index位的数据，并把该数据赋给num***/
Status RemoveSqList(SqList &SqL, int index, ElemType &num){
    if(index < 1 || index > SqL.length)
        return ERROR;

    ElemType *point, *sqdelete;
    point = SqL.elem + SqL.length - 1;
    sqdelete = SqL.elem + index - 1;
    num = *sqdelete;

    for(sqdelete++; sqdelete <= point; sqdelete++)//第一次进入循环时，index位应该加一，不然index-1位会受到影响；
        *(sqdelete - 1) = *sqdelete;
    SqL.length--;

    return DONE;
}

/***查询顺序线性表第一个值为cur_num的前一位数据***/
Status PriorSqElem(SqList SqL, ElemType cur_num, ElemType &pre_num){
    ElemType *point = SqL.elem + 1;//从第二个元素开始
    int index = 2;

    for(;index <= SqL.length && *point != cur_num; index++)
        point++;
    if(index > SqL.length)
        return ERROR;
    else
        pre_num = *--point;

    return DONE;
}

/***查询顺序线性表第一个值为cur_num的后一位数据***/
Status NextSqElem(SqList SqL, ElemType cur_num, ElemType next_num){
    ElemType *point = SqL.elem;
    index = 1;

    for(;index < SqL.length && *point != cur_num; index++)
        point++;
    if(index == SqL.length)
        return ERROR;
    else
        next_num = *++point;
    
    return DONE; 
}
