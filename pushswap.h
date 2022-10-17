/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:27:19 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/23 12:55:06 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# define ASC 1
# define DSC 2
# define JUMP 2
# define SHOW 1
# define CLEAR 2
# define INPUT 4
# define CHECKER 128
# define NOT_SHOW 16
# define A 16
# define B 32
# define SWAP 1
# define PUSH 2
# define ROTATE 4
# define R_ROTATE 8
# define NOT 2
# define FREE 4
# define ERROR_OUT 8

/* typedef struct s_dlist
** {
** 	ssize_t			value;
** 	struct s_dlist	*next;
** 	struct s_dlist	*pre;
** }				t_dlist;
*/

typedef struct s_stack
{
	t_dlist		*a;
	t_dlist		*b;
	int			cnt;
	int			show;
}				t_stack;

typedef struct s_parse
{
	int			argc_idx;
	int			key;
	int			is_find;
	int			temp;
	t_dlist		*list_temp;
}				t_parse;

typedef struct s_atoi
{
	long long	sign;
	long long	sum;
	int			cnt;
}				t_atoi;

typedef struct s_print
{
	size_t		len_a;
	size_t		len_b;
	size_t		max_len;
	size_t		max_width;
}				t_print;

typedef struct s_pivot
{
	ssize_t	pivot_top;
	size_t	more;
	size_t	cnt;
	size_t	ra;
	size_t	rb;
	ssize_t	pivot_bot;
	size_t	rra;
	size_t	rrb;
	size_t	pa;
	size_t	pb;
	size_t	ok;
}				t_pivot;

typedef struct s_dlist_pivot
{
	t_dlist	*mov;
	t_dlist	*pos;
	size_t	cnt;
	size_t	i;
	size_t	j;
	size_t	more;
}				t_dlist_pivot;

typedef struct s_three_value
{
	ssize_t		v1;
	ssize_t		v2;
	ssize_t		v3;
}				t_three;

/*
** Sort_stack
*/
int			fn_sort_atob(t_stack *stack, size_t cycle);
int			fn_rra_atob(t_stack *stack, size_t cycle);
int			fn_sort_btoa(t_stack *stack, size_t size);
int			fn_rrb_btoa(t_stack *stack, size_t size);

/*
**	Sort_ small_case
*/
int			fn_sort_small_case(t_stack *stack, size_t size, int key);
int			fn_sort_a(t_stack *stack, int key);
int			fn_sort_b(t_stack *stack, int key);
int			fn_sort_c(t_stack *stack, int key);
int			fn_sort_d(t_stack *stack, int key);
int			fn_sort_e(t_stack *stack, int key);
int			fn_sort_f(t_stack *stack, int key);
int			fn_sort_small_case_rra(t_stack *stack, size_t size, int key);
int			fn_sort_a_rra(t_stack *stack, int key);
int			fn_sort_b_rra(t_stack *stack, int key);
int			fn_sort_c_rra(t_stack *stack, int key);
int			fn_sort_d_rra(t_stack *stack, int key);
int			fn_sort_e_rra(t_stack *stack, int key);
int			fn_sort_f_rra(t_stack *stack, int key);

/*
** Push_Swap Operations
*/
char		sa(t_stack *stack, char key);
char		sb(t_stack *stack, char key);
char		ss(t_stack *stack);
char		pa(t_stack *stack, char key, t_pivot *pvt);
char		pb(t_stack *stack, char key, t_pivot *pvt);
char		ra(t_stack *stack, char key, t_pivot *pvt);
char		rb(t_stack *stack, char key, t_pivot *pvt);
char		rr(t_stack *stack);
char		rra(t_stack *stack, char key);
char		rrb(t_stack *stack, char key);
char		rrr(t_stack *stack);

/*
** ERROR handler
*/
int			fn_free(t_dlist **head, int key);
int			ft_abs(int nbr);

/*
**	Parse_argv
*/
void		fn_is_there_option(char *str, char ***argv, int *cnt, int argc);
void		fn_is_other_option(char **str, int *cnt);
int			fn_clear_input_option(int *key);
void		fn_argv_to_list(int argc, char **argv, t_dlist **stack);
int			fn_is_argc_end(char **argv, t_parse *parse);
void		fn_mv_atoi_init(t_atoi *info);

/*
**	Print Frame - List or Operation
*/
void		fn_listprint(t_stack *stack, int key);
void		fn_list_print_workhorse(t_dlist **a, t_dlist **b, int *key);

/*
**	sort util
*/
int			fn_issort_dlist_asc(t_dlist **head, size_t size);
int			fn_issort_dlist_dsc(t_dlist **head, size_t size);
int			fn_push_size(t_stack *stack, size_t size);
int			fn_r_rotate_size(t_stack *stack, size_t size, int key);

/*
**	Pivot util
*/
void		fn_init_pivot(t_pivot *pivot);
void		ft_dlist_find_pivot_head(t_dlist *lst, size_t cycle, t_pivot *info);
void		ft_dlist_find_pivot_tail(t_dlist *lst, size_t cycle, t_pivot *info);

/*
**	Work_Horse
*/
void		fn_op_optimize(t_stack *stack, char key);
int			fn_operation(char opt, t_stack *stack, int show);
int			fn_op_net(t_stack *stack, char key);
void		fn_print_arr_init(int *print);
void		fn_is_printable(int key);

/*
**	Checker Func
*/
void		fn_check_input(t_stack *stack);

#endif
