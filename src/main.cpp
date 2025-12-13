#include <iostream>
#include "includes/linkedList.hpp"

// ignore this file, i use this to test stuff, and also ignore this full program/project, im using this to re-learn the basics in a better way lmao, ^-^ >_<

int main() {
    LinkedList<int> numbers{};
    for (auto i{ 0uz }; i < 10; ++i) {
        numbers.push_back(i);
        std::cout << numbers.capacity() << '\n';
    }

    // print all elemetnts xd
    auto currentNode{ numbers.getHead() };
    while (currentNode) {
        std::cout << "current node value: " << currentNode->data << " current node pointer/address: " << currentNode << '\n';
        currentNode = currentNode->next;
    }

    return 0;
}