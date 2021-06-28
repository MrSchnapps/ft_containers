/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:55:57 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/08 02:15:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIST_ITER_HPP__
# define __LIST_ITER_HPP__

# include "Utils.hpp"
# include "Iterators.hpp"

namespace ft
{
	
/*
** Iterator for list container
** its a bidirectionnal iterator
*/
template <class T>
class ListIter : public ft::Iterator<ft::bidirectionnal_iterator_tag, T>
{
	public:
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::value_type			value_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::reference			reference;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::pointer				pointer;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::iterator_category	iterator_category;

		DL_List<T>*	_elem;

		ListIter() {};
		ListIter(DL_List<T> *elem): _elem(elem) {};
		ListIter(const ListIter &copy): _elem(copy._elem) {};
		virtual ~ListIter() {};

		ListIter	&operator=(const ListIter &op)
		{
			if (&op == this)
				return (*this);
			this->_elem = op._elem;
			return (*this);
		}

		reference	operator*() {return (_elem->val);};

		pointer		operator->()
		{
			return (&(this->operator*()));
		}
		
		ListIter&	operator++()
		{
			_elem = _elem->next;
			return (*this);
		}

		ListIter	operator++(int)
		{
			ListIter tmp(*this);
			operator++();
			return (tmp);
		}

		ListIter&	operator--()
		{
			_elem = _elem->prev;
			return (*this);
		}

		ListIter	operator--(int)
		{
			ListIter tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool operator==(const ListIter<T> &it1, const ListIter<T> &it2)
		{
			return (it1._elem == it2._elem);
		}

		friend bool operator!=(const ListIter<T> &it1, const ListIter<T> &it2)
		{
			return (it1._elem != it2._elem);
		}
};

/*
** Const ListIter
*/
template <class T>
class ListIterConst : public Iterator<ft::bidirectionnal_iterator_tag, T>
{
	public:
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::value_type				value_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::difference_type			difference_type;
		typedef const typename  ft::Iterator<ft::bidirectionnal_iterator_tag, T>::reference			reference;
		typedef const typename  ft::Iterator<ft::bidirectionnal_iterator_tag, T>::pointer			pointer;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::iterator_category		iterator_category;

		DL_List<T>*	_elem;

		ListIterConst() {};
		ListIterConst(DL_List<T> *elem): _elem(elem) {};
		ListIterConst(const ListIterConst &copy): _elem(copy._elem) {};
		virtual ~ListIterConst() {};

		ListIterConst	&operator=(const ListIterConst &op)
		{
			if (&op == this)
				return (*this);
			this->_elem = op._elem;
			return (*this);
		}

		reference	operator*()
		{
			return (_elem->val);
		}

		pointer		operator->()
		{
			return (&(this->operator*()));
		}

		ListIterConst&	operator++()
		{
			_elem = _elem->next;
			return (*this);
		}

		ListIterConst	operator++(int)
		{
			ListIterConst tmp(*this);
			operator++();
			return (tmp);
		}

		ListIterConst&	operator--()
		{
			_elem = _elem->prev;
			return (*this);
		}

		ListIterConst	operator--(int)
		{
			ListIterConst tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool operator==(const ListIterConst<T> &it1, const ListIterConst<T> &it2)
		{
			return (it1._elem == it2._elem);
		}

		friend bool operator!=(const ListIterConst<T> &it1, const ListIterConst<T> &it2)
		{
			return (it1._elem != it2._elem);
		}
};

} //end namespace ft


#endif