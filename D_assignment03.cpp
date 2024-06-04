#include<iostream>
#include <string>
using namespace std;
class Node
{
 public:
   char data;
   Node *next;
};
class stack
{
 public:
   Node*top=NULL;

void push(char value)
 {
 	Node*newNode= new Node;
 	newNode->data=value;
 	newNode->next=top;
 	top=newNode;
 }
 char pop()
 {
     if(isEmpty())
     {
         cout<<"Stack is empty \n";
     }else 
     {
 	    Node*newNode = top; // here just store top in newnode
 	    top = newNode->next; //if we directly remove newnode then we loose our link hence we just store in top
 	    char temp = newNode->data; //here I just store data in temp and return it
 	    delete newNode; //here we just delete newnode i.e. top 
 	    return temp;
    }
 }
 int isEmpty()
   {
 	if(top==NULL)
 	{
 		return 1;
 	}else
 	return 0;
  }  
 };
class expression 
{
    public:
   string infix;
   string prefix="";
   string postfix="";
   stack st;
   
public:
   bool is_operator(char c)
  {
  	if(c=='/'||c=='*'||c=='+'||c=='-')
  	{
  		return true;
  	}else
  	{
  		return false;
  	}
  }
  int priority(char ch)
  {
      if(ch=='^')
  	{
  		return 3;
  	}
  	else if(ch=='/'||ch=='*')
  	{
  		return 2;
  	}else if(ch=='+'||ch=='-')
  	{
  		return 1;
  	
  	}
  	return -1;
  }
  void infix_postfix(string infix)
  {
    for( int i=0 ; i < infix.length() ; i++)
  	{
         if((infix[i] >= 'A' && infix[i] <= 'Z' )||( infix[i] >= 'a' && infix[i] <= 'z'))
  	        {
  		        postfix += infix[i];
  		    }
  		 else if(infix[i]=='(') // opening bracket here hence we apply push condition
  	        {
  		        st.push(infix[i]);
  		        
  	        }
  	     else if(infix[i]==')') // if closing bracket arrived then we siply dose pop op.
  	        {
  	            while(!st.isEmpty() && st.top->data !=  '(')
  		        {
  			        postfix+=st.pop();//we check count how many operator 
                    // we pop until unless we reach to opening bracket
  		        }
  		        if(st.top->data=='(') //if reach to ( then pop it
                {
                     st.pop();
  		        }
  		    }
  	         else if(is_operator(infix[i]))
  	        {
                if(st.isEmpty())
                {
                    st.push(infix[i]);
                }else
                {
                   if( priority(infix[i])>priority(st.top->data))
                   {
                       st.push(infix[i]);
                   }else{
                       while(priority(st.top->data)>priority(infix[i]))
                       {
                           postfix+=st.pop();
                       }
                       st.push(infix[i]);
                   }
                   
                }
                
            }
  	   }
  	    while(!st.isEmpty()) //???
  	    {
  	        postfix+=st.pop();
  	    }
        cout<<"\n";
        cout<<"Postfix Expression is : "<<postfix<<endl;
        cout<<"\n";
    }

