#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

namespace ft
{
    template< class T, class Container = std::deque<T> >
    class Queue
    {
        public:
        // member types
            typedef Container container_type;
            typedef typename Container::value_type value_type;
            typedef typename Container::size_type size_type;
            typedef typename Container::reference reference;
            typedef typename Container::const_reference const_reference;

        // member functions
            explicit Queue(const Container &cont = Container());
            Queue<T, Container> &operator=(const Queue<T, Container> &other);
            ~Queue();
//--
        // Element access
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
//--
        // Capacity
            bool empty() const;
            size_type size() const;
//--
        // Modifiers
            void push(const T &value);
            void pop();
            void swap(const Queue<T, Container> &other);
//--
        // member obbjects
            container_type C;
    };

    // Member functions
    template< class T, class Container >
    Queue<T, Container>::Queue(const Container &cont) : C(cont) {}
    template< class T, class Container >
    Queue<T, Container> &Queue<T, Container>::operator=(const Queue<T, Container> &other)
    {
        if (this == &other) return(*this);
	    this->~Queue();
	    return *new(this) Queue(other);
    }

    template< class T, class Container >
    Queue<T, Container>::~Queue() {}

    // Element access
    template< class T, class Container >
    typename Queue<T, Container>::reference Queue<T, Container>::front()
    {
        return (C.front());
    }
    
    template< class T, class Container >
    typename Queue<T, Container>::const_reference Queue<T, Container>::front() const 
    {
        return (C.front());
    }

    template< class T, class Container >
    typename Queue<T, Container>::reference Queue<T, Container>::back()
    {
		return (C.back());
    }
    
    template< class T, class Container >
    typename Queue<T, Container>::const_reference Queue<T, Container>::back() const 
    {
        return (C.back());
    }
    
    // Capacity
    template< class T, class Container >
    bool Queue<T, Container>::empty() const 
    {
        return (C.empty()); 
    }
    
    template< class T, class Container >
    typename Queue<T, Container>::size_type Queue<T, Container>::size() const 
    {
        return (C.size()); 
    }

    // Modifiers
    template< class T, class Container >
    void Queue<T, Container>::push(const T &value) 
    {
        C.push_back(value); 
    }

    template< class T, class Container >
    void Queue<T, Container>::pop() 
    {
        C.pop_front();
    }
    
    template< class T, class Container >
    void Queue<T, Container>::swap(const Queue<T, Container> &other)
    {
        Container tmp = C;
        C = other.C;
        other.C = tmp;
    }

    // Non-member functions
    template< class T, class Container >
    void swap(Queue<T, Container> &lhs, Queue<T, Container> &rhs)
    {
        Container tmp = lhs.C;
        lhs.C = rhs.C;
        rhs.C = tmp;
    }

    template< class T >
    bool operator==(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C == rhs.C); }
    template< class T >
    bool operator!=(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C != rhs.C); }
    template< class T >
    bool operator>(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C > rhs.C); }
    template< class T >
    bool operator>=(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C >= rhs.C); }
    template< class T >
    bool operator<(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C < rhs.C); }
    template< class T >
    bool operator<=(Queue<T> &lhs, Queue<T> &rhs) { return (lhs.C <= rhs.C); }
}

#endif
