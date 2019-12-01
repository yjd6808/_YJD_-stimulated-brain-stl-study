#include "pch.h"
#include "common.h"

template<typename T>
struct Node {
	T data;
	Node* pnext;
};

template<typename T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~LinkedList() {
	}

	void push_back(T data) {
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->pnext = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->pnext = newNode;
			tail = newNode;
		}

		size++;
	}

	void remove(T&& data) {
		Node<T>* mover = head;
		Node<T>* beforeNode = nullptr;

		while (mover != nullptr) {
			if (mover->data == data) {
				if (mover == head) {
					Node<T>* temp = mover;
					head = head->pnext;
					delete temp;
					return;
				}
				else {
					Node<T>* temp = mover;
					beforeNode->pnext = mover->pnext;
					mover = beforeNode;
					delete temp;
					return;
				}
				size--;
			}
			beforeNode = mover;
			mover = mover->pnext;
		}

		cout << "cannot find value" << endl;
	}

	T at(int index) const {
		try {
			if (index >= size || index < 0) {
				throw "out of range";
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}


		int startIndex = 0;
		Node<T>* mover = head;

		while (mover != nullptr) {
			if (startIndex == index)
				return mover->data;
			startIndex++;
			mover = mover->pnext;
		}

		return T();
	}

	void print() const {
		Node<T>* mover = head;

		while (mover != nullptr) {
			cout << mover->data << endl;
			mover = mover->pnext;
		}
	}

	int getSize() const {
		return size;
	}
};

TEST(링크드리스트) {
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.print();
	cout << list.getSize() << endl;
	cout << list.at(0) << endl;
	cout << list.at(1) << endl;
	cout << list.at(2) << endl;
}