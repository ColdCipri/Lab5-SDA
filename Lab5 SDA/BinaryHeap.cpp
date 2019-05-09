#include "BinaryHeap.h"
#include <iostream>


BinaryHeap::BinaryHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

int BinaryHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap 
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	BinaryHeapify(0);

	return root;
}

void BinaryHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void BinaryHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

void BinaryHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		std::cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end 
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void BinaryHeap::BinaryHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		BinaryHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
