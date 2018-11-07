	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"Termin2Aufgabe1.c"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	ldr	r3, .L7
	str	r3, [fp, #-12]
	ldr	r3, .L7+4
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-16]
	mov	r2, #65280
	str	r2, [r3]
	ldr	r3, [fp, #-16]
	mov	r2, #65280
	str	r2, [r3, #16]
.L6:
	ldr	r3, [fp, #-16]
	mov	r2, #512
	str	r2, [r3, #52]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #2
	bls	.L3
	ldr	r3, [fp, #-16]
	mov	r2, #512
	str	r2, [r3, #48]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L4
.L5:
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L4:
	ldr	r3, [fp, #-8]
	cmp	r3, #2
	bls	.L5
	b	.L6
.L8:
	.align	2
.L7:
	.word	-49152
	.word	-65536
	.size	main, .-main
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2017-q4-major) 7.2.1 20170904 (release) [ARM/embedded-7-branch revision 255204]"
