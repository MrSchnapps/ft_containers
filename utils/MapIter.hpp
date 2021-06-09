/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mapiter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:51:55 by judecuyp          #+#    #+#             */
/*   Updated: 2021/06/07 20:51:55 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAPITER_HPP__
# define __MAPITER_HPP__

# include "Utils.hpp"
# include "Iterators.hpp"

namespace ft
{

template <typename T, class Compare>
class MapIter : /*public ft::Iterator<ft::bidirectionnal_iterator_tag, T>*/
{
	public:
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::value_type			value_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::reference			reference;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::pointer				pointer;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::iterator_category	iterator_category;

	BST_List<T>	*_elem;
	BST_List<T>	*_endlist;
	Comp		_comp;

	/*
	** Constructor - Destructor - Copy
	*/
	MapIter(const Compare &comp = Compare())
	:	_elem(NULL),
		_endlist(NULL),
		_comp(comp)
	{}

	MapIter(const MapIter &copy)
	:	_elem(copy._elem),
		_endlist(copy._endlist),
		_comp(copy._comp)
	{}

	MapIter(T *elem, T *endlist, const Compare &comp = Compare())
	:	_elem(elem),
		_endlist(endlist),
		_comp(comp)
	{}

	MapIter	&operator=(const MapIter &op)
	{
		if (op == *this)
			return (*this);
		_elem(op._elem);
		_endlist(op._endlist);
		_comp(op._comp);
		return (*this);
	}

	virtual ~MapIter() {}

	/*
	** Operators
	*/
	reference operator*() const
	{
		return (this->_elem->_v);
	}

	pointer operator->() const
	{
		return (&this->_elem->_v);
	}

	MapIter &operator++()
	{
		T* tmp = _elem;
	}

	MapIter &operator++(int)
	{
		MapIter tmp(*this);
		operator++();
		return(tmp);
	}

	MapIter &operator--()
	{
		
	}

	MapIter &operator--(int)
	{
		MapIter tmp(*this);
		operator--();
		return(tmp);
	}

	friend bool	operator==(const MapIter &it)
	{
		return ((this->_elem == it._elem));
	}

	friend bool	operator!=(const MapIter &it)
	{
		return ((this->_elem->p != it._elem->p));
	}
};

} // End namespace ft
#endif