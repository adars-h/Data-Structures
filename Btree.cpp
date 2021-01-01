#include<bits/stdc++.h>
using namespace std;
struct Btree
{
  int cnt=0;
  int key[8];
  struct Btree* child[8]={NULL};
  struct Btree* left=NULL;
};
typedef struct Btree* mwptr;
mwptr* search(mwptr *root,int &idx,int k,mwptr* &prev);
void insert(mwptr* root,int idx,int k)
{
  if((*root)==NULL)
  { 
    *root = new Btree;
    (*root)->key[idx]=k;
    (*root)->cnt+=1;
  }
  else
  {
    (*root)->key[idx]=k;(*root)->cnt+=1;
  }
}
bool isleafnode(mwptr root)
{
   if(root==NULL)return false;int i;
   for(i=0;i<3;i++)
    if(root->child[i])return false;
   return true;
}
void split(mwptr* curr,mwptr* prev,mwptr *root,int degree)
{
   mwptr right = new Btree;
   int idx=((*curr)->cnt)/2;
   mwptr left = new Btree;
   for(int i=0;i<=idx;i++)
   {  
    if(i<idx)
     left->key[left->cnt++]=(*curr)->key[i];
     if(i<=idx)
     left->child[i]=(*curr)->child[i];
   }
   if(isleafnode(*curr)){right->key[right->cnt++]=(*curr)->key[idx];}
   for(int i=idx+1;i<=((*curr)->cnt);i++)
   {
    if(i<=(*curr)->cnt)
    right->child[right->cnt]=(*curr)->child[i];
    if(i<(*curr)->cnt)
    { right->key[right->cnt]=(*curr)->key[i];right->cnt++;}
   }
    
   if((prev)==NULL)
   {
     mwptr temp = new Btree;
     temp->key[0]=(*curr)->key[idx];
     temp->cnt++;
     (*curr)->cnt=idx;
     temp->child[temp->cnt-1] = left;
     temp->child[temp->cnt] = right;
     (*curr) = temp;
   }
     else
     {
       int i=(*prev)->cnt-1;
       while(i>=0 && (*prev)->key[i]>(*curr)->key[idx])
       {
          (*prev)->key[i+1]=(*prev)->key[i];
          (*prev)->child[i+2]=(*prev)->child[i+1];
          (*prev)->child[i+1]=(*prev)->child[i];
          i--;
       }
       (*prev)->key[i+1]=(*curr)->key[idx];(*prev)->cnt++;
       (*prev)->child[i+1]=left;
       (*prev)->child[i+2]=right;
       (*curr)->cnt=idx;
       if((*prev)->cnt==degree)
       {
        int k=(*prev)->key[(*prev)->cnt-1];
         mwptr *prevnew=NULL;
         mwptr *currnew=search(root,i,k,prevnew);
         split(currnew,prevnew,root,degree);
       }
     }
}
mwptr* search(mwptr *root,int &idx,int k,mwptr* &prev)
{
  if(*(root)==NULL)
  {idx=0; return root;}
  int i=0;
  while(i < (*root)->cnt && (*root)->key[i] < k) i++;
  if(i<(*root)->cnt && (*root)->key[i]==k){idx=i;return root;}
  if(i==0)
  {
     if((*root)->child[0]==NULL){idx=(*root)->cnt;return root;}
     else {
      prev=root;
      return search(&((*root)->child[0]),idx,k,prev);}
  }
  if(i==(*root)->cnt){
       if((*root)->child[(*root)->cnt])
       {
        prev=root;
        return search(&((*root)->child[(*root)->cnt]),idx,k,prev);
       }
       else { idx=(*root)->cnt; return root;}
  }
  if((*root)->child[i]==NULL){idx=(*root)->cnt;return root;}
  else {prev=root;return search(&((*root)->child[i]),idx,k,prev);}
}
void add(mwptr *root,int k,int degree)
{
  int idx;
  mwptr *prev=NULL;
  mwptr *curr=search(root,idx,k,prev);
  insert(curr,idx,k);
  sort((*curr)->key,(*curr)->key+(*curr)->cnt);
  if((*curr)->cnt!=degree)return;
  else
  {
     split(curr,prev,root,degree);
  }
}

void inorder(mwptr root)
{
  if(root==NULL)return;
  for(int i=0;i<=(root->cnt);i++)
    {
      inorder(root->child[i]);
      if(i<root->cnt)
      cout << root->key[i] << " ";
    }
}
void print(mwptr root)
{
   if(root==NULL)return;
   for(int i=0;i<(root->cnt);i++)
    cout << root->key[i] << " ";
}
void levelorder(mwptr root)
{
   if(root==NULL)return;
   queue<mwptr> q;
   q.push(root);q.push(NULL);
   while(q.empty()==false)
   {
     if(q.front()==NULL){
      cout << endl;
      q.pop();
      if(q.empty())break;
      else q.push(NULL);
     }
     print(q.front());
     for(int i=0;i<=(q.front()->cnt);i++)
      if(q.front()->child[i])q.push(q.front()->child[i]);
    q.pop();
   }
}

int main()
{
  mwptr root=NULL;
  int degree,size;
  cin >> degree >> size;
  int arr[size];
  for(int i=0;i<size;i++)
    cin >> arr[i];
  for(int i=0;i<size;i++)
  {
    add(&root,arr[i],degree);
  }
levelorder(root);cout << endl;
}