/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:17:57 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/01 17:56:55 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <cstddef>

namespace ft
{ 
template <class Category, class T, class Distance=ptrdiff_t,
class Pointer = T*, class Reference = T&>
struct Iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	pointer_category;
};

struct bidirectionnal_iterator_tag {};

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

	/*DL_List(T data)
	:	next(NULL),
		prev(NULL),
		val(data)
	{}*/
};
}

#endif