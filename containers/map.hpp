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
		typedef ft::MapIter<BST_List<value_type>, key_compare>	iterator;
		//typedef	const_iterator;	
		//typedef	reverse_iterator;
		//typedef	const_reverse_iterator;
		//typedef	difference_type;
		typedef size_t size_type;

		/*
		** Constructor - Destructor - Copy
		*/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{}
		
		map (const map& x)
		{}
		
		~map() {}

	private:
		BST_List<T>	*_root;
		Alloc 		_alloc;

};

} // end namespace ft

#endif