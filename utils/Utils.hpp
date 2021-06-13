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
# include <utility>
# include <iostream>
# include <string>

# define P(x) std::cout << x << std::endl;
# define PP(x) std::cout << "|" << x << "|" << std::endl;
# define PL(name, x) std::cout << name << x << std::endl;

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

template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <typename K, typename V>
std::pair<K, V>	make_pair(K key, V value)
{
	std::pair<K, V> p;

	p.first = key;
	p.second = value;
	return (p);
}

template <typename T>
struct BST_List
{
	BST_List	*parent;
	BST_List	*right;
	BST_List	*left;

	T _v;

	BST_List()
	:	right(NULL),
		left(NULL),
		parent(NULL)
	{}

	BST_List(const T &v, BST_List *p = NULL, BST_List *r = NULL, BST_List *l = NULL)
	:	_v(v),
		right(r),
		left(l),
		parent(p)
	{}

	BST_List(const BST_List &copy)
	:	_v(copy._v),
		right(copy.right),
		left(copy.left),
		parent(copy.parent)
	{}

	BST_List	&operator=(const BST_List &op)
	{
		if (*op == *this)
			return (*this);
		_v = op._v;
		right = op.right;
		left = op.left;
		parent = op.parent;
		return (*this);
	}

	virtual ~BST_List() {}

	bool operator==(const BST_List &cmp)
	{
		return ((_v == cmp._v));
	}
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

	DL_List(T v, DL_List *nxt = NULL, DL_List *prv = NULL)
	:	next(nxt),
		prev(prv),
		val(v)
	{}
};

} //end namespace ft

#endif