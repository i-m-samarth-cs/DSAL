#include<iostream>
using namespace std;
struct Stud 
{ 
    int rno;
    string name;
    float sgpa;
};
class Stud_Info 
{   
    struct Stud s[20];
    public: 
           int n;
           void getData();
           void display_b();
           void bubbleSort();
           void insertionSort();
           void display_I();
           void quickSort(int start,int end);
           void display_Q();
           void linearSearch(float element);
           void binarySearch(string key);
};

void Stud_Info::getData()
{   
    cout<<"enter the no. of Students"<<endl;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {    cout<<"enter the Student rollno:"<<endl;
         cin>>s[i].rno;
         cout<<"enter the Student name:"<<endl;
         cin>>s[i].name;
         cout<<"enter the Student SGPA:"<<endl;
         cin>>s[i].sgpa;
         cout<<"-----------------------------------------------------------"<<endl;
    }
}
void Stud_Info::bubbleSort()
{ 
    int i,j;
    struct Stud temp;
    for(i=0;i<(n-1);i++)
    { 
        for(j=0;j<(n-1-i);j++)
        { 
            if(s[j].rno>s[j+1].rno)
            { 
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void Stud_Info::display_b()
{
    int i;
   // cout<<"ROLL NO:"<<"  "<<"NAME"<<"  "<<"SGPA"<<endl;
    for(i=0;i<n;i++)
    { 
       cout<<"ROLL NO|"<<" "<<s[i].rno<<"  "<<"NAME|"<<" "<<s[i].name<<"  "<<"SGPA|"<<" "<<s[i].sgpa<<endl;
    }
}
void Stud_Info::insertionSort()
{  
    int i,j;
    struct Stud key= s[i]; 
    for(i=1;i<=(n-1);i++)            
    { 
        key=s[i];        
        j=i-1;                          
        while(j>=0 && s[j].name > key.name)            
        { 
           s[j+1]=s[j];
           j--;                                                                            
        }   
        s[j+1]= key;                                       
    }
}
void Stud_Info::display_I()
{  int i;
   for(i=0;i<n;i++)
    { 
       cout<<"NAME|"<<" "<<s[i].name<<"  "<<"ROLL.NO|"<<" "<<s[i].rno<<"  "<<"SGPA|"<<" "<<s[i].sgpa<<endl;
    }
} 
// quicksort 
void Stud_Info:: quickSort(int start,int end)
{
    int i;
    int j;
    int pivot;
    struct Stud temp;
    if(start<end)
    {
        pivot=start;
        i=start;
        j=end;
        while(i<j)
        {
            while((s[i].sgpa >= s[pivot].sgpa) && (i<end))
            {
                i++;
            }
            while(s[j].sgpa < s[pivot].sgpa)
            {
                j--;
            }
            if(i<j)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
        temp=s[pivot];
        s[pivot]=s[j];
        s[j]=temp;
        quickSort(start,j-1);
        quickSort(j+1,end);
    }
}

void Stud_Info::display_Q()
{    int i;
     cout<<"first 10 toppers are:"<<endl;
     for(i=0;i<=10;i++)
     { 
        cout<<"NAME|"<<" "<<s[i].name<<"  "<<"ROLL.NO|"<<" "<<s[i].rno<<"  "<<"SGPA|"<<" "<<s[i].sgpa<<endl;
     }
}

void Stud_Info::linearSearch(float element)
{   int i;
    int found=0;
    for(i=0;i<n;i++)
    { 
        if(s[i].sgpa==element)
        { 
            // cout<<"element found!!"<<endl;
            cout<<"NAME|"<<" "<<s[i].name<<"  "<<"ROLL.NO|"<<" "<<s[i].rno<<"  "<<"SGPA|"<<" "<<s[i].sgpa<<endl;
            found=1;
        }
    }
    if(found==0)
    {  
        cout<<"element not found "<<endl;
    }
}

void Stud_Info::binarySearch(string key)
{ 
     int low=0;
     int high=n - 1;
     int mid; 
     int found=0;                         //low=starting point, high= ending point
     //start searching
     while(low<=high)
     { 
        mid= (low+high)/2;
        if(s[mid].name==key)
        { 
            found=1;
        }
        if(s[mid].name<key)
        {
            low=mid+1;
        }
        else
        { 
            high=mid-1;
        }
     }
        if (found==1)
        {
            cout<<"element found!!"<<endl;
            cout<<"NAME|"<<" "<<s[mid].name<<"  "<<"ROLL.NO|"<<" "<<s[mid].rno<<"  "<<"SGPA|"<<" "<<s[mid].sgpa<<endl;  
        }
        else 
        { 
            cout<<"element not found!!"<<endl;
        }
     
}

int main()
{  float element;
   int choice; 
   string key;
   Stud_Info obj;
   cout<<"choice 1: sorting roll call(ascending order)"<<endl;
   cout<<"choice 2: sorting name alphabetically"<<endl;
   cout<<"choice 3: To know first 10 toppers"<<endl;
   cout<<"choice 4: Search student by its SGPA"<<endl;
   cout<<"choice 5:Search Student by its Name"<<endl;
   cout<<"enter your choice:"<<endl;
   cin>>choice;
   switch(choice)
   { 
    case 1:obj.getData();
           obj.bubbleSort();
           obj.display_b();
           break;

    case 2:obj.getData();  
           obj.insertionSort(); 
           obj.display_I(); 
           break;

    case 3:obj.getData();
           obj.quickSort(0,obj.n-1);
           obj.display_Q();  
           break;

    case 4:obj.getData();
           cout<<"enter the SGPA to be searched:"<<endl;
           cin>>element;
           obj.linearSearch( element);
           break;

    case 5:obj.getData();
           cout<<"enter the name to be searched:"<<endl;
           cin>>key;
           obj.binarySearch(key);
           break;       

    default:
           cout<<"wrong choice"<<endl;       
    
   return 0;
   }
}



   