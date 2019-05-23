#include "BinaryHeap.h"
#include <iostream>
using namespace std;

BinaryHeap::BinaryHeap(int cap, Relation r)
{
	this->heap_size = 0;
	this->capacity = cap;
	this->el = new Element[capacity];
	this->r = r;
}
//O(log n) 
Element BinaryHeap::extractMin()
{
	if (heap_size <= 0)
		throw std::exception();

	Element root = el[0];
	el[0] = el[heap_size - 1];
	heap_size--;
	if (this->r(1, 2) == true) 
		BinaryHeapify1(0);
	else 
		BinaryHeapify2(0);
	return root;
}

//W.C: O(log n) || AVG: O(log n) || BC: O(1)
void BinaryHeap::insertKey(Element k)
{
	//resize
	if (heap_size == capacity)
	{
		this->capacity *= 2;
		Element *newharr = new Element[this->capacity];
		for (int i = 0; i < this->capacity / 2; i++)
			newharr[i] = this->el[i];
		delete this->el;
		this->el = newharr;
	}
	// First insert the new key at the end 
	heap_size++;
	int i = heap_size - 1;
	el[i] = k;
	//min heap
	if (this->r(1,2)==true) {
		while (i != 0 && el[parent(i)].second > el[i].second)
		{
			Element temp = el[i];
			el[i] = el[parent(i)];
			el[parent(i)] = temp;
			i = parent(i);
		}
	}
	//max heap
	else {
		while (i != 0 && el[parent(i)].second < el[i].second)
		{

			Element temp = el[i];
			el[i] = el[parent(i)];
			el[parent(i)] = temp;
			i = parent(i);
		}
	}
}

//O(log n) (does it 3 times)
Element BinaryHeap::returnThird() {
	Element temp[2];
	for (int i = 0; i < 2; i++)
		temp[i] = this->extractMin();
	Element e = extractMin();
	this->insertKey(temp[0]);
	this->insertKey(temp[1]);
	this->insertKey(e);
	return e;
}

Element BinaryHeap::extractThird() {
	Element i = this->extractMin();
	Element j = this->extractMin();
	Element e = this->extractMin();
	this->insertKey(i);
	this->insertKey(j);

	return e;
}
//O(log n) (Bubble-down)
void BinaryHeap::BinaryHeapify1(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && el[l].second < el[i].second)
		smallest = l;
	if (r < heap_size && el[r].second < el[smallest].second)
		smallest = r;
	if (smallest != i)
	{
		Element temp = el[i];
		el[i] = el[smallest];
		el[smallest] = temp;
		BinaryHeapify1(smallest);
	}
}
//O(log n)
void BinaryHeap::BinaryHeapify2(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && el[l].second > el[i].second)
		smallest = l;
	if (r < heap_size && el[r].second > el[smallest].second)
		smallest = r;
	if (smallest != i)
	{
		Element temp = el[i];
		el[i] = el[smallest];
		el[smallest] = temp;
		BinaryHeapify2(smallest);
	}
}

void BinaryHeap::printare() {
	for (int i = 0; i < this->heap_size; i++) {
		cout << this->el[i].second << " ";
	}
}
