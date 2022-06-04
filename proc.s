.text
    .global proc
    .type proc, @function

# rdi - Указатель на первый элемент глав. матрицы 
# rsi - Указатель на первый эл. новой матрицы
# rdx - Кол-во строк в глав. матрице
# rcx - Кол-во стобцов в глав. матрице
# r8 - Номер удаляемой строки
# r9 - Номер удаляемого столбца

# Основная функция обработки
proc:
    
    # Обнуление счетчика строк
    xorl %r10d, %r10d
i:
    
    # Обнуление счетчика столбца
    xorl %r11d, %r11d
j:
    # Проверка тек. строки с удаляемой
    cmpl %r10d, %r8d
    je next

    # Проверка тек. стобца с удаляемым
    cmpl %r11d, %r9d
    je next

    # Если все ок, то переносим значение из глав. мат. в новую
    movl (%rdi), %eax
    movl %eax, (%rsi)
    # Передвигаем указатель нов. матрицы дальше
    addq $4, %rsi

next:
    # Передвигаем указатель глав. матрицы дальше
    addq $4, %rdi
    # Увеличиваем счетчике столбцов
    inc %r11d
    # Дошел ли он до конца
    cmpl %ecx, %r11d
    jne j

    # Увеличиваем счет. строк
    inc %r10d
    # Дошел ли он до конца
    cmpl %edx, %r10d
    jne i
    

    # Выход из функции
    ret


