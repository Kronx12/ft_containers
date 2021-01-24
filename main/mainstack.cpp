#include "Tester.hpp"

void stack_test(int size)
{
    title("Stack", size);
    
    std::stack<int> std_stack;
    ft::Stack<int> ft_stack;
    std::stack<int> other_std_stack;
    ft::Stack<int> other_ft_stack;

    other_std_stack = std_stack;
    other_ft_stack = ft_stack;

    for (int i = 0; i < size; i++)
    {
        std_stack.push(i);
        ft_stack.push(i);
    }

    title("size :");
    std::stringstream ss_std;
    std::stringstream ss_ft;
    ss_std << std_stack.size();
    ss_ft << ft_stack.size();
    check(&ss_std, &ss_ft, DEFINED);

    title("operator==");
    ss_std << (std_stack == other_std_stack);
    ss_ft << (ft_stack == other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator!=");
    ss_std << (std_stack != other_std_stack);
    ss_ft << (ft_stack != other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator>");
    ss_std << (std_stack > other_std_stack);
    ss_ft << (ft_stack > other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator>=");
    ss_std << (std_stack >= other_std_stack);
    ss_ft << (ft_stack >= other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator<");
    ss_std << (std_stack < other_std_stack);
    ss_ft << (ft_stack < other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);
    title("operator<=");
    ss_std << (std_stack <= other_std_stack);
    ss_ft << (ft_stack <= other_ft_stack);
    check(&ss_std, &ss_ft, DEFINED);

    swap(std_stack, other_std_stack);
    swap(ft_stack, other_ft_stack);

    title("construction :");
    describe_stack(std_stack, ft_stack);

    title("assignement :");
    describe_stack(other_std_stack, other_ft_stack);
}

int main()
{
    
    // constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	stack_test(10);
	stack_test(5);
	stack_test(2);
	stack_test(1);
	stack_test(0);

    end_test();

}