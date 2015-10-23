#include <iostream>
//Реализация стека при помощи односвязного списка
using namespace std;
struct Node {
	char data;
	Node* next;

	Node() : data(0), next(0) {}
	Node(char data) : data(data), next(0) {}
};

class List {
public:
	List() : first(0) {}
	~List() { delete_all(); }

	void add_first(Node *node);
	const Node* get_first() const;
	void delete_first();
	void delete_all();
	bool is_empty() const {return first == NULL;}; //метод не будет менять объект (для более хорошего понимания кода)

private:
	Node* first;
};

inline void List::add_first(Node *node) {
	if ( first == 0){
		first = node;
	}
	else {
		node->next = first;
		first = node;
	}
}

/*inline Node* List::get_first(){
    пишем внутри класса, так как метод маленький
}*/

inline void List::delete_first(){
	if(!is_empty()) {
		Node* toDelete = first;
		first = first->next;
		delete toDelete;
	}
}

inline void List::delete_all(){
	while(!is_empty()) {
		delete_first();
	}
}

inline const Node* List::get_first() const {
	if(first) {
		return first;
	}
	else {
		return NULL;
	}
}

class Stack{
public:
	Stack() {}

	void push(char data);
	char pop();
	bool is_empty() const {return list.is_empty();}

private:
	List list;
};

void Stack::push(char data){
	list.add_first(new Node(data));
}

char Stack::pop(){
	if(!(is_empty())) {
		char data = list.get_first()->data;
		list.delete_first();
		return data;
	}
	else {
		return char(0);
	}
}


int main() {
	char ch;
	std::string str = "";
	Stack* stack = new Stack();
	while(cin >> ch) {
		str += ch;
		if(!(stack->is_empty())) {
			char temp = stack->pop();
			if (!(ch == 41 && temp == 40 || ch == 93 && temp == 91 || ch == 125 && temp == 123)) {
				stack->push(temp);
				stack->push(ch);
			}
		}
		else {
			stack->push(ch);
		}
	}

	char poped = 0;
	while ((poped = stack->pop()) == 40 || poped == 91 || poped == 123) {

		switch (poped) {
			case 40: {
				str.push_back(char(41));
				break;
			}
			case 91: {
				str.push_back(char(93));
				break;
			}
			case 123: {
				str.push_back(char(125));
				break;
			}
		}
	}

	if(poped != 0) {
		stack->push(poped);
	}

	std::string prefix = "";

	while ((poped = stack->pop()) == 41 || poped == 93 || poped == 125) {
		switch (poped) {
			case 41: {
				prefix.push_back(char(40));
				break;
			}
			case 93: {
				prefix.push_back(char(91));
				break;
			}
			case 125:
			{
				prefix.push_back(char(123));
				break;
			}
		}
		poped = 0;
	}

	if (stack->is_empty() && poped == 0) {
		cout << prefix << str << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	delete stack;
	return 0;

}