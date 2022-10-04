/*******************************************************
 *	Stack.c
 *
 *
 *	Created by Jean-Philippe Legault
 *
 * Your task is to implement the section with the comment:
 * * TODO: finish implementing this
 ******************************************************/

// allows the usage of `scanf` and `printf`
#include <stdio.h>

// Has the macro definition for EXIT_SUCCESS
#include <stdlib.h>

// allows the usage of `bool`
#include <stdbool.h>

#define STACK_MAX_SIZE 5

/**
 * function:
 *		is_whitespace
 *
 * expects:
 *		a single char
 *
 * returns:
 *  	true when the char is a whitespace character
 *		false otherwise
 */
bool is_whitespace(char in)
{
	return (in == ' ' || in == '\t' || in == '\n' || in == '\r');
}

/**
 * function:
 *		print_stack
 *
 * expects:
 *		a pointer to the root of the stack
 *		a pointer to the current size of the stack
 *
 * Prints a visual representation of the current state of the stack
 */
void print_stack(int *stack, int *size)
{
    int i;
	for(i=0; i<(*size); i++)
	{
		printf("|_ %d _|\n", stack[i] );
	}
	printf("%d elements\n", (*size) );
}

/**
 * function:
 *		push
 *
 * expects:
 *		pointer to the stack
 *		pointer to the size
 *		the value to push
 *
 * returns:
 *  	true when value has been pushed
 *		false otherwise
 *
 * The push function push a value to the passed in stack
 */
bool push(int *stack, int *size, int max_size, int to_push)
{
	/**
	 * TODO: finish implementing this
	 */
    if(*size<max_size){
        stack[*size]=to_push;
        *size=*size+1;
        return true;      
    }
    return false;
}

/**
 * function:
 *		pop
 *
 * expects:
 *		pointer to the stack
 *		pointer to the size
 *		pointer to location to store the popped value
 *
 * returns:
 *  	true when value has been popped
 *		false otherwise
 *
 * The pop function pops a value from the passed in stack and stores it at the to_return location.
 */
bool pop(int *stack, int *size, int *to_return)
{
	/**
	 * TODO: finish implementing this
	 */
    if(*size<=0) return false;
    *size=*size-1;
    *to_return=stack[*size];
    return true;
}

/**
 * function:
 *		peek
 *
 * expects:
 *		pointer to the stack
 *		pointer to the size
 *		pointer to location to store the popped value
 *
 * returns:
 *  	true when value has been peeked
 *		false otherwise
 *
 * The peek function looks at the top value from the stack and stores it at the to_return location.
 */
bool peek(int *stack, int *size, int *to_return)
{
	/**
	 * TODO: finish implementing this
	 */
   if(*size<=0) 
       return false;
    *to_return=stack[*size-1];
    return true;
}

/*******************************************************
 * function implementation
 */

/**
 * function:
 *		main
 *
 * expects:
 *		n/a
 *
 * returns:
 *		EXIT_SUCCESS when program ends.
 *
 * while we are not instructed to exit the program
 *
 *		We read in a char as an instruction :
 *			'u' for push
 *			'o' for pop
 *			'e' for peek
 *			'x' to exit the program
 *
 *		if the instruction is push ('u'),
 *			we read in an integer (you may assume it is a valid integer)
 *			push the read value onto the stack
 *			if failed
 *				printf("failed push\n")
 *			else
 *				print the value pushed
 *
 *		else if the instruction is pop ('o')
 *			we execute the pop function
 *			if failed
 *				printf("failed pop\n")
 *			else
 *				print the value popped
 *
 *		else if the instruction is peek ('e')
 *			we execute the peek function
 *			if failed
 *				printf("failed peek\n")
 *			else
 *				print the value peeked
 *
 *		else if the instruction is exit ('x')
 *			we break out of the loop
 *
 *		else
 *			printf("invalid instruction %c\n", input_instruction);
 */
int main( int argc, char **argv )
{
	// keep track of the max size and the current size of the stack
	int stack_max_size = STACK_MAX_SIZE;
	int stack_current_size = 0;

	// the stack is an array located on the main() function stack frame
	int stack[stack_max_size];

	// initialize our stack with 0 values
    int i;
	for(i=0; i < stack_max_size; i++)
	{
		stack[i] = 0;
	}

	// count the number of instructions (peek, pop, push) that successfully happened
	int successful_instructions = 0;
	bool stop_execution = false;

	while(!stop_execution)
	{
		// read the input instruction (a single character)
		char input_instruction = 0;
		scanf("%c", &input_instruction);

		// the character could be a whitespace so we need to skip those
		if( false == is_whitespace(input_instruction) )
		{
			/**
			 * TODO: finish implementing this
			 */

                if(input_instruction=='u'){
                int to_push;
                scanf("%d",&to_push);
                if(!push(stack,&stack_current_size,stack_max_size,to_push))
                    printf("failed push\n");
                else{
                    printf("%d\n",to_push);
                    successful_instructions++;
                }
            }
            else if(input_instruction=='o'){
                int popped;
                if(!pop(stack,&stack_current_size,&popped))
                    printf("failed pop\n");
                else{
                    printf("%d\n",popped);
                        successful_instructions++;
                    }
            }
            else if(input_instruction=='e'){
                int peeked;
                if(!peek(stack,&stack_current_size,&peeked))
                    printf("failed peek\n");
                else{
                    printf("%d\n",peeked);
                        successful_instructions++;
                    }
            }
            else if(input_instruction=='x'){
                break;
            }
            else
                printf("invalid instruction %c\n",input_instruction);         
		}
       
	}

	printf("Successfully executed %d instructions\n", successful_instructions);
 	print_stack(stack, &stack_current_size);

	return EXIT_SUCCESS;
}
