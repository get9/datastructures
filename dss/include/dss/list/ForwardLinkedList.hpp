#pragma once

#include <stdexcept>

#include "dss/list/ForwardNode.hpp"

namespace dss
{

template <typename T>
class ForwardLinkedList
{
public:
    // Iterator types
    using iterator = ForwardNode<T>*;
    using const_iterator = const ForwardNode<T>*;

    ForwardLinkedList() : head_{nullptr}, size_{0} {}
    explicit ForwardLinkedList(T value) : head_{new ForwardNode<T>{value}}, size_{1} {}
    ForwardLinkedList(const ForwardLinkedList& other)
    {
        for (auto t : other) {
            push_front(t);
        }
    }
    ~ForwardLinkedList()
    {
        auto tmp_node = head_;
        while (head_ != nullptr) {
            head_ = head_->next;
            delete tmp_node;
        }
    }

    const ForwardNode<T>* head() const { return head_; }
    ForwardNode<T>& head() { return head_; }
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    const_iterator begin() const { return head_; }
    iterator begin() { return head_; }
    const_iterator end() const { return nullptr; }
    iterator end() { return nullptr; }

    // Push a value onto the front of the list.
    void push_front(const T& value)
    {
        auto tmp_node = new ForwardNode<T>{value};

        // Special case - empty list
        if (size_ == 0) {
            head_ = tmp_node;
        }

        // General case
        else {
            tmp_node->next = head_;
            head_ = tmp_node;
        }
        size_++;
    }

    // Pop a value from the front of the list.
    T pop_front()
    {
        if (size_ == 0) {
            throw std::out_of_range{"empty list"};
        }

        // Keep track of old head and value we want to return.
        auto old_head = head_;
        auto ret_value = old_head->value;

        // Special case - one element.
        if (size_ == 1) {
            delete head_;
            head_ = nullptr;
        }

        // General case - move head down.
        else {
            head_ = head_->next;
            delete old_head;
            old_head = nullptr;
        }

        size_--;
        return ret_value;
    }

private:
    ForwardNode<T>* head_;
    size_t size_;
};
}
