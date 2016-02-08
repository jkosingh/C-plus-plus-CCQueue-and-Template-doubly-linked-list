// File:        dlinkedlist.cpp
// Author:      Justin Singh
// Date:        January 18, 2016
// Description: Testing for CMPT 225 assignment 2


#include <cstdlib>
#include <iostream>
#include <string>

#include "ccqueue.h"
#include "dlinkedlist.h"
#include "ticket.h"

using namespace std;


// forward function declarations
void Copytest();
void InsertTest();

void RemoveTest();
void RemoveDupTest();

void AccessorTest();
void AssignOpTest();

void LLTest();
void LLTest2();

void CCQTest();
void CCQTest2();


// program entry point
int main()
{
	cout << "Testing Functions... " << endl;
	
	Copytest();
	InsertTest();

	RemoveTest();
	RemoveDupTest();

	AccessorTest();
	AssignOpTest();

	cout << "Entering DLinkedList test function... " << endl << endl;
	LLTest();
	LLTest2();
	cout << "... DLinkedList test function complete!\n" << endl;

	cout << "Entering CCQueue test function... " << endl;
	CCQTest();
	CCQTest2();
	cout << "... CCQueue test function complete!\n" << endl;


	system("pause");
	return 0;
}


void Copytest()
{
	cout << "---------------------------------COPYTEST------------------------------------" << endl;

	DLinkedList<string> ll;
	
	cout << "Initial List" << endl;
	ll.InsertAt("One", 0);
	ll.InsertFront("Hat");
	ll.InsertFront("AB");
	ll.InsertBack("Top");
	ll.InsertBack("S");
	for (int i = 0;i < ll.Size();i++) { cout << i << " | " << ll.ElementAt(i) << endl; }
	cout << "List contains " << ll.Size() << " items." << endl;
	cout << endl;
	cout << "Make Copy1" << endl;

	DLinkedList<string> Copy1(ll);

	for (int i = 0;i < Copy1.Size();i++) { cout << i << " | " << Copy1.ElementAt(i) << endl; }
	cout << "List contains " << Copy1.Size() << " items." << endl << endl;
	cout << "Remove First and Last of Copy1" << endl;
	Copy1.RemoveAt(4);
	Copy1.RemoveAt(0);
	for (int i = 0;i < Copy1.Size();i++) { cout << i << " | " << Copy1.ElementAt(i) << endl; }
	cout << "List contains " << Copy1.Size() << " items." << endl << endl;


	DLinkedList<string> Copy2(Copy1);

	cout << "Make Copy2 of Copy1" << endl;
	for (int i = 0;i < Copy2.Size();i++) { cout << i << " | " << Copy2.ElementAt(i) << endl; }
	cout << "List contains " << Copy2.Size() << " items." << endl << endl;
	cout << "Remove All Elements of Copy2" << endl;
	Copy2.RemoveAt(0);
	Copy2.RemoveAt(0);
	Copy2.RemoveAt(0);
	for (int i = 0;i < Copy2.Size();i++) { cout << i << " | " << Copy2.ElementAt(i) << endl; }
	cout << "List contains " << Copy2.Size() << " items." << endl << endl;
	Copy2.InsertBack("2"); //Cant Destory Empty List some HOW?

	DLinkedList<string> Empty;
	cout << "Empty List" << endl;
	for (int i = 0;i < Empty.Size();i++) { cout << i << " | " << Empty.ElementAt(i) << endl; }
	cout << "List contains " << Empty.Size() << " items." << endl << endl;

	DLinkedList<string> CopyE(Empty);
	cout << "Copy Empty List" << endl;
	for (int i = 0;i < CopyE.Size();i++) { cout << i << " | " << CopyE.ElementAt(i) << endl; }
	cout << "List contains " << CopyE.Size() << " items." << endl << endl;

	cout << "[End of Copy Test]" << endl << endl;

	DLinkedList<string> CopyE1;

}

