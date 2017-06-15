//
//  main.cpp
//  CTCI-ch4s1
//
//  Created by EllenHu on 8/18/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct TreeNode{
    char name;
    TreeNode *lchild,*rchild;
}TreeNode;




void BalanceTree(TreeNode *head,int depth[],int count,int &i,bool &end)
{
    if((!head->lchild)&&(!head->rchild))
    {
        depth[i]=count;
  //      cout<<i<<"  "<<count<<endl;
        for(int j=0;j<i+1;j++)
        {
            if((count<depth[j]-1)|(count>depth[j]+1))
            {
                //cout<<"tree is not balanced"<<endl;
                end=true;
                break;
            }
        }
        i++;
        return;
    }
    if((head->lchild)&&(!end)) BalanceTree(head->lchild, depth, count+1,i,end);
    if((head->rchild)&&(!end)) BalanceTree(head->rchild, depth, count+1,i,end);
    //if(!end) cout<<"tree is balanced"<<endl;
}




void InitialTree(TreeNode *&head)
{
    char left,right;
    TreeNode *p,*q;
    p=NULL;
    q=NULL;
    cout<<"input node "<<head->name<<"'s left child: (input 0 if there's no child)"<<endl;
    cin>>left;
    if(left!='0')
    {
        p=new TreeNode;
        head->lchild=p;
        p->name=left;
        p->lchild=NULL;
        p->rchild=NULL;
        
    }
    cout<<"input node "<<head->name<<"'s right child: (input 0 if there's no child)"<<endl;
    cin>>right;
    if(right!='0')
    {
        q=new TreeNode;
        head->rchild=q;
        q->name=right;
        q->lchild=NULL;
        q->rchild=NULL;
        
    }
    if(left!='0') InitialTree(p);
    if(right!='0') InitialTree(q);
}


TreeNode *Initializer()
{
    char quit,name;
    TreeNode *head=new TreeNode;
    cout<<"start to initialize a binary tree: (input 0 to quit)"<<endl;
    cin>>quit;
    if(quit=='0')
    {
        delete head;
        return NULL;
    }
    cout<<"input head's name:"<<endl;
    cin>>name;
    head->name=name;
    head->lchild=NULL;
    head->rchild=NULL;
    InitialTree(head);
    return head;
}


int main()
{
    int depth[20]={0};
    int count=0;
    int i=0;
    bool end=false;
    TreeNode *head=Initializer();
    BalanceTree(head,depth,count,i,end);
    if(!end) cout<<"tree is balanced"<<endl;
    if(end) cout<<"tree is unbalanced"<<endl;
    delete[] head;
    head=NULL;
    return 0;
}
