#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100 
#define MAX_LENGTH 50  

void sortByLength(char words[][MAX_LENGTH], int count) {
    char temp[MAX_LENGTH];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {

                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    char words[MAX_WORDS][MAX_LENGTH];
    int count;

    printf("Введите количество слов: ");
    scanf("%d", &count);

    if (count <= 0 || count > MAX_WORDS) {
        printf("Некорректное количество слов!\n");
        return 1;
    }

    printf("Введите слова:\n");
    for (int i = 0; i < count; i++) {
        scanf("%s", words[i]);
    }

    sortByLength(words, count);

    printf("Слова, отсортированные по длине:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}