void InsertTest()
{
	cout << "---------------------------------InsertTEST---------------------------------" << endl;

	DLinkedList<double> L;
	
	cout << "Insert Items" << endl;
	L.InsertFront(100);
	L.InsertFront(10);
	L.InsertFront(1);
	L.InsertBack(2);
	L.InsertBack(20);
	L.InsertBack(200);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl;
	cout << endl;

	cout << "Insert  More Items" << endl;
	L.InsertAt(2.101, 0);
	L.InsertAt(3.999, 0);
	L.InsertAt(4.154, 0);
	L.InsertAt(-5543, 1);
	L.InsertAt(999, 5);
	L.InsertAt(-999.99, 3);
	L.InsertAt(300.01, 9);
	L.InsertAt(546.21, 10);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl;
	cout << endl;

	cout << "Insert At End Index (Check for Proper Index of Last items)" << endl;
	L.InsertAt(777, 13);
	L.InsertAt(999, 14);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl;
	cout << endl;

	//Exception Handling for Insert Functions
	try{cout << "ERROR TEST: Insert At 12345 (Out of Range)" << endl; L.InsertAt(0, 12345);}
	catch (exception e){cout << "Exception in InsertAt(): " << e.what() << endl << endl;}
	try{cout << "ERROR TEST: Insert At -1 (Out of Range)" << endl; L.InsertAt(0, -1);}
	catch (exception e){cout << "Exception in InsertAt(): " << e.what() << endl << endl;}
	try { cout << "ERROR TEST: Insert At Number of Size (Not Out of Range?)" << endl << endl; L.InsertAt(1231, 16); }
	catch (exception e) { cout << "Exception in InsertAt(): " << e.what() << endl << endl; }

	cout << "Final List" << endl;
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl;
	cout << endl;

	cout << "[END of INSERT TEST]" << endl << endl;
}

void RemoveTest()
{
	cout << "---------------------------------RemoveTEST---------------------------------" << endl;

	DLinkedList<int> L;
	DLinkedList<int> L2;

	cout << "List Add" << endl;
	L.InsertBack(1);
	L.InsertBack(0);
	L.InsertBack(1);
	L.InsertBack(2);
	L.InsertBack(3);
	L.InsertBack(4);
	L.InsertBack(5);
	L.InsertBack(6);
	L.InsertBack(7);
	L.InsertBack(8);
	L.InsertBack(9);
	L.InsertBack(10);
	L.InsertBack(100);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl << endl;

	cout << "Remove Front" << endl;
	L.RemoveAt(0);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl << endl;

	cout << "Remove Back" << endl;
	L.RemoveAt(11);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl << endl;

	cout << "Remove x6 in Middle" << endl;
	L.RemoveAt(2);
	L.RemoveAt(6);
	L.RemoveAt(2);
	L.RemoveAt(7);
	L.RemoveAt(3);
	L.RemoveAt(2);
	for (int i = 0;i < L.Size();i++) { cout << i << " | " << L.ElementAt(i) << endl; }
	cout << "List contains " << L.Size() << " items." << endl << endl;

	//Exception Handling for RemoveAt()
	try { cout << "ERROR TEST: Remove At 12345 (Out of Range)" << endl; L.RemoveAt(12345); }
	catch (exception e){cout << "Exception in RemoveAt(): " << e.what() << endl << endl;}
	try { cout << "ERROR TEST: Remove At -10 (Out of Range)" << endl; L.RemoveAt(-10); }
	catch (exception e) { cout << "Exception in RemoveAt(): " << e.what() << endl << endl; }
	try { cout << "ERROR TEST: Remove At Number of Size (Out of Range)" << endl; L.RemoveAt(5); }
	catch (exception e) { cout << "Exception in RemoveAt(): " << e.what() << endl << endl; }
	try { cout << "ERROR TEST: Remove Empty List" << endl; L2.RemoveAt(0); }
	catch (exception e) { cout << "Exception in RemoveAt(): " << e.what() << endl << endl; }

	cout << "List with 1 Node" << endl;
	L2.InsertFront(1);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;
	cout << "Remove List with 1 Node" << endl;
	L2.RemoveAt(0);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;

	cout << "List with 2 Node" << endl;
	L2.InsertFront(777);
	L2.InsertFront(10);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;
	cout << "Remove Front" << endl;
	L2.RemoveAt(0);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;
	L2.RemoveAt(0);

	cout << "List with 2 Node" << endl;
	L2.InsertFront(4);
	L2.InsertFront(7);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;
	cout << "Remove Back" << endl;
	L2.RemoveAt(1);
	for (int i = 0;i < L2.Size();i++) { cout << i << " | " << L2.ElementAt(i) << endl; }
	cout << "List contains " << L2.Size() << " items." << endl << endl;

	cout << "[END of Remove TEST]" << endl << endl;
}

