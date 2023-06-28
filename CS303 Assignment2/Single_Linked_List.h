#pragma once
// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#ifndef CS303_ASSIGNMENT2_SINGLE_LINKED_LIST_H
#define CS303_ASSIGNMENT2_SINGLE_LINKED_LIST_H

#endif //CS303_ASSIGNMENT2_SINGLE_LINKED_LIST_H


#include <string>
#include <iostream>
#include <iomanip>


template<typename Item_Type>
class Single_Linked_List {
private:
		struct Node {
			Item_Type item;
			Node* next;
		};

		Node* head;
		Node* tail;
		size_t num_items;

public:
		Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {};
		void push_front(Item_Type item);
		void push_back(Item_Type item);
		void pop_front();
		void pop_back();
		Item_Type& front() const;
		Item_Type& back() const;
		bool empty() const;
		void insert(size_t index, const Item_Type& item);
		bool remove(size_t index);
		size_t find(const Item_Type& item);
};