#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
//��������������
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}BiTNode,*BiTree;//���У�BiTreeΪ��������ָ�룬��lchild��rchildΪͬһ����
//��������
BiTree createBiTree(BiTree root);
void PostOrder(BiTree root);
void PreOrder(BiTree root);
void InOrder(BiTree root);
char str[] ="ABC^D^^E^^FGH^^^I^J^^";//��������ԭʼֵ������,^Ϊ���ߣ�����Ϊ����
BiTree createBiTree(BiTree root){//����������
	static int count;//����Ӿ�̬��ԭ����:static��̬���У��ڴ����������ĵݹ鷽���У���Ҫcount��ÿһ��ݹ������ε��ӣ�����Ҫÿ�δ���intֵ��countĬ��Ϊ0
	char ch = str[count];
	count++;
	if(ch=='^'){
		return NULL;//�÷���������������һ�㷽��
	}
	root = (BiTNode*)malloc(sizeof(BiTNode));
	root->data = ch ;
	root->lchild = createBiTree(root->lchild);
	root->rchild = createBiTree(root->rchild);
	return root;
}
void PreOrder(BiTree root){//�������:��->��->��
	if(root==NULL){
		return;
	}
	printf("%c",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(BiTree root){//�������:��->��->��
	if(root==NULL){
		return;
	}
	InOrder(root->lchild);
	printf("%c",root->data);
	InOrder(root->rchild);
}
void PostOrder(BiTree root){//�������:��->��->��
	if(root==NULL){
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c",root->data);
}
int main(){
	BiTree root;
	root = createBiTree(root);
	printf("�������:");
	PreOrder(root);
	printf("\n�������:");
	InOrder(root);
	printf("\n�������:");
	PostOrder(root);
	printf("\n");
}