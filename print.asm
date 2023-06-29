; print.asm
global myprint 				; 设置print为全局可见


myprint:
    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx
    push edx
    push esi

    mov edi, 0

    sub esp, 1
    mov byte [esp], 0
    add edi, 1

    sub esp, 1
    mov byte [esp], 10
    add edi, 1

    mov edx, 0
    mov eax, [ebp + 8]
    ; mov eax, 98765
    mov ecx, 10
LOOP_:
    div ecx
    add edx, 48
    sub esp, 1
    mov byte [esp], dl
    add edi, 1
    mov edx, 0
    cmp eax, 0
    jne LOOP_

    mov eax, 4              ; 发起系统调用
    mov ebx, 1              ; ebx表示stdout
    mov ecx, esp      ; 表示字符串的地址
    mov edx, edi     ; 表示字符的个数
    int 0x80                ; int 0x80表示系统调用

    add esp, edi

    pop esi
    pop edx
    pop ecx
    pop ebx
    pop eax
    pop ebp
    ret
