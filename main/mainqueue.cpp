#include "Tester.hpp"

void queue_test(int size)
{
    title("Queue", size);
    
    std::queue<int> std_queue;
    ft::Queue<int> ft_queue;
    std::queue<int> other_std_queue;
    ft::Queue<int> other_ft_queue;

    other_std_queue = std_queue;
    other_ft_queue = ft_queue;

    for (int i = 0; i < size; i++)
    {
        std_queue.push(i);
        ft_queue.push(i);
    }

    title("size :");
    std::stringstream ss_std;
    std::stringstream ss_ft;
    ss_std << std_queue.size();
    ss_ft << ft_queue.size();
    check(&ss_std, &ss_ft, DEFINED);

    title("operator== :");
    ss_std << (std_queue == other_std_queue);
    ss_ft << (ft_queue == other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator!= :");
    ss_std << (std_queue != other_std_queue);
    ss_ft << (ft_queue != other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator> :");
    ss_std << (std_queue > other_std_queue);
    ss_ft << (ft_queue > other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator>= :");
    ss_std << (std_queue >= other_std_queue);
    ss_ft << (ft_queue >= other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator< :");
    ss_std << (std_queue < other_std_queue);
    ss_ft << (ft_queue < other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator<= :");
    ss_std << (std_queue <= other_std_queue);
    ss_ft << (ft_queue <= other_ft_queue);
    check(&ss_std, &ss_ft, DEFINED);

    swap(std_queue, other_std_queue);
    swap(ft_queue, other_ft_queue);

    title("construction :");
    describe_queue(std_queue, ft_queue);

    title("assignement :");
    describe_queue(other_std_queue, other_ft_queue);
}

int main()
{
    
    queue_test(1000); // OK Sur linux (juste chiant a afficher)
	queue_test(10);
	queue_test(5);
	queue_test(2);
	queue_test(1);
	queue_test(0);

    end_test();

}