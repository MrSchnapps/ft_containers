/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:53:52 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/31 19:53:52 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "../utils/Utils.hpp"
# include "../utils/MapIter.hpp"
# include <utility>

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map
{
	public:
		/*
		** Member types
		*/
		typedef Key											key_type;
		typedef T											mapped_type;	
		typedef std::pair<key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			friend class map<key_type, mapped_type, key_compare, Alloc>;

			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

			public:
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}


		};
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		//typedef ft::MapIter<value_type, key_compare>			iterator;
		typedef ft::ListIter<value_type>						iterator;
		typedef ft::ListIterConst<value_type>					const_iterator;
		//typedef	reverse_iterator;
		//typedef	const_reverse_iterator;
		//typedef	difference_type;
		typedef size_t size_type;

		/*
		** Constructor - Destructor - Copy
		** endlist is set to pair<int, mapped type> int is for stock the number of elements (in ubuntu if we print end()->first we can see the size) ??? a voir
		*/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_comp(comp)
		{
			_endlist = new (DL_List<std::pair<int, mapped_type> >);  //Voir si on enleve pas ça mdr
			_endlist->next = _endlist;
			_endlist->prev = _endlist;
		}

		/*template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_comp(comp),
			_endlist(NULL)

		{}
		
		map (const map& x)
		{}*/
		
		~map()
		{
			this->clear();
			delete _endlist;
		}

		/*
		** Iterators
		*/
		iterator begin()
		{
			return (iterator(_endlist->next));
		}

		const_iterator begin() const
		{
			return (const_iterator(_endlist->next));
		}

		iterator end()
		{
			return (iterator(_endlist));	
		}

		const_iterator end() const
		{
			return (const_iterator(_endlist));
		}

		/*
		** Modifiers
		*/
		std::pair<iterator,bool> insert (const value_type& val)
		{
			DL_List<value_type> *to_add;
			DL_List<value_type> *tmp = _endlist->next;

			//BST_List<T> *new_elem = new BST_List<T>();
			while (tmp != _endlist && tmp->val.first < val.first)
			{
				tmp = tmp->next;
			}
			if (tmp != _endlist && tmp->val.first == val.first)
				return (std::pair<iterator, bool>(iterator(tmp), false));
			to_add = new_elem(val);
			add_elem_before(to_add, tmp);
			return (std::pair<iterator, bool>(iterator(to_add), true));
		}

		/*iterator insert (iterator position, const value_type& val)
		{

		}
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{

		}*/

		void clear()
		{
			DL_List<value_type> *node = _endlist->next;
			DL_List<value_type> *tmp;

			while (node != _endlist)
			{
				tmp = node->next;
				DL_List_allocator().destroy(node);
				DL_List_allocator().deallocate(node, 1);
				node = tmp;
			}
			_endlist->next = _endlist;
			_endlist->prev = _endlist;
		}

	private:
		/*
		** Attributs
		*/
		/*BST_List<T>	*_root;
		BST_List<T>	*_endlist;*/
		typedef typename allocator_type::template rebind<DL_List<value_type> >::other DL_List_allocator;

		DL_List<value_type> *_endlist;
		allocator_type 		_alloc;
		key_compare			_comp;


		void		del_one(DL_List<value_type> *_elem)
		{
			_elem->prev->next = _elem->next;
			_elem->next->prev = _elem->prev;
			DL_List_allocator().destroy(_elem);
			DL_List_allocator().deallocate(_elem, 1);
		}

		DL_List<value_type>	*new_elem(const value_type &val)
		{
			//DL_List<value_type> *n = new (DL_List<value_type>);
			DL_List<value_type> *n = DL_List_allocator().allocate(1);
			DL_List_allocator().construct(n, DL_List<value_type>(val));
			
			/*n->next = NULL;
			n->prev = NULL;*/
			//n->val = val;
			return (n);
		}

		void		add_elem_back(DL_List<value_type> *elem)
		{
			elem->prev = _endlist->prev;
			elem->next = _endlist;
			if (_endlist->next == _endlist)
				_endlist->next = elem;
			else
				_endlist->prev->next = elem;
			_endlist->prev = elem;
		}

		void		add_elem_front(DL_List<value_type> *elem)
		{
			elem->next = _endlist->next;
			elem->prev = _endlist;
			if (_endlist->prev == _endlist)
				_endlist->prev = elem;
			else
				_endlist->next->prev = elem;
			_endlist->next = elem;
		}

		DL_List<value_type>	*add_elem_before(DL_List<value_type> *add, DL_List<value_type> *pos)
		{
			pos->prev->next = add;
			add->prev = pos->prev;
			add->next = pos;
			pos->prev = add;
			return (add);
		}

		void		disconnect_elem(DL_List<value_type> *elem)
		{
			if (elem->prev)
				elem->prev->next = elem->next;
			if (elem->next)
				elem->next->prev = elem->prev;
			elem->prev = NULL;
			elem->next = NULL;
		}

		void		swap_elem(DL_List<value_type> *e1, DL_List<value_type> *e2)
		{
			DL_List<value_type> *tmp = e1->prev;

			e1->prev->next = e2;
			e2->next->prev = e1;

			e1->next = e2->next;
			e1->prev = e2;

			e2->next = e1;
			e2->prev = tmp;
		}

};

} // end namespace ft

#endif