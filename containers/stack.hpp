/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:02:33 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/22 14:33:13 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

# include <deque> // A VirEerrr // modif std::deque -> ft::deque
# include "list.hpp"

/*
** TODO
*/

namespace ft
{
template <class T, class Container = ft::list<T> >
class stack
{
	public:
		/*
		** Member types
		*/
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	/*
	** Constructor - Destructor - Copy
	*/
	explicit stack (const container_type& ctnr = container_type())
	:	_cont(ctnr)
	{}

	~stack() {};

	/*
	** Member functions
	*/
	bool empty() const
	{
		return (this->_cont.empty());
	}

	size_type size() const
	{
		return (_cont.size());
	}

	value_type& top()
	{
		return (_cont.back());
	}

	const value_type& top() const
	{
		return (_cont.back());
	}

	void push (const value_type& val)
	{
		_cont.push_back(val);
	}

	void pop()
	{
		_cont.pop_back();
	}

	template <class Tx, class ContainerX>
  		friend bool operator== (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);
	template <class Tx, class ContainerX>
		friend bool operator!= (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);
	template <class Tx, class ContainerX>
		friend bool operator<  (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);
	template <class Tx, class ContainerX>
		friend bool operator<= (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);
	template <class Tx, class ContainerX>
		friend bool operator>  (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);
	template <class Tx, class ContainerX>
		friend bool operator>= (const ft::stack<Tx,ContainerX>& lhs, const ft::stack<Tx,ContainerX>& rhs);

	protected:
		container_type _cont;

};

template <class T, class Container>
  bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont == rhs._cont);
  }

template <class T, class Container>
  bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont != rhs._cont);
  }

template <class T, class Container>
  bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont < rhs._cont);
  }

template <class T, class Container>
  bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont <= rhs._cont);
  }

template <class T, class Container>
  bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont > rhs._cont);
  }

template <class T, class Container>
  bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return (lhs._cont >= rhs._cont);
  }

} // end namespace ft

#endif