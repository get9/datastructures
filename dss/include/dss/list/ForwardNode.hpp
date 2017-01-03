#pragma once

namespace dss
{

template <typename T>
struct ForwardNode {
    ForwardNode() : value{}, next{nullptr} {}
    ForwardNode(T val) : value{val}, next{nullptr} {}

    ForwardNode& operator++()
    {
        next = next->next;
        return *this;
    }
    ForwardNode& operator++(int)
    {
        auto& tmp = *this;
        next = next->next;
        return tmp;
    }

    T value;
    ForwardNode<T>* next;
};
}
