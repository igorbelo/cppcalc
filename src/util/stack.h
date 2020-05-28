#ifndef STACK_H
#define STACK_H

#include <vector>

template <typename T>
struct Stack {
    void push(T item) {
        stack.push_back(item);
    }

    T pop() {
        T item = get();
        stack.pop_back();
        return item;
    }

    T get() {
        return stack[stack.size() - 1];
    }

    size_t size() {
        return stack.size();
    }

private:
    std::vector<T> stack;
};
#endif // STACK_H