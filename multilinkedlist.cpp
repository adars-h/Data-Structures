#include<iostream>
using namespace std;
struct multinode
{
  int data;
  int tag;
  struct multinode* right;
  struct multinode* down;
  multinode(int data)
  {
     this->data=data;
     right=NULL;
     left=NULL;
  }
};
typedef struct multinode* mptr;
struct node
{
  mptr data;
  struct node* next;
  node(int data)
  {
    this->data=data;
    next=NULL;
  }
};
typedef struct node* lptr;
 struct queue
   {
     lptr head=NULL;
     void enqueue(mptr n)
     {
       if(head==NULL){
        head=new node(n);
      }
      else
      {
        lptr T=head;
        while(T->next!=NULL)
          T=T->next;
        T->next=new node(n);
        T=T->next;
      }
     }
     void dequeue()
     {
       if(head==NULL)cout <<"IMPossible" << endl;
       else
        head=head->next;
     }
     mptr front()
     {
       return head->data;
     }
     bool empty()
     {
      if(head)return false;
      else return true;
     }
   };
   struct stack
    {
      lptr head=NULL;
      void push(mptr n)
      {
          lptr T;
          T=new node(n);
          T->next=head;
          head=T;
      }
      void pop()
      {
        if(head==NULL)cout <<"Not possible" << endl;
        else {head=head->next;}
      }
      mptr peek()
      {
        if(head==NULL)return NULL;
        else return head->data;
      }
      bool empty()
      {
        if(head==NULL)return true;
        else return false;
      }
    };
void createmain(mptr &L)
{
    mptr T=NULL;
    int num,tag;
    cin >> num;
    if(num!=-1)
    {
      L = new multinode(num);
      cin >> L->tag;
      if(L->tag)createmain(L->down);
      L->right = NULL;
      T = L;
      while(true)
      {
        cin >> num;
        if(num==-1)return;
        T->right = new multinode(num);
        T=T->right;
        cin >> T->tag;
        if(T->tag)createmain(T->down);
      }
    } 
}
void printlevel(mptr L)
{
  if(L==NULL)
    return;
  mptr T=L;
  queue q;
  while(T!=NULL)
  {
    cout << T->data <<" ";
    if(T->tag)q.enqueue(T->down);
    T=T->right;
  }
  while(q.empty()==false)
  {
    mptr T=q.front();
    while(T!=NULL)
    {
      cout << T->data <<" ";
      if(T->tag)q.enqueue(T->down);
      T=T->right;
    }
    q.dequeue();
  }
  return;
}
void printdepth(mptr L)
{
  if(L==NULL)return;
  mptr T=L;
  stack s;
  while(T!=NULL)
  {
    cout << T->data << " ";
    if(T->right)s.push(T->right);
    T=T->down;
  }
  while(s.empty()==false)
  {
    printdepth(s.peek());
    s.pop();
  }
}
int main()
{
  mptr L;
  createmain(L);
  printlevel(L);
  cout << endl;
  printdepth(L);
}

