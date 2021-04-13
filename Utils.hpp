/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:17:57 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/13 16:13:02 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <cstddef>

# define P(x) std::cout << x << std::endl;

namespace ft
{

/*
** http://www.cplusplus.com/reference/functional/binary_function/
*/
template <class Arg1, class Arg2, class Result>
struct binary_function {
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
};


template <typename T>
struct DL_List
{
	DL_List *next;
	DL_List *prev;
	T 		val;

	DL_List()
	:	next(NULL),
		prev(NULL)
	{}
};
} //end namespace ft

#endif