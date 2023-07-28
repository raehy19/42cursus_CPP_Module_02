/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 05:28:20 by rjeong            #+#    #+#             */
/*   Updated: 2023/07/29 05:28:21 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _FRACTIONAL_BITS = 8;

public:
	Fixed();

	Fixed(const Fixed &fixed);

	Fixed(const int input_int);

	Fixed(const float input_float);

	Fixed &operator=(const Fixed &fixed);

	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;

	int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif


