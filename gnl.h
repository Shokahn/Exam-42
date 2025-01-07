/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:08:53 by root              #+#    #+#             */
/*   Updated: 2025/01/07 00:25:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLN_H
# define GLN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *get_next_line(int fd);
#endif