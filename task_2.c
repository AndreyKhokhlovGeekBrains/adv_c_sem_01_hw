// Задание 2. Инверсия старших

// На вход программе подается беззнаковое 32-битное целое число N. Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.

// Данные на входе: Беззнаковое 32-битное целое число N
// Данные на выходе: Одно целое число.

// Пример №1
// Данные на входе: 1
// Данные на выходе: 4278190081

// Пример №2
// Данные на входе: 4278190081
// Данные на выходе: 1

#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t N;
    scanf("%u", &N);

    uint32_t result = (~(N >> (32 - 8)) << (32 - 8)) | (N << 8 >> 8);
    printf("%u\n", result);

    return 0;
}