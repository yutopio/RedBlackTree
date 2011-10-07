
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	Node *Left, *Right;
	T Value;

	Node() {
		this->Left = this->Right = NULL;
	}

	Node(T value) {
		this->Left = this->Right = NULL;
		this->Value = value;
	}
};

#endif
