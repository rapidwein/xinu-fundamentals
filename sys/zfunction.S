.section	.data
.section	.text
.globl zfunction

zfunction:
	pushl  %ebp
	movl  %esp, %ebp
	movl    8(%ebp), %eax
        andl    $0xffffe01f, %eax
        rol     $0x8, %eax
        andl    $0xffffff00, %eax
	leave
	ret

