//
//  main.cpp
//  CTCI-ch2
//
//  Created by EllenHu on 8/9/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;


struct LinklistNode{
    int data;
    LinklistNode *next=NULL;
}node;

void print(LinklistNode *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}



//LinklistNode *InitialLinklist(int a[],int n)
//{
//    if(n<1) return NULL;
//    LinklistNode *head=new LinklistNode;
//    head->data=a[0];
//    head->next=NULL;
//    LinklistNode *q=head;
//    for(int i=1;i<n;i++)
//    {
//        LinklistNode *p=new LinklistNode;
//        p->data=a[i];
//        p->next=NULL;
//        q->next=p;
//        q=p;
//    }
//    return head;
//}


////s1-initial
//void removedulicate(LinklistNode *head)
//{
//    
//    if(head==NULL) return;
//    bool hash[20];
//    memset(hash,false,sizeof(hash));
//    LinklistNode *p=head,*q=p->next;
//    hash[p->data]=true;
//    while(q!=NULL)
//    {
//        if(hash[q->data]==true)
//        {
//            LinklistNode *temp=q;
//            p->next=q->next;
//            q=p->next;
//            delete temp;
//        }
//        else if(hash[q->data]==false)
//        {
//            hash[q->data]=true;
//            p=q;
//            q=p->next;
//        }
//    }
//}
//
////s1-followup
//void removedulicateNoBuffer(LinklistNode *head)
//{
//    if(head==NULL) return;
//    LinklistNode *local=head,*p=local,*q=local->next;
//    while(local)
//    {
//        p=local;
//        q=local->next;
//        while(q)
//        {
//            if(q->data==local->data)
//            {
//                LinklistNode *temp=q;
//                p->next=q->next;
//                q=p->next;
//                delete temp;
//            }
//            else if(q->data!=local->data)
//            {
//                p=q;
//                q=q->next;
//            }
//                
//        }
//        local=local->next;
//    }
//    
//}

//s2-stack(recursion)
//void FindNthElement(LinklistNode *head,LinklistNode *&p,int &n)
//{
//    if(head==NULL) return;
//    if(n<1) return;
//    FindNthElement(head->next, p,n);
//    if(n<1) return;
//    if(n==1)
//    {
//        p=new LinklistNode;
//        p=head;
//        cout<<p->data<<endl;
//        n--;
//        return;
//    }
//    n--;
//    
//}


//s2-tricky
//LinklistNode *FindNthTricky(LinklistNode *head,int n)
//{
//    LinklistNode *p=head;
//    int count=1;
//    while(count<n+1)
//    {
//        count++;
//        p=p->next;
//        if(!p)
//        {
//            cout<<"the length is smaller than n"<<endl;
//            return NULL;
//        }
//    }
//    LinklistNode *q=head;
//    while(p)
//    {
//        p=p->next;
//        q=q->next;
//    }
//    return q;
//}


//s3-把C结点的全部信息改为D，数组中将有两个D，删除后一个D
//void DeleteGivenNode(LinklistNode *&p)
//{
//    if(!p) return;
//    LinklistNode *q=new LinklistNode;
//    q=p->next;
//    if(!q)
//    {
//        cout<<"not in the middle"<<endl;
//        delete q;
//        delete p;
//        return;
//    }
//    else
//    {
//        p->data=q->data;
//        p->next=q->next;
//        delete q;
//    }
//    return;
//}

//s4
//LinklistNode *AddDigit(LinklistNode *head1,LinklistNode *head2)
//{
//    int add=0,ishead=1;
//    bool h1=false,h2=false;
//    LinklistNode *head,*q;
//    if(!head1) h1=true;
//    if(!head2) h2=true;
//    if(h2) return head1;
//    if(h1) return head2;
//    while((!h1|!h2)|add)
//    {
//        LinklistNode *p=new LinklistNode;
//        if(!ishead) {q->next=p;q=q->next;}
//        p->data=(add+head1->data+head2->data)%10;
//        add=(add+head1->data+head2->data)/10;
//        p->next=NULL;
//        if(ishead)
//        {
//            head=p;
//            q=head;
//            ishead=0;
//        }
//       if(h1&&h2) break;
//       if(head1->next&&head2->next)
//       {
//           head1=head1->next;
//           head2=head2->next;
//       }
//       else if(!head1->next&&head2->next)
//       {
//           head1->data=0;
//           head2=head2->next;
//           h1=true;
//       }
//       else if(head1->next&&!head2->next)
//       {
//           head2->data=0;
//           head1=head1->next;
//           h2=true;
//       }
//       else if(!head1->next&&!head2->next)
//       {
//           h1=true;
//           h2=true;
//           head1->data=0;
//           head2->data=0;
//       }
//    }
//    return head;
//}


//s5
LinklistNode *FindLoopPoint(LinklistNode *head)
{
    if(head==NULL) return NULL;
    map<LinklistNode*,bool> hash;
    while(head)
    {
        if(hash[head]) return head;
        else
        {
            hash[head]=true;
            head=head->next;
        }
    }
    return NULL;
}


LinklistNode *LoopInit(int a[],int n,int m)
{
    LinklistNode *head=new LinklistNode;
    head->data=a[0];
    head->next=NULL;
    LinklistNode *p=head;
    LinklistNode *looppoint=NULL;
    for(int i=1;i<n;i++)
    {
        LinklistNode *q=new LinklistNode;
        q->data=a[i];
        p->next=q;
        p=p->next;
        if(i==m-1) looppoint=q;
    }
    p->next=looppoint;
    return head;
}


int main()
{
    int count,m;
    cout<<"input the number of Linklist node."<<endl;
    cin>>count;
    cout<<"input the number of loop point."<<endl;
    cin>>m;
    int a[]={1,2,3,4,5,3,1,2,8,5};
    LinklistNode *head=LoopInit(a, count, m);
    LinklistNode *looppoint=FindLoopPoint(head);
    if(looppoint)
        cout<<looppoint->data<<endl;
//    LinklistNode *head=InitialLinklist(a, count);
//    print(head);
//    cout<<"input n"<<endl;
//    cin>>n;
//    LinklistNode *ntodelete=head;
//    for(int i=1;i<n;i++)
//    {
//        ntodelete=ntodelete->next;
//    }
    //DeleteGivenNode(ntodelete);
    //LinklistNode *p=FindNthTricky(head, n);
    //if(p) cout<<p->data<<endl;
    //LinklistNode *p=head;
    //FindNthElement(head, p, n);
    //cout<<p->data<<endl;
    //removedulicateNoBuffer(head);
//    int a1[]={4,3,1,9};
//    int a2[]={5,7,3,1};
//    LinklistNode *head1=InitialLinklist(a1, 4);
//    LinklistNode *head2=InitialLinklist(a2, 4);
//    LinklistNode *head=AddDigit(head1, head2);
//    print(head);
//    delete head;
    //delete p;
    return 0;
}
















