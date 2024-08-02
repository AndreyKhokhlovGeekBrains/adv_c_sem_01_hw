// На стандартном потоке ввода задается целое неотрицательное число N и последовательность допустимых символов в кодировке ASCII, оканчивающаяся точкой. Допустимые символы – латинские буквы 'a' ... 'z', 'A' ... 'Z' и пробел. Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') шифром Цезаря, пробелы вывести без изменения. Число N задает сдвиг в шифре. Шифр Цезаря заключается в следующем преобразовании. Пусть буквы алфавита пронумерованы от 0 до K - 1, где K - число символов в алфавите. Тогда символ с номером n кодируется символом с номером p = (n + N) mod K (mod - операция взятия остатка). На стандартном потоке вывода напечатать зашифрованное сообщение, оканчивающееся точкой. Преобразование требуется выполнять независимо для заглавных и строчных латинских букв.

// Указание: использовать массивы запрещается.

// Данные на входе: Натуральное число N (N > 0), после которого следует
// сообщение.
// Данные на выходе: Зашифрованное сообщение.

// Пример №1
// Данные на входе: 0 Hello World.
// Данные на выходе: Hello World.

// Пример №2
// Данные на входе: 1 Aa.
// Данные на выходе: Bb.

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_LETTERS 26

char* ceasar_cipher(const char *my_string, int N) {
    int length = strlen(my_string);
    char* result_string = (char*)malloc(length + 1);
    if(result_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for(int i = 0; i < length; i++) {
        if(my_string[i] == ' ') {
            result_string[i] = ' ';
        } else if(my_string[i] >= 'a' && my_string[i] <= 'z') {
            int n = my_string[i] - 'a';
            int p = (n + N) % NUMBER_OF_LETTERS;
            result_string[i] = 'a' + p;
        } else if(my_string[i] >= 'A' && my_string[i] <= 'Z') {
            int n = my_string[i] - 'A';
            int p = (n + N) % NUMBER_OF_LETTERS;
            result_string[i] = 'A' + p;
        } else {
            result_string[i] = my_string[i];
        }
    }
    result_string[length] = '\0';
    return result_string;
}

int main(void) {
    int N;
    char* input_string = (char*)malloc(255 * sizeof(char));
    if(input_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(input_string);
        return 1;
    }

    printf("Enter a number that follows with a string that ends with a dot:\n");
    scanf("%d", &N);
    getchar(); // Consume the space character after the number

    char ch;
    int i = 0;
    int flag = 1;
    while (flag)
    {
        ch = getchar();
        if(ch == '.') {
            flag = 0;
        }
        input_string[i++] = ch;
    }
    input_string[i] = '\0';
    printf("%s\n", input_string);

    char* ciphered_string = ceasar_cipher(input_string, N);

    printf("%s\n", ciphered_string);

    free(input_string);
    free(ciphered_string);
    return 0;
}