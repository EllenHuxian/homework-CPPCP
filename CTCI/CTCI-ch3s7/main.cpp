//
//  main.cpp
//  CTCI-ch3s7
//
//  Created by EllenHu on 8/16/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#define Queue_Num 10

class Myqueue{
public:
    Myqueue(int queue_size=Queue_Num){
        buf=new string[queue_size];
        for(int i=0;i<queue_size;i++) buf[i]=" ";
        front=0;
        rear=0;
        size=queue_size+1;
    }
    ~Myqueue(){
        delete[] buf;
    }
    bool isempty(){
        if(front==rear) return true;
        else return false;
    }
    
    bool isfull(){
        if((rear==front-1)|((front==0)&&(rear==size))) return true;
        else return false;
    }
    
    string peek(){
        if(!this->isempty()) return buf[front];
        else return "queue is empty";
    }
    
    void push(string name){
        if(!this->isfull())
        {
            if(rear<size)
            {

                buf[rear]=name;
                rear++;
            }
            
            else if((rear==size)&&(front>0))
            {
                buf[0]=name;
                rear=1;
            }
        }
        else if(this->isfull())
        {
            cout<<"queue is full"<<endl;
        }

    }
    void pop(){
        if(this->isempty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        if(front<size-1)
        {
            buf[front]=" ";
            front++;
        }
        else if((front==size-1)&&(rear>0)&&(rear<front))
        {
            buf[front]=" ";
            front=0;
        }
    }
private:
    int size;
    int front,rear;
    string *buf;
};



class AnimalShelterSys{
public:
    void enqueue(string name,char a){
        if(a=='c') {cat.push(name);all.push(name);cout<<"push "<<name<<endl;}
        if(a=='d') {dog.push(name);all.push(name);cout<<"push "<<name<<endl;}
        if((a!='c')&&(a!='d'))
        {
            cout<<"error"<<endl;
            return;
        }
        
    }
    
    void dequeueAny(){
        while((all.peek()!=cat.peek())&&(all.peek()!=dog.peek())) all.pop();
        if(all.peek()==cat.peek()) cat.pop();
        else if(all.peek()==dog.peek()) dog.pop();
        cout<<"dequeueany "<<all.peek()<<endl;
        all.pop();
    }
    
    void dequeueCat(){
        if(all.peek()==cat.peek()) all.pop();
        cout<<"dequeuecat "<<cat.peek()<<endl;
        cat.pop();
    }
    
    void dequeueDog(){
        if(all.peek()==dog.peek()) all.pop();
        cout<<"dequeuedog "<<dog.peek()<<endl;
        dog.pop();
    }
    
private:
    
    Myqueue dog;
    Myqueue cat;
    Myqueue all;
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
    sys.dequeueAny();
    sys.dequeueDog();
    sys.dequeueCat();
    sys.enqueue("Reaper",'d');
    sys.enqueue("Morrison",'c');
    sys.enqueue("Tracer",'d');
    sys.enqueue("Phara",'d');
    sys.enqueue("Mei",'c');
    sys.enqueue("Zen",'c');
    sys.enqueue("Lucio",'d');
    sys.dequeueAny();
    sys.dequeueDog();
    sys.dequeueCat();
    sys.dequeueCat();
    sys.dequeueAny();
    sys.dequeueDog();
    return 0;
}


