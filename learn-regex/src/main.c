#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct Sentence {
    char* characters;
    size_t charactersNumber;
} Sentence;

typedef struct Text {
    Sentence* sentences;
    size_t sentencesNumber;
} Text;

Sentence readSentence() {
    size_t charactersMaxNumber = 20;
    Sentence sentence;
    sentence.characters = calloc(charactersMaxNumber, sizeof(char));
    sentence.charactersNumber = 0;

    do {
        if (sentence.charactersNumber >= charactersMaxNumber - 1) {
            charactersMaxNumber += 20;
            sentence.characters = realloc(sentence.characters, charactersMaxNumber * sizeof(char));
        }

        sentence.characters[sentence.charactersNumber++] = fgetc(stdin);

    } while (sentence.characters[sentence.charactersNumber - 1] != '\n' && sentence.characters[sentence.charactersNumber - 1] != EOF);

    sentence.characters[sentence.charactersNumber - 1] = '\0';

    if (sentence.charactersNumber + 1 < charactersMaxNumber) {
        sentence.characters = realloc(sentence.characters, sentence.charactersNumber * sizeof(char));
    }

    return sentence;
}

Text* readText() {
    Text* text = malloc(sizeof(Text));
    text->sentences = calloc(5, sizeof(Sentence));
    text->sentencesNumber = 0;

    size_t sentencesMaxNumber = 5;

    do {
        if (text->sentencesNumber >= sentencesMaxNumber) {
            sentencesMaxNumber *= 2;
            text->sentences = realloc(text->sentences, sentencesMaxNumber * sizeof(Sentence));
        }

        text->sentences[text->sentencesNumber++] = readSentence();

    } while (strcmp(text->sentences[text->sentencesNumber - 1].characters, "Fin.") != 0);

    if (text->sentencesNumber < sentencesMaxNumber) {
        text->sentences = realloc(text->sentences, text->sentencesNumber * sizeof(Sentence));
    }

    return text;
}

void findRootUserCommands(Text* text) {
    regex_t regexPattern;
    regcomp(&regexPattern, "(\\w+)@(\\w|-)+: ?~ ?# ((.)+)$", REG_EXTENDED);

    for (size_t i = 0; i < text->sentencesNumber - 1; i++) {
        regmatch_t regexMatch[4];
        int matchResult = regexec(&regexPattern, text->sentences[i].characters, 4, regexMatch, 0);

        if (matchResult == 0) {
            for (size_t j = regexMatch[1].rm_so; j < regexMatch[1].rm_eo; j++) {
                printf("%c", text->sentences[i].characters[j]);
            }

            printf(" - ");

            for (size_t j = regexMatch[3].rm_so; j < regexMatch[3].rm_eo; j++) {
                printf("%c", text->sentences[i].characters[j]);
            }

            printf("\n");
        }
    }

    regfree(&regexPattern);
}

void freeText(Text* text) {
    for (int i = 0; i < text->sentencesNumber; i++) {
        free(text->sentences[i].characters);
    }

    free(text->sentences);
    free(text);
}

int main() {
    Text *text = readText();

    findRootUserCommands(text);
    freeText(text);

    return 0;
}