void RemoveDupTest()
{
	cout << "--------------------------------RemoveDupTEST---------------------------------" << endl;

	DLinkedList<string> list;

	cout << "List Dup Remove Stress Test" << endl;
	list.InsertBack("A");
	list.InsertBack("A");
	list.InsertBack("A");
	list.InsertBack("Bill");
	list.InsertBack("A");
	list.InsertBack("Hill");
	list.InsertBack("A");
	list.InsertBack("Bill");
	list.InsertFront("A");
	list.InsertFront("A");
	list.InsertFront("Tree");
	list.InsertAt("A",2);
	list.InsertAt("A", 2);
	list.InsertAt("Pop", 6);
	list.InsertBack("Tree");
	list.InsertBack("A");
	list.InsertBack("A");
	list.InsertBack("A");
	list.InsertBack("Bill");
	list.InsertBack("A");
	list.InsertBack("Hill");
	list.InsertBack("A");
	list.InsertBack("Bill");
	list.InsertFront("A");
	list.InsertFront("A");
	list.InsertFront("Tree");
	list.InsertAt("A", 2);
	list.InsertAt("A", 2);
	list.InsertAt("Pop", 6);
	list.InsertBack("Tree");

	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List contains " << list.Size() << " items." << endl << endl;
	list.RemoveDuplicates();
	cout << "Remove Dups" << endl;
	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List contains " << list.Size() << " items." << endl << endl;

	DLinkedList<char> list2;

	list2.InsertBack('+');
	list2.InsertBack('-');
	list2.InsertBack('*');
	list2.InsertBack('<');
	list2.InsertBack('>');
	list2.InsertFront('+');
	list2.InsertBack('&');
	list2.InsertBack('^');
	list2.InsertBack('%');
	list2.InsertBack('!');
	list2.InsertBack('`');
	list2.InsertBack('~');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('-');
	list2.InsertBack('*');
	list2.InsertBack('<');
	list2.InsertBack('>');
	list2.InsertFront('+');
	list2.InsertBack('&');
	list2.InsertBack('^');
	list2.InsertBack('%');
	list2.InsertBack('!');
	list2.InsertBack('`');
	list2.InsertBack('~');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertBack('$');
	list2.InsertAt('+',9);
	list2.InsertAt('+', 9);
	list2.InsertAt('+', 9);
	list2.InsertAt('+', 9);
	list2.InsertAt('+', 9);
	list2.InsertAt('+', 9);
	list2.InsertAt('+', 10);

	cout << "List 2" << endl;
	for (int i = 0;i < list2.Size();i++) { cout << i << " | " << list2.ElementAt(i) << endl; }
	cout << "List contains " << list2.Size() << " items." << endl << endl;
	list2.RemoveDuplicates();
	cout << "Remove Dups" << endl;
	for (int i = 0;i < list2.Size();i++) { cout << i << " | " << list2.ElementAt(i) << endl; }
	cout << "List contains " << list2.Size() << " items." << endl << endl;

	DLinkedList<char> list3(list2);

	list3.RemoveAt(0);
	list3.RemoveAt(0);
	cout << "List 3 (copy of list 2 with 2 front removed)" << endl;
	for (int i = 0;i < list3.Size();i++) { cout << i << " | " << list3.ElementAt(i) << endl; }
	cout << "List contains " << list3.Size() << " items." << endl << endl;
	cout << "Remove Dups x2" << endl;
	list3.RemoveDuplicates();
	list3.RemoveDuplicates();
	for (int i = 0;i < list3.Size();i++) { cout << i << " | " << list3.ElementAt(i) << endl; }
	cout << "List contains " << list3.Size() << " items." << endl << endl;

	DLinkedList<int> list4;

	list4.InsertFront(1);
	list4.InsertFront(1);
	list4.InsertFront(1);
	list4.InsertFront(1);
	cout << "List 4" << endl;
	for (int i = 0;i < list4.Size();i++) { cout << i << " | " << list4.ElementAt(i) << endl; }
	cout << "List contains " << list4.Size() << " items." << endl << endl;
	cout << "Remove Dups" << endl;
	list4.RemoveDuplicates();
	for (int i = 0;i < list4.Size();i++) { cout << i << " | " << list4.ElementAt(i) << endl; }
	cout << "List contains " << list4.Size() << " items." << endl << endl;

	cout << "[END Remove Dup Test]" << endl;
}

