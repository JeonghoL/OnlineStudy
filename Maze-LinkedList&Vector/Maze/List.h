#pragma once
#include <iostream>
using namespace std;

class Node
{
	// typedef int T;
	using T = int;
public:
	Node(int data) : data{ data }, prev{ nullptr }, next{ nullptr } {};

public:
	T data;
	Node* prev;
	Node* next;
};

//	[dummy]	  [dummy]
// [head]		[tail]
class List {
public:
	List() {
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List() {
		Node* node = _head;
		while (node)
		{
			Node* deleteNode = node;
			node = node->next;
			delete deleteNode;

		}
	}

	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; ++i)
		{
			if (node == _tail->prev)
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";

			node = node->next;
		}
		cout << endl;

	}

	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);
		Node* nextNode = _head->next;

		node->prev = _head;
		node->next = nextNode;

		_head->next = node;
		nextNode->prev = node;

		return node;
	}

	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* prevNode = _tail->prev;

		node->next = _tail;
		node->prev = prevNode;

		prevNode->next = node;
		_tail->prev = node;

		return node;
	}

	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		node->prev = prevNode;
		prevNode->next = node;
		
		node->next = posNode;
		posNode->prev = node;
	}

	Node* Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};