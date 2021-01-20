#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

namespace ft
{
    template< class T, class Container = std::deque<T> >
    class Stack
    {
        public:
        // member types
            typedef Container container_type;
            typedef typename Container::value_type value_type;
            typedef typename Container::size_type size_type;
            typedef typename Container::reference reference;
            typedef typename Container::const_reference const_reference;

        // member functions
            explicit Stack(const Container &cont = Container());
            Stack<T, Container> &operator=(const Stack<T, Container> &other);
            ~Stack();
//--
        // Element access
            reference top();
            const_reference top() const;
//--
        // Capacity
            bool empty() const;
            size_type size() const;
//--
        // Modifiers
            void push(const T &value);
            void pop();
            void swap(const Stack<T, Container> &other);
//--
        // member obbjects
            container_type C;
    };

    // Member functions
    template< class T, class Container >
    Stack<T, Container>::Stack(const Container &cont) : C(cont) {}
    template< class T, class Container >
    Stack<T, Container> &Stack<T, Container>::operator=(const Stack<T, Container> &other)
    {
        if (this == &other) return(*this);
	    this->~Stack();
	    return *new(this) Stack(other);
    }

    template< class T, class Container >
    Stack<T, Container>::~Stack() {}

    // Element access
    template< class T, class Container >
    typename Stack<T, Container>::reference Stack<T, Container>::top()
    {
        return (C.back());
    }
    
    template< class T, class Container >
    typename Stack<T, Container>::const_reference Stack<T, Container>::top() const 
    {
        return (C.back());
    }
    
    // Capacity
    template< class T, class Container >
    bool Stack<T, Container>::empty() const 
    {
        return (C.empty()); 
    }
    
    template< class T, class Container >
    typename Stack<T, Container>::size_type Stack<T, Container>::size() const 
    {
        return (C.size()); 
    }

    // Modifiers
    template< class T, class Container >
    void Stack<T, Container>::push(const T &value) 
    {
        C.push_back(value); 
    }

    template< class T, class Container >
    void Stack<T, Container>::pop() 
    {
        C.pop_back();
    }
    
    template< class T, class Container >
    void Stack<T, Container>::swap(const Stack<T, Container> &other)
    {
        Container tmp = C;
        C = other.C;
        other.C = tmp;
    }

    // Non-member functions
    template< class T, class Container >
    void swap(Stack<T, Container> &lhs, Stack<T, Container> &rhs)
    {
        Container tmp = lhs.C;
        lhs.C = rhs.C;
        rhs.C = tmp;
    }

    template< class T >
    bool operator==(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C == rhs.C); }
    template< class T >
    bool operator!=(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C != rhs.C); }
    template< class T >
    bool operator>(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C > rhs.C); }
    template< class T >
    bool operator>=(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C >= rhs.C); }
    template< class T >
    bool operator<(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C < rhs.C); }
    template< class T >
    bool operator<=(Stack<T> &lhs, Stack<T> &rhs) { return (lhs.C <= rhs.C); }
}

#endif
