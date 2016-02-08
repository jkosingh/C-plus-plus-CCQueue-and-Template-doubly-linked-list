// File:        dlinkedlist.cpp
// Author:      Justin Singh
// Date:        January 18, 2016
// Description: Definition of a implementation  doubly-linked-list class for CMPT 225 assignment 2


#ifdef _LINK_
#include "dlinkedlist.h"
#include "ccqueue.cpp"
#include <iostream>

using namespace std;



 // helper function for deep copy
    // Used by copy constructor and operator=




   template <class T>
   void DLinkedList<T>::CopyList(const DLinkedList& ll)
   {

	   InsertFront(ll.ElementAt(0));

		for (int i = 1; i < ll.Size(); i++)
		{
		   InsertAt(ll.ElementAt(i), i);

		}

	}


    // helper function for deep delete
    // Used by destructor and copy/assignment
    template <class T>
    void DLinkedList<T>::DeleteList()
	{
		Node<T>* cursor = front;

		while(cursor)
		{
			cursor = front->next;
			delete front;
			front = cursor;
		}
		front = NULL;
	}

   // default constructor
    template <class T>
   DLinkedList<T>::DLinkedList()

	{
		size = 0;
		front = NULL;
		back = NULL;
	}

     // copy constructor, performs deep copy of list elements
    template <class T>
    DLinkedList<T>::DLinkedList(const DLinkedList& ll)

	{
		if(ll.Size()> 0)
		{
			CopyList(ll);
		}

	}


   // destructor
	 template <class T>
   DLinkedList<T>::~DLinkedList()
   {
	   DeleteList();
   }


     // MUTATORS

    // Inserts an item at the front of the list
    // POST:  List contains item at position 0
    // PARAM: item = item to be inserted
   template<class T>
 void DLinkedList<T>::InsertFront(T item)
 {
	  Node<T>* insert;
	  insert = new Node<T>;

	 if(front == NULL)
	 {
		insert->data = item;
		insert->next = NULL;
		front = insert;
		back =insert;
		front->prev = NULL;
		size++;
	 }
	 else
	 {
		 insert->data = item;
		 insert->next =front;
		 front->prev = insert;
		 insert->prev = NULL;
		 front = insert;
		 size++;
	 }

 }

  // Inserts an item at the back of the list
    // POST:  List contains item at back
    // PARAM: item = item to be inserted
 template<class T>
 void DLinkedList<T>::InsertBack(T item)
 {
	  Node<T>* insert;
	  insert = new Node<T>;

	  if(front == NULL)
	 {
		insert->data = item;
		insert->next = NULL;
		front = insert;
		back =insert;
		front->prev = NULL;
		size++;
	 }

	  else
	  {
		   insert->data = item;
		   back->next = insert;
		   insert->prev = back;
		   back = insert;
		   back->next = NULL;
		   size++;

	  }

 }

 // Inserts an item in position p (0-indexed)
    // Throws exception for invalid index
    // PRE:   0 <= p <= size
    // POST:  List contains item at position p
    // PARAM: item = item to be inserted, p = position where item will be inserted
  template<class T>
 void DLinkedList<T>::InsertAt(T item, int p)
 {


  try
  {
	  if(front == NULL)
	  {
		  if(p != 0)
		   throw p;

		  InsertFront(item);

	  }

	  if(p > size+1)
		  throw p;


	  if(p == size +1)
	  {
		  InsertBack(item);
	  }


	  Node<T>* insert;
	  insert->data = item;
	  Node<T>* cursor;
	  cursor = front;
	  int counter = 0;

	 while(counter <= p && cursor)
	 {

		if(counter == p)
		{
			insert = new Node<T>;
			cursor ->prev->next = insert;
			insert ->next = cursor;
			insert ->prev = cursor ->prev;
			cursor ->prev = insert;
			size++;

		}
	  counter++;
	  cursor = cursor ->next;
	 }
  }

  catch(int p)
  {
	  cout << " There is no position: " << p << " Invalid index error " << endl;
  }
 }


  // Removes and returns an item from position p (0-indexed)
  // Throws exception if list is empty or index invalid
  // PRE:   0 <= p <= size
  // POST:  Item is removed from list
  // PARAM: p = position from where item will be removed
 template<class T>
 T DLinkedList<T>::RemoveAt(int p)
 {
	 Node<T>* remove, *cursor, *before;
	 T itemReturned;
	try
	{
		if(size == 0)
		throw p;

		if(p >= size)
			throw p;



		//removing front;
		if(p == 0)
		{
			if(size == 1)
			{
				itemReturned = front->data;
				delete front;
				front = NULL;
				back = NULL;
				size--;
			}
			else
			{
				remove = front;
				front = front->next;
				front->prev = NULL;
				remove->next = NULL;
				itemReturned = remove->data;
				delete remove;
				remove = NULL;
				size--;
			}


		}


		//removing back
		else if ( p == size -1)
		{
			remove = back;
			back = back->prev;
			remove->prev = NULL;
			back->next = NULL;
			itemReturned = remove->data;
			delete remove;
			remove = NULL;
			size--;
		}

		//removing in betweens
		else
		{
			int counter = 0;
			cursor = front;

			while (cursor)
			{
				before = cursor->prev;
				if(counter == p)
				{
					remove = cursor;
					cursor = cursor->next;
					cursor->prev = before;
					before->next = remove->next;
					remove->prev = NULL;
					remove->next = NULL;
					itemReturned = remove->data;
					delete remove;
					size--;
					return itemReturned;

				}

				cursor = cursor->next;
				counter++;

			}
		}

		return itemReturned;
	}

	catch(int p)
	{
	    cout<< "ERROR INVALID INDEX"<<endl;
	}

 }

 // Removes duplicates from the list, preserving existing order of remaining items.
    // The first occurrence of any duplicate (relative to the front of the list)
    //   is the one which remains.
    // We have not yet learned about efficiency so you may implement this in any way
    //   as long as the resulting list satisfies the requirement above.
    // PRE:
    // POST:  List contains no duplicates, front and back point to the appropriate nodes
    // PARAM:
	template <class T>
	void DLinkedList<T>::RemoveDuplicates()
	{
		T duplicate;
		int found = 0;
		for(int i = 0; i< size; i++)
		{
			duplicate = ElementAt(i);
			for(int j = i+1; j < size; j++)
			{
				if(duplicate == ElementAt(j))
				{
					RemoveAt(j);
					j--;
				}
			}

		}

	}




  // Returns size of list
    template <class T>
    int  DLinkedList<T>::Size() const
	{
		return size;
	}

	// Returns whether the list is empty
	template <class T>
    bool DLinkedList<T>::IsEmpty() const
	{
		if(front == NULL)
		{
			return true;
		}
		return false;

	}

	// Returns existence of item
	template <class T>
    bool  DLinkedList<T>::Contains(T item) const
	{
		Node<T>* cursor = front;

		while(cursor)
		{
			if(cursor->data == item)
			{
				return true;
			}
			cursor= cursor->next;
		}

		return false;


	}

    // Returns item at index (0-indexed)
    // Throws exception for invalid index
    template <class T>
    T  DLinkedList<T>::ElementAt(int p) const
	{
		Node<T>* cursor;
		cursor = front;
		int count;

		try
		{
		if(p < 0 || p > size)
		{
			throw p;
		}


		while(cursor)
		{
			if(count == p)
			{

				return cursor->data;
			}

			count++;
			cursor = cursor->next;
		}

		}

		catch( int p)
		{
			cout<<"Invalid index at "<< p<<endl;
		}

	}


 //   // OVERLOADED OPERATORS

 //   // overloaded assignment operator
 //   // must work in the following cases:
 //   // list2 = list1 -> general case
 //   // list2 = list2 -> should do nothing
   template <class T>
    DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& ll)
	{
		if(	this != &ll)
		{
			DeleteList();
			CopyList(ll);
		}

		return *this;

	}
#endif
