/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** validate.c — ตรวจสอบว่า argument แต่ละตัวเป็น valid 32-bit integer
**
** count_digits(s, i, neg):
**   วนอ่านตัวเลขจาก position i เป็นต้นไป
**   ตรวจ overflow ด้วย long (> 2147483648 = early exit)
**   ตรวจว่าหลังตัวเลขไม่มีอักขระอื่น
**   คืน range ที่ถูก: neg → max 2147483648, pos → max 2147483647
**
** valid_int(s):
**   ตรวจ string ว่าเป็น integer valid หรือไม่
**   รองรับ sign +/- นำหน้า (ต้องมีตัวเลขตามหลัง)
**   เรียก count_digits สำหรับส่วนตัวเลข
*/

#include "push_swap.h"

static int	count_digits(const char *s, int i, int neg)
{
	long	n;

	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		if (n > 2147483648L)
			return (0);
		i++;
	}
	if (s[i])
		return (0);
	if (neg)
		return (n <= 2147483648L);
	return (n <= 2147483647L);
}

int	valid_int(const char *s)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (!s[0])
		return (0);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	if (!s[i])
		return (0);
	return (count_digits(s, i, neg));
}
