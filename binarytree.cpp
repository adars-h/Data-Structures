#include<bits/stdc++.h>
using namespace std;
struct bt
{
  int data;
  struct bt* lchild;
  struct bt* rchild;
  bt(int data)
  {
    this->data = data;
    lchild=NULL;
    rchild=NULL;
  }
};
typedef struct bt* btptr;                                         
void levelorder(btptr &root)
{
     if(root==NULL)return;
     queue<btptr> q;
     q.push(root);
     q.push(NULL);
     while(q.empty()==false)
     {
      if(q.front()==NULL){
        cout << endl;
        q.pop();
        if(!q.empty())
          q.push(NULL);
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
void createbt(btptr &root,string s)
{
  if(s[0]=='#')return;
   queue<btptr> q;
   root = new bt(s[0]+'0');
   q.push(root);
   int idx=1;
   while(q.empty()==false && idx<s.size()-1)
   {
    if(s[idx]!='#')
    {
      q.front()->lchild = new bt(s[idx]+'0');
      q.push(q.front()->lchild);
    }
    idx++;
    if(idx==s.size()-1)break;
    if(s[idx]!='#')
    {
      q.front()->rchild = new bt(s[idx]+'0');
      q.push(q.front()->rchild);
    }
    q.pop();
    idx++;
   }
}
int main()
{
   btptr root=NULL;
   string s;
   cin >> s;
   createbt(root,s);
   levelorder(root);
}