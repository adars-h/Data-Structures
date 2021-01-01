#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node* next;
  node(int data)
  {
     this->data=data;
     next=NULL;
  }
};
typedef struct node* lptr;
void create(lptr &L)
{
  lptr T=NULL;
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
        T->next = new node(num);
        T=T->next;
      }
    }
}
void print(lptr L)
{
  lptr T=L;
  while(T!=NULL)
  {
    cout << T->data << " ";
    T=T->next;
  }
  cout << endl;
}
int main()
{
  lptr L;
  create(L);
  return 0;
}
