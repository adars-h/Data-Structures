#include<bits/stdc++.h>
using namespace std;
struct minheap
{
  int arr[10000];
  int top=-1;
  // function checks and maintains the minheap property at each node.
  void modify()
  {                      
    int i=top;

    while(i!=0 && arr[(i-1)/2] > arr[i]) // if child is smaller than parent
    {
       swap(arr[(i-1)/2],arr[i]);     // swap parent node with child

        i = ((i-1)/2);       // continue recursively for parent node.
    }
  }
  // function to check and maintain the minheap property whenever root node is modified.
  void heapify(int idx)
  {
       // idx is current node index.
    int left = 2*idx+1;   // left child node index
    int right = 2*idx+2;  // right child node index.
    int smallest = i;   // stores the index of smallest value of the three nodes.

    if(left<=top && arr[left]<arr[idx]) // if left node is smallest store it's index.
      smallest = left;
    if(right<=top && arr[right]<arr[smallest]) // check for right node.
      smallest = right;
    if(smallest!=idx) // check for current 
    {
      swap(arr[smallest],arr[idx]);
      heapify(smallest);
    }
  }
  void insert(int key)
  {
    top++;
    arr[top] = key;
    modify();
  }
  void del()
  {
    arr[0] = arr[top];
    top--;
    heapify(0);
  }
  int root()
  {
    return arr[0];
  }
  void print()
  {
    for(int i=0;i<=top;i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  bool empty()
  {
    if(top==-1)return true;
    return false;
  }
};
struct maxheap
{
  int arr[10000];
  int top=-1;
  void modify()
  {
     int i=top;
    while(i!=0 && arr[(i-1)/2]<arr[i])
    {
        swap(arr[(i-1)/2],arr[i]);
        i = (i-1)/2;
    }
  }
  void heapify(int idx)
  {
     int left = 2*idx+1;
     int right = 2*idx+2;
     int greatest = idx;
     if(left<=top && arr[left]>arr[idx])
      greatest = left;
     if(right<=top && arr[right]>arr[greatest])
      greatest = right;
     if(greatest!=idx)
     {
       swap(arr[greatest],arr[idx]);
       heapify(greatest);
     }
  }
  void insert(int key)
  {
    top++;
    arr[top]=key;
    modify();
  }
  void del()
  {
    arr[0]=arr[top];
    top--;
    heapify(0);
  }
  int root()
  {
    return arr[0];
  }
  void print()
  {
    for(int i=0;i<=top;i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  bool empty()
  {
    if(top==-1)return true;
    return false;
  }
};
int main()
{
  int n;
  maxheap h;
  while(true)
  {
      cin >> n;
      if(n==-1)break;
      h.insert(n);
  }
  while(!h.empty())
  {
    cout << h.root() << " ";
    h.del();
  }
  return 0;
}