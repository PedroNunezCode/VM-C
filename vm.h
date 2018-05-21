/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:30:55 by pnunez            #+#    #+#             */
/*   Updated: 2018/05/21 12:27:14 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdbool.h>
# include <stdio.h>

typedef enum{
	PSH, //pushes five to the stack.
	ADD, // pops two values to top of stack.
	POP, // pops the value on the stack.
	SET, // sets regestry to zero.
	HLT  // Stops the program.
}		InstructionSet;

typedef enum{
	A, B, C, D, E, F, // Arrays becuase enums.
	NUM_OF_REGISTERS // Used to see if the number of registers changes.
}				registers;

#endif