void AccessorTest()
{
	cout << "-------------------------------AccessorTest------------------------------------" << endl;

	DLinkedList<int> list;
	DLinkedList<int> list2;

	cout << "Create Empty List" << endl;
	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List contains " << list.Size() << " items." << endl;
	if (list.IsEmpty() == true) { cout << "Empty List" << endl; }
	else { cout << "NOT Empty" << endl; }

	list.InsertAt(7,0);
	list.InsertBack(7);
	list.InsertFront(80);
	list.InsertBack(-100);
	list.InsertAt(4, 3);

	cout << endl << "Insert Numbers" << endl;
	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List contains " << list.Size() << " items." << endl;
	if (list.IsEmpty() == true) { cout << "Empty List" << endl; }
	else { cout << "NOT Empty" << endl; }
	cout <<"Element At Index 0: " << list.ElementAt(0) << endl << endl;

	cout << "Contain Test" << endl;
	cout << "List Contains 7: ";
	if (list.Contains(7) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }
	cout << "List Contains 52: ";
	if (list.Contains(52) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }
	cout << "List Contains 999: ";
	if (list.Contains(999) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }
	cout << "List Contains -2: ";
	if (list.Contains(-2) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }
	cout << "List Contains 80: ";
	if (list.Contains(80) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }
	cout << "List Contains -100: ";
	if (list.Contains(-100) == true) { cout << "Yes" << endl; }
	else { cout << "NO" << endl; }

	cout << endl << "Element Error Tests" << endl;
	try { cout << "ERROR TEST: Element At 12345 (Out of Range)" << endl; list.ElementAt(12345); }
	catch (exception e) { cout << "Exception in ElementAt(): " << e.what() << endl << endl; }

	try { cout << "ERROR TEST: Element At -5 (Out of Range)" << endl; list.ElementAt(-5); }
	catch (exception e) { cout << "Exception in ElementAt(): " << e.what() << endl << endl; }

	try { cout << "ERROR TEST: Element At Empty List (Out of Range)" << endl; list2.ElementAt(0); }
	catch (exception e) { cout << "Exception in ElementAt(): " << e.what() << endl << endl; }

	try { cout << "ERROR TEST: Contain of Empty List (Out of Range)" << endl; list2.Contains(12); }
	catch (exception e) { cout << "Exception in Contains(): " << e.what() << endl << endl; }

	cout << "[END Accessors Test]" << endl << endl;
}

