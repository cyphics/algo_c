	.file	"linked_list_str.c"
# GNU C17 (GCC) version 14.2.1 20240910 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 14.2.1 20240910, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.27-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64
	.text
	.globl	GetEmptyList
	.type	GetEmptyList, @function
GetEmptyList:
.LFB6:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)	# .result_ptr, .result_ptr
# linked_list_str.c:10:     list.length = 0;
	movl	$0, -32(%rbp)	#, list.length
# linked_list_str.c:11:     list.head = NULL;
	movq	$0, -24(%rbp)	#, list.head
# linked_list_str.c:12:     list.tail = NULL;
	movq	$0, -16(%rbp)	#, list.tail
# linked_list_str.c:13:     return list;
	movq	-40(%rbp), %rcx	# .result_ptr, tmp98
	movq	-32(%rbp), %rax	# list, tmp99
	movq	-24(%rbp), %rdx	# list,
	movq	%rax, (%rcx)	# tmp99, <retval>
	movq	%rdx, 8(%rcx)	#, <retval>
	movq	-16(%rbp), %rax	# list, tmp100
	movq	%rax, 16(%rcx)	# tmp100, <retval>
# linked_list_str.c:14: }
	movq	-40(%rbp), %rax	# .result_ptr,
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	GetEmptyList, .-GetEmptyList
	.globl	IsEmpty
	.type	IsEmpty, @function
IsEmpty:
.LFB7:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# list, list
# linked_list_str.c:17:     return list->head == NULL;
	movq	-8(%rbp), %rax	# list, tmp101
	movq	8(%rax), %rax	# list_3(D)->head, _1
# linked_list_str.c:17:     return list->head == NULL;
	testq	%rax, %rax	# _1
	sete	%al	#, _4
# linked_list_str.c:18: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	IsEmpty, .-IsEmpty
	.globl	Append
	.type	Append, @function
Append:
.LFB8:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# list, list
	movq	%rsi, -32(%rbp)	# value, value
# linked_list_str.c:28:     Node *new = malloc(sizeof(Node));
	movl	$24, %edi	#,
	call	malloc@PLT	#
	movq	%rax, -8(%rbp)	# tmp106, new
# linked_list_str.c:29:     new->value = value;
	movq	-7(%rbp), %rax	# new, tmp107
	movq	-32(%rbp), %rdx	# value, tmp108
	movq	%rdx, (%rax)	# tmp108, new_12->value
# linked_list_str.c:30:     if (IsEmpty(list)) {
	movq	-24(%rbp), %rax	# list, tmp109
	movq	%rax, %rdi	# tmp109,
	call	IsEmpty	#
# linked_list_str.c:30:     if (IsEmpty(list)) {
	testb	%al, %al	# _1
	je	.L6	#,
# linked_list_str.c:31:         list->head = new;
	movq	-24(%rbp), %rax	# list, tmp110
	movq	-8(%rbp), %rdx	# new, tmp111
	movq	%rdx, 8(%rax)	# tmp111, list_15(D)->head
# linked_list_str.c:32:         list->tail = new;
	movq	-24(%rbp), %rax	# list, tmp112
	movq	-8(%rbp), %rdx	# new, tmp113
	movq	%rdx, 16(%rax)	# tmp113, list_15(D)->tail
	jmp	.L7	#
.L6:
# linked_list_str.c:34:         list->tail->next = new;
	movq	-24(%rbp), %rax	# list, tmp114
	movq	16(%rax), %rax	# list_15(D)->tail, _2
# linked_list_str.c:34:         list->tail->next = new;
	movq	-8(%rbp), %rdx	# new, tmp115
	movq	%rdx, 8(%rax)	# tmp115, _2->next
# linked_list_str.c:35:         new->prev = list->tail;
	movq	-24(%rbp), %rax	# list, tmp116
	movq	16(%rax), %rdx	# list_15(D)->tail, _3
# linked_list_str.c:35:         new->prev = list->tail;
	movq	-8(%rbp), %rax	# new, tmp117
	movq	%rdx, 16(%rax)	# _3, new_12->prev
