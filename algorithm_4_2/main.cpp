#include <iostream>
#include <cstring>
using namespace std;

class Dequeue {
public:
	Dequeue();
	~Dequeue() {delete [] buffer;}
	void push_back(int data);
	const int* pop_back();
	inline bool isEmpty() {return size == 0;}
private:
	void increase_capacity();
	inline bool isFull() {return size == capacity;}
	int *buffer;
	int size;
	int capacity;
	int head, tail;
};

Dequeue::Dequeue() {
	capacity = 100;
	buffer = new int[capacity];
	size, head, tail = 0;
}

void Dequeue::increase_capacity() {
	int *temp = new int[capacity*2];
	if (head <= tail) {
		std::memcpy(temp, buffer, sizeof(int)*size);
		head = 0;
		tail = size;
	}
	else {
		std::memcpy(temp, buffer, sizeof(int)*tail);
		std::memcpy(temp+(2*capacity-size+tail), buffer+capacity-size+tail, sizeof(int)*(size-tail));
		capacity = 2*capacity;
		head = capacity - size + tail;
	}
	delete [] buffer;
	buffer = temp;
}

void Dequeue::push_back(int data) {
	if(isFull()) {
		increase_capacity();
	}
	buffer[tail] = data;
	++tail;
}

const int* Dequeue::pop_back() {
	if(!isEmpty()) {
		return null;
	}
	else {

	}
}

int main()
{
	cout << "Hello, World!" << endl;
	return 0;
}