#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}



void print_inorder(node * tree,char *p)
{
    if (tree)
    { 
        print_inorder(tree->left,p);

        sprintf(p,"%s, %d",p,tree->data);

        
        print_inorder(tree->right,p); 
    }
}


void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
   int m=0,p=0;char n[100];

while(1)
 
 { 
 
  scanf("%s", n);
  
  
  if(n !="-999")
  { 
      if(n!=" " && n!=",")
      {
          m=atoi(n);
          //printf("%d\n",m);
          if(m!=-999)
          {
          insert(&root,m);
          p=p+1;
          }
          else
          {
              break;
          }
      } 
    }
    else
      {
      break;
  }
}
char t[100]={'j'};
int i=2;
    printf("In-order Traversal of the Binary Search Tree Constructed:");
    print_inorder(root,t);
    while(t[i]!='\0')
    {
        if(t[i]!='j')
    printf("%c",t[i]);
    i++;
        
    }

}
