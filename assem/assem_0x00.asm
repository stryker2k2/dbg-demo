; ------------------------------------------------------------------
; helloworld.asm
;
; This is a Win32 console program that writes "Hello World"
; on a single line and then exits.
;
; To assemble to .obj: nasm -f win32 assem_0x00.asm
; To compile to .exe:  gcc assem_0x00.obj -o assem_0x00.exe
;
; Follow the instructions at this link
; https://labs.bilimedtech.com/nasm/windows-install/1.html
; ------------------------------------------------------------------

        global    _main                ; declare main() method
        extern    _printf              ; link to external library

        segment  .data
        message: db   'Hello world', 0xA, 0  ; text message
                    ; 0xA (10) is hex for (NL), carriage return
                    ; 0 terminates the line

        ; code is put in the .text section
        section .text
_main:                            ; the entry point! void main()
        push    message           ; save message to the stack
        call    _printf           ; display the first value on the stack
        add     esp, 4            ; clear the stack
        ret                       ; return