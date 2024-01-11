#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

using namespace std;

typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status InitBiTree(BiTree &T){
	T=(BiTree)malloc(sizeof(BiTNode));
	if(!T) exit(EOVERFLOW);
	T->data='0';
	T->lchild=T->rchild=NULL;
	return OK;
}

Status CreateBiTree(BiTree &T){
	BiTree p;
	BiTree q1,q2;
	queue<BiTree>Q;
	TElemType data;
	Q.push(T);
	while(!Q.empty()){
		p=Q.front();
		scanf("%c",&data);
		getchar();
		if(data=='#') break;
		p->data=data;
		Q.pop();
		InitBiTree(q1);
		p->lchild=q1;
		Q.push(p->lchild);
		InitBiTree(q2);
		p->rchild=q2;
		Q.push(p->rchild);
	}
	return OK;
}

Status num_root(BiTree T){
	if(T->data=='0'){
		return 0;
	}
	if(T->lchild->data=='0'&&T->rchild->data=='0'){
		return 1;
	}
	else{
		return num_root(T->lchild)+num_root(T->rchild);
	}
}

int main(){
	
	return 0;
}/*7
A B C D E 0 0 0 0 F G #*/