void AssignOpTest()
{
	cout << "------------------------------AssignmentOpTest----------------------------------" << endl;

	DLinkedList<string> list;

	cout << "Create List A" << endl;
	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List A contains " << list.Size() << " items." << endl;
	if (list.IsEmpty() == true) { cout << "Empty List" << endl; }
	else { cout << "NOT Empty" << endl; }

	cout << endl << "Insert Items to List A" << endl;
	list.InsertFront("B");
	list.InsertFront("S");
	list.InsertBack("A");
	list.InsertBack("Z");
	list.InsertBack("T");
	list.InsertBack("P");
	list.InsertBack("O");

	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List A contains " << list.Size() << " items." << endl;
	if (list.IsEmpty() == true) { cout << "Empty List" << endl; }
	else { cout << "NOT Empty" << endl; }

	DLinkedList<string> listB;

	cout << endl << "Create List B" << endl;
	cout << "Assign List A to Empty List B" << endl;
	listB = list;
	for (int i = 0;i < listB.Size();i++) { cout << i << " | " << listB.ElementAt(i) << endl; }
	cout << "List B contains " << listB.Size() << " items." << endl;
	if (listB.IsEmpty() == true) { cout << "Empty List" << endl; }
	else { cout << "NOT Empty" << endl; }

	cout << endl << "Insert items into B" << endl;
	listB.InsertBack("Pop");
	listB.InsertFront("Jima");
	listB.InsertFront("Tree");
	listB.InsertFront("Tex");
	listB.InsertFront("Moon");
	for (int i = 0;i < listB.Size();i++) { cout << i << " | " << listB.ElementAt(i) << endl; }
	cout << "List B contains " << listB.Size() << " items." << endl;

	DLinkedList<string> listC;

	cout << endl << "Create List C" << endl;
	cout << "Insert Items to List C" << endl;
	listC.InsertFront("ZZZZZ");
	listC.InsertFront("ZZZZ");
	listC.InsertFront("ZZZ");
	listC.InsertFront("ZZ");
	listC.InsertFront("Z");
	listC.InsertBack("ZZZZ");
	listC.InsertBack("ZZZ");
	listC.InsertBack("ZZ");
	listC.InsertBack("Z");
	cout << "List C" << endl;
	for (int i = 0;i < listC.Size();i++) { cout << i << " | " << listC.ElementAt(i) << endl; }
	cout << "List C contains " << listC.Size() << " items." << endl;

	cout << endl << "Assign List B to List C Containing Elements" << endl;
	listC = listB;
	for (int i = 0;i < listC.Size();i++) { cout << i << " | " << listC.ElementAt(i) << endl; }
	cout << "List C contains " << listC.Size() << " items." << endl << endl;

	DLinkedList<string> one;

	cout << "Create List of One" << endl;
	one.InsertAt("V", 0);
	for (int i = 0;i < one.Size();i++) { cout << i << " | " << one.ElementAt(i) << endl; }
	cout << "One contains " << one.Size() << " items." << endl << endl;

	cout << "Assign one to All lists" << endl;

	list = listB = listC = one;

	cout << "List A" << endl;
	for (int i = 0;i < list.Size();i++) { cout << i << " | " << list.ElementAt(i) << endl; }
	cout << "List A contains " << list.Size() << " items." << endl << endl;
	cout << "List B" << endl;
	for (int i = 0;i < listB.Size();i++) { cout << i << " | " << listB.ElementAt(i) << endl; }
	cout << "List B contains " << listB.Size() << " items." << endl << endl;
	cout << "List C" << endl;
	for (int i = 0;i < listC.Size();i++) { cout << i << " | " << listC.ElementAt(i) << endl; }
	cout << "List C contains " << listC.Size() << " items." << endl << endl;


	DLinkedList<long double> x;
	DLinkedList<long double> y;

	cout << "Create Empty List X and Y" << endl;
	cout << "Insert into x" << endl;
	x.InsertBack(9.9999);
	cout << "List x" << endl;
	for (int i = 0;i < x.Size();i++) { cout << i << " | " << x.ElementAt(i) << endl; }
	cout << "List x contains " << x.Size() << " items." << endl << endl;

	cout << "Assign y (Empty list) to x" << endl;
	x = y;
	cout << "List x" << endl;
	for (int i = 0;i < x.Size();i++) { cout << i << " | " << x.ElementAt(i) << endl; }
	cout << "List x contains " << x.Size() << " items." << endl << endl;

	cout << "[END Assignment Operator Test]" << endl << endl;
}

