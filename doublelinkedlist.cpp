#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
  node(int data)
  {
     this->data = data;
     left=NULL;
     right=NULL;
  }
};
typedef struct node* dlptr;
void create(dlptr &L)
{
   dlptr T=NULL,prev;
    int num;
    cin >> num;
    if(num!=-1)
    {
      L = new node(num);
      T = L;
      while(true)
      {
        cin >> num;
        if(num==-1)break;
        T->right = new node(num);
        prev = T;
        T = T->right;
        T->left = prev;
      }
    }
}
void addfront(dlptr &L,int k)
{
  dlptr T;
  T = new node(k);
  T->right = L;
  L->left = T;
  L = T;
}
void addend(dlptr &L,int k)
{
  dlptr T = L,prev = NULL;
  while(T->right)
    T=T->right;
  T->right = new node(k);
  prev = T;
  T = T->right;
  T->left = prev;
}
void print(dlptr L)
{
  dlptr T=L;
  while(T!=NULL)
  {
    cout << T->data << " ";
    T = T->right;
  }
  cout << endl;
}
void addbefore(dlptr &L,int toadd,int before)
{
   dlptr T = L,prev=NULL;
   while(T->data!=before && T!=NULL)
   {
     prev=T;
     T=T->right;
   }
  if(prev)
  {
    prev->right = new node(toadd);
    dlptr prev1 = prev;
    prev = prev->right;
    prev->left = prev1;
    prev->right = T;
  }
  else addfront(L,toadd);
}
void addafter(dlptr &L,int toadd,int after)
{
  dlptr T=L,next=L->right;
  while(T->data!=after)
    T=T->right,next=next->right;
  T->right = new node;
  dlptr prev=T;
  T=T->right;
  T->data = toadd;
  T->left = prev;
  T->right = next;

}
void delfront(dlptr &L)
{
  L=L->right;
  L->left = NULL;
}
void delend(dlptr &L)
{
  dlptr T=L;
  while(T!=NULL && T->right!=NULL && T->right->right!=NULL)T=T->right;
  T->right = NULL;
}
void del(dlptr &L,int todel)
{
  dlptr T=L,prev=NULL,next=T->right;
  while(T->data!=todel){prev=T;T=next;next=next->right;}
  if(prev){
    prev->right=next;
    if(next)
    next->left=prev;
  }
  else delfront(L);
}
int main()
{
  dlptr L;
  create(L);
  print(L);
  return 0;
}