# linked_list_str.c:36:         list->tail = new;
	movq	-24(%rbp), %rax	# list, tmp118
	movq	-8(%rbp), %rdx	# new, tmp119
	movq	%rdx, 16(%rax)	# tmp119, list_15(D)->tail
# linked_list_str.c:37:         if (list->length == 1) {
	movq	-24(%rbp), %rax	# list, tmp120
	movl	(%rax), %eax	# list_15(D)->length, _4
# linked_list_str.c:37:         if (list->length == 1) {
	cmpl	$1, %eax	#, _4
	jne	.L7	#,
# linked_list_str.c:38:             list->head->next = list->tail;
	movq	-24(%rbp), %rax	# list, tmp121
	movq	8(%rax), %rax	# list_15(D)->head, _5
# linked_list_str.c:38:             list->head->next = list->tail;
	movq	-24(%rbp), %rdx	# list, tmp122
	movq	16(%rdx), %rdx	# list_15(D)->tail, _6
# linked_list_str.c:38:             list->head->next = list->tail;
	movq	%rdx, 8(%rax)	# _6, _5->next
.L7:
# linked_list_str.c:41:     list->length++;
	movq	-24(%rbp), %rax	# list, tmp123
	movl	(%rax), %eax	# list_15(D)->length, _7
# linked_list_str.c:41:     list->length++;
	leal	1(%rax), %edx	#, _8
	movq	-24(%rbp), %rax	# list, tmp124
	movl	%edx, (%rax)	# _8, list_15(D)->length
# linked_list_str.c:42: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE8:
	.size	Append, .-Append
	.globl	Prepend
	.type	Prepend, @function
Prepend:
.LFB9:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# list, list
	movq	%rsi, -32(%rbp)	# value, value
# linked_list_str.c:51:     Node *new = malloc(sizeof(Node));
	movl	$24, %edi	#,
	call	malloc@PLT	#
	movq	%rax, -8(%rbp)	# tmp106, new
# linked_list_str.c:52:     new->value = value;
	movq	-8(%rbp), %rax	# new, tmp107
	movq	-32(%rbp), %rdx	# value, tmp108
	movq	%rdx, (%rax)	# tmp108, new_12->value
# linked_list_str.c:53:     if (IsEmpty(list)) {
	movq	-24(%rbp), %rax	# list, tmp109
	movq	%rax, %rdi	# tmp109,
	call	IsEmpty	#
# linked_list_str.c:53:     if (IsEmpty(list)) {
	testb	%al, %al	# _1
	je	.L9	#,
# linked_list_str.c:54:         list->head = new;
	movq	-24(%rbp), %rax	# list, tmp110
	movq	-8(%rbp), %rdx	# new, tmp111
	movq	%rdx, 8(%rax)	# tmp111, list_15(D)->head
# linked_list_str.c:55:         list->tail = new;
	movq	-24(%rbp), %rax	# list, tmp112
	movq	-8(%rbp), %rdx	# new, tmp113
	movq	%rdx, 16(%rax)	# tmp113, list_15(D)->tail
	jmp	.L10	#
.L9:
# linked_list_str.c:57:         new->next = list->head;
	movq	-24(%rbp), %rax	# list, tmp114
	movq	8(%rax), %rdx	# list_15(D)->head, _2
# linked_list_str.c:57:         new->next = list->head;
	movq	-8(%rbp), %rax	# new, tmp115
	movq	%rdx, 8(%rax)	# _2, new_12->next
# linked_list_str.c:58:         list->head->prev = new;
	movq	-24(%rbp), %rax	# list, tmp116
	movq	8(%rax), %rax	# list_15(D)->head, _3
# linked_list_str.c:58:         list->head->prev = new;
	movq	-8(%rbp), %rdx	# new, tmp117
	movq	%rdx, 16(%rax)	# tmp117, _3->prev
# linked_list_str.c:59:         list->head = new;
	movq	-24(%rbp), %rax	# list, tmp118
	movq	-8(%rbp), %rdx	# new, tmp119
	movq	%rdx, 8(%rax)	# tmp119, list_15(D)->head
