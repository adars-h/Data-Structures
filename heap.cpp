#include<iostream>
using namespace std;
struct minheap
{
  int arr[10000];
  int top=-1;
  void heapify()
  {
	  int i=top;
	  while(i>=0 && (i-1)/2>=0)
	  {
	  	 if(arr[(i-1)/2]>arr[i])
        swap(arr[(i-1)/2],arr[i]);
	  	 i--;
	  }
  }
  void insert(int key)
  {
    top++;
    arr[top]=key;
    heapify();
  }
  void del()
  {
  	arr[0]=arr[top];
  	top--;
  	heapify();
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
  void heapify()
  {
  	 int i=top;
  while(i>=0 && (i-1)/2>=0)
  {
  	 if(arr[(i-1)/2]<arr[i])
      swap(arr[(i-1)/2],arr[i]);
  	 i--;
  }
  }
  void insert(int key)
  {
    top++;
    arr[top]=key;
    heapify();
  }
  void del()
  {
  	arr[0]=arr[top];
  	top--;
  	heapify();
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