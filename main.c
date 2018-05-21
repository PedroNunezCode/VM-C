/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:42:33 by pnunez            #+#    #+#             */
/*   Updated: 2018/05/21 12:27:13 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

const int program[] = {
	PSH, 5,
	PSH, 5,
	ADD,
	POP,
	HLT
};
/*The program above will push 5 and 6 to the stack, Execute the add instruction
 * which will pop the two values on top of the stack, add them together and the
 * pop instruction will print them for debugging purposes.*/
int ip = 0;
int sp = -1;
int stack[256];
bool running = true;

int fetch()
{
		return(program[ip]);
}

void eval(int instru){
	switch (instru) {
		case HLT:{
			running = false;
			break;
		}
		case PSH:{
			sp++;
			stack[sp] = program[++ip];
			break;
		}
		case POP:{
			int val_popped = stack[sp--];
			//print it for debugging purposes.
			printf("Popped:%d\n", val_popped);
		}
		case ADD:{
			// Pop stack and store it into a.
			int a = stack[sp--];
			// Pop the TOP of the stack and set it equal to b.
			int b = stack[sp--];
			int result = b + a;
			sp++; // incriment stack pointer.
			stack[sp] = result;
			break;
		}
	}
}

int main()
{
	while (running)
	{
		eval(fetch());
		ip++;// increment the ip every iteration.
	}

	return (0);
}
