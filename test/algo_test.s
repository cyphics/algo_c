	.file	"algo_test.c"
# GNU C17 (GCC) version 14.2.1 20240910 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 14.2.1 20240910, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.27-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64
	.text
	.section	.rodata
.LC0:
	.string	"test 1"
.LC1:
	.string	"test 2"
.LC2:
	.string	"test 3"
.LC3:
	.string	"test 4"
.LC4:
	.string	"test 5"
	.text
	.globl	PopulateList
	.type	PopulateList, @function
PopulateList:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# list, list
# algo_test.c:15:     Append(list, "test 1");
	movq	-8(%rbp), %rax	# list, tmp98
	leaq	.LC0(%rip), %rdx	#, tmp99
	movq	%rdx, %rsi	# tmp99,
	movq	%rax, %rdi	# tmp98,
	call	Append@PLT	#
# algo_test.c:16:     Append(list, "test 2");
	movq	-8(%rbp), %rax	# list, tmp100
	leaq	.LC1(%rip), %rdx	#, tmp101
	movq	%rdx, %rsi	# tmp101,
	movq	%rax, %rdi	# tmp100,
	call	Append@PLT	#
# algo_test.c:17:     Append(list, "test 3");
	movq	-8(%rbp), %rax	# list, tmp102
	leaq	.LC2(%rip), %rdx	#, tmp103
	movq	%rdx, %rsi	# tmp103,
	movq	%rax, %rdi	# tmp102,
	call	Append@PLT	#
# algo_test.c:18:     Append(list, "test 4");
	movq	-8(%rbp), %rax	# list, tmp104
	leaq	.LC3(%rip), %rdx	#, tmp105
	movq	%rdx, %rsi	# tmp105,
	movq	%rax, %rdi	# tmp104,
	call	Append@PLT	#
# algo_test.c:19:     Append(list, "test 5");
	movq	-8(%rbp), %rax	# list, tmp106
	leaq	.LC4(%rip), %rdx	#, tmp107
	movq	%rdx, %rsi	# tmp107,
	movq	%rax, %rdi	# tmp106,
	call	Append@PLT	#
# algo_test.c:20: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	PopulateList, .-PopulateList
	.section	.rodata
.LC5:
	.string	""
.LC6:
	.string	"algo_test.c"
.LC7:
	.string	"list.length == 5"
.LC8:
	.string	"list.head != NULL"
	.align 8
.LC9:
	.string	"strcmp(list.head->value, \"test 1\") == 0"
	.align 8
.LC10:
	.string	"strcmp(list.head->next->next->next->next->value, \"test 5\") == 0"
	.align 8
.LC11:
	.string	"list.head->next->next->next->next->next == NULL"
	.text
	.globl	TestAppend
	.type	TestAppend, @function
