/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:44:56 by rjeong            #+#    #+#             */
/*   Updated: 2023/07/29 08:44:57 by rjeong           ###   ########.fr       */
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

	bool operator>(const Fixed &fixed) const;

	bool operator<(const Fixed &fixed) const;

	bool operator>=(const Fixed &fixed) const;

	bool operator<=(const Fixed &fixed) const;

	bool operator==(const Fixed &fixed) const;

	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;

	Fixed operator-(const Fixed &fixed) const;

	Fixed operator*(const Fixed &fixed) const;

	Fixed operator/(const Fixed &fixed) const;

	Fixed &operator++(void);

	Fixed operator++(int);

	Fixed &operator--(void);

	Fixed operator--(int);

	static Fixed &max(Fixed &fixed1, Fixed &fixed2);

	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

	static Fixed &min(Fixed &fixed1, Fixed &fixed2);

	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif


