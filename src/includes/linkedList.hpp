#include "node.hpp"
#include <cstddef>
template<typename T>
class LinkedList {
private:
    Node<T>* m_head{ nullptr }; //first node
    Node<T>* m_tail = m_head; //last node
    size_t m_capacity{ 0uz };
public:

    Node<T>* getHead() const {
        return m_head;
    }

    Node<T>* getTail() const {
        return m_tail;
    }

    // add element at the end / tail
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

    // add element at the start / head
    constexpr void push_front(const T& value) {
        Node<T>* newNode{ new Node<T> };
        newNode->data = value;
        newNode->next = m_head;
        m_head = newNode;

        ++m_capacity;
    }

    // remove element at the end / tail
    void pop_back() {
        if (!m_head) { return; }

        if (m_head == m_tail) {
            delete m_head;
            m_head = m_tail = nullptr;
            --m_capacity;
            return;
        }

        Node<T>* currentNode{ m_head };
        while (currentNode->next != m_tail) {
            currentNode = currentNode->next;
        }
        delete m_tail;
        m_tail = currentNode;
        m_tail->next = nullptr;
        --m_capacity;
    }

    // delete element at the start / head
    void pop_front() {
        if (!m_head) { return; }

        if (m_head == m_tail) {
            delete m_head;
            m_head = m_tail = nullptr;
            --m_capacity;
            return;
        }

        Node<T>* nextNode{ m_head->next };
        delete m_head;
        m_head = nextNode;
        --m_capacity;
    }


    inline size_t capacity() const {
        return m_capacity;
    }


    LinkedList(Node<T> head) : m_head{ head }, m_tail{ head }
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