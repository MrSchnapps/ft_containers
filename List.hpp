/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:42:00 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/02 15:02:09 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIST_HPP__
# define __LIST_HPP__

# include <memory>
# include "Utils.hpp"
# include "ListIter.hpp"

namespace ft
{
template <class T, class Alloc = std::allocator<T> > 
class List
{
	public :
		/*
		** Member types
		*/
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef	ft::ListIter<T>											iterator;
		typedef ft::ListIterConst<T>									const_iterator;
		//typedef	ft::ListIter<T>								reverse_iterator; //modifier literateur en reverse wsh
		// ... other iterators
		//other
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t													size_type;

		/*
		** Constructor - Destructor - Copy
		*/
		explicit List (const allocator_type& alloc = allocator_type())
		:	_endlist(NULL),
			_size(1)
		{
			_endlist = new (DL_List<T>);
			_endlist->next = _endlist;
			_endlist->prev = _endlist;
		};

		List(T val)
		:	_endlist(NULL),
			_size(1)
		{
			add_elem_back(new_elem(val));
		}

		virtual ~List()
		{
			del_list();
			delete _endlist;
		}

		/*
		** Asked functions
		*/

		/*
		** Iterators
		*/
		iterator			begin()
		{
			return (iterator(_endlist->next));
		}

		iterator 			end()
		{
			return (iterator(_endlist));
		}

		/*reverse_iterator	rbegin()
		{
			
		}

		reverse_iterator	rend()
		{
			
		}*/

		/*
		**	Capacity
		*/
		bool 		empty()
		{
			if (_size == 0)
				return (true);
			else
				return (false);		
		}

		size_type	size() const {return (_size);}

		size_type	max_size() const {return (node_allocator().max_size());}

		/*
		** Element access
		*/
		reference		front() {return (_endlist->next->val);}

		const_reference	front() const {return (_endlist->next->val);}

		reference		back() {return (_endlist->prev->val);}

		const_reference	back() const {return (_endlist->prev->val);}
		
		/*
		** Modifiers
		*/
		void	push_front(const value_type &val) {add_elem_front(new_elem(val));}

		void	push_back(const value_type &val) {add_elem_back(new_elem(val));}

	private :
		/*  
		** Allocator size for max_size
		** The real size to calculate max_size is DL_List no "T"
		** Doc https://stackoverflow.com/questions/14148756/what-does-template-rebind-do 
		*/
		typedef typename allocator_type::template rebind<DL_List<T> >::other node_allocator;

		DL_List<T>	*_endlist;
		size_type	_size;

		/*
		** Other
		*/
		void	del_list()
		{
			DL_List<T> *begin;
			DL_List<T> *tmp;

			begin = _endlist->next;
			while (begin != _endlist)
			{
				tmp = begin->next;
				delete begin;
				begin = tmp;
			}
		}

		DL_List<T> *new_elem(const value_type &val)
		{
			DL_List<T> *n = new (DL_List<T>);

			n->next = NULL;
			n->prev = NULL;
			n->val = val;
			return (n);
		}

		void	add_elem_back(DL_List<T> *elem)
		{
			elem->prev = _endlist->prev;
			elem->next = _endlist;
			if (_endlist->next == _endlist)
				_endlist->next = elem;
			else
				_endlist->prev->next = elem;
			_endlist->prev = elem;
			_size += 1;
		}

		void	add_elem_front(DL_List<T> *elem)
		{
			elem->next = _endlist->next;
			elem->prev = _endlist;
			if (_endlist->prev == _endlist)
				_endlist->prev = elem;
			else
				_endlist->next->prev = elem;
			_endlist->next = elem;
			_size += 1;
		}
};
} // end namespace ft

#endif