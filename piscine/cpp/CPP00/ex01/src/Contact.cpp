/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:19:20 by doriani           #+#    #+#             */
/*   Updated: 2023/11/27 18:09:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():  
    firstName(""),
    lastName(""),
    nickname(""),
    phoneNumber(""),
    darkestSecret("")
{}
Contact::Contact
(
    const std::string& _firstName,
    const std::string& _lastName,
    const std::string& _nickname,
    const std::string& _phoneNumber,
    const std::string& _darkestSecret
):  firstName(_firstName),
    lastName(_lastName),
    nickname(_nickname),
    phoneNumber(_phoneNumber),
    darkestSecret(_darkestSecret)
{}

std::string Contact::getFirstName() const    { return firstName; };
std::string Contact::getLastName() const     { return lastName; };
std::string Contact::getNickname() const     { return nickname; };
std::string Contact::getPhoneNumber() const  { return phoneNumber; };
std::string Contact::getSecret() const       { return darkestSecret; };
