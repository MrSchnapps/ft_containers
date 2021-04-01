/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:02:33 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/22 14:33:13 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

#include <deque> // A VirEerrr // modif std::deque -> ft::deque

namespace ft
{
	template <class T, class Container = std::deque<T> >class stack
	{
		public:
			/*
			** Member types
			*/
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

	};
}

#endif