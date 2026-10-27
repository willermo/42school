/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:58 by doriani           #+#    #+#             */
/*   Updated: 2024/03/22 09:34:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
int
easyfind(T &container, int value) {
    typename T::iterator it =
        std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return *it;
    }
    throw std::runtime_error("Value not found");
}

#endif