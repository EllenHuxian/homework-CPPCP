//
//  main.cpp
//  CTCI-CH4s3
//
//  Created by EllenHu on 8/23/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode *lchild,*rchild,*parent;
}TreeNode;


void BuildSortedTree(int a[],int n)
{
    int i=0;
    TreeNode *left,*right,*head,*parent;
    left=NULL;
    right=NULL;
    head=NULL;
    parent=NULL;
    if(!a)
    {
        cout<<"the array is empty"<<endl;
        return;
    }
    while(i<n)
    {
        TreeNode *p=new TreeNode;
        p->val=a[i++];
        if(!left) {left=p;return;}
        if(left)
        {
            
        }

    }
}

