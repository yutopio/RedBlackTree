
#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <queue>

enum TraversalMode {
	PreOrder,
	InOrder,
	PostOrder
};

template <class Node>
Node *DFS(Node *node, bool (*action)(Node *), TraversalMode mode) {
	Node *ret;

	if (mode == PreOrder && action(node)) return node;
	if (node->Left) {
		ret = DFS(node->Left, action, mode);
		if (ret) return ret;
	}
	if (mode == InOrder && action(node)) return node;
	if (node->Right) {
		ret = DFS(node->Right, action, mode);
		if (ret) return ret;
	}
	if (mode == PostOrder && action(node)) return node;

	return NULL;
}

template <class Node>
Node *BFS(Node *node, bool (*action)(Node *)) {
	if (!node) return NULL;

	std::queue<Node *> q;
	q.push(node);

	while (q.size()) {
		Node *current = q.front();
		q.pop();

		if (action(current)) return current;
		if (current->Left) q.push(current->Left);
		if (current->Right) q.push(current->Right);
	}

	return NULL;
}

#endif
