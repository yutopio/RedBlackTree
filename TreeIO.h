
#ifndef TREEIO_H
#define TREEIO_H

#include "Node.h"
#include "Traversal.h"

static void *_toListVector;

template <class Value>
static bool ToListInternal(Node<Value> *node) {
	static_cast<std::vector<Value> *>(_toListVector)->push_back(
		node->Left ? node->Left->Value : -1);
	static_cast<std::vector<Value> *>(_toListVector)->push_back(
		node->Right ? node->Right->Value : -1);
	return false;
};

template <class Value, class Node>
std::vector<Value> *ToList(Node *tree, Value (*selector)(Node *node)) {
	std::vector<Value> *ret = new std::vector<Value>;
	ret->push_back(selector(tree));

	_toListVector = ret;
	if (tree) BFS<Node>(tree, ToListInternal);
	_toListVector = NULL;

	return ret;
};

template <class Value, class Node>
Node *FromList(const std::vector<Value> &list, Node *(*selector)(Value value)) {
	if (list.empty()) return NULL;
	std::vector<Value>::const_iterator iter = list.begin();
	Node *ret = selector(*iter);
	if (!ret) return NULL;

	std::queue<Node *> *prev = new std::queue<Node *>,
		*current = new std::queue<Node *>;
	prev->push(ret);

	while (++iter < list.end()) {
		if (prev->empty()) {
			delete prev;
			prev = current;
			current = new std::queue<Node *>;
		}
		if (prev->empty()) break;

		Node *node = prev->front();
		prev->pop();

		Node *temp;
		if (temp = node->Left = selector(*iter)) current->push(temp);
		if (++iter == list.end()) break;
		if (temp = node->Right = selector(*iter)) current->push(temp);
	}

	delete prev;
	delete current;
	return ret;
};

#endif
