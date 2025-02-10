/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:15:16 by aybelaou          #+#    #+#             */
/*   Updated: 2024/11/14 19:20:24 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, const char c);
int	ft_printchar(const char c);
int	ft_printnbr(int n);
int	ft_printstr(const char *s);
int	ft_printptr(void *ptr);
int	ft_printpercent(void);
int	ft_printunbr(unsigned int n);
int	ft_printhex(uintptr_t hex, const char c);
#endif