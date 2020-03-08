#ifndef LINKEDLIST_H_INCLUDED

#define LINKEDLIST_H_INCLUDED

template <class ItemType>

class SortedType

{

struct NodeType

{

ItemType info;

NodeType* next;

};

public:

SortedType();

//~SortedType();
 void makeEmpty();
 int LengthIs();
 void RetrieveItem (ItemType&, bool&);
 void InsertItem(ItemType);
 void DeleteItem(ItemType);
 bool IsEmpty();
 bool IsFull();
 void ResetList();
 void GetNextItem(ItemType&);
private:

NodeType* Ptr;
NodeType* Other_ptr;
NodeType* inptr;

int length;

};

#endif // LINKEDLIST_H_INCLUDED