TestAppend:
.LFB1:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:22: void TestAppend(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp126
	movq	%rax, -8(%rbp)	# tmp126, D.4962
	xorl	%eax, %eax	# tmp126
# algo_test.c:23:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp127
	movq	%rax, %rdi	# tmp127,
	call	GetEmptyList@PLT	#
# algo_test.c:24:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp128
	movq	%rax, %rdi	# tmp128,
	call	PopulateList	#
# algo_test.c:25:     CU_ASSERT(list.length == 5);
	movl	-32(%rbp), %eax	# list.length, _1
	cmpl	$5, %eax	#, _1
	sete	%al	#, _2
	movzbl	%al, %eax	# _2, _3
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp129
	movq	%rdx, %rcx	# tmp129,
	leaq	.LC7(%rip), %rdx	#, tmp130
	movl	$25, %esi	#,
	movl	%eax, %edi	# _3,
	call	CU_assertImplementation@PLT	#
# algo_test.c:26:     CU_ASSERT(list.head != NULL);
	movq	-24(%rbp), %rax	# list.head, _4
	testq	%rax, %rax	# _4
	setne	%al	#, _5
	movzbl	%al, %eax	# _5, _6
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp131
	movq	%rdx, %rcx	# tmp131,
	leaq	.LC8(%rip), %rdx	#, tmp132
	movl	$26, %esi	#,
	movl	%eax, %edi	# _6,
	call	CU_assertImplementation@PLT	#
# algo_test.c:27:     CU_ASSERT(strcmp(list.head->value, "test 1") == 0);
	movq	-24(%rbp), %rax	# list.head, _7
	movq	(%rax), %rax	# _7->value, _8
	leaq	.LC0(%rip), %rdx	#, tmp133
	movq	%rdx, %rsi	# tmp133,
	movq	%rax, %rdi	# _8,
	call	strcmp@PLT	#
# algo_test.c:27:     CU_ASSERT(strcmp(list.head->value, "test 1") == 0);
	testl	%eax, %eax	# _9
	sete	%al	#, _10
	movzbl	%al, %eax	# _10, _11
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp134
	movq	%rdx, %rcx	# tmp134,
	leaq	.LC9(%rip), %rdx	#, tmp135
	movl	$27, %esi	#,
	movl	%eax, %edi	# _11,
	call	CU_assertImplementation@PLT	#
# algo_test.c:28:     CU_ASSERT(strcmp(list.head->next->next->next->next->value, "test 5") == 0);
	movq	-24(%rbp), %rax	# list.head, _12
	movq	8(%rax), %rax	# _12->next, _13
	movq	8(%rax), %rax	# _13->next, _14
	movq	8(%rax), %rax	# _14->next, _15
	movq	8(%rax), %rax	# _15->next, _16
	movq	(%rax), %rax	# _16->value, _17
	leaq	.LC4(%rip), %rdx	#, tmp136
	movq	%rdx, %rsi	# tmp136,
	movq	%rax, %rdi	# _17,
	call	strcmp@PLT	#
# algo_test.c:28:     CU_ASSERT(strcmp(list.head->next->next->next->next->value, "test 5") == 0);
	testl	%eax, %eax	# _18
	sete	%al	#, _19
	movzbl	%al, %eax	# _19, _20
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp137
	movq	%rdx, %rcx	# tmp137,
	leaq	.LC10(%rip), %rdx	#, tmp138
	movl	$28, %esi	#,
	movl	%eax, %edi	# _20,
	call	CU_assertImplementation@PLT	#
# algo_test.c:29:     CU_ASSERT(list.head->next->next->next->next->next == NULL);
	movq	-24(%rbp), %rax	# list.head, _21
	movq	8(%rax), %rax	# _21->next, _22
	movq	8(%rax), %rax	# _22->next, _23
	movq	8(%rax), %rax	# _23->next, _24
	movq	8(%rax), %rax	# _24->next, _25
	movq	8(%rax), %rax	# _25->next, _26
	testq	%rax, %rax	# _26
	sete	%al	#, _27
	movzbl	%al, %eax	# _27, _28
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp139
	movq	%rdx, %rcx	# tmp139,
	leaq	.LC11(%rip), %rdx	#, tmp140
	movl	$29, %esi	#,
	movl	%eax, %edi	# _28,
	call	CU_assertImplementation@PLT	#
# algo_test.c:30:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp141
	movq	%rax, %rdi	# tmp141,
	call	Clear@PLT	#
# algo_test.c:31: }
	nop	
	movq	-8(%rbp), %rax	# D.4962, tmp142
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp142
	je	.L3	#,
	call	__stack_chk_fail@PLT	#
.L3:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	TestAppend, .-TestAppend
	.section	.rodata
	.align 8
.LC12:
	.string	"strcmp(GetAt(&list, 0), \"test 1\") == 0"
	.align 8
.LC13:
	.string	"strcmp(GetAt(&list, 1), \"test 2\") == 0"
	.align 8
.LC14:
	.string	"strcmp(GetAt(&list, 4), \"test 5\") == 0"
.LC15:
	.string	"GetAt(&list, 5) == NULL"
	.text
	.globl	TestGetAt
	.type	TestGetAt, @function
TestGetAt:
.LFB2:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:34: void TestGetAt(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp113
	movq	%rax, -8(%rbp)	# tmp113, D.4972
	xorl	%eax, %eax	# tmp113
# algo_test.c:35:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp114
	movq	%rax, %rdi	# tmp114,
	call	GetEmptyList@PLT	#
# algo_test.c:36:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp115
	movq	%rax, %rdi	# tmp115,
	call	PopulateList	#
# algo_test.c:37:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 1") == 0);
	leaq	-32(%rbp), %rax	#, tmp116
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp116,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _1
# algo_test.c:37:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 1") == 0);
	leaq	.LC0(%rip), %rax	#, tmp117
	movq	%rax, %rsi	# tmp117,
	movq	%rdx, %rdi	# _1,
	call	strcmp@PLT	#
# algo_test.c:37:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 1") == 0);
	testl	%eax, %eax	# _2
	sete	%al	#, _3
	movzbl	%al, %eax	# _3, _4
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp118
	movq	%rdx, %rcx	# tmp118,
	leaq	.LC12(%rip), %rdx	#, tmp119
	movl	$37, %esi	#,
	movl	%eax, %edi	# _4,
	call	CU_assertImplementation@PLT	#
# algo_test.c:38:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 2") == 0);
	leaq	-32(%rbp), %rax	#, tmp120
	movl	$1, %esi	#,
	movq	%rax, %rdi	# tmp120,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _5
# algo_test.c:38:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 2") == 0);
	leaq	.LC1(%rip), %rax	#, tmp121
	movq	%rax, %rsi	# tmp121,
	movq	%rdx, %rdi	# _5,
	call	strcmp@PLT	#
# algo_test.c:38:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 2") == 0);
	testl	%eax, %eax	# _6
	sete	%al	#, _7
	movzbl	%al, %eax	# _7, _8
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp122
	movq	%rdx, %rcx	# tmp122,
	leaq	.LC13(%rip), %rdx	#, tmp123
	movl	$38, %esi	#,
	movl	%eax, %edi	# _8,
	call	CU_assertImplementation@PLT	#
# algo_test.c:39:     CU_ASSERT(strcmp(GetAt(&list, 4), "test 5") == 0);
	leaq	-32(%rbp), %rax	#, tmp124
	movl	$4, %esi	#,
	movq	%rax, %rdi	# tmp124,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _9
# algo_test.c:39:     CU_ASSERT(strcmp(GetAt(&list, 4), "test 5") == 0);
	leaq	.LC4(%rip), %rax	#, tmp125
	movq	%rax, %rsi	# tmp125,
	movq	%rdx, %rdi	# _9,
	call	strcmp@PLT	#
# algo_test.c:39:     CU_ASSERT(strcmp(GetAt(&list, 4), "test 5") == 0);
	testl	%eax, %eax	# _10
	sete	%al	#, _11
	movzbl	%al, %eax	# _11, _12
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp126
	movq	%rdx, %rcx	# tmp126,
	leaq	.LC14(%rip), %rdx	#, tmp127
	movl	$39, %esi	#,
	movl	%eax, %edi	# _12,
	call	CU_assertImplementation@PLT	#
# algo_test.c:40:     CU_ASSERT(GetAt(&list, 5) == NULL);
	leaq	-32(%rbp), %rax	#, tmp128
	movl	$5, %esi	#,
	movq	%rax, %rdi	# tmp128,
	call	GetAt@PLT	#
# algo_test.c:40:     CU_ASSERT(GetAt(&list, 5) == NULL);
	testq	%rax, %rax	# _13
	sete	%al	#, _14
	movzbl	%al, %eax	# _14, _15
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp129
	movq	%rdx, %rcx	# tmp129,
	leaq	.LC15(%rip), %rdx	#, tmp130
	movl	$40, %esi	#,
	movl	%eax, %edi	# _15,
	call	CU_assertImplementation@PLT	#
# algo_test.c:41:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp131
	movq	%rax, %rdi	# tmp131,
	call	Clear@PLT	#
# algo_test.c:42: }
	nop	
	movq	-8(%rbp), %rax	# D.4972, tmp132
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp132
	je	.L5	#,
	call	__stack_chk_fail@PLT	#
.L5:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2:
	.size	TestGetAt, .-TestGetAt
	.section	.rodata
.LC16:
	.string	"test 6"
.LC17:
	.string	"test 7"
.LC18:
	.string	"test 8"
.LC19:
	.string	"test 9"
.LC20:
	.string	"test 10"
	.align 8
.LC21:
	.string	"strcmp(GetAt(&list, 0), \"test 10\") == 0"
	.align 8
.LC22:
	.string	"strcmp(GetAt(&list, 1), \"test 9\") == 0"
	.align 8
.LC23:
	.string	"strcmp(GetAt(&list, 5), \"test 1\") == 0"
	.align 8
.LC24:
	.string	"strcmp(GetAt(&list, 9), \"test 5\") == 0"
.LC25:
	.string	"GetAt(&list, 10) == 0"
.LC26:
	.string	"list.length == 10"
	.text
	.globl	TestPrepend
	.type	TestPrepend, @function
TestPrepend:
.LFB3:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:44: void TestPrepend(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp120
	movq	%rax, -8(%rbp)	# tmp120, D.4978
	xorl	%eax, %eax	# tmp120
# algo_test.c:45:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp121
	movq	%rax, %rdi	# tmp121,
	call	GetEmptyList@PLT	#
# algo_test.c:46:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp122
	movq	%rax, %rdi	# tmp122,
	call	PopulateList	#
# algo_test.c:47:     Prepend(&list, "test 6");
	leaq	-32(%rbp), %rax	#, tmp123
	leaq	.LC16(%rip), %rdx	#, tmp124
	movq	%rdx, %rsi	# tmp124,
	movq	%rax, %rdi	# tmp123,
	call	Prepend@PLT	#
# algo_test.c:48:     Prepend(&list, "test 7");
	leaq	-32(%rbp), %rax	#, tmp125
	leaq	.LC17(%rip), %rdx	#, tmp126
	movq	%rdx, %rsi	# tmp126,
	movq	%rax, %rdi	# tmp125,
	call	Prepend@PLT	#
# algo_test.c:49:     Prepend(&list, "test 8");
	leaq	-32(%rbp), %rax	#, tmp127
	leaq	.LC18(%rip), %rdx	#, tmp128
	movq	%rdx, %rsi	# tmp128,
	movq	%rax, %rdi	# tmp127,
	call	Prepend@PLT	#
# algo_test.c:50:     Prepend(&list, "test 9");
	leaq	-32(%rbp), %rax	#, tmp129
	leaq	.LC19(%rip), %rdx	#, tmp130
	movq	%rdx, %rsi	# tmp130,
	movq	%rax, %rdi	# tmp129,
	call	Prepend@PLT	#
# algo_test.c:51:     Prepend(&list, "test 10");
	leaq	-32(%rbp), %rax	#, tmp131
	leaq	.LC20(%rip), %rdx	#, tmp132
	movq	%rdx, %rsi	# tmp132,
	movq	%rax, %rdi	# tmp131,
	call	Prepend@PLT	#
# algo_test.c:52:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 10") == 0);
	leaq	-32(%rbp), %rax	#, tmp133
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp133,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _1
# algo_test.c:52:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 10") == 0);
	leaq	.LC20(%rip), %rax	#, tmp134
	movq	%rax, %rsi	# tmp134,
	movq	%rdx, %rdi	# _1,
	call	strcmp@PLT	#
# algo_test.c:52:     CU_ASSERT(strcmp(GetAt(&list, 0), "test 10") == 0);
	testl	%eax, %eax	# _2
	sete	%al	#, _3
	movzbl	%al, %eax	# _3, _4
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp135
	movq	%rdx, %rcx	# tmp135,
	leaq	.LC21(%rip), %rdx	#, tmp136
	movl	$52, %esi	#,
	movl	%eax, %edi	# _4,
	call	CU_assertImplementation@PLT	#
# algo_test.c:53:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 9") == 0);
	leaq	-32(%rbp), %rax	#, tmp137
	movl	$1, %esi	#,
	movq	%rax, %rdi	# tmp137,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _5
# algo_test.c:53:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 9") == 0);
	leaq	.LC19(%rip), %rax	#, tmp138
	movq	%rax, %rsi	# tmp138,
	movq	%rdx, %rdi	# _5,
	call	strcmp@PLT	#
# algo_test.c:53:     CU_ASSERT(strcmp(GetAt(&list, 1), "test 9") == 0);
	testl	%eax, %eax	# _6
	sete	%al	#, _7
	movzbl	%al, %eax	# _7, _8
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp139
	movq	%rdx, %rcx	# tmp139,
	leaq	.LC22(%rip), %rdx	#, tmp140
	movl	$53, %esi	#,
	movl	%eax, %edi	# _8,
	call	CU_assertImplementation@PLT	#
# algo_test.c:54:     CU_ASSERT(strcmp(GetAt(&list, 5), "test 1") == 0);
	leaq	-32(%rbp), %rax	#, tmp141
	movl	$5, %esi	#,
	movq	%rax, %rdi	# tmp141,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _9
# algo_test.c:54:     CU_ASSERT(strcmp(GetAt(&list, 5), "test 1") == 0);
	leaq	.LC0(%rip), %rax	#, tmp142
	movq	%rax, %rsi	# tmp142,
	movq	%rdx, %rdi	# _9,
	call	strcmp@PLT	#
# algo_test.c:54:     CU_ASSERT(strcmp(GetAt(&list, 5), "test 1") == 0);
	testl	%eax, %eax	# _10
	sete	%al	#, _11
	movzbl	%al, %eax	# _11, _12
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp143
	movq	%rdx, %rcx	# tmp143,
	leaq	.LC23(%rip), %rdx	#, tmp144
	movl	$54, %esi	#,
	movl	%eax, %edi	# _12,
	call	CU_assertImplementation@PLT	#
# algo_test.c:55:     CU_ASSERT(strcmp(GetAt(&list, 9), "test 5") == 0);
	leaq	-32(%rbp), %rax	#, tmp145
	movl	$9, %esi	#,
	movq	%rax, %rdi	# tmp145,
	call	GetAt@PLT	#
	movq	%rax, %rdx	#, _13
# algo_test.c:55:     CU_ASSERT(strcmp(GetAt(&list, 9), "test 5") == 0);
	leaq	.LC4(%rip), %rax	#, tmp146
	movq	%rax, %rsi	# tmp146,
	movq	%rdx, %rdi	# _13,
	call	strcmp@PLT	#
# algo_test.c:55:     CU_ASSERT(strcmp(GetAt(&list, 9), "test 5") == 0);
	testl	%eax, %eax	# _14
	sete	%al	#, _15
	movzbl	%al, %eax	# _15, _16
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp147
	movq	%rdx, %rcx	# tmp147,
	leaq	.LC24(%rip), %rdx	#, tmp148
	movl	$55, %esi	#,
	movl	%eax, %edi	# _16,
	call	CU_assertImplementation@PLT	#
# algo_test.c:56:     CU_ASSERT(GetAt(&list, 10) == 0);
	leaq	-32(%rbp), %rax	#, tmp149
	movl	$10, %esi	#,
	movq	%rax, %rdi	# tmp149,
	call	GetAt@PLT	#
# algo_test.c:56:     CU_ASSERT(GetAt(&list, 10) == 0);
	testq	%rax, %rax	# _17
	sete	%al	#, _18
	movzbl	%al, %eax	# _18, _19
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp150
	movq	%rdx, %rcx	# tmp150,
	leaq	.LC25(%rip), %rdx	#, tmp151
	movl	$56, %esi	#,
	movl	%eax, %edi	# _19,
	call	CU_assertImplementation@PLT	#
# algo_test.c:57:     CU_ASSERT(list.length == 10);
	movl	-32(%rbp), %eax	# list.length, _20
	cmpl	$10, %eax	#, _20
	sete	%al	#, _21
	movzbl	%al, %eax	# _21, _22
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp152
	movq	%rdx, %rcx	# tmp152,
	leaq	.LC26(%rip), %rdx	#, tmp153
	movl	$57, %esi	#,
	movl	%eax, %edi	# _22,
	call	CU_assertImplementation@PLT	#
# algo_test.c:58:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp154
	movq	%rax, %rdi	# tmp154,
	call	Clear@PLT	#
# algo_test.c:59: }
	nop	
	movq	-8(%rbp), %rax	# D.4978, tmp155
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp155
	je	.L7	#,
	call	__stack_chk_fail@PLT	#
.L7:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3:
	.size	TestPrepend, .-TestPrepend
	.section	.rodata
	.align 8
.LC27:
	.string	"strcmp(RemoveAt(&list, 0), \"test 1\") == 0"
.LC28:
	.string	"list.length == 4"
	.align 8
.LC29:
	.string	"strcmp(RemoveAt(&list, 3), \"test 5\") == 0"
	.align 8
.LC30:
	.string	"strcmp(RemoveAt(&list, 2), \"test 4\") == 0"
	.align 8
.LC31:
	.string	"strcmp(RemoveAt(&list, 0), \"test 2\") == 0"
.LC32:
	.string	"list.length == 1"
	.align 8
.LC33:
	.string	"strcmp(RemoveAt(&list, 0), \"test 3\") == 0"
.LC34:
	.string	"list.length == 0"
.LC35:
	.string	"RemoveAt(&list, 0) == 0"
	.text
	.globl	TestRemoveAt
	.type	TestRemoveAt, @function
TestRemoveAt:
.LFB4:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:61: void TestRemoveAt(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp130
	movq	%rax, -8(%rbp)	# tmp130, D.4991
	xorl	%eax, %eax	# tmp130
# algo_test.c:62:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp131
	movq	%rax, %rdi	# tmp131,
	call	GetEmptyList@PLT	#
# algo_test.c:63:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp132
	movq	%rax, %rdi	# tmp132,
	call	PopulateList	#
# algo_test.c:64:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 1") == 0);
	leaq	-32(%rbp), %rax	#, tmp133
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp133,
	call	RemoveAt@PLT	#
	movq	%rax, %rdx	#, _1
# algo_test.c:64:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 1") == 0);
	leaq	.LC0(%rip), %rax	#, tmp134
	movq	%rax, %rsi	# tmp134,
	movq	%rdx, %rdi	# _1,
	call	strcmp@PLT	#
# algo_test.c:64:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 1") == 0);
	testl	%eax, %eax	# _2
	sete	%al	#, _3
	movzbl	%al, %eax	# _3, _4
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp135
	movq	%rdx, %rcx	# tmp135,
	leaq	.LC27(%rip), %rdx	#, tmp136
	movl	$64, %esi	#,
	movl	%eax, %edi	# _4,
	call	CU_assertImplementation@PLT	#
# algo_test.c:65:     CU_ASSERT(list.length == 4);
	movl	-32(%rbp), %eax	# list.length, _5
	cmpl	$4, %eax	#, _5
	sete	%al	#, _6
	movzbl	%al, %eax	# _6, _7
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp137
	movq	%rdx, %rcx	# tmp137,
	leaq	.LC28(%rip), %rdx	#, tmp138
	movl	$65, %esi	#,
	movl	%eax, %edi	# _7,
	call	CU_assertImplementation@PLT	#
# algo_test.c:66:     CU_ASSERT(strcmp(RemoveAt(&list, 3), "test 5") == 0);
	leaq	-32(%rbp), %rax	#, tmp139
	movl	$3, %esi	#,
	movq	%rax, %rdi	# tmp139,
	call	RemoveAt@PLT	#
	movq	%rax, %rdx	#, _8
# algo_test.c:66:     CU_ASSERT(strcmp(RemoveAt(&list, 3), "test 5") == 0);
	leaq	.LC4(%rip), %rax	#, tmp140
	movq	%rax, %rsi	# tmp140,
	movq	%rdx, %rdi	# _8,
	call	strcmp@PLT	#
# algo_test.c:66:     CU_ASSERT(strcmp(RemoveAt(&list, 3), "test 5") == 0);
	testl	%eax, %eax	# _9
	sete	%al	#, _10
	movzbl	%al, %eax	# _10, _11
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp141
	movq	%rdx, %rcx	# tmp141,
	leaq	.LC29(%rip), %rdx	#, tmp142
	movl	$66, %esi	#,
	movl	%eax, %edi	# _11,
	call	CU_assertImplementation@PLT	#
# algo_test.c:67:     CU_ASSERT(strcmp(RemoveAt(&list, 2), "test 4") == 0);
	leaq	-32(%rbp), %rax	#, tmp143
	movl	$2, %esi	#,
	movq	%rax, %rdi	# tmp143,
	call	RemoveAt@PLT	#
	movq	%rax, %rdx	#, _12
# algo_test.c:67:     CU_ASSERT(strcmp(RemoveAt(&list, 2), "test 4") == 0);
	leaq	.LC3(%rip), %rax	#, tmp144
	movq	%rax, %rsi	# tmp144,
	movq	%rdx, %rdi	# _12,
	call	strcmp@PLT	#
# algo_test.c:67:     CU_ASSERT(strcmp(RemoveAt(&list, 2), "test 4") == 0);
	testl	%eax, %eax	# _13
	sete	%al	#, _14
	movzbl	%al, %eax	# _14, _15
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp145
	movq	%rdx, %rcx	# tmp145,
	leaq	.LC30(%rip), %rdx	#, tmp146
	movl	$67, %esi	#,
	movl	%eax, %edi	# _15,
	call	CU_assertImplementation@PLT	#
# algo_test.c:68:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 2") == 0);
	leaq	-32(%rbp), %rax	#, tmp147
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp147,
	call	RemoveAt@PLT	#
	movq	%rax, %rdx	#, _16
# algo_test.c:68:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 2") == 0);
	leaq	.LC1(%rip), %rax	#, tmp148
	movq	%rax, %rsi	# tmp148,
	movq	%rdx, %rdi	# _16,
	call	strcmp@PLT	#
# algo_test.c:68:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 2") == 0);
	testl	%eax, %eax	# _17
	sete	%al	#, _18
	movzbl	%al, %eax	# _18, _19
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp149
	movq	%rdx, %rcx	# tmp149,
	leaq	.LC31(%rip), %rdx	#, tmp150
	movl	$68, %esi	#,
	movl	%eax, %edi	# _19,
	call	CU_assertImplementation@PLT	#
# algo_test.c:69:     CU_ASSERT(list.length == 1);
	movl	-32(%rbp), %eax	# list.length, _20
	cmpl	$1, %eax	#, _20
	sete	%al	#, _21
	movzbl	%al, %eax	# _21, _22
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp151
	movq	%rdx, %rcx	# tmp151,
	leaq	.LC32(%rip), %rdx	#, tmp152
	movl	$69, %esi	#,
	movl	%eax, %edi	# _22,
	call	CU_assertImplementation@PLT	#
# algo_test.c:70:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 3") == 0);
	leaq	-32(%rbp), %rax	#, tmp153
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp153,
	call	RemoveAt@PLT	#
	movq	%rax, %rdx	#, _23
# algo_test.c:70:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 3") == 0);
	leaq	.LC2(%rip), %rax	#, tmp154
	movq	%rax, %rsi	# tmp154,
	movq	%rdx, %rdi	# _23,
	call	strcmp@PLT	#
# algo_test.c:70:     CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 3") == 0);
	testl	%eax, %eax	# _24
	sete	%al	#, _25
	movzbl	%al, %eax	# _25, _26
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp155
	movq	%rdx, %rcx	# tmp155,
	leaq	.LC33(%rip), %rdx	#, tmp156
	movl	$70, %esi	#,
	movl	%eax, %edi	# _26,
	call	CU_assertImplementation@PLT	#
# algo_test.c:71:     CU_ASSERT(list.length == 0);
	movl	-32(%rbp), %eax	# list.length, _27
	testl	%eax, %eax	# _27
	sete	%al	#, _28
	movzbl	%al, %eax	# _28, _29
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp157
	movq	%rdx, %rcx	# tmp157,
	leaq	.LC34(%rip), %rdx	#, tmp158
	movl	$71, %esi	#,
	movl	%eax, %edi	# _29,
	call	CU_assertImplementation@PLT	#
# algo_test.c:72:     CU_ASSERT(RemoveAt(&list, 0) == 0);
	leaq	-32(%rbp), %rax	#, tmp159
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp159,
	call	RemoveAt@PLT	#
# algo_test.c:72:     CU_ASSERT(RemoveAt(&list, 0) == 0);
	testq	%rax, %rax	# _30
	sete	%al	#, _31
	movzbl	%al, %eax	# _31, _32
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp160
	movq	%rdx, %rcx	# tmp160,
	leaq	.LC35(%rip), %rdx	#, tmp161
	movl	$72, %esi	#,
	movl	%eax, %edi	# _32,
	call	CU_assertImplementation@PLT	#
# algo_test.c:73:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp162
	movq	%rax, %rdi	# tmp162,
	call	Clear@PLT	#
# algo_test.c:74: }
	nop	
	movq	-8(%rbp), %rax	# D.4991, tmp163
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp163
	je	.L9	#,
	call	__stack_chk_fail@PLT	#
.L9:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4:
	.size	TestRemoveAt, .-TestRemoveAt
	.section	.rodata
	.align 8
.LC36:
	.string	"strcmp(RemoveFirst(&list), \"test 1\") == 0"
	.align 8
.LC37:
	.string	"strcmp(RemoveFirst(&list), \"test 2\") == 0"
.LC38:
	.string	"list.length == 3"
	.align 8
.LC39:
	.string	"strcmp(RemoveFirst(&list), \"test 3\") == 0"
	.align 8
.LC40:
	.string	"strcmp(RemoveFirst(&list), \"test 4\") == 0"
	.align 8
.LC41:
	.string	"strcmp(RemoveFirst(&list), \"test 5\") == 0"
.LC42:
	.string	"RemoveFirst(&list) == 0"
	.text
	.globl	TestRemoveFirst
	.type	TestRemoveFirst, @function
TestRemoveFirst:
.LFB5:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:76: void TestRemoveFirst(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp130
	movq	%rax, -8(%rbp)	# tmp130, D.5002
	xorl	%eax, %eax	# tmp130
# algo_test.c:77:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp131
	movq	%rax, %rdi	# tmp131,
	call	GetEmptyList@PLT	#
# algo_test.c:78:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp132
	movq	%rax, %rdi	# tmp132,
	call	PopulateList	#
# algo_test.c:79:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 1") == 0);
	leaq	-32(%rbp), %rax	#, tmp133
	movq	%rax, %rdi	# tmp133,
	call	RemoveFirst@PLT	#
	movq	%rax, %rdx	#, _1
# algo_test.c:79:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 1") == 0);
	leaq	.LC0(%rip), %rax	#, tmp134
	movq	%rax, %rsi	# tmp134,
	movq	%rdx, %rdi	# _1,
	call	strcmp@PLT	#
# algo_test.c:79:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 1") == 0);
	testl	%eax, %eax	# _2
	sete	%al	#, _3
	movzbl	%al, %eax	# _3, _4
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp135
	movq	%rdx, %rcx	# tmp135,
	leaq	.LC36(%rip), %rdx	#, tmp136
	movl	$79, %esi	#,
	movl	%eax, %edi	# _4,
	call	CU_assertImplementation@PLT	#
# algo_test.c:80:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 2") == 0);
	leaq	-32(%rbp), %rax	#, tmp137
	movq	%rax, %rdi	# tmp137,
	call	RemoveFirst@PLT	#
	movq	%rax, %rdx	#, _5
# algo_test.c:80:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 2") == 0);
	leaq	.LC1(%rip), %rax	#, tmp138
	movq	%rax, %rsi	# tmp138,
	movq	%rdx, %rdi	# _5,
	call	strcmp@PLT	#
# algo_test.c:80:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 2") == 0);
	testl	%eax, %eax	# _6
	sete	%al	#, _7
	movzbl	%al, %eax	# _7, _8
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp139
	movq	%rdx, %rcx	# tmp139,
	leaq	.LC37(%rip), %rdx	#, tmp140
	movl	$80, %esi	#,
	movl	%eax, %edi	# _8,
	call	CU_assertImplementation@PLT	#
# algo_test.c:81:     CU_ASSERT(list.length == 3);
	movl	-32(%rbp), %eax	# list.length, _9
	cmpl	$3, %eax	#, _9
	sete	%al	#, _10
	movzbl	%al, %eax	# _10, _11
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp141
	movq	%rdx, %rcx	# tmp141,
	leaq	.LC38(%rip), %rdx	#, tmp142
	movl	$81, %esi	#,
	movl	%eax, %edi	# _11,
	call	CU_assertImplementation@PLT	#
# algo_test.c:82:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 3") == 0);
	leaq	-32(%rbp), %rax	#, tmp143
	movq	%rax, %rdi	# tmp143,
	call	RemoveFirst@PLT	#
	movq	%rax, %rdx	#, _12
# algo_test.c:82:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 3") == 0);
	leaq	.LC2(%rip), %rax	#, tmp144
	movq	%rax, %rsi	# tmp144,
	movq	%rdx, %rdi	# _12,
	call	strcmp@PLT	#
# algo_test.c:82:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 3") == 0);
	testl	%eax, %eax	# _13
	sete	%al	#, _14
	movzbl	%al, %eax	# _14, _15
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp145
	movq	%rdx, %rcx	# tmp145,
	leaq	.LC39(%rip), %rdx	#, tmp146
	movl	$82, %esi	#,
	movl	%eax, %edi	# _15,
	call	CU_assertImplementation@PLT	#
# algo_test.c:83:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 4") == 0);
	leaq	-32(%rbp), %rax	#, tmp147
	movq	%rax, %rdi	# tmp147,
	call	RemoveFirst@PLT	#
	movq	%rax, %rdx	#, _16
# algo_test.c:83:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 4") == 0);
	leaq	.LC3(%rip), %rax	#, tmp148
	movq	%rax, %rsi	# tmp148,
	movq	%rdx, %rdi	# _16,
	call	strcmp@PLT	#
# algo_test.c:83:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 4") == 0);
	testl	%eax, %eax	# _17
	sete	%al	#, _18
	movzbl	%al, %eax	# _18, _19
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp149
	movq	%rdx, %rcx	# tmp149,
	leaq	.LC40(%rip), %rdx	#, tmp150
	movl	$83, %esi	#,
	movl	%eax, %edi	# _19,
	call	CU_assertImplementation@PLT	#
# algo_test.c:84:     CU_ASSERT(list.length == 1);
	movl	-32(%rbp), %eax	# list.length, _20
	cmpl	$1, %eax	#, _20
	sete	%al	#, _21
	movzbl	%al, %eax	# _21, _22
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp151
	movq	%rdx, %rcx	# tmp151,
	leaq	.LC32(%rip), %rdx	#, tmp152
	movl	$84, %esi	#,
	movl	%eax, %edi	# _22,
	call	CU_assertImplementation@PLT	#
# algo_test.c:85:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 5") == 0);
	leaq	-32(%rbp), %rax	#, tmp153
	movq	%rax, %rdi	# tmp153,
	call	RemoveFirst@PLT	#
	movq	%rax, %rdx	#, _23
# algo_test.c:85:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 5") == 0);
	leaq	.LC4(%rip), %rax	#, tmp154
	movq	%rax, %rsi	# tmp154,
	movq	%rdx, %rdi	# _23,
	call	strcmp@PLT	#
# algo_test.c:85:     CU_ASSERT(strcmp(RemoveFirst(&list), "test 5") == 0);
	testl	%eax, %eax	# _24
	sete	%al	#, _25
	movzbl	%al, %eax	# _25, _26
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp155
	movq	%rdx, %rcx	# tmp155,
	leaq	.LC41(%rip), %rdx	#, tmp156
	movl	$85, %esi	#,
	movl	%eax, %edi	# _26,
	call	CU_assertImplementation@PLT	#
# algo_test.c:86:     CU_ASSERT(list.length == 0);
	movl	-32(%rbp), %eax	# list.length, _27
	testl	%eax, %eax	# _27
	sete	%al	#, _28
	movzbl	%al, %eax	# _28, _29
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp157
	movq	%rdx, %rcx	# tmp157,
	leaq	.LC34(%rip), %rdx	#, tmp158
	movl	$86, %esi	#,
	movl	%eax, %edi	# _29,
	call	CU_assertImplementation@PLT	#
# algo_test.c:87:     CU_ASSERT(RemoveFirst(&list) == 0);
	leaq	-32(%rbp), %rax	#, tmp159
	movq	%rax, %rdi	# tmp159,
	call	RemoveFirst@PLT	#
# algo_test.c:87:     CU_ASSERT(RemoveFirst(&list) == 0);
	testq	%rax, %rax	# _30
	sete	%al	#, _31
	movzbl	%al, %eax	# _31, _32
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp160
	movq	%rdx, %rcx	# tmp160,
	leaq	.LC42(%rip), %rdx	#, tmp161
	movl	$87, %esi	#,
	movl	%eax, %edi	# _32,
	call	CU_assertImplementation@PLT	#
# algo_test.c:88:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp162
	movq	%rax, %rdi	# tmp162,
	call	Clear@PLT	#
# algo_test.c:89: }
	nop	
	movq	-8(%rbp), %rax	# D.5002, tmp163
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp163
	je	.L11	#,
	call	__stack_chk_fail@PLT	#
.L11:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE5:
	.size	TestRemoveFirst, .-TestRemoveFirst
	.section	.rodata
	.align 8
.LC43:
	.string	"strcmp(RemoveLast(&list), \"test 5\") == 0"
	.align 8
.LC44:
	.string	"strcmp(RemoveLast(&list), \"test 4\") == 0"
	.align 8
.LC45:
	.string	"strcmp(RemoveLast(&list), \"test 3\") == 0"
	.align 8
.LC46:
	.string	"strcmp(RemoveLast(&list), \"test 2\") == 0"
	.align 8
.LC47:
	.string	"strcmp(RemoveLast(&list), \"test 1\") == 0"
	.text
	.globl	TestRemoveLast
	.type	TestRemoveLast, @function
TestRemoveLast:
.LFB6:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:91: void TestRemoveLast(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp118
	movq	%rax, -8(%rbp)	# tmp118, D.5011
	xorl	%eax, %eax	# tmp118
# algo_test.c:92:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp119
	movq	%rax, %rdi	# tmp119,
	call	GetEmptyList@PLT	#
# algo_test.c:93:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp120
	movq	%rax, %rdi	# tmp120,
	call	PopulateList	#
# algo_test.c:94:     CU_ASSERT(strcmp(RemoveLast(&list), "test 5") == 0);
	leaq	-32(%rbp), %rax	#, tmp121
	movq	%rax, %rdi	# tmp121,
	call	RemoveLast@PLT	#
	movq	%rax, %rdx	#, _1
# algo_test.c:94:     CU_ASSERT(strcmp(RemoveLast(&list), "test 5") == 0);
	leaq	.LC4(%rip), %rax	#, tmp122
	movq	%rax, %rsi	# tmp122,
	movq	%rdx, %rdi	# _1,
	call	strcmp@PLT	#
# algo_test.c:94:     CU_ASSERT(strcmp(RemoveLast(&list), "test 5") == 0);
	testl	%eax, %eax	# _2
	sete	%al	#, _3
	movzbl	%al, %eax	# _3, _4
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp123
	movq	%rdx, %rcx	# tmp123,
	leaq	.LC43(%rip), %rdx	#, tmp124
	movl	$94, %esi	#,
	movl	%eax, %edi	# _4,
	call	CU_assertImplementation@PLT	#
# algo_test.c:95:     CU_ASSERT(strcmp(RemoveLast(&list), "test 4") == 0);
	leaq	-32(%rbp), %rax	#, tmp125
	movq	%rax, %rdi	# tmp125,
	call	RemoveLast@PLT	#
	movq	%rax, %rdx	#, _5
# algo_test.c:95:     CU_ASSERT(strcmp(RemoveLast(&list), "test 4") == 0);
	leaq	.LC3(%rip), %rax	#, tmp126
	movq	%rax, %rsi	# tmp126,
	movq	%rdx, %rdi	# _5,
	call	strcmp@PLT	#
# algo_test.c:95:     CU_ASSERT(strcmp(RemoveLast(&list), "test 4") == 0);
	testl	%eax, %eax	# _6
	sete	%al	#, _7
	movzbl	%al, %eax	# _7, _8
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp127
	movq	%rdx, %rcx	# tmp127,
	leaq	.LC44(%rip), %rdx	#, tmp128
	movl	$95, %esi	#,
	movl	%eax, %edi	# _8,
	call	CU_assertImplementation@PLT	#
# algo_test.c:96:     CU_ASSERT(strcmp(RemoveLast(&list), "test 3") == 0);
	leaq	-32(%rbp), %rax	#, tmp129
	movq	%rax, %rdi	# tmp129,
	call	RemoveLast@PLT	#
	movq	%rax, %rdx	#, _9
# algo_test.c:96:     CU_ASSERT(strcmp(RemoveLast(&list), "test 3") == 0);
	leaq	.LC2(%rip), %rax	#, tmp130
	movq	%rax, %rsi	# tmp130,
	movq	%rdx, %rdi	# _9,
	call	strcmp@PLT	#
# algo_test.c:96:     CU_ASSERT(strcmp(RemoveLast(&list), "test 3") == 0);
	testl	%eax, %eax	# _10
	sete	%al	#, _11
	movzbl	%al, %eax	# _11, _12
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp131
	movq	%rdx, %rcx	# tmp131,
	leaq	.LC45(%rip), %rdx	#, tmp132
	movl	$96, %esi	#,
	movl	%eax, %edi	# _12,
	call	CU_assertImplementation@PLT	#
# algo_test.c:97:     CU_ASSERT(strcmp(RemoveLast(&list), "test 2") == 0);
	leaq	-32(%rbp), %rax	#, tmp133
	movq	%rax, %rdi	# tmp133,
	call	RemoveLast@PLT	#
	movq	%rax, %rdx	#, _13
# algo_test.c:97:     CU_ASSERT(strcmp(RemoveLast(&list), "test 2") == 0);
	leaq	.LC1(%rip), %rax	#, tmp134
	movq	%rax, %rsi	# tmp134,
	movq	%rdx, %rdi	# _13,
	call	strcmp@PLT	#
# algo_test.c:97:     CU_ASSERT(strcmp(RemoveLast(&list), "test 2") == 0);
	testl	%eax, %eax	# _14
	sete	%al	#, _15
	movzbl	%al, %eax	# _15, _16
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp135
	movq	%rdx, %rcx	# tmp135,
	leaq	.LC46(%rip), %rdx	#, tmp136
	movl	$97, %esi	#,
	movl	%eax, %edi	# _16,
	call	CU_assertImplementation@PLT	#
# algo_test.c:98:     CU_ASSERT(strcmp(RemoveLast(&list), "test 1") == 0);
	leaq	-32(%rbp), %rax	#, tmp137
	movq	%rax, %rdi	# tmp137,
	call	RemoveLast@PLT	#
	movq	%rax, %rdx	#, _17
# algo_test.c:98:     CU_ASSERT(strcmp(RemoveLast(&list), "test 1") == 0);
	leaq	.LC0(%rip), %rax	#, tmp138
	movq	%rax, %rsi	# tmp138,
	movq	%rdx, %rdi	# _17,
	call	strcmp@PLT	#
# algo_test.c:98:     CU_ASSERT(strcmp(RemoveLast(&list), "test 1") == 0);
	testl	%eax, %eax	# _18
	sete	%al	#, _19
	movzbl	%al, %eax	# _19, _20
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp139
	movq	%rdx, %rcx	# tmp139,
	leaq	.LC47(%rip), %rdx	#, tmp140
	movl	$98, %esi	#,
	movl	%eax, %edi	# _20,
	call	CU_assertImplementation@PLT	#
# algo_test.c:99:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp141
	movq	%rax, %rdi	# tmp141,
	call	Clear@PLT	#
# algo_test.c:100: }
	nop	
	movq	-8(%rbp), %rax	# D.5011, tmp142
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp142
	je	.L13	#,
	call	__stack_chk_fail@PLT	#
.L13:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	TestRemoveLast, .-TestRemoveLast
	.section	.rodata
.LC48:
	.string	"list.head == NULL"
.LC49:
	.string	"list.tail == NULL"
	.text
	.globl	TestClear
	.type	TestClear, @function
TestClear:
.LFB7:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# algo_test.c:103: void TestClear(void) {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp107
	movq	%rax, -8(%rbp)	# tmp107, D.5018
	xorl	%eax, %eax	# tmp107
# algo_test.c:104:     LinkedList list = GetEmptyList();
	leaq	-32(%rbp), %rax	#, tmp108
	movq	%rax, %rdi	# tmp108,
	call	GetEmptyList@PLT	#
# algo_test.c:105:     PopulateList(&list);
	leaq	-32(%rbp), %rax	#, tmp109
	movq	%rax, %rdi	# tmp109,
	call	PopulateList	#
# algo_test.c:106:     Clear(&list);
	leaq	-32(%rbp), %rax	#, tmp110
	movq	%rax, %rdi	# tmp110,
	call	Clear@PLT	#
# algo_test.c:107:     CU_ASSERT(list.length == 0);
	movl	-32(%rbp), %eax	# list.length, _1
	testl	%eax, %eax	# _1
	sete	%al	#, _2
	movzbl	%al, %eax	# _2, _3
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp111
	movq	%rdx, %rcx	# tmp111,
	leaq	.LC34(%rip), %rdx	#, tmp112
	movl	$107, %esi	#,
	movl	%eax, %edi	# _3,
	call	CU_assertImplementation@PLT	#
# algo_test.c:108:     CU_ASSERT(list.head == NULL);
	movq	-24(%rbp), %rax	# list.head, _4
	testq	%rax, %rax	# _4
	sete	%al	#, _5
	movzbl	%al, %eax	# _5, _6
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp113
	movq	%rdx, %rcx	# tmp113,
	leaq	.LC48(%rip), %rdx	#, tmp114
	movl	$108, %esi	#,
	movl	%eax, %edi	# _6,
	call	CU_assertImplementation@PLT	#
# algo_test.c:109:     CU_ASSERT(list.tail == NULL);
	movq	-16(%rbp), %rax	# list.tail, _7
	testq	%rax, %rax	# _7
	sete	%al	#, _8
	movzbl	%al, %eax	# _8, _9
	movl	$0, %r9d	#,
	leaq	.LC5(%rip), %r8	#,
	leaq	.LC6(%rip), %rdx	#, tmp115
	movq	%rdx, %rcx	# tmp115,
	leaq	.LC49(%rip), %rdx	#, tmp116
	movl	$109, %esi	#,
	movl	%eax, %edi	# _9,
	call	CU_assertImplementation@PLT	#
# algo_test.c:110: }
	nop	
	movq	-8(%rbp), %rax	# D.5018, tmp117
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp117
	je	.L15	#,
	call	__stack_chk_fail@PLT	#
.L15:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	TestClear, .-TestClear
	.section	.rodata
.LC50:
	.string	"Append"
.LC51:
	.string	"GetAt"
.LC52:
	.string	"Prepend"
.LC53:
	.string	"RemoveAt"
.LC54:
	.string	"RemoveFirst"
.LC55:
	.string	"RemoveLast"
.LC56:
	.string	"Clear"
	.text
	.globl	TestLinkedList
	.type	TestLinkedList, @function
TestLinkedList:
.LFB8:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# suite, suite
# algo_test.c:113:     CU_add_test(suite, "Append", TestAppend);
	movq	-8(%rbp), %rax	# suite, tmp98
	leaq	TestAppend(%rip), %rdx	#, tmp99
	leaq	.LC50(%rip), %rcx	#, tmp100
	movq	%rcx, %rsi	# tmp100,
	movq	%rax, %rdi	# tmp98,
	call	CU_add_test@PLT	#
# algo_test.c:114:     CU_add_test(suite, "GetAt", TestGetAt);
	movq	-8(%rbp), %rax	# suite, tmp101
	leaq	TestGetAt(%rip), %rdx	#, tmp102
	leaq	.LC51(%rip), %rcx	#, tmp103
	movq	%rcx, %rsi	# tmp103,
	movq	%rax, %rdi	# tmp101,
	call	CU_add_test@PLT	#
# algo_test.c:115:     CU_add_test(suite, "Prepend", TestPrepend);
	movq	-8(%rbp), %rax	# suite, tmp104
	leaq	TestPrepend(%rip), %rdx	#, tmp105
	leaq	.LC52(%rip), %rcx	#, tmp106
	movq	%rcx, %rsi	# tmp106,
	movq	%rax, %rdi	# tmp104,
	call	CU_add_test@PLT	#
# algo_test.c:116:     CU_add_test(suite, "RemoveAt", TestRemoveAt);
	movq	-8(%rbp), %rax	# suite, tmp107
	leaq	TestRemoveAt(%rip), %rdx	#, tmp108
	leaq	.LC53(%rip), %rcx	#, tmp109
	movq	%rcx, %rsi	# tmp109,
	movq	%rax, %rdi	# tmp107,
	call	CU_add_test@PLT	#
# algo_test.c:117:     CU_add_test(suite, "RemoveFirst", TestRemoveFirst);
	movq	-8(%rbp), %rax	# suite, tmp110
	leaq	TestRemoveFirst(%rip), %rdx	#, tmp111
	leaq	.LC54(%rip), %rcx	#, tmp112
	movq	%rcx, %rsi	# tmp112,
	movq	%rax, %rdi	# tmp110,
	call	CU_add_test@PLT	#
# algo_test.c:118:     CU_add_test(suite, "RemoveLast", TestRemoveLast);
	movq	-8(%rbp), %rax	# suite, tmp113
	leaq	TestRemoveLast(%rip), %rdx	#, tmp114
	leaq	.LC55(%rip), %rcx	#, tmp115
	movq	%rcx, %rsi	# tmp115,
	movq	%rax, %rdi	# tmp113,
	call	CU_add_test@PLT	#
# algo_test.c:119:     CU_add_test(suite, "Clear", TestClear);
	movq	-8(%rbp), %rax	# suite, tmp116
	leaq	TestClear(%rip), %rdx	#, tmp117
	leaq	.LC56(%rip), %rcx	#, tmp118
	movq	%rcx, %rsi	# tmp118,
	movq	%rax, %rdi	# tmp116,
	call	CU_add_test@PLT	#
# algo_test.c:120: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE8:
	.size	TestLinkedList, .-TestLinkedList
	.section	.rodata
.LC57:
	.string	"Sorting"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# algo_test.c:123:     CU_initialize_registry();
	call	CU_initialize_registry@PLT	#
# algo_test.c:124:     CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
	movl	$0, %edx	#,
	movl	$0, %esi	#,
	leaq	.LC57(%rip), %rax	#, tmp100
	movq	%rax, %rdi	# tmp100,
	call	CU_add_suite@PLT	#
	movq	%rax, -8(%rbp)	# tmp101, suite
# algo_test.c:125:     TestLinkedList(suite);
	movq	-8(%rbp), %rax	# suite, tmp102
	movq	%rax, %rdi	# tmp102,
	call	TestLinkedList	#
# algo_test.c:126:     CU_basic_run_tests();
	call	CU_basic_run_tests@PLT	#
# algo_test.c:127:     CU_cleanup_registry();
	call	CU_cleanup_registry@PLT	#
# algo_test.c:128:     return 0;
	movl	$0, %eax	#, _8
# algo_test.c:129: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240910"
	.section	.note.GNU-stack,"",@progbits
