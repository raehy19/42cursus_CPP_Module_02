/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 01:06:40 by rjeong            #+#    #+#             */
/*   Updated: 2023/07/29 01:06:42 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _value;
	static const int _FRACTIONAL_BITS = 8;

public:
	Fixed();

	Fixed(const Fixed &fixed);

	Fixed &operator=(const Fixed &fixed);

	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);
};

#endif

