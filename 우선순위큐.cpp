#include "pch.h"
#include "common.h"


template<typename T>
struct Item {
	T data;
	bool empty;
};

template<typename T>
class PriorityQueue {
	Item<T>* heapArray;
	function<bool(T&, T&)> comparator;
	int size;
	int capacity;

private:
	void swap(int lhs, int rhs) {
		Item<T> temp = heapArray[lhs];
		heapArray[lhs] = heapArray[rhs];
		heapArray[rhs] = temp;
	}

	void print(int index) const {
		if (index > size)
			return;

		cout << "index : " << index << " / " << heapArray[index].data << endl;
		print(2 * index);
		print(2 * index + 1);
	}

public:
	PriorityQueue(function<bool(T&, T&)> comparator, int capacity = 100) {
		this->capacity = capacity;
		this->heapArray = new Item<T>[capacity];
		this->size = 0;
		this->comparator = comparator;

		for (int i = 0; i < capacity; i++)
			heapArray[i].empty = true;
	}

	void push(T data) {
		heapArray[++size].data = data;
		heapArray[size].empty = false;
		int lastIndex = size;
		int parentIndex = 0;
		while (true) {
			parentIndex = lastIndex / 2;

			if (parentIndex == 0)
				break;

			if (comparator(heapArray[lastIndex].data, heapArray[parentIndex].data)) {
				swap(lastIndex, parentIndex);
				lastIndex = parentIndex;
			}
			else
				break;
		};

	
		print();
		cout << "---------------" << endl;
	}

	T pop() {
		if (size <= 0) {
			cout << "no data" << endl;
			return T();
		}

		T ret = heapArray[1].data;
		int parentIndex = 1;

		swap(1, size);
		heapArray[size].empty = true;
		size--;

		while (true) {
			if (parentIndex >= size)
				break;

			int leftChildIndex = parentIndex * 2;
			int rightChildIndex = parentIndex * 2 + 1;

			if (heapArray[leftChildIndex].empty || heapArray[rightChildIndex].empty) {
				if (comparator(heapArray[leftChildIndex].data, heapArray[parentIndex].data)) {
					swap(leftChildIndex, parentIndex);
					parentIndex = leftChildIndex;
				} 
				else
					break;
			}
			else if (heapArray[leftChildIndex].empty == false && heapArray[leftChildIndex].empty == false){
				int biggerIndex = leftChildIndex;

				if (comparator(heapArray[rightChildIndex].data, heapArray[leftChildIndex].data))
					biggerIndex = rightChildIndex;

				if (comparator(heapArray[biggerIndex].data, heapArray[parentIndex].data)) {
					swap(biggerIndex, parentIndex);
					parentIndex = biggerIndex;
				}
				else
					break;
			} 
			else {
				break;
			}
		}
		
		return ret;
	}

	int getSize() const {
		return size;
	}

	void print() const {
		if (size <= 0)
			return;
		print(1);
	}

	int getCapacity() const {
		return capacity;
	}

	bool empty() const {
		return size == 0 ? true : false;
	}
};

TEST(우선순위큐) {
	PriorityQueue<int>  pq = PriorityQueue<int>([](int& lhs, int& rhs) { 
		return lhs > rhs; 
	});

	pq.push(5);
	pq.push(4);
	pq.push(9);
	pq.push(1);
	pq.push(7);
	pq.push(100);
	pq.push(101);
	pq.push(105);
	pq.push(104);
	pq.push(103);

	cout << "비우기 시작" << endl;
	while (pq.empty() == false) {
		cout << pq.pop() << endl;
		pq.print();
		cout << "-------------";
	}
}