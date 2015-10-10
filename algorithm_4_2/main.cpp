#include <iostream>
#include <cstring>
using namespace std;

class Dequeue {
public:
	Dequeue();
	~Dequeue() {delete [] buffer;}
	void push_back(int data);
	int pop_back();
	void push_front(int data);
	int pop_front();
	inline bool is_empty() {return size == 0;}
private:
	void increase_capacity();
	inline bool is_full() {return size == capacity;}
	int *buffer;
	int size;
	int capacity;
	int head, tail;
};

Dequeue::Dequeue() {
	capacity = 5;
	buffer = new int[capacity];
	size = 0;
	head = 0;
	tail = 0;
}

void Dequeue::increase_capacity() {
	int *temp = new int[capacity*2];
	if ((head < tail) || (size == 0)) {
		std::memcpy(temp + head, buffer, sizeof(int)*size);
	}
	else {
		std::memcpy(temp, buffer, sizeof(int)*tail);
		std::memcpy(temp+(2*capacity-size+tail), buffer+head, sizeof(int)*(size-tail));
		capacity = 2*capacity;
		head = capacity - size + tail;
	}
	delete [] buffer;
	buffer = temp;
}

void Dequeue::push_back(int data) {
	if(is_full()) {
		increase_capacity();
	}
	buffer[tail] = data;
	if(tail != capacity - 1) {
		++tail;
	}
	else {
		tail = 0;
	}
	++size;
}

int Dequeue::pop_back() {
	if(is_empty()) {
		return -1;
	}
	else {
		int res;
		if (tail != 0) {
			--tail;
		}
		else {
			tail = capacity - 1;
		}
		res = buffer[tail];
		--size;
		return res;
	}
}

void Dequeue::push_front(int data) {
	if(is_full()) {
		increase_capacity();
	}
	if(head != 0) {
		--head;
	}
	else
	{
		head = capacity - 1;
	}
	buffer[head] = data;
	++size;
}

int Dequeue::pop_front() {
	if(is_empty()){
		return -1;
	}
	else {
		int res;
		res = buffer[head];
		if (head != (capacity - 1)) {
			++head;
		}
		else {
			head = 0;
		}
		--size;
		return res;
	}
}

int main()
{
	int number_moves;
	cin >> number_moves;
	string answer = "YES";
	Dequeue* deq = new Dequeue();
	for (int i = 0; i < number_moves; ++i) {
		int cmd, data;
		cin >> cmd >> data;
		switch (cmd) {
			case 1: {
				deq->push_front(data);
				break;
			}

			case 2: {
				const int temp = deq->pop_front();
				if (temp != data) {
					answer = "NO";
				}
				break;
			}

			case 3: {
				deq->push_back(data);
				break;
			}

			case 4: {
				const int temp = deq->pop_back();
				if(temp != data) {
					answer = "NO";
				}
				break;
			}
		}
	}
	cout << answer << endl;
	delete deq;
	return 0;
}