/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:15:32 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 01:15:32 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <class T>
void	init_stacks(ft::stack<T> &l1, ft::stack<T> &l2)
{
	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);
	l1.push(5);

	l2.push(103);
	l2.push(-5);
	l2.push(42);
	l2.push(19);
}

void	test_stack()
{ 
	P("###############  STACK  ###############");
	ft::stack<int> st;
	ft::stack<int> st2;

	std::cout << "Stack empty? : ";
	if (st.empty())
	{
		P("Yes.");
	}
	else
		P("No");
	std::cout << "  Size stack : " << st.size() << std::endl;
	P("Push des valeurs  :");
	for (int i = 1; i < 10; i++)
	{
		std::cout << "Push : " << i << std::endl;
		st.push(i);
	}
	std::cout << "Stack empty? : ";
	if (st.empty())
	{
		P("Yes.");
	}
	else
		P("No");
	P("Contenu de la stack : ");
	for (int i = 1; i < 10; i++)
	{
		std::cout << "  Top stack  : " << st.top() << std::endl;
		std::cout << "  Size stack : " << st.size() << std::endl;
		P("______________");
		st.pop();
	}
	std::cout << "  Size stack : " << st.size() << std::endl;
	std::cout << "Stack empty? : ";
	if (st.empty())
	{
		P("Yes.");
	}
	else
		P("No");

	P("#####  Non member operators overload == != > >= < <=  #####");
	init_stacks(st, st2);
	std::cout << "st == st2 ?? : ";
	if (st == st2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "st == st ?? : ";
	if (st == st)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "st != st2 ?? : ";
	if (st != st2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "st != st ?? : ";
	if (st != st)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "st < st2 ?? : ";
	if (st < st2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "st < st ?? : ";
	if (st < st)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}

/*int main()
{
	test_stack();
	return (0);
}*/