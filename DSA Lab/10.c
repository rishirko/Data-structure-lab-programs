#include<stdio.h>
#include<stdlib.h>

struct BST{
	int data;
	struct BST *left;
	struct BST *right;
};

typedef struct BST NODE;

NODE *root=NULL,*cur,*prev,*temp;

NODE *insert(int item,NODE *root)
{
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item>=(temp->data))
		{
			cur=cur->right;
		}
		else if(item<(temp->data))
		{
			cur=cur->left;
		}
		else
		{
			return root;
		}
	}
	if(item>(prev->data))
	{
		prev->right=temp;
	}
	else
	{
		prev->left=temp;
	}
	return root;
}

NODE *search(NODE *node, int key)
{
	if(node==NULL)
	{
		printf("\nElement not found\n");
	}
	else if(key<(node->data))
	{
		search(node->left,key);
	}
	else if(key>(node->data))
	{
		search(node->right,key);
	}
	else
	{
		printf("\nElement found \n");
	}
}

NODE *inorder(NODE *node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	printf("%d\t",node->data);
	inorder(node->right);
	
}

NODE *preorder(NODE *node)
{
	if(node!=NULL)
	{
		printf("%d\t",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

NODE *postorder(NODE *node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->data);
	}
}

void del(int item)
{
	NODE *parent=NULL,*suc,*q;
	if(root==NULL)
	{
		printf("\n Tree Empty\n");
		return;
	}
	cur=root;
	while(cur!=NULL)
	{
		if(item==(cur->data))
			break;
		parent=cur;
		cur= (item<cur->data) ? cur->left : cur->right;
	}
	if(cur==NULL)
	{
		printf("\nItem not found\n");
		return;
	}
	if(cur->left==NULL)
	{
		q=cur->right;
	}
	else if(cur->right==NULL)
	{
		q=cur->left;
	}
	else
	{
		suc=cur->right;
		while(suc->left!=NULL)
			suc=suc->left;
		suc->left=cur->left;
		q=cur->right;
	}
	if(parent==NULL)
	{
		root=q;
		return;
	}
	if(cur==parent->left)
	{
		parent->left=q;
	}
	else
	{
		parent->right=q;
	}
	free(cur);
}
void main()
{
	int item,ch,i,n;
	while(1)
	{
		printf("\n1.Create\n2.Search\n3.Delete\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
		printf("\nEnter your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter item to creat BTS like 6,9,5,2,8,15,24,14,7,8,5,2\n");
					for(i=0;i<5;i++)
					{
						scanf("%d",&item);
						root=insert(item,root);
					}
					break;
			case 2:	printf("\nEnter the element to be search: ");
					scanf("%d",&item);
					search(root,item);
					break;
			case 3:	printf("\nEnter the element to be deleted: ");
					scanf("%d",&item);
					del(item);
					break;
			case 4:	printf("\nInorder Transversal\n");
					inorder(root);
					break;
			case 5:	printf("\nPreorder Transversal\n");
					preorder(root);
					break;
			case 6:	printf("\nPostorder Transversal\n");
					postorder(root);
					break;
			case 7: exit(0);	
			default:printf("\nINVALID");
		}
	}
}

