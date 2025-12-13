#include "node.hpp"
#include <cstddef>
template<typename T>
class LinkedList {
private:
    Node<T>* m_head{ nullptr }; //first node
    Node<T>* m_tail = m_head; //last node
    size_t m_capacity{ 0uz };
public:

    Node<T>* getHead() {
        return m_head;
    }

    Node<T>* getTail() {
        return m_tail;
    }

    constexpr void push_back(const T& value) {
        Node<T>* newNode{ new Node<T> };
        newNode->data = value;
        newNode->next = nullptr;
        if (!m_head) {
            m_head = newNode;
            m_tail = newNode;
            return;
        }
        m_tail->next = newNode;
        m_tail = newNode;

        ++m_capacity;
    }

    constexpr void push_front(const T& value) {
        Node<T>* newNode{ new Node<T> };
        newNode->data = value;
        newNode->next = m_head;
        m_head = newNode;

        ++m_capacity;
    }


    inline size_t capacity() const {
        return m_capacity;
    }


    LinkedList(Node<T> head) : m_head{ head }
    {

    }

    LinkedList() = default;

    ~LinkedList() {
        Node<T>* current = m_head;
        while (current) {
            auto next = current->next;
            delete current;
            current = next;
        }
    }
};