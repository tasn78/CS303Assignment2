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

// Added definitions and declarations to .hpp file after watching video : https://www.youtube.com/watch?v=WoGoAMDvwEQ - Fabrzy
// Changes to Node class and Single_Linked_List based on Fabrzy's video
// Used code for reference from https://www.javatpoint.com/create-linked-list-in-cpp and https://codefreakr.com/how-is-c-stl-list-implemented-internally/

// Using typename TS
namespace TS {
    //Node Class and declarations
    template<typename Item_Type>
    class Node {
    public:
        Item_Type item;
        Node<Item_Type>* next;

        //Constructors
        Node() : item(NULL), next(NULL) {};
        Node(Item_Type val) : item(val), next(NULL) {};

        // Node Functions
        void setItem(Item_Type item);
        Item_Type getItem();
        void setNext(Node<Item_Type>* next);
        Node<Item_Type> getNext();
    };


    // Single linked list and declarations
    template<typename Item_Type>
    class Single_Linked_List {

    public:
        Node<Item_Type>* head;
        Node<Item_Type>* tail;
        size_t num_items;
        // Constructor
        Single_Linked_List() : head(NULL), tail(NULL), num_items(0) {}; // Default constructor

        // Functions
        void push_front(const Item_Type& item);
        void push_back(const Item_Type& item);
        void pop_front();
        void pop_back();
        Item_Type& front();
        Item_Type& back();
        bool empty() const;
        void insert(size_t index, const Item_Type& item);
        bool remove(size_t index);
        size_t find(const Item_Type& item);
        void print();
    };
 
};


//NODE Functions
// Setter for Node item
template <typename Item_Type>
void TS::Node<Item_Type>::setItem(Item_Type item) {
    this->item = item;
}

//Getter for Node item
template <typename Item_Type>
Item_Type TS::Node<Item_Type>::getItem() {
    return this->item;
}

// Sets node next
template <typename Item_Type>
void TS::Node<Item_Type>::setNext(Node<Item_Type>* next) {
    this->next = next;
}

// Gets node next
template <typename Item_Type>
TS::Node<Item_Type> TS::Node<Item_Type>::getNext() {
    return this->next;
}


// SINGLE_LINKED_LIST FUNCTIONS
// Adds item to the front of list
template <typename Item_Type>
void TS::Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    new_node->next = head;
    head = new_node;
    if (empty()) {
        tail = head;
    }
    num_items++;
}

// Adds item to the back of list
template <typename Item_Type>
void TS::Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (num_items == 0) {
        this->head = new_node;
        this->tail = new_node;
    }
    else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    num_items++;
}

// Removes the item at the front of list
template <typename Item_Type>
void TS::Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        return;
    }
    else if (head != nullptr) {
        Node<Item_Type>* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

// Removes item at the end of list
template <typename Item_Type>
void TS::Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// Returns the item at the front of the list
template <typename Item_Type>
Item_Type& TS::Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        Item_Type item;
        return item;
    }
    return head->item;
}

// Returns the item at the back of the list
template <typename Item_Type>
Item_Type& TS::Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        Item_Type item;
        return item;
    }
    return tail->item;
}

// Returns whether or not the list is empty based on num_items
template <typename Item_Type>
bool TS::Single_Linked_List<Item_Type>::empty() const {
    if (num_items == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Inserts item based on index provided
template <typename Item_Type>
void TS::Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) {
        push_back(item);
    }

    else if (index == 0) {
        push_front(item);
    }

    else if (index == num_items && index != 0) {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        tail->next = new_node;
        tail = new_node;
    }

    else {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        Node<Item_Type>* current = head;

        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    ++num_items;
}


// Removes item based on index chosen, returns true if removed and false if unable/not removed
template <typename Item_Type>
bool TS::Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }

    Node<Item_Type>* node_to_remove;

    if (index == 0) {
        node_to_remove = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        Node<Item_Type>* current = head;

        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        node_to_remove = current->next;
        current->next = node_to_remove->next;

        if (current->next == nullptr) {
            tail = current;
        }
    }

    delete node_to_remove;
    num_items--;
    return true;
}

// Searches for item and returns index, returns list size if not found
template <typename Item_Type>
size_t TS::Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node<Item_Type>* current = head;
    size_t index = 0;

    while (current != nullptr) {
        if (current->item == item) {
            return index;
        }

        current = current->next;
        ++index;
    }

    return num_items;
}

// Prints list
template<typename Item_Type>
void TS::Single_Linked_List<Item_Type>::print() {
    Node<Item_Type>* current = head;
    while (current != nullptr) {
        std::cout << current->item << " ";
        current = current->next;
    }
    std::cout << std::endl << std::endl;
};