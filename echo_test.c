/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:09:30 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 13:19:21 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
echo"-n"	    true
echo"-nn"	    true
echo"-nnn"	    true
echo"-nnother"	false
echo"-nn-n"	    false
echo"-n-"	    false
echo"n"         false
echo NULL	    false
*/
/*
CMD                     Resultat attendu
echo                    \n
echo hello world	    hello world\n
echo -n hello world	    hello world
echo -n -n hello	h   ello
echo $USER	            <valeur de USER>\n
echo -n $USER	        <valeur de USER>
*/
