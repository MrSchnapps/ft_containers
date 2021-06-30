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

void 	test_stack_constructor()
{
	print_title("Constructors / Empty / Size / Push / Pop / Top");
	ft::stack<int> my1;
	std::stack<int> real1;

	check("Declare", (my1 == real1));
	
	my1.push(1);
	real1.push(1);
	check("push(1)", (my1 == real1));

	my1.push(2);
	real1.push(2);
	my1.push(3);
	real1.push(3);
	my1.push(4);
	real1.push(4);
	check("push(2, 3, 4)", (my1 == real1));

	while (!my1.empty())
	{
		my1.pop();
		real1.pop();
		check("pop", (my1 == real1));
	}
	check("Empty + size", (my1 == real1));
}

void	test_stack_operators()
{
	print_title("Operators");
	ft::stack<int> my1;
	ft::stack<int> my2;

	std::stack<int> real1;
	std::stack<int> real2;

	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));
	
	my1.push(1);
	my1.push(2);
	my1.push(3);
	my2.push(1);
	my2.push(2);
	my2.push(3);
	real1.push(1);
	real1.push(2);
	real1.push(3);
	real2.push(1);
	real2.push(2);
	real2.push(3);
	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));
	
	my1.pop();
	real1.pop();
	my1.push(4);
	real1.push(4);
	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));

	check("Operator <=", (my1 <= my2), (real1 <= real2));
	check("Operator <", (my1 < my2), (real1 < real2));
	check("Operator >=", (my1 >= my2), (real1 >= real2));
	check("Operator >", (my1 > my2), (real1 > real2));
	
}

void	test_stack()
{
	print_header("STACK");
	P("");
	test_stack_constructor();
	P("");
	test_stack_operators();
	P("");
}
