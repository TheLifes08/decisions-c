#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readSentence() {
    char symbol, isInSentence = 0;
    int sentenceSize = 0, maxSentenceSize = 10;
    char* sentence = (char*)calloc(maxSentenceSize, sizeof(char));

    do {
        scanf("%c", &symbol);

        while (!isInSentence && strchr("\t\n ", symbol) != NULL) {
            scanf("%c", &symbol);
        }

        isInSentence = 1;

        if (sentenceSize + 1 >= maxSentenceSize) {
            maxSentenceSize *= 2;
            sentence = (char*)realloc(sentence, maxSentenceSize * sizeof(char));
        }

        sentence[sentenceSize++] = symbol;

    } while (strchr(";.?!", symbol) == NULL);

    sentence[sentenceSize++] = '\0';

    if (sentenceSize < maxSentenceSize) {
        sentence = (char*)realloc(sentence, sentenceSize * sizeof(char));
    }

    return sentence;
}

int deleteSentencesContainingSeven(char** sentences, int sentencesSize) {
    int deletedSentencesCount = 0;

    for (int i = 0; i < sentencesSize; i++) {
        if (strchr(sentences[i], '7')) {
            deletedSentencesCount++;
            free(sentences[i]);
            sentences[i] = NULL;
        }
    }

    return deletedSentencesCount;
}

void printText(char** sentences, int sentencesSize) {
    for (int i = 0; i < sentencesSize; i++) {
        if (sentences[i] != NULL) {
            printf("%s\n", sentences[i]);
        }
    }
}

void cleanUpMemory(char** sentences, int sentencesSize) {
    for (int i = 0; i < sentencesSize; i++) {
        if (sentences[i] != NULL) {
            free(sentences[i]);
        }
    }

    free(sentences);
}

int main() {
    int n = 0, m = 0;
    int sentencesSize = 0, maxSentencesSize = 4;
    char** sentences = (char**)calloc(maxSentencesSize, sizeof(char*));
    char endSentence[] = "Dragon flew away!";

    do {
        if (sentencesSize >= maxSentencesSize) {
            maxSentencesSize *= 2;
            sentences = (char**)realloc(sentences, maxSentencesSize * sizeof(char*));
        }

        sentences[sentencesSize++] = readSentence();

    } while (strcmp(sentences[sentencesSize - 1], endSentence));

    if (sentencesSize < maxSentencesSize) {
        sentences = (char**)realloc(sentences, sentencesSize * sizeof(char*));
    }

    n = sentencesSize;
    m = sentencesSize - deleteSentencesContainingSeven(sentences, sentencesSize);

    printText(sentences, sentencesSize);
    printf("Количество предложений до %d и количество предложений после %d\n", n - 1, m - 1);

    cleanUpMemory(sentences, sentencesSize);

    return 0;
}
