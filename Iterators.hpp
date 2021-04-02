/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:54:27 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/02 22:33:39 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATORS_HPP__
# define __ITERATORS_HPP__

# include <cstddef>

namespace ft
{
/*
** Basic class iterator
*/
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

/*
** Iterators tag
*/
struct bidirectionnal_iterator_tag {};
struct random_access_iterator_tag {};

/*
** Iterator traits
** sources : cplusplus.com/reference/iterator/iterator_traits/
*/
template <class Iterator>
class iterator_traits
{
	public:
		typedef typename Iterator::value_type		value_type;
		typedef typename Iterator::difference_type	difference_type;
		typedef typename Iterator::pointer			pointer;
		typedef typename Iterator::reference		reference;
		typedef typename Iterator::pointer_category	pointer_category;
};

template <class T>
class iterator_traits<T*>
{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	pointer_category;
};

template <class T>
class iterator_traits<const T*>
{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	pointer_category;
};

/*
** Reverse iterator
*/
template <class Iterator>
class reverse_iterator
{
	public:
		/*
		** Member types
		*/
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		/*
		** Constructor - Destructor - Copy
		*/
		reverse_iterator() : _iter() {};
		explicit reverse_iterator(iterator_type it) : _iter(it) {};
		template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) {};
		virtual ~reverse_iterator();

		/*
		** Member functions
		*/
		iterator_type base() const {return (_iter);};

		/*
		** Operators overload
		*/
		reference	operator*() const
		{
			iterator_type copy = _iter;
			return (*(--copy));
		}

		reverse_iterator& operator++()
		{
			--_iter;
			return (*this);
		}

		reverse_iterator& operator++(int)
		{
			reverse_iterator copy = *this;
			++(*this);
			return (*copy);
		}

	private:
		iterator_type _iter;
};

} //end namespace ft
#endif