# linked_list_str.c:60:         if (list->length == 1) {
	movq	-24(%rbp), %rax	# list, tmp120
	movl	(%rax), %eax	# list_15(D)->length, _4
# linked_list_str.c:60:         if (list->length == 1) {
	cmpl	$1, %eax	#, _4
	jne	.L10	#,
# linked_list_str.c:61:             list->tail->prev = list->head;
	movq	-24(%rbp), %rax	# list, tmp121
	movq	16(%rax), %rax	# list_15(D)->tail, _5
# linked_list_str.c:61:             list->tail->prev = list->head;
	movq	-24(%rbp), %rdx	# list, tmp122
	movq	8(%rdx), %rdx	# list_15(D)->head, _6
# linked_list_str.c:61:             list->tail->prev = list->head;
	movq	%rdx, 16(%rax)	# _6, _5->prev
.L10:
# linked_list_str.c:64:     list->length++;
	movq	-24(%rbp), %rax	# list, tmp123
	movl	(%rax), %eax	# list_15(D)->length, _7
# linked_list_str.c:64:     list->length++;
	leal	1(%rax), %edx	#, _8
	movq	-24(%rbp), %rax	# list, tmp124
	movl	%edx, (%rax)	# _8, list_15(D)->length
# linked_list_str.c:65: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE9:
	.size	Prepend, .-Prepend
	.section	.rodata
	.align 8
.LC0:
	.string	"WARNING! Out-of-boud access attempt with Get (index %d)\n"
	.align 8
.LC1:
	.string	"WARNING: Attempt to access NULL pointer in SLLGetAt, index %d.\n"
	.text
	.globl	GetAt
	.type	GetAt, @function
GetAt:
.LFB10:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# list, list
	movl	%esi, -28(%rbp)	# index, index
# linked_list_str.c:75:     if (index >= list->length) {
	movq	-24(%rbp), %rax	# list, tmp106
	movl	(%rax), %eax	# list_22(D)->length, _1
# linked_list_str.c:75:     if (index >= list->length) {
	cmpl	%eax, -28(%rbp)	# _1, index
	jl	.L12	#,
# linked_list_str.c:76:         printf("WARNING! Out-of-boud access attempt with Get (index %d)\n", index);
	movl	-28(%rbp), %eax	# index, tmp107
	movl	%eax, %esi	# tmp107,
	leaq	.LC0(%rip), %rax	#, tmp108
	movq	%rax, %rdi	# tmp108,
	movl	$0, %eax	#,
	call	printf@PLT	#
# linked_list_str.c:77:         return NULL;
	movl	$0, %eax	#, _14
	jmp	.L13	#
.L12:
# linked_list_str.c:80:     if (index < (list->length)/2) {
	movq	-24(%rbp), %rax	# list, tmp109
	movl	(%rax), %eax	# list_22(D)->length, _2
# linked_list_str.c:80:     if (index < (list->length)/2) {
	movl	%eax, %edx	# _2, tmp110
	shrl	$31, %edx	#, tmp110
	addl	%edx, %eax	# tmp110, tmp111
	sarl	%eax	# _3
# linked_list_str.c:80:     if (index < (list->length)/2) {
	cmpl	%eax, -28(%rbp)	# _3, index
	jge	.L14	#,
# linked_list_str.c:82:         current = list->head;
	movq	-24(%rbp), %rax	# list, tmp113
	movq	8(%rax), %rax	# list_22(D)->head, tmp114
	movq	%rax, -8(%rbp)	# tmp114, current
# linked_list_str.c:83:         for (int i = 0; i < index; i++) {
	movl	$0, -16(%rbp)	#, i
# linked_list_str.c:83:         for (int i = 0; i < index; i++) {
	jmp	.L15	#
.L18:
# linked_list_str.c:84:             if (current->next != NULL) {
	movq	-8(%rbp), %rax	# current, tmp115
	movq	8(%rax), %rax	# current_8->next, _4
# linked_list_str.c:84:             if (current->next != NULL) {
	testq	%rax, %rax	# _4
	je	.L16	#,
