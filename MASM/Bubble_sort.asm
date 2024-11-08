 data segment
msg1 db 'Enter the count: $'
str db 10,13,'Enter the numbers: $'
str1 db 0dh,0ah,'Bubble Sorted: $'
str3 db 0dh,0ah,'$'
array1 db 10 dup(0)
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
mov ds,ax
lea dx,msg1
mov ah,09h
int 21h
mov ah,01h
int 21h
and al,0fh
mov cl,al
mov ch,00h
push cx
mov ah,09h
lea dx,str
int 21h
lea si,array1
inputs:	
	mov ah,01h
	int 21h
        cmp al,' '
        jz inputs
	mov [si],al
	inc si
	dec cx
jnz inputs
pop cx
mov bx,cx
push bx
dec cx
nextscan:
	mov bx,cx
	lea si,array1

nextcomp:
	mov al,[si]
	mov dl,[si+1]
	cmp al,dl
	jc noswap

	mov [si],dl
	mov [si+1],al

noswap:
	inc si
	dec bx
	jnz nextcomp
        dec cx
	jnz nextscan

mov ah,09
lea dx,str1
int 21h
mov ah,09
lea dx,str3
int 21h
pop bx
mov cx,bx
lea si,array1

; this loop to display elements on the screen
print:mov dl,','
mov ah,02h
int 21h
mov dl,[si]
mov ah,02h
int 21h
inc si
dec cx
jnz print

mov ah,4ch
int 21h
code ends
end start
