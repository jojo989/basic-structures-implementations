#include <iostream>
#include <string>
#include "includes/linkedList.hpp"

// ignore this file, i use this to test stuff, and also ignore this full program/project, im using this to re-learn the basics in a better way lmao, ^-^ >_<
template<typename T>
void printLinkedList(const LinkedList<T>& list) {
    auto currentNode{ list.getHead() };
    while (currentNode) {
        std::cout << "current node value: " << currentNode->data << " current node pointer/address: " << currentNode << '\n';
        currentNode = currentNode->next;
    }
}

int main() {
    LinkedList<std::string> numbers{};

    numbers.push_front("hello");
    numbers.pop_front();
    std::cout << numbers.capacity();

    return 0;
}