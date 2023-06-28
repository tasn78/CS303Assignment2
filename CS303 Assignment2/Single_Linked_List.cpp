// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Single_Linked_List.h"


template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(Item_Type item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (!tail) {
        tail = head;
    }
    num_items++;
}


template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(Item_Type item) {
    Node* new_node = new Node(item);
    if (!head) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        return;
    }
    else if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}


template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
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


template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        std::cout << "List is empty." << std::endl << std::endl;
        return Item_Type();
    }
    return head->data;
}


template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        std::cout << "The list is empty." << std::endl << std::endl;
        return Item_Type();
    }
    return tail->data;
}


template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    if (num_items == 0) {
        return false;
    }
    else {
        return true;
    }
}


template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) {
        push_back(item);
    }
        
    else if (index == 0) {
        push_front(item);
        }

    else if (index == num_items && index != 0) {
        Node* new_node = new Node(item);
        tail->next = new_node;
        tail = new_node;
        }

    else {
        Node* new_node = new Node(item);
        Node* current = head;

        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
        }

        ++num_items;
}


template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }

    Node* node_to_remove;

    if (index == 0) {
        node_to_remove = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        Node* current = head;

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
    --num_items;
    return true;
}


template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
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
