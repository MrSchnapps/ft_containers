/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:25:30 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/31 16:21:35 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __QUEUE_HPP__
# define __QUEUE_HPP__

#include "list.hpp"

namespace ft
{

template <class T, class Container = ft::list<T> >
	class queue
{
	public:
		/*
		** Member types
		*/	
		typedef T			value_type;
		typedef	Container	container_type;
		typedef size_t		size_type;

		/*
		** Constructor - Destructor - Copy
		*/
		explicit queue (const container_type& ctnr = container_type())
		:	_cont(ctnr)
		{}

		~queue() {}

		/*
		** Member functions
		*/
		bool empty() const
		{
			return (this->_cont.empty());
		}

		size_type size() const
		{
			return (this->_cont.size());
		}
		
		value_type& front()
		{
			return (this->_cont.front());
		}
		
		const value_type& front() const
		{
			return (this->_cont.front());
		}

		value_type& back()
		{
			return (this->_cont.back());
		}
		
		const value_type& back() const
		{
			return (this->_cont.back());
		}

		void push (const value_type& val)
		{
			this->_cont.push_back(val);
		}

		void pop()
		{
			this->_cont.pop_front();
		}


	template <class Tx, class ContainerX>
		friend bool operator== (const queue<Tx,ContainerX>& lhs, const queue<Tx,ContainerX>& rhs);

	template <class Tx, class ContainerX>
		friend bool operator!= (const ft::queue<Tx,ContainerX>& lhs, const ft::queue<Tx,ContainerX>& rhs);

	template <class Tx, class ContainerX>
		friend bool operator<  (const ft::queue<Tx,ContainerX>& lhs, const ft::queue<Tx,ContainerX>& rhs);

	template <class Tx, class ContainerX>
		friend bool operator<= (const ft::queue<Tx,ContainerX>& lhs, const ft::queue<Tx,ContainerX>& rhs);

	template <class Tx, class ContainerX>
		friend bool operator>  (const ft::queue<Tx,ContainerX>& lhs, const ft::queue<Tx,ContainerX>& rhs);

	template <class Tx, class ContainerX>
		friend bool operator>= (const ft::queue<Tx,ContainerX>& lhs, const ft::queue<Tx,ContainerX>& rhs);

	protected:
		container_type _cont;
	
};

template <class T, class Container>
	bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont == rhs._cont);
}

template <class T, class Container>
	bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont != rhs._cont);
}

template <class T, class Container>
	bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont < rhs._cont);
}

template <class T, class Container>
	bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont <= rhs._cont);
}

template <class T, class Container>
	bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont > rhs._cont);
}

template <class T, class Container>
	bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
	return (lhs._cont >= rhs._cont);
}
	
} //End namespace ft

#endif
