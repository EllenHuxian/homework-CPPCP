//
//  main.cpp
//  ch3s3
//
//  Created by EllenHu on 8/14/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class stack{
public:
    stack(int stack_size=10){
        buf=new int[stack_size];
        top=-1;
        size=stack_size;
    }
    ~stack(){
        delete[] buf;
    }
    
    bool full(){
        if(top==size-1) return true;
        else return false;
    }  
    
    bool isempty(){
        if(top==-1) return true;
        else return false;
    }
    int returntop(){
        return top;
    }
    
    int findtop(){
        return buf[top];
    }
    
    void push(int val){
        if(top==size-1)
        {
            cout<<"stack is full."<<endl;
            return;
        }
        else{
        
            top++;
            buf[top]=val;
            return;
        }
    }
    void pop(){
        top--;
    }

private:
    int size;
    int top;
    int *buf;
};






class SetOfStacks{
public:
    SetOfStacks(int stack_num=3){
        st=new stack[stack_num];
        count=0;
        size=stack_num;
    }
    ~SetOfStacks(){
        delete[] st;
    }
   
    
    void push(int value){
        if(st[count].full())
        {
            count++;
            if(count>size-1)
            {
                cout<<"stack is full for "<<value<<endl;
                count--;
                return;
            }
        }
        st[count].push(value);
    }
    
    void pop(){
        if((st[count].returntop()==0)&&count>0) count--;
        else if(st[count].returntop()>0) st[count].pop();
        else if((st[count].returntop()==0)&&count==0)
        {
            st[count].pop();
            cout<<"stack is empty."<<endl;
        }
    }
    
    void PopAt(int index){
        if(!st[index].isempty()) st[index].pop();
        else cout<<"stack "<<index<<" is empty."<<endl;
    }
    
    int findtop(){
        return st[count].findtop();
    }
    bool isempty(){
        return ((count==0)&&(st[count].isempty()));
    }
    bool isfull(){
        return ((count==size-1)&&st[count].full());
    }
    
private:
    stack *st;
    int count;
    int size;

    
};



int main()
{
    SetOfStacks mystack;
    for(int i=0;i<31;i++)
        mystack.push(i);
    mystack.PopAt(1);
    while(!mystack.isempty())
    {
        cout<<mystack.findtop()<<endl;
        mystack.pop();
    }
    return 0;
}