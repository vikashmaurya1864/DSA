#include<iostream>
using namespace std;
class Stack{
    private:
    int *arr;
    int top;
    int size;
    public:
    //this is constructor of class
    Stack(int size)
    {
      this->size=size;
      arr=new int[size]; 
      this->top=-1;
    }
    //push operation is here
   void push(int data){
        if(top+1<size  ){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

   int pop(void)
   {
     if(top>-1)
     {
        int k=arr[top];
        top--;
        return k;
     }
     else{
        return 0;
     }
   }

   pair<int,int> SizeOf(void)
   {
      pair<int,int>pair;
      pair.first=top;
      pair.second=size;

      return pair;
   }
   bool Isempty(void){
    if(top==-1){
        return 1;
    }
    else 
    return 0;
   }

};

int main()
{
   Stack s1(5);
   s1.push(1);
   s1.push(4);
   s1.push(7);

   cout<<"pop element is "<<s1.pop()<<endl;

   auto pair=s1.SizeOf();
   cout<<"filled  stack is "<<pair.first<<endl;
   cout<<"size of stack is "<<pair.second<<endl;

   s1.pop();
   s1.pop();

   cout<<"stack is empty "<<s1.Isempty()<<endl;




}