# linked_list_str.c:85:                 current = current->next;
	movq	-8(%rbp), %rax	# current, tmp116
	movq	8(%rax), %rax	# current_8->next, tmp117
	movq	%rax, -8(%rbp)	# tmp117, current
	jmp	.L17	#
.L16:
# linked_list_str.c:87:                 printf("WARNING: Attempt to access NULL pointer in SLLGetAt, index %d.\n", index);
	movl	-28(%rbp), %eax	# index, tmp118
	movl	%eax, %esi	# tmp118,
	leaq	.LC1(%rip), %rax	#, tmp119
	movq	%rax, %rdi	# tmp119,
	movl	$0, %eax	#,
	call	printf@PLT	#
.L17:
# linked_list_str.c:83:         for (int i = 0; i < index; i++) {
	addl	$1, -16(%rbp)	#, i
.L15:
# linked_list_str.c:83:         for (int i = 0; i < index; i++) {
	movl	-16(%rbp), %eax	# i, tmp120
	cmpl	-28(%rbp), %eax	# index, tmp120
	jl	.L18	#,
	jmp	.L19	#
.L14:
# linked_list_str.c:92:         current = list->tail;
	movq	-24(%rbp), %rax	# list, tmp121
	movq	16(%rax), %rax	# list_22(D)->tail, tmp122
	movq	%rax, -8(%rbp)	# tmp122, current
# linked_list_str.c:93:         for (int i = list->length -1; i > index; i--) {
	movq	-24(%rbp), %rax	# list, tmp123
	movl	(%rax), %eax	# list_22(D)->length, _5
# linked_list_str.c:93:         for (int i = list->length -1; i > index; i--) {
	subl	$1, %eax	#, tmp124
	movl	%eax, -12(%rbp)	# tmp124, i
# linked_list_str.c:93:         for (int i = list->length -1; i > index; i--) {
	jmp	.L20	#
.L23:
# linked_list_str.c:94:             if (current->prev != NULL) {
	movq	-8(%rbp), %rax	# current, tmp125
	movq	16(%rax), %rax	# current_10->prev, _6
# linked_list_str.c:94:             if (current->prev != NULL) {
	testq	%rax, %rax	# _6
	je	.L21	#,
# linked_list_str.c:95:                 current = current->prev;
	movq	-8(%rbp), %rax	# current, tmp126
	movq	16(%rax), %rax	# current_10->prev, tmp127
	movq	%rax, -8(%rbp)	# tmp127, current
	jmp	.L22	#
.L21:
# linked_list_str.c:97:                 printf("WARNING: Attempt to access NULL pointer in SLLGetAt, index %d.\n", index);
	movl	-28(%rbp), %eax	# index, tmp128
	movl	%eax, %esi	# tmp128,
	leaq	.LC1(%rip), %rax	#, tmp129
	movq	%rax, %rdi	# tmp129,
	movl	$0, %eax	#,
	call	printf@PLT	#
.L22:
# linked_list_str.c:93:         for (int i = list->length -1; i > index; i--) {
	subl	$1, -12(%rbp)	#, i
.L20:
# linked_list_str.c:93:         for (int i = list->length -1; i > index; i--) {
	movl	-12(%rbp), %eax	# i, tmp130
	cmpl	-28(%rbp), %eax	# index, tmp130
	jg	.L23	#,
.L19:
# linked_list_str.c:101:     return current->value;
	movq	-8(%rbp), %rax	# current, tmp131
	movq	(%rax), %rax	# current_11->value, _14
.L13:
# linked_list_str.c:102: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE10:
	.size	GetAt, .-GetAt
	.section	.rodata
	.align 8
.LC2:
	.string	"Warning: Attempt to remove first of empty list."
	.text
	.globl	RemoveEmptyOrOne
	.type	RemoveEmptyOrOne, @function
RemoveEmptyOrOne:
.LFB11:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# list, list
# linked_list_str.c:105:     if (list->length == 0) {
	movq	-24(%rbp), %rax	# list, tmp103
	movl	(%rax), %eax	# list_7(D)->length, _1
