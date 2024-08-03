#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str);
void countWordFrequencies(char *paragraph, WordCount wordCounts[], int *wordCount);
void printWordFrequencies(WordCount wordCounts[], int wordCount);

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph (max %d characters):\n", MAX_PARAGRAPH_LENGTH);
    fgets(paragraph, MAX_PARAGRAPH_LENGTH, stdin);

    toLowerCase(paragraph);

    countWordFrequencies(paragraph, wordCounts, &wordCount);

    printf("\nWord Frequencies:\n");
    printWordFrequencies(wordCounts, wordCount);

    return 0;
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void countWordFrequencies(char *paragraph, WordCount wordCounts[], int *wordCount) {
    char *token = strtok(paragraph, " \t\n\r.,!?");

    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(wordCounts[i].word, token) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(wordCounts[*wordCount].word, token);
            wordCounts[*wordCount].count = 1;
            (*wordCount)++;
        }

        token = strtok(NULL, " \t\n\r.,!?");
    }
}

void printWordFrequencies(WordCount wordCounts[], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}
