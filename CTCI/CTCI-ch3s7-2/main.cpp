//
//  main.cpp
//  CTCI-ch3s7-2
//
//  Created by EllenHu on 8/17/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node{
    string name=" ";
    Node *next=NULL;
}Node;

class LinkQueue{
public:
    LinkQueue(){
        size=0;
        first=true;
    }
    
    bool isempty(){
        if(size==0) return true;
        else return false;
    }
    
    void push(string name){
        if(!first)
        {
            rear->name=name;
            Node *p=new Node;
            rear->next=p;
            p->name=" ";
            p->next=NULL;
            rear=p;
            cout<<"push "<<name<<endl;
            cout<<"front name is "<<front->name<<endl;
        }
        else if(first)
        {
            front=new Node;
            front->name=name;
            rear=new Node;
            rear->name=" ";
            front->next=rear;
            rear->next=NULL;
            first=false;
            cout<<"push head "<<name<<endl;
            cout<<"front name is "<<front->name<<endl;
        }
        size++;
    }
    
    void pop(){
        if(!this->isempty())
        {
            Node *p=front;
            front=front->next;
            delete p;
            size--;
        }
        else cout<<"queue is empty."<<endl;
    }
    
    string peek(){
        if(!this->isempty()) return front->name;
        else cout<<"queue is empty."<<endl;
        return NULL;
    }
    
    int getsize(){
        return size;
    }
    
    Node *front,*rear;

private:
    int size;
    bool first;
    };


class AnimalShelterSys{
public:
    void enqueue(string name,char a){
        if(a=='c') cat.push(name);
        if(a=='d') dog.push(name);
        all.push(name);
    }
    
    void DequeueAny(){
        if(all.isempty()) {cout<<"empty"<<endl;return;}
        cout<<"dequeue any "<<all.peek()<<endl;
        if(all.peek()==cat.peek()) cat.pop();
        if(all.peek()==dog.peek()) dog.pop();
        all.pop();
        cout<<all.peek()<<endl;
    }
    
    void DequeueCat(){
        if(cat.isempty())
        {
            cout<<"no cat left."<<endl;
            return;
        }
        if(all.peek()==cat.peek())
        {
            all.pop();
            cout<<"dequeue cat "<<cat.peek()<<endl;
            cat.pop();
            cout<<all.peek()<<endl;
            return;
        }
        Node *q=all.front;
        Node *p=q;
        if(p->name!=cat.peek()) p=p->next;
        while((p->name!=cat.peek())&&(p!=NULL))
        {
            p=p->next;
            q=q->next;
        }
        if((p->name==cat.peek())&&(p!=q))
        {
            q->next=p->next;
            //delete p;
        }
        cout<<"dequeue cat "<<cat.peek()<<endl;
        cat.pop();
        cout<<all.peek()<<endl;
    }
    
    void DequeueDog(){
        if(dog.isempty())
        {
            cout<<"no dog left."<<endl;
            return;
        }
        if(all.peek()==dog.peek())
        {
            all.pop();
            cout<<"dequeue dog "<<dog.peek()<<endl;
            dog.pop();
            cout<<all.peek()<<endl;
            return;
        }
        Node *q=all.front;
        Node *p=q;
        if(p->name!=dog.peek()) p=p->next;
        while((p->name!=dog.peek())&&(p!=NULL))
        {
            p=p->next;
            q=q->next;
        }
        if((p->name==dog.peek())&&(p!=q))
        {
            q->next=p->next;
            //delete p;
        }
        cout<<"dequeue dog "<<dog.peek()<<endl;
        dog.pop();
        cout<<all.peek()<<endl;
    }
    
private:
        
    LinkQueue all;
    LinkQueue cat;
    LinkQueue dog;
};


int main()
{
    AnimalShelterSys sys;
    sys.enqueue("Hanzo",'c');
    sys.enqueue("Genji",'c');
    sys.enqueue("Dolf",'d');
    sys.enqueue("S76",'c');
    sys.enqueue("Gabe",'d');
    sys.enqueue("Jess",'d');
    sys.DequeueAny();
    sys.DequeueDog();
    sys.DequeueCat();
    sys.DequeueAny();
    sys.enqueue("Reaper",'d');
    sys.enqueue("Morrison",'c');
    sys.enqueue("Tracer",'d');
    sys.enqueue("Phara",'d');
    sys.enqueue("Mei",'c');
    sys.enqueue("Zen",'c');
    sys.enqueue("Lucio",'d');
    sys.DequeueAny();
    sys.DequeueDog();
    sys.DequeueCat();
    sys.DequeueCat();
    sys.DequeueAny();
    sys.DequeueDog();
    return 0;
}