# linked_list_str.c:105:     if (list->length == 0) {
	testl	%eax, %eax	# _1
	jne	.L25	#,
# linked_list_str.c:106:         printf("Warning: Attempt to remove first of empty list.\n");
	leaq	.LC2(%rip), %rax	#, tmp104
	movq	%rax, %rdi	# tmp104,
	call	puts@PLT	#
# linked_list_str.c:107:         return 0;
	movl	$0, %eax	#, _4
	jmp	.L26	#
.L25:
# linked_list_str.c:110:         value = list->head->value;
	movq	-24(%rbp), %rax	# list, tmp105
	movq	8(%rax), %rax	# list_7(D)->head, _2
# linked_list_str.c:110:         value = list->head->value;
	movq	(%rax), %rax	# _2->value, tmp106
	movq	%rax, -8(%rbp)	# tmp106, value
# linked_list_str.c:111:         free(list->head);
	movq	-24(%rbp), %rax	# list, tmp107
	movq	8(%rax), %rax	# list_7(D)->head, _3
# linked_list_str.c:111:         free(list->head);
	movq	%rax, %rdi	# _3,
	call	free@PLT	#
# linked_list_str.c:112:         list->head = NULL;
	movq	-24(%rbp), %rax	# list, tmp108
	movq	$0, 8(%rax)	#, list_7(D)->head
# linked_list_str.c:113:         list->tail = NULL;
	movq	-24(%rbp), %rax	# list, tmp109
	movq	$0, 16(%rax)	#, list_7(D)->tail
# linked_list_str.c:114:         list->length = 0;
	movq	-24(%rbp), %rax	# list, tmp110
	movl	$0, (%rax)	#, list_7(D)->length
# linked_list_str.c:115:         return value;
	movq	-8(%rbp), %rax	# value, _4
.L26:
# linked_list_str.c:117: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE11:
	.size	RemoveEmptyOrOne, .-RemoveEmptyOrOne
	.globl	RemoveFirst
	.type	RemoveFirst, @function
RemoveFirst:
.LFB12:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# list, list
# linked_list_str.c:120:     if (list->length <= 1) {
	movq	-8(%rbp), %rax	# list, tmp101
	movl	(%rax), %eax	# list_5(D)->length, _1
# linked_list_str.c:120:     if (list->length <= 1) {
	cmpl	$1, %eax	#, _1
	jg	.L28	#,
# linked_list_str.c:121:         return RemoveEmptyOrOne(list);
	movq	-8(%rbp), %rax	# list, tmp102
	movq	%rax, %rdi	# tmp102,
	call	RemoveEmptyOrOne	#
	jmp	.L29	#
.L28:
# linked_list_str.c:123:     return  RemoveAt(list, 0);
	movq	-8(%rbp), %rax	# list, tmp103
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp103,
	call	RemoveAt	#
.L29:
# linked_list_str.c:124: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE12:
	.size	RemoveFirst, .-RemoveFirst
	.globl	RemoveLast
	.type	RemoveLast, @function
RemoveLast:
.LFB13:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# list, list
# linked_list_str.c:127:     if (list->length <= 1) {
	movq	-8(%rbp), %rax	# list, tmp103
	movl	(%rax), %eax	# list_7(D)->length, _1
# linked_list_str.c:127:     if (list->length <= 1) {
	cmpl	$1, %eax	#, _1
	jg	.L31	#,
# linked_list_str.c:128:         return RemoveEmptyOrOne(list);
	movq	-8(%rbp), %rax	# list, tmp104
	movq	%rax, %rdi	# tmp104,
	call	RemoveEmptyOrOne	#
	jmp	.L32	#
.L31:
# linked_list_str.c:130:     return RemoveAt(list, list->length - 1);
	movq	-8(%rbp), %rax	# list, tmp105
	movl	(%rax), %eax	# list_7(D)->length, _2
