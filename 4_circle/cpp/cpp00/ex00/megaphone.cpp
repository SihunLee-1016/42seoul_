/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:30:00 by silee             #+#    #+#             */
/*   Updated: 2022/10/07 14:50:41 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
int main(int ac, char **av)
{
    int i = 1;
    int j = 0;

    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (i = 1 ; i < ac; i++)
        {
            j = 0;
            while (av[i][j])
            {
                av[i][j] = toupper(av[i][j]);
                std::cout << av[i][j];
                j++;
            }
            std::cout << " ";
        }
    }
    std::cout<<std::endl;
    return (0);
}