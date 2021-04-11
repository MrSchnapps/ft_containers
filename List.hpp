/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:42:00 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/11 03:08:03 by judecuyp         ###   ########.fr       */
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
		typedef const ft::ListIterConst<T>									const_iterator;
		//typedef ft::ListIterConst<T>									const_iterator;
		typedef	ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t													size_type;

		/*
		** Constructor - Destructor - Copy
		*/
		explicit List (const allocator_type& alloc = allocator_type())
		:	_endlist(NULL)
		{
			_endlist = new (DL_List<T>);
			_endlist->next = _endlist;
			_endlist->prev = _endlist;
		};

		List(T val)
		:	_endlist(NULL)
		{
			add_elem_back(new_elem(val));
		}

		virtual ~List()
		{
			//del_list();
			clear();
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

		const_iterator		begin() const
		{
			return (const_iterator(_endlist->next));
		}

		const_iterator 		end() const
		{
			return (const_iterator(_endlist));
		}

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(end()));
		}

		reverse_iterator	rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(begin()));
		}

		/*
		**	Capacity
		*/
		bool 		empty()
		{
			if (size() == 0)
				return (true);
			else
				return (false);		
		}

		size_type	size() const
		{
			size_type			sz = 0;
			DL_List<value_type>	*tmp = _endlist->next;

			while (tmp != _endlist)
			{
				++sz;
				tmp = tmp->next;
			}
			return (sz);
		}

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
		template <class InputIterator>
		void 		assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(new_elem(*first));
				++first;
			}
		}

		void 		assign (size_type n, const value_type& val)
		{
			clear();
			while (n--)
				push_back(new_elem(val));
		}

		void		push_front(const value_type &val) {add_elem_front(new_elem(val));}

		void		pop_front() {del_one(_endlist->next);}

		void		push_back(const value_type &val) {add_elem_back(new_elem(val));}

		void		pop_back() {del_one(_endlist->prev);}

		iterator 	insert (iterator position, const value_type& val)
		{
			return (iterator(add_elem_before(new_elem(val), position._elem)));
		}

		void 		insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
			{
				add_elem_before(new_elem(val), position._elem);
			}
		}

		template <class InputIterator>
		void		insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				add_elem_before(new_elem(*first), position._elem);
				++first;
			}
		}

		iterator	erase (iterator position)
		{
			iterator ret(position._elem->next);

			del_one(position._elem);
			return (ret);
		}

		iterator	erase (iterator first, iterator last)
		{
			iterator ret(last._elem->next);

			while (first != last)
			{
				del_one(first._elem);
				++first;
			}
			return (ret);
		}

		void		swap(List &x)
		{
			/*if (x == *this)
				return ;*/
			DL_List<T>	*tmp = x._endlist;
			x._endlist = _endlist;
			_endlist = tmp;
		}

		void		resize(size_type n, value_type val = value_type())
		{
			size_t	len = size();
			if (len > n)
			{
				while (len > n)
				{
					pop_back();
					--len;
				}
			}
			else
			{
				while (len < n)
				{
					insert(end(), val);
					++len;
				}
			}
		}

		void		clear()
		{
			DL_List<T> *node = _endlist->next;
			DL_List<T> *tmp;

			while (node != _endlist)
			{
				tmp = node->next;
				delete node;
				node = tmp;
			}
			_endlist->next = _endlist;
			_endlist->prev = _endlist;
		}

	private :
		/*  
		** Allocator size for max_size
		** The real size to calculate max_size is DL_List no "T"
		** Doc https://stackoverflow.com/questions/14148756/what-does-template-rebind-do 
		*/
		typedef typename allocator_type::template rebind<DL_List<T> >::other node_allocator;

		DL_List<T>	*_endlist;

		/*
		** Other
		*/

		/*
		** Using allocator for destroy / deallocate a node
		** https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator
		*/
		void	del_one(DL_List<T> *_elem)
		{
			_elem->prev->next = _elem->next;
			_elem->next->prev = _elem->prev;
			node_allocator().destroy(_elem);
			node_allocator().deallocate(_elem, 1);
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
		}

		DL_List<T>	*add_elem_before(DL_List<T> *add, DL_List<T> *pos)
		{
			pos->prev->next = add;
			add->prev = pos->prev;
			add->next = pos;
			pos->prev = add;
			return (add);
		}
};
} // end namespace ft

#endif