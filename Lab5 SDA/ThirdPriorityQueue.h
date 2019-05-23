#pragma once
#include <iostream>
#include "BinaryHeap.h"
typedef int TElem;

typedef int TPriority;

typedef std::pair<TElem, TPriority> Element;

typedef bool(*Relation)(TPriority p1, TPriority p2);


class ThirdPriorityQueue {
private:
	Relation r;
	BinaryHeap *elems;
	int capacity;
	int len;
public:
	//implicit constructor
	ThirdPriorityQueue(Relation r);

	//adds an element with a priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the third highest priority with respect to the relation
   //throws exception if the queue has less than 3 elements
	Element top()  const;

	//removes and returns the element with the third highest priority
	//throws exception if the queue has less than 3 elements
	Element pop();

	//checks if the queue has at most two elements
	bool atMostTwo() const;

	//destructor
	~ThirdPriorityQueue();
};
