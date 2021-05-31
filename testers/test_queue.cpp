/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:49:49 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/31 17:13:47 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	test_queue()
{
	ft::queue<int> q;
	std::queue<int> rq;

	//PL("Queue empty? : ", q.empty());
	print_comp("Empty()", q.empty(), rq.empty());
	print_comp("Size()", q.size(), rq.size());

	q.push(19);
	rq.push(19);
	print_comp("push(19)\nfront()", q.front(), rq.front());
	print_comp("Size()", q.size(), rq.size());
	
	q.push(42);
	rq.push(42);
	print_comp("push(42)\nfront()", q.front(), rq.front());
	print_comp("Size()", q.size(), rq.size());
	print_comp("back()", q.back(), rq.back());

	q.pop();
	rq.pop();
	print_comp("pop()\nfront()", q.front(), rq.front());
	print_comp("Size()", q.size(), rq.size());

	q.pop();
	rq.pop();
	print_comp("pop()\nSize()", q.size(), rq.size());

	//Segfault
	//q.pop();
	//rq.pop();
}