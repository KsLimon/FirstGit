#include <iostream>
#include"linkedlist.cpp"

using namespace std;

int main()
{
    SortedType <int> o;
    SortedType <int> p;
    if(o.IsEmpty()==true)
        cout<<"List is empty."<<endl;
    else
        cout<<"List is not empty."<<endl;
    for(int i=0; i<5; i++)
    {
        int x;
        cin>>x;
        o.InsertItem(x);
    }
    cout<<"Print"<<endl;
    o.ResetList();
    for(int i=0; i<5; i++)
    {
        int l;
        o.GetNextItem(l);
        cout<<l<<" ";
    }
    cout<<endl;
    if(o.IsFull()==true)
        cout<<"List is Full"<<endl;
    else
        cout<<"List is not Full."<<endl;

    cout<<"Enter value if u want to search: "<<endl;
    int L;
    bool found;
    cin>>L;
    o.ResetList();
    o.RetrieveItem(L, found);
    if(found)
        cout<<"Item is found."<< endl;
    else
        cout<< "Item is not found."<<endl;

    o.ResetList();
    int d;
    cout<< "Enter a value to delete: "<<endl;
    cin>>d;
    o.DeleteItem(d);
    o.ResetList();
    cout<< "After deleted: "<<endl;
    for(int i=0; i<5; i++)
    {
        int l;
        o.GetNextItem(l);
        cout<<l<<" ";
    }

}
