/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_inters_item.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:21:10 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:21:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** Recorre la lista de intersecciones y devuelve la 
 * ultima.
 * @param inter_head Puntero al primer elemento de la lista
 * @return Puntero al ultimo elemento de la lista.
 */
t_inters	*ft_lst_inters_item(t_inters *inter_head)
{
	while (inter_head->next)
		inter_head = inter_head->next;
	return (inter_head);
}
