#ifndef S_SHELL
#define S_SHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

/*Global variables*/
extern struct INFO info;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct List - linked list of 2 strings
 * @str: first string
 * @str2: second string
 * @next: pointer to the next node
*/
typedef struct List
{
	char *str;
	char *str2;
	struct List *next;
} list_t;


/**
 * struct INFO - structure of command details.
 * @command_count: position of command entry.
 * @status: exit status.
 * @argc: argument count.
 * @argv: name of the program.
 * @input: string entered by user.
 * @command: command entered.
 * @commands_To_run:  what to consider in the string.
 * @buffer_index: position specifier in buffer.
 * @BUFFER_SIZE: size of buffer.
 * @buffer: array of buffer strings.
 * @functions: pointer to functions.
 * @stack: stack we work at.
 * @top: top elem of stack.
 * @MODE: max int value.
 * @fn: file take input from.
 * @exit: exit command
*/
struct INFO
{
	u_int64_t command_count;
	int status;

	int argc;
	char **argv;

	char *input;
	char **command;
	char ***commands_To_run;

	int buffer_index;
	int BUFFER_SIZE;
	char *buffer;

	instruction_t functions[20];

	stack_t *stack;
	stack_t *top;

	int MODE;
	int fn;
	int exit;
};

/*Custom Functions*/
int monty(void);
int execute_Command(void);

/* Geting Command Functions*/
int get_input(void);
int get_Command(void);

/*monty Functions*/
/*1*/
int set_info(void);
int set_fuction(void);
int set_buffer(void);
void FreeInfo(void);
void _exitS(void);
/*2*/
void MalocError(void);
void CodeError(char *str);
/*3*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/*4*/
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
/*5*/
void nop(stack_t **stack, unsigned int line_number);

/*Print functions*/
int _putchar(char c);
void _puts(char *str);
void _perror(char *str);
void print_int(int n);
int _getline(char **lineptr, int *len, int fd);

/*List Functions */
/*1*/
size_t print_dlistint(const stack_t *h);
size_t print_end_dlistint(const stack_t *h);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void rem_node(stack_t *head);
void free_dlistint(stack_t *head);

/* Integer Functons */
int _isInt(char *s);
char *int_to_string(int n);
int64_t _stoi(char *s);

/*String Functions*/
/*1*/
int _strlen(char *str);
int str_find(char *str, char c);
int _strcnt(char *str, char *drl);
char **_strtok(char *str, char *drl);
void freeString(char **str);
/*2*/
int _strcpy(char **str1, char *str2);
int _lcp(char *str1, char *str2);
void _appendStr(char **str1, char *str2);
int _strcomp(char *str1, char *str2);
void _reverse(char *s);
/*3*/
int _sstrlen(char **str);
char *_strSuffix(char *str, int index);
int _strassemb(char **str, char **s);
void free_2d_String(char ***str);

#endif
