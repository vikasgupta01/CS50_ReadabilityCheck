#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters (string a);
int count_words (string a);
int count_sentances (string a);
float index_of_readability (string a);
string textt;
float Letters, Words, Sentances, L, S, index;

int main (void) {
    textt = get_string("Enter the text you want to check readability of here: \n");

    for (int i = 0, n = strlen(textt); i<n; i++) {
        if (isupper(textt[i])) {
            textt[i] = tolower(textt[i]);
        }
    }

    printf("Letters: %d\n", count_letters(textt));
    printf("Words: %d\n", count_words(textt));
    printf("Sentances: %d\n", count_sentances(textt));


    if (index_of_readability(textt) >= 1) {
        if (index_of_readability(textt) <= 16){
            printf("Coleman-Liau index of readability (Grade): %.0f\n", index_of_readability(textt));

        }
        else {
            printf ("Coleman-Liau index of readability (Grade): Grade 16+\n");
        }
    }

    else {
        printf ("Coleman-Liau index of readability (Grade): Before Grade 1\n");
    }
}



int count_letters (string a) {

    int count = 0;
    int totlen = strlen(a);
    for (int i=0, n = strlen(a); i<n; i++) {
        if (textt[i]<='z' && textt[i]>='a') {
            count++;
        }
    }

    Letters = count;
    return count;
}

int count_words (string a) {
    int count = 1;
    for (int i=0, n = strlen(a); i<n; i++) {
        if (textt[i] == ' ') {
            count++;
        }
    }
    Words = count;
    return count;
}

int count_sentances (string a) {
    int count = 0;
    for (int i=0, n = strlen(a); i<n; i++) {
        if (textt[i] == '.' || textt[i] == '?' || textt[i] == '!') {
            count++;
        }
    }
    Sentances = count;
    return count;
}


float index_of_readability (string a) {
    L = (Letters/Words)*100;
    S = (Sentances/Words)*100;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