# linked_list_str.c:130:     return RemoveAt(list, list->length - 1);
	leal	-1(%rax), %edx	#, _3
	movq	-8(%rbp), %rax	# list, tmp106
	movl	%edx, %esi	# _3,
	movq	%rax, %rdi	# tmp106,
	call	RemoveAt	#
.L32:
# linked_list_str.c:131: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE13:
	.size	RemoveLast, .-RemoveLast
	.section	.rodata
	.align 8
.LC3:
	.string	"WARNING! Out-of-boud access attempt with RemoveAt (index %d)\n"
	.text
	.globl	RemoveAt
	.type	RemoveAt, @function
RemoveAt:
.LFB14:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$48, %rsp	#,
	movq	%rdi, -40(%rbp)	# list, list
	movl	%esi, -44(%rbp)	# index, index
# linked_list_str.c:134:     if (list->length <= 1) {
	movq	-40(%rbp), %rax	# list, tmp112
	movl	(%rax), %eax	# list_20(D)->length, _1
# linked_list_str.c:134:     if (list->length <= 1) {
	cmpl	$1, %eax	#, _1
	jg	.L34	#,
# linked_list_str.c:135:         return RemoveEmptyOrOne(list);
	movq	-40(%rbp), %rax	# list, tmp113
	movq	%rax, %rdi	# tmp113,
	call	RemoveEmptyOrOne	#
	jmp	.L35	#
.L34:
# linked_list_str.c:137:     if(index >= list->length) {
	movq	-40(%rbp), %rax	# list, tmp114
	movl	(%rax), %eax	# list_20(D)->length, _2
# linked_list_str.c:137:     if(index >= list->length) {
	cmpl	%eax, -44(%rbp)	# _2, index
	jl	.L36	#,
# linked_list_str.c:138:         printf("WARNING! Out-of-boud access attempt with RemoveAt (index %d)\n", index);
	movl	-44(%rbp), %eax	# index, tmp115
	movl	%eax, %esi	# tmp115,
	leaq	.LC3(%rip), %rax	#, tmp116
	movq	%rax, %rdi	# tmp116,
	movl	$0, %eax	#,
	call	printf@PLT	#
# linked_list_str.c:139:         return 0;
	movl	$0, %eax	#, _15
	jmp	.L35	#
.L36:
# linked_list_str.c:141:     Node *to_remove = list->head;
	movq	-40(%rbp), %rax	# list, tmp117
	movq	8(%rax), %rax	# list_20(D)->head, tmp118
	movq	%rax, -16(%rbp)	# tmp118, to_remove
# linked_list_str.c:143:     for (int i = 0; i < index; i++) {
	movl	$0, -20(%rbp)	#, i
# linked_list_str.c:143:     for (int i = 0; i < index; i++) {
	jmp	.L37	#
.L38:
# linked_list_str.c:144:       to_remove = to_remove->next;
	movq	-16(%rbp), %rax	# to_remove, tmp119
	movq	8(%rax), %rax	# to_remove_13->next, tmp120
	movq	%rax, -16(%rbp)	# tmp120, to_remove
# linked_list_str.c:143:     for (int i = 0; i < index; i++) {
	addl	$1, -20(%rbp)	#, i
.L37:
# linked_list_str.c:143:     for (int i = 0; i < index; i++) {
	movl	-20(%rbp), %eax	# i, tmp121
	cmpl	-44(%rbp), %eax	# index, tmp121
	jl	.L38	#,
# linked_list_str.c:147:     if (to_remove->prev == NULL) {
	movq	-16(%rbp), %rax	# to_remove, tmp122
	movq	16(%rax), %rax	# to_remove_13->prev, _3
# linked_list_str.c:147:     if (to_remove->prev == NULL) {
	testq	%rax, %rax	# _3
	jne	.L39	#,
# linked_list_str.c:148:       list->head = to_remove->next;
	movq	-16(%rbp), %rax	# to_remove, tmp123
	movq	8(%rax), %rdx	# to_remove_13->next, _4
# linked_list_str.c:148:       list->head = to_remove->next;
	movq	-40(%rbp), %rax	# list, tmp124
	movq	%rdx, 8(%rax)	# _4, list_20(D)->head
	jmp	.L40	#
