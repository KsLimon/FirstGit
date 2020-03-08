#include"linkedlist.h"
#include<cstddef>
#include<new>

template <class ItemType>
SortedType<ItemType>::SortedType()
{
    Ptr=NULL;
    Other_ptr=NULL;
    length=0;
}
template <class ItemType>
void SortedType<ItemType>::makeEmpty()
{
    NodeType* location;

while (Ptr != NULL)

{

location= Ptr;

Ptr = Ptr->next;

delete location;

}
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType* location;
    location= new NodeType;
    if(Ptr==NULL)
    {
        location->next=Ptr;
        location->info=item;
        Ptr=location;
        inptr=Ptr;
        Other_ptr=location;
    }
    else
    {
        if(Other_ptr->info<item)
        {
            location->info=item;
            location->next=Other_ptr->next;
            Other_ptr->next=location;
            Other_ptr=location;
        }
        else if(item<Ptr->info)
        {
            location->info=item;
            location->next=Ptr;
            Ptr=location;
            inptr=location;
        }
        else
        {
            for(int i=0; inptr!=Other_ptr; i++)
            {
                inptr=inptr->next;
                if(inptr->info>item || inptr->info==item)
                {
                    location->info=inptr->info;
                    location->next=inptr->next;
                    inptr->info=item;
                    inptr->next=location;
                    if(inptr==Other_ptr)
                        Other_ptr=location;
                    inptr=Ptr;
                    break;
                }
                else
                    continue;
            }
        }
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    item=inptr->info;
    inptr=inptr->next;


}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    inptr=Ptr;
}
template <class ItemType>
bool SortedType<ItemType>::IsEmpty()
{
    if(Ptr==NULL)
        return true;
    else
        return false;
}
template <class ItemType>
bool SortedType<ItemType>::IsFull()
{
 NodeType* location;
 try
 {
 location = new NodeType;
 delete location;
 return false;
 }
 catch(std::bad_alloc& exception)
 {
 return true;
 }
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem (ItemType& item, bool& found)
{
     for(int i=0; i<length; i++)
     {
     if(inptr->info==item)
     {
         found=true;
     }
     else
        {
            inptr=inptr->next;
        }
     }
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType* location;
    location=Ptr;
    if(Ptr->info==item)
    {
        Ptr=Ptr->next;
        inptr=inptr->next;
        location->next=NULL;
        delete location;
        length--;
    }
    else
    {
       while(location!=Other_ptr)
        {
            location=location->next;
            if(location->info==item)
            {
                inptr->next=location->next;
                if(location==Other_ptr)
                {
                    Other_ptr=inptr;
                }
                location->next=NULL;
                delete location;
                length--;
                inptr=Ptr;
            }
            else
            {
                inptr=location;
                continue;
            }
        }
    }
}
