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

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{
	/*
	** Member types
	*/
	typedef Key key_type;
	typedef T mapped_type;	
	//typedef pair<const key_type,mapped_type> value_type;
	//typdedef Compare key_compare;
	//value_compare	Nested function class to compare elements	see value_comp
	typedef Alloc allocator_type;
	typedef typename allocator_typr::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	//typedef iterator;
	//typedef	const_iterator;	
	//typedef	reverse_iterator;
	//typedef	const_reverse_iterator;
	//typedef difference_type;
	typedef size_t size_type;

	/*
	** Constructor - Destructor - Copy
	*/
	
	
	~map()
	{}
};

} // end namespace ft