#include <iostream>
using namespace std;
class queue
{
private:
  int front, rear;
  int *arr;
  int n;
public:
    queue (int size) // constructor
  {
    n = size;
    arr = new int[n];//for dynamic i used here
      front = rear = -1;
  }
  bool is_empty ()
  {
     return (front == -1 && rear == -1);
  }
  bool is_full ()
  {
    return (front == (rear + 1) % n);
  }
  void init()//?
  {
    for (int i = 0; i < n - 1; i++)
      {
	      arr[i] = 0;
      }
  }
  void enqueue ()
  {
    if (is_full ())
      {
	   cout << "Queue is full." << endl;
	   return;
      }
    int no;
    cout << "Enter enqueue:" << endl;
    cin >> no;
    if (is_empty())
      {
	     front = 0;
      }
    rear = (rear + 1) % n;
    arr[rear] = no;// if i want print no. then arr[rear]=no. 
  } 
  void dequeue ()
  {
    if (is_empty ())
      {
      	cout << "Queue is empty." << endl;
	      return;
      }
      
    cout << "Deleted: " << arr[front] << endl;
    if (front == rear)
    //means both are at end postion(front is traversal and reach at rear position)
      {
      front = rear = -1;
      }
    else
      {
	     front = (front + 1) % n;
      }
  }
  void show ()
  {
    if (is_empty ())
      {
    	cout << "Queue is empty." << endl;
	    return;
      }
    else
      {
    	int i = front;
    	cout << "Queue contain: " << endl;
	   while (true)
	  {
	    cout << arr[i] << " ";
	    if (i == rear)//when i is reach at rear then break means all queue elements are return
	      {
		     break;
	      }
	    i = (i + 1) % n;
	  }
	cout << "" << endl;
	cout << "front:" << front << " rear:" << rear << endl;
      }
  }
};

int main ()
{
  int n;
  cout << "enter size of queue:";
  cin >> n;
  queue obj(n);
  while (true)
    {
      int choice;
      cout << "enter your choice:" << endl;
      cout << "1.enqueue" << endl;
      cout << "2.dequeue" << endl;
      cout << "3.show enqueue" << endl;
      cout << "4.exit." << endl;
      cout<<"choice is=";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  obj.enqueue ();
	  obj.show ();
	  break;
	case 2:
	  obj.dequeue ();
	  obj.show ();
	  break;
	case 3:
	  obj.show ();
	  break;
	case 4:
      exit (0);
	  break;
	default:
	  cout << "wrong choice !!!" << endl;
	}
  }
  return 0;
}

