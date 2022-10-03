/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:06 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:32:06 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# include "structs.h"
# include "draw.h"
# include "hook.h"
# include "parse.h"
# include "utils.h"
# include "keycode.h"

//--------------------------- defines ----------------------------
# define OBJ_SP 0
# define OBJ_PL 1
# define OBJ_CY 2

# define CYL_CAP_TOP 0
# define CYL_CAP_BOT 1

# define WID 1200
# define HEI 900

# define EPSILON 1e-6

# define RED "\\033[0;31m"
# define GRN "\\033[0;32m"
# define YLW "\\033[0;33m"
# define BLU "\\033[0;36m"
# define DFL "\\033[0;37m"

//--------------------------- minirt ----------------------------
int		rt_loop_hook(t_minirt *info);

#endif