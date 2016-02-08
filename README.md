# C++-CCQueue/Generic-doubly-linked-list

 a CCQueue class modeling a simple queue for an online computer equipment retailer's customer service department with many angry customers. The data storage of the CCQueue is a doubly-linked list template class.

DLinkedList class also throws exceptions on invalid inputs such as list indices out or bounds to give the user feedback if they try to do something harmful to the program.

CCQueue contains a private DLinkedList member with a Ticket template type (provided in ticket.h and ticket.cpp). The CCQueue public functions interact with the ticket queue using calls to DLinkedList methods.
