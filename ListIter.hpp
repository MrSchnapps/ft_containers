/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:55:57 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/01 21:14:20 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIST_ITER_HPP__
# define __LIST_ITER_HPP__

# include "utils.hpp"

namespace ft
{
template <class T>
class ListIter : ft::bidirectionnal_iterator_tag
{
	public:
		typedef T& reference;
		typedef T* pointer;

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

		friend bool operator==(const ListIter<T> &it1, const ListIter<T> &it2)
		{
			return (it1 == it2);
		}

		friend bool operator!=(const ListIter<T> &it1, const ListIter<T> &it2)
		{
			return (it1._elem != it2._elem);
		}
};
}


#endif