.L39:
# linked_list_str.c:150:         to_remove->prev->next = to_remove->next;
	movq	-16(%rbp), %rax	# to_remove, tmp125
	movq	16(%rax), %rax	# to_remove_13->prev, _5
# linked_list_str.c:150:         to_remove->prev->next = to_remove->next;
	movq	-16(%rbp), %rdx	# to_remove, tmp126
	movq	8(%rdx), %rdx	# to_remove_13->next, _6
# linked_list_str.c:150:         to_remove->prev->next = to_remove->next;
	movq	%rdx, 8(%rax)	# _6, _5->next
.L40:
# linked_list_str.c:153:     if (to_remove->next == NULL) {
	movq	-16(%rbp), %rax	# to_remove, tmp127
	movq	8(%rax), %rax	# to_remove_13->next, _7
# linked_list_str.c:153:     if (to_remove->next == NULL) {
	testq	%rax, %rax	# _7
	jne	.L41	#,
# linked_list_str.c:154:       list->tail = to_remove->prev;
	movq	-16(%rbp), %rax	# to_remove, tmp128
	movq	16(%rax), %rdx	# to_remove_13->prev, _8
# linked_list_str.c:154:       list->tail = to_remove->prev;
	movq	-40(%rbp), %rax	# list, tmp129
	movq	%rdx, 16(%rax)	# _8, list_20(D)->tail
	jmp	.L42	#
.L41:
# linked_list_str.c:156:         to_remove->next->prev = to_remove->prev;
	movq	-16(%rbp), %rax	# to_remove, tmp130
	movq	8(%rax), %rax	# to_remove_13->next, _9
# linked_list_str.c:156:         to_remove->next->prev = to_remove->prev;
	movq	-16(%rbp), %rdx	# to_remove, tmp131
	movq	16(%rdx), %rdx	# to_remove_13->prev, _10
# linked_list_str.c:156:         to_remove->next->prev = to_remove->prev;
	movq	%rdx, 16(%rax)	# _10, _9->prev
.L42:
# linked_list_str.c:158:     value = to_remove->value;
	movq	-16(%rbp), %rax	# to_remove, tmp132
	movq	(%rax), %rax	# to_remove_13->value, tmp133
	movq	%rax, -8(%rbp)	# tmp133, value
# linked_list_str.c:159:     free(to_remove);
	movq	-16(%rbp), %rax	# to_remove, tmp134
	movq	%rax, %rdi	# tmp134,
	call	free@PLT	#
# linked_list_str.c:160:     list->length--;
	movq	-40(%rbp), %rax	# list, tmp135
	movl	(%rax), %eax	# list_20(D)->length, _11
# linked_list_str.c:160:     list->length--;
	leal	-1(%rax), %edx	#, _12
	movq	-40(%rbp), %rax	# list, tmp136
	movl	%edx, (%rax)	# _12, list_20(D)->length
# linked_list_str.c:161:     return value;
	movq	-8(%rbp), %rax	# value, _15
.L35:
# linked_list_str.c:162: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE14:
	.size	RemoveAt, .-RemoveAt
	.globl	Clear
	.type	Clear, @function
Clear:
.LFB15:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# list, list
# linked_list_str.c:165:     while(list->length > 0) {
	jmp	.L44	#
.L45:
# linked_list_str.c:166:         RemoveFirst(list);
	movq	-8(%rbp), %rax	# list, tmp99
	movq	%rax, %rdi	# tmp99,
	call	RemoveFirst	#
.L44:
# linked_list_str.c:165:     while(list->length > 0) {
	movq	-8(%rbp), %rax	# list, tmp100
	movl	(%rax), %eax	# list_4(D)->length, _1
# linked_list_str.c:165:     while(list->length > 0) {
	testl	%eax, %eax	# _1
	jg	.L45	#,
# linked_list_str.c:168: }
	nop	
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE15:
	.size	Clear, .-Clear
	.ident	"GCC: (GNU) 14.2.1 20240910"
	.section	.note.GNU-stack,"",@progbits