void LLTest()
{
	DLinkedList<int> ll2;

	//DUP STRESS TEST
	ll2.InsertFront(52);
	ll2.InsertBack(5);
	ll2.InsertBack(5);
	ll2.InsertBack(52);
	ll2.InsertBack(5);
	ll2.InsertBack(5);
	ll2.InsertBack(5);
	cout << "Remove Dup Stress Test 2" << endl;
	for (int i = 0;i < ll2.Size();i++) { cout << i << " | " << ll2.ElementAt(i) << endl; }
	cout << "ll2 contains " << ll2.Size() << " items." << endl << endl;
	ll2.RemoveDuplicates();
	cout << "Result" << endl;
	for (int i = 0;i < ll2.Size();i++) { cout << i << " | " << ll2.ElementAt(i) << endl; }
	cout << "ll2 contains " << ll2.Size() << " items." << endl;
	cout << endl;


	cout << "----------------------------------------Test------------------------------------" << endl;

	DLinkedList<int> lld;

	//Remove only 1 test
	lld.InsertFront(7);
	cout << "Insert 7 at index 0" << endl;
	for (int i = 0;i < lld.Size();i++) { cout << i << " | " << lld.ElementAt(i) << endl; }
	if (lld.IsEmpty() == true) { cout << "empty" << endl; }
	else { cout << "NOT empty" << endl; }
	cout << endl;

	lld.RemoveAt(0);

	cout << "Remove 1" << endl;
	cout << "Size: " << lld.Size() << endl;
	if (lld.IsEmpty() == true) { cout << "empty" << endl; }
	else { cout << "NOT empty" << endl; }
	cout << endl;
	
	try{int temp = lld.RemoveAt(12345);}
	catch (exception e){cout << "Exception in RemoveAt(): " << e.what() << endl << endl;}
	try{lld.InsertAt(0, 12345);}
	catch (exception e){cout << "Exception in InsertAt(): " << e.what() << endl << endl;}

	lld.InsertBack(0);
	cout << "[END Test 1]" << endl << endl;
}

