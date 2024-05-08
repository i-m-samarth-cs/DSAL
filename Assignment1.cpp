#include <iostream>
#include <cstring>
using namespace std;

struct data
{
    char name[30];
    long teleno;
};

class Hash1
{
public:
    int n, sum, x, c, j;
    char na[30];
    long no;
    struct data d[10];

    Hash1()
    {
        for (int i = 0; i < 10; i++)
        {
            d[i].teleno = 0;
        }
    }

    void insert()
    {
        cout << "\nenter no. of clients: ";
        cin >> n;
        for (j = 0; j < n; j++)
        {
            cout << "\nenter name of client: ";
            cin >> na;
            cout << "enter telephone no. of client: ";
            cin >> no;
            sum = 0;
           
            x = (strlen(na)) % 10;  //Hash Function
            cout << x;
            c = x;
            while (1)
            {
                if (d[x].teleno == 0)
                {
                    strcpy(d[x].name, na);
                    d[x].teleno = no;
                    break;
                }
                x = (x + 1) % 10;
                if (c == x)
                {
                    cout << "\nhash table is full";
                    break;
                }
            }
        }
    }

    void search()
    {
        cout << "\nenter name to be searched: ";
        cin >> na;
        sum = 0;
        x = (strlen(na)) % 10;
        c = x;
        while (1)
        {
            if (!strcmp(d[x].name, na))
            {
                cout << "\ndata found: TELEPHONE NO: " << d[x].teleno;
                break;
            }
            x = (x + 1) % 10;
            if (c == x)
            {
                cout << "\ndata not found";
                break;
            }
        }
    }

    void display()
    {
        cout << "\nClient Details:\n";
        for (int i = 0; i < 10; i++)
        {
            if (d[i].teleno != 0)
            {
                cout << d[i].name << " " << d[i].teleno << endl;
            }
        }
    }
};

int main()
{
    Hash1 h;
    h.insert();
    h.search();
    h.display();
    return 0;
}