    string reversest(string s)// for infix we reverse the expression
    {
        int n = s.length();
        for (int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);//1 5-1-1 =3 
        }
        return s;
    }
    void infix_prefix(string infix)
    {
        string inf=reversest(infix);
        string temp_prefix="";
        for(int i=0;i<inf.length();i++)
        {
            if (inf[i]=='(')
            {
                inf[i]=')';

            }
            else if (inf[i]==')')
            {
                inf[i]='(';
            }
        }
        for(int i=0;i<inf.length();i++)
        {
            if((inf[i] >= 'A' && inf[i] <= 'Z' )||( inf[i] >= 'a' && inf[i] <= 'z'))
  	        {
  		        temp_prefix += inf[i];
  		    } 
  		    else if(inf[i]=='(')//opening bracket
  		    {
  		        st.push(inf[i]);
  		    }
  		    else if(inf[i]==')')
  		    {
  		        while(st.top->data!='('&& !st.isEmpty()  ) //reverse operation just
  		        {
  		            temp_prefix+=st.pop();
  		        }
  		        if(st.top->data=='(')
  		        {
  		            st.pop();
  		        }
  		    }
  		    else if(is_operator(inf[i]))
  		    {
  		        if(st.isEmpty())
  		        {
  		            st.push(inf[i]);
  		        }else
  		        {
  		            if(priority(inf[i])>priority(st.top->data))
  		            {
  		                st.push(inf[i]);//push
  		            }
                    else if(priority(inf[i])==priority(st.top->data)&& inf[i]=='^')
  		            {
  		                while(priority(inf[i])==priority(st.top->data) && inf[i]!='^')
  		                {
  		                    temp_prefix+=st.pop();
  		                }
  		                st.push(inf[i]);
  		            } //
  		            else if(priority(inf[i])==priority(st.top->data))
  		            {
  		                st.push(inf[i]);//push
  		            }
  		            else {
  		                while(!st.isEmpty()&& priority(st.top->data) > priority(inf[i]))
  		                {
  		                    temp_prefix+=st.pop();
                            //when priority of top element is greater then pop
  		                }
                        st.push(inf[i]);
  		            }
  		        }
  		    }
        }
        while(!st.isEmpty())
        {
            temp_prefix+=st.pop();
        }//performing again reverse the temp_prefix 
        prefix=reversest(temp_prefix);
        cout<<"\nPrefix Expression is : "<<prefix<<endl;
        cout<<"\n";
    }
    bool is_char(char ch)
    {
        if(ch >= 'a' && ch<= 'z'||ch >= 'A' && ch<= 'Z')
        {
            return true ;
        }
        else {
            return false;
        }
    }
    bool is_num(char ch)
    {
        if (ch >= '0'&& ch<='9')
        {
            return true;
        }else{
            return false;
        }
    }
    bool is_operand(char ch)
    {
        return is_char(ch) || is_num(ch);
    }
    int postfix_evalution(string postfix)
    {
        for(int i=0;i<postfix.length();i++)
        {
            if(is_operand(postfix[i]))
            {
                int val;
                cout<<"Enter value of : "<<postfix[i]<<" ";
                cin>>val;
                st.push(val);
            }
            else
            {
                int a=st.pop();
                int b=st.pop();
                switch (postfix[i])
                {
                    case '/':
                        st.push(b/a);
                        break;
                        
                    case '*':
                        st.push(b*a);
                        break;
                        
                    case '+':
                        st.push(b+a);
                        break;
                        
                    case '-':
                        st.push(b-a);
                        break;
                }
            }
        }
        int ans =st.pop();
        cout<<"Solution of  "<<postfix<<" is "<<ans<<"\n";
        return ans;
    }
    int prefix_evalution(string prefix)
    {
        for(int i=prefix.length()-1;i>=0;i--)
        {
            if(is_operand(prefix[i]))
            {
                int val;
                cout<<"Enter value of : "<<prefix[i]<<" ";
                cin>>val;
                st.push(val);
            }
            else
            {
                int a=st.pop();
                int b=st.pop();
                switch (prefix[i])
                {
                    case '/':
                        st.push(a/b);
                        break;
                        
                    case '*':
                        st.push(a*b);
                        break;
                        
                    case '+':
                        st.push(a+b);
                        break;
                        
                    case '-':
                        st.push(a-b);
                        break;
                }
            }
        }
        int ans =st.pop();
        cout<<"Solution of  "<<prefix<<" is "<<ans<<"\n";
        return ans;
    }
};
int main()
 {
 	expression e1;
 	string infix;
 	int choice;
 	
 	cout<<"Enter expression : ";
  	cin>>infix;
  	
  	while (choice!=5)
  	{
  	    cout<<"----------------------------------------------------------------------------\n";
  	    cout<<"\n\tSTACK operation\n";
  	    cout<<"1.Infix to Postfix conversion\n2.Postfix evalution\n3.Infix to Prefix conversion\n4.Prefix evalution\n5.exit\n";
  	    cout<<" ENTER CHOICE :\n";
  	    cin>>choice;
  	    switch(choice)
  	    {
  	        case 1:
  	        e1.infix_postfix(infix);
  	        break;
  	        case 2:
  	        e1.postfix_evalution(e1.postfix);
  	        break;
  	        case 3:
  	        e1.infix_prefix(infix);
  	        break;
  	        case 4:
  	        e1.prefix_evalution(e1.prefix);
  	        break;
  	        case 5 :
  	        break;
  	        default:
  	        cout<<"Invalid choice \n";
  	    }
  	}
 	return 0;
 }
 	

