void LLTest2()
{
	cout << "-----------------------------------A--------------------------------------" << endl;

	// default constructor, InsertFront, InsertBack, ElementAt
	DLinkedList<int> lla;

	//EMPTY TEST
	if (lla.IsEmpty() == true) { cout << "Empty" << endl; }
	else { cout << "NOT empty" << endl; }

	//INSERT TESTS
	lla.InsertAt(98, 0);
	lla.InsertAt(45, 0);
	lla.InsertFront(52);
	lla.InsertFront(5);
	lla.InsertFront(12);
	lla.InsertBack(333);
	lla.InsertBack(52);
	lla.InsertBack(11);
	lla.InsertAt(88, 2);
	lla.InsertAt(828, 8);

	//INDEX TEST
	for (int i = 0;i < lla.Size();i++) { cout << i << " | " << lla.ElementAt(i) << endl; }
	cout << "lla contains " << lla.ElementAt(1) << " at index 1." << endl;

	//EMPTY TEST 2
	if (lla.IsEmpty() == true) { cout << "Empty" << endl; }
	else { cout << "NOT empty" << endl; }

	//SIZE TEST
	cout << "Size: " << lla.Size() << endl;

	//CONTAIN TEST
	if (lla.Contains(52) == true) { cout << "52: Yes" << endl; }
	else { cout << "52: NO" << endl; }
	//CONTAIN TEST 2
	if (lla.Contains(9999) == true) { cout << "9999: Yes" << endl; }
	else { cout << "9999: NO" << endl; }

	// REMOVE TEST
	cout << endl << "Remove 3" << endl;
	lla.RemoveAt(0); //front
	lla.RemoveAt(6); //back
	lla.RemoveAt(3);//Middle

	for (int i = 0;i < lla.Size();i++) { cout << i << " | " << lla.ElementAt(i) << endl; }
	cout << "Size: " << lla.Size() << endl;
	cout << "lla contains " << lla.ElementAt(4) << " at index 4." << endl;

	cout << "----------------------------------------B------------------------------------" << endl;

	//COPY CONSTRUCTOR
	DLinkedList<int> llb(lla);

	//DUP STRESS TEST
	llb.InsertFront(52);
	llb.InsertBack(5);
	llb.InsertBack(5);
	llb.InsertBack(52);
	llb.InsertBack(5);
	llb.InsertBack(5);
	llb.InsertBack(5);

	cout << "List B Copy of A + Items" << endl;
	for (int i = 0;i < llb.Size();i++) { cout << i << " | " << llb.ElementAt(i) << endl; }
	cout << "llb contains " << llb.Size() << " items." << endl;

	llb.RemoveDuplicates();
	cout << "Remove Dup" << endl;
	for (int i = 0;i < llb.Size();i++) { cout << i << " | " << llb.ElementAt(i) << endl; }
	cout << "llb contains " << llb.Size() << " items." << endl;
	cout << endl;

	llb.RemoveAt(0);
	cout << "Remove At index 0" << endl;
	for (int i = 0;i < llb.Size();i++) { cout << i << " | " << llb.ElementAt(i) << endl; }
	cout << "llb contains " << llb.Size() << " items." << endl;
	cout << endl;

	cout << "-----------------------------------C--------------------------------------" << endl;

	// assignment operator, IsEmpty, Size, RemoveDuplicates, Contains
	DLinkedList<int> llc;

	if (llc.IsEmpty()){cout << "List C is Empty." << endl;}
	else { cout << "List C is not empty." << endl; }
	llc.InsertBack(15);

	//ASSIGNMENT OPERATOR
	cout << "ASSIGN A to C" << endl;
	llc = lla;

	cout << "LIST C" << endl;
	for (int i = 0;i < llc.Size();i++) { cout << i << " | " << llc.ElementAt(i) << endl; }
	cout << endl << "LIST A" << endl;
	for (int i = 0;i < lla.Size();i++) { cout << i << " | " << lla.ElementAt(i) << endl; }
	cout << endl;

	cout << "INSERT into C" << endl;

	llc.InsertBack(3);
	llc.InsertBack(2);
	llc.InsertBack(7);
	llc.InsertBack(15);
	llc.InsertBack(131);
	llc.InsertBack(132);
	llc.InsertBack(13);
	llc.InsertBack(22);
	llc.InsertBack(13);
	llc.InsertBack(999);
	llc.InsertBack(323);
	llc.InsertBack(88);
	llc.InsertBack(88);

	for (int i = 0;i < llc.Size();i++) { cout << i << " | " << llc.ElementAt(i) << endl; }
	if (llc.Contains(10)) { cout << "10 found in C." << endl; }
	else { cout << "10 not found in llc." << endl; }
	if (llc.Contains(13)) { cout << "13 found in C." << endl; }
	else { cout << "13 not found in llc." << endl; }

	cout << endl << "Remove Duplicates" << endl;
	llc.RemoveDuplicates();
	for (int i = 0;i < llc.Size();i++) { cout << i << " | " << llc.ElementAt(i) << endl; }
	cout << endl;

	cout << "[End Test 2]" << endl;
}

