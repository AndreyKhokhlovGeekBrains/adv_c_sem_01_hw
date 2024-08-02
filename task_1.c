// Задание 1. Сколько раз встречается максимум

// На стандартном потоке ввода задается натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.

// Указание: использовать массивы запрещается.

// Данные на входе: Натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
// Данные на выходе: Одно целое число.

// Пример №1
// Данные на входе: 6 1 2 3 2 0 3
// Данные на выходе: 2

// Пример №2
// Данные на входе: 3 5 2 -1
// Данные на выходе: 1.

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int N;
    int number;
    int32_t max_value = INT32_MIN;
    int max_count = 0;

    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", &number);
        int greater_than_max = number > max_value;
        int equal_to_max = !(number ^ max_value);

        max_value = greater_than_max ? number : max_value;
        max_count = greater_than_max ? 1 : (equal_to_max ? max_count + 1 : max_count);
    }
    
    printf("Max count = %d\n", max_count);

    return 0;
}