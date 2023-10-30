//文件名:exp2-6.cpp
#include "linklist.cpp"				//包含单链表的基本运算算法
#include <iostream>
#include<string.h>
void Split1(LinkNode *&L)			//解法1：将L中所有结点按首结点值进行划分
{
	LinkNode *pre,*p;
	if( L->next==NULL||L->next->next==NULL)
	          return;
	   	int x=L->next->data;
		pre=L->next;				//pre指向首结点
		p=pre->next;		//取尾结点值x 
						//单链表L为空或者只有一个结点时返回 
			
							//p指向pre结点的后继结点 
	while(p!=NULL) 
	{
		if(p->data<x)				//结点p的值小于x时 
		{ 
			pre->next=p->next;		//删除结点p
			p->next=L->next;		//将结点p插入到表头
			L->next=p;
			p=pre->next;			//继续遍历 
		}
		else						//结点p的值大于等于x时 
		{
			pre=p;					//pre,p同步后移 
			p=pre->next;
		}
	}
}
void Split2(LinkNode *&L)			//解法2：将L中所有结点按首结点值进行划分
{
	LinkNode *p=L->next,*r,*L1,*r1;
	if(L->next==NULL || L->next->next==NULL)
		return;						//单链表L为空或者只有一个结点时返回 
	int x=L->next->data;			//取首结点值x 
	r=L;
	L1=(LinkNode*)malloc(sizeof(LinkNode));	//建立大于等于x的单链表L1
	r1=L1; 
	while (p!=NULL)
	{
		if (p->data<x)			//若p结点值小于x
		{
			r->next=p; r=p;
			p=p->next;
		}
		else
		{
			r1->next=p; r1=p;
			p=p->next;
		}
	}
	r1->next=NULL;
	r->next=L1->next;			//L和L1连接 
	free(L1);
}

void Split3(LinkNode *&L)			//解法2：将L中所有结点按首结点值进行划分
{
	LinkNode *p=L->next,*r,*L1,*r1;
	LinkNode *temp; // temp node
	if(L->next==NULL || L->next->next==NULL)
		return;						//单链表L为空或者只有一个结点时返回
	
	while(p->next){
	   p = p->next;
	} 
	temp = p; // 保存尾结点
	int x=p->data;			//取尾结点值x 
	p = L->next;  //重新让p指向链表的首结点
		
	r=L; 
	L1=(LinkNode*)malloc(sizeof(LinkNode));	//建立大于等于x的单链表L1
	r1=L1; 
	while (p->next!=NULL)
	{	
		if (p->data<x)			//若p结点值小于x
		{
			r->next=p; r=p;
			p=p->next;
		}
		else
		{
			r1->next=p; r1=p;
			p=p->next;
		}
	}
	p->next = NULL; // 将提前设置尾结点为空
	
	
	r1->next=NULL;
	r->next = temp;
	temp->next=L1->next;			//L和L1连接 
	free(L1);
}


int main()
{
	LinkNode *L;
	ElemType a[]="daxgdchaeb";
	int n=strlen(a);
	
	
	printf("解法1\n"); 
	CreateListR(L,a,n);
	printf("  L: "); DispList(L);
	printf("  以首结点值进行划分\n");
	Split1(L);
	printf("  L: "); DispList(L);
	DestroyList(L);
	
	printf("解法2\n"); 
	CreateListR(L,a,n);
	printf("  L: "); DispList(L);
	printf("  以首结点值进行划分\n");
	
	Split2(L);
	printf("  L: "); DispList(L);
	
	
	// 下面是以尾结点更改的
		printf("解法3\n"); 
		CreateListR(L,a,n);
		printf("  L: "); DispList(L);
		
		
		printf("  以尾结点值进行划分\n");
		
		Split3(L);
		printf("  L: "); DispList(L);
	
	DestroyList(L);
	return 1;
}
