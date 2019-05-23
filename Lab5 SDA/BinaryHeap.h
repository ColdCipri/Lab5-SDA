#pragma once
#include <iostream>
typedef int TElem;

typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool(*Relation)(TPriority p1, TPriority p2);
class BinaryHeap
{
private:
	Element *el; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 
	Relation r;
public:
	BinaryHeap(int cap, Relation r);

	int parent(int i) { return floor((i - 1) / 2); }

	// to get index of left child of node at index i 
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i 
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the minimum element 
	Element extractMin();
	Element extractThird(); 
	Element returnThird();



	void printare();

	// Inserts a new element 'k' 
	void insertKey(Element k);


	void BinaryHeapify1(int i);
	void BinaryHeapify2(int i);

	

};

