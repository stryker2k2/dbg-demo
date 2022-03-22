; name: asm_0x01.asm
; target: linux

global _start

section .text:

_start:
    ; Write HelloWorld to stdout
    mov eax, 0x4                    ; use the 'write' syscall
    mov ebx, 1                      ; use stdout as the fd
    mov ecx, message                ; use message as buf
    mov edx, message_length         ; provide message length
    int 0x80                        ; interrupt with syscall (aka do syscall)

    ; Exit program
    mov eax, 0x1                    ; use the 'exit' syscall
    mov ebx, 0                      ; return 0 for success
    int 0x80                        ; interrupt with syscall (aka do syscall)

section .data:
    message: db "Hello World!", 0xA     ; 0xA = "\n"
    message_length equ $-message

; Notes:
;   - Find 'write' and 'exit' syscalls in "unistd_32.h" by running
;         "locate unistd_32.h" in a terminal
;   - Find write usage by running "man 2 write"
;         usage: ssize_t write(int fd, const void *buf, size_t count);
;   - Registers
;         eax: syscall (and return value)
;         ebx: int fd
;         ecx: const void *buf
;         edx: size_t count
;  - Compile with nasm for Linux
;         nasm -f elf32 -o ./assembly/assem_0x01.o ./assembly/assem_0x01.asm
;         ld -m elf_i386 -o ./output/assem_0x01 ./assembly/assem_0x01.o