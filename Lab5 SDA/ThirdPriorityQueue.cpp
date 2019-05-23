#pragma once
#include <exception>
#include "ThirdPriorityQueue.h"
using namespace std;
ThirdPriorityQueue::ThirdPriorityQueue(Relation r)
{
	this->len = 0;
	this->capacity = 100;
	this->elems = new BinaryHeap(capacity,r);
	this->r = r;
}
//O(log n)
void ThirdPriorityQueue::push(TElem e, TPriority p)
{
	this->len++;
	this->elems->insertKey(std::make_pair(e, p));
	
}
//O(log n)
Element ThirdPriorityQueue::top() const
{
	if (this->atMostTwo())
		throw std::exception();
	else
		return this->elems->returnThird();
}
//O(log n)
Element ThirdPriorityQueue::pop()
{
	if (this->atMostTwo())
		throw std::exception();
	else{
		this->len--;
		return this->elems->extractThird();
	}
}
//O(1)
bool ThirdPriorityQueue::atMostTwo() const
{
	if (this->len <=2)
		return true;
	return false;
}


ThirdPriorityQueue::~ThirdPriorityQueue()
{
	delete this->elems;
}