void CCQTest()
{
	CCQueue ccq;

	ccq.Add("Alrikr", "Video card smoked");
	ccq.Add("Bjornstjerne", "Received wrong colour cable");
	ccq.Add("Cyprianus", "Motherboard DOA");
	ccq.Add("Dietrich", "Order not received");
	ccq.Add("Elisaeus", "Only 931GB on 1TB hard drive");
	cout << ccq.PrintStatus() << endl;
	cout << "Size of ticket queue: " << ccq.Size() << endl;

	ccq.Service();

	cout << ccq.PrintStatus() << endl;

	CCQueue ccq2;

	ccq2.Add("0", "0");
	ccq2.Add("1", "1");
	ccq2.Add("2", "2");
	ccq2.Add("3", "3");
	ccq2.Add("4", "4");
	ccq2.Add("5", "5");

	cout << ccq2.PrintStatus() << endl;
	ccq2.MoveUp(3);

	cout << ccq2.PrintStatus() << endl;
	ccq2.MoveUp(2);

	cout << ccq2.PrintStatus() << endl;
	ccq2.MoveDown(2);

	cout << ccq2.PrintStatus() << endl;
	ccq2.MoveDown(0);

	cout << ccq2.PrintStatus() << endl;
	cout << endl;

	ccq2.Service();
	ccq2.Service();
	ccq2.Service();
	ccq2.Service();
	ccq2.Service();
	ccq2.Service();
	cout << ccq2.PrintStatus() << endl << endl;

	ccq2.Add("0", "0");

	cout << ccq2.PrintStatus() << endl << endl;
}

void CCQTest2()
{
	cout << "------------------------------CCQTest2--------------------------------" << endl;

	CCQueue ccq;

	ccq.Add("A", "Luna");
	ccq.Add("B", "Colour");
	ccq.Add("C", "Mother");
	ccq.Add("D", "Order");
	ccq.Add("E", "Drive");
	cout << ccq.PrintStatus() << endl;
	cout << "Size of ticket queue: " << ccq.Size() << endl << endl;

	cout << "Empty Input Test" << endl;
	if (ccq.Add("A", "") == false) { cout << "Empty String input" << endl; }
	else { cout << "Inserted" << endl; }
	if (ccq.Add("", "B") == false) { cout << "Empty String input" << endl; }
	else { cout << "Inserted" << endl; }
	if (ccq.Add("", "") == false) { cout << "Empty String input" << endl; }
	else { cout << "Inserted" << endl; }

	cout << endl << "Remove all Items" << endl;
	ccq.Service();
	ccq.Service();
	ccq.Service();
	ccq.Service();
	ccq.Service();

	cout << ccq.PrintStatus() << endl;
	try { cout << endl << "ERROR TEST: Service Empty List" << endl; ccq.Service(); }
	catch (exception e) { cout << "Exception in Service(): " << e.what() << endl << endl; }

	cout << "Add New Items" << endl;
	ccq.Add("A1", "Luna");
	ccq.Add("B2", "Colour");
	ccq.Add("C3", "Mother");
	ccq.Add("D4", "Order");
	ccq.Add("E5", "Drive");
	cout << ccq.PrintStatus() << endl;

	ccq.MoveUp(4);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveUp(3);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveUp(2);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveUp(1);
	cout << ccq.PrintStatus() << endl;

	ccq.MoveDown(0);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveDown(1);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveDown(2);
	cout << ccq.PrintStatus() << endl;
	ccq.MoveDown(3);
	cout << ccq.PrintStatus() << endl;

	if (ccq.MoveUp(0) == false) { cout << "Move Up at Index 0: Out of Range" << endl; }
	if (ccq.MoveUp(-8) == false) { cout << "Move Up at Index -8: Out of Range" << endl; }
	if (ccq.MoveUp(123) == false) { cout << "Move Up at Index 123: Out of Range" << endl; }
	if (ccq.MoveUp(5) == false) { cout << "Move Up at Index 5: Out of Range" << endl; }
	if (ccq.MoveUp(ccq.Size()) == false) { cout << "Move Up at Index size(): Out of Range" << endl; }
	cout << endl;
	if (ccq.MoveDown(9999) == false) { cout << "Move Up at Index 9999: Out of Range" << endl; }
	if (ccq.MoveDown(-8) == false) { cout << "Move Up at Index -8: Out of Range" << endl; }
	if (ccq.MoveDown(123) == false) { cout << "Move Up at Index 123: Out of Range" << endl; }
	if (ccq.MoveDown(4) == false) { cout << "Move Up at Index 4: Out of Range" << endl; }
	if (ccq.MoveDown(ccq.Size()) == false) { cout << "Move Up at Index size(): Out of Range" << endl; }

	cout << endl;
}
