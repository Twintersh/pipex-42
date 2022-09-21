/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:04:46 by twinters          #+#    #+#             */
/*   Updated: 2022/09/21 10:37:09 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
# include <stdio.h>

# define FILE1 argv[1]
# define CMD1 argv[2]
# define CMD2 argv[3]
# define FILE2 argv[4]

int main(int argc, char **argv, char **envp)
{
	int fd;

	// if (argc != 5)
	// 	return (0);
	fd = open(FILE1, O_WRONLY);
	write(fd, "yolo\n", 5);
	return (0);
}
