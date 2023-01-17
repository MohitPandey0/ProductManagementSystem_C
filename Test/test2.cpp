#include <iostream>
#include <fstream>
using namespace std;

ofstream os("linkedList.txt", ios::binary);
ifstream if1("linkedList.txt", ios::binary);

struct link
{
    int data;
    link *next;
};

class linkedList
{
public:
    linkedList();
    void addItem(int);
    void print(void);

private:
    link *first;
};

linkedList::linkedList()
{
    first = NULL;
}

void linkedList::addItem(int n)
{
    link *temp = new link;
    temp->data = n;
    temp->next = first;
    first = temp;
    os.write(reinterpret_cast<char *>(temp), sizeof(temp));
}

void linkedList::print()
{
    for (link *p = first; p != NULL; p = p->next)
    {
        cout << p->data << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        if1.read()
    }
    
}

int main()
{
    int n;

    linkedList ll;

    do
    {
        cout << "Enter number to insert: (-1 to print): ";
        cin >> n;

        ll.addItem(n);
    } while (n != -1);

    ll.print();
    return 0;
}