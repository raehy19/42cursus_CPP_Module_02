/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:45:02 by rjeong            #+#    #+#             */
/*   Updated: 2023/07/29 08:45:07 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int input_int) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = input_int << Fixed::_FRACTIONAL_BITS;
}

Fixed::Fixed(const float input_float) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int) roundf((input_float) * (1 << Fixed::_FRACTIONAL_BITS));
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

int Fixed::toInt() const {
	return (this->_value >> Fixed::_FRACTIONAL_BITS);
}

float Fixed::toFloat() const {
	return (((float) this->_value) / ((float) (1 << Fixed::_FRACTIONAL_BITS)));
}

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	const Fixed temp(this->toFloat());
	this->_value++;
	return (temp);
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	const Fixed temp(this->toFloat());
	this->_value--;
	return (temp);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
