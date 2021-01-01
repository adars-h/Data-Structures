#include<bits/stdc++.h>
using namespace std;
struct bst
{
  int data;
  struct bst* lchild;
  struct bst* rchild;
  bst(int data)
  {
     this->data=data;
     lchild=NULL;
     rchild=NULL;
  }
};
typedef struct bst* bstptr;
void insert(bstptr &root,int n)
{
   if(root==NULL)
   {
      bstptr temp = new bst(n);
      root = temp;
      return;
   }
  if(root->data<n)
    insert(root->rchild,n);
  else 
    insert(root->lchild,n);

}
void create(bstptr &root)
{
   int n;
   cin >>n; 
   if(n==-1)return;
   insert(root,n);
   create(root);
}
void levelorder(bstptr root)
{
     if(root==NULL)return;
     queue<bstptr> q;
     q.push(root);
     q.push(NULL);
     while(q.empty()==false)
     {
      if(q.front()==NULL){
        cout << endl;
        q.pop();
        if(!q.empty())
          q.push(temp);
        else break;
      }
       cout << q.front()->data << " ";
       if(q.front()->lchild)
       q.push(q.front()->lchild);
       if(q.front()->rchild)
       q.push(q.front()->rchild);
       q.pop();
     }                                                                                                                                                                                                                                                                               
 cout << endl;
}
int main()
{
  return 0;
}     