/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:42:06 by silee             #+#    #+#             */
/*   Updated: 2022/05/31 16:43:23 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    so_long(char *file)
{
    t_data  *g_data;

    check_valid_map(g_data, file);
    
}

int main(int argc, char **argv)
{
    so_long(argv[1]);
}