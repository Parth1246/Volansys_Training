#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n)
{
    return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m)
{
    return document[m - 1][k - 1];
}

char ***kth_paragraph(char ****document, int k)
{
    return document[k - 1];
}

// this function will get the addresses of the word out of those sentences
char *get_word(char *text, int start, int end)
{
    char *word;

    word = calloc(end - start + 1, sizeof(char));
    int index = 0;
    int i;

    // now assign the *text to *word directly
    for (i = start; i <= end; i++)
    {
        word[index++] = text[i];
    }
    // make last word null to every word
    word[index] = '\0';
    return word;
}

// this function will get the addresses of the sentences out of para
char **get_sen(char *text, int start, int end)
{
    char **sen;
    // make word count initially = 1
    int word_count = 1;

    int i;

    for (i = start; i <= end; i++)
    {
        if (text[i] == ' ')
        {
            ++word_count;
        }
    }

    // now allocate the memory to store the addresses of those words

    //**en will store *word addresses

    sen = calloc(word_count, sizeof(char *));
    int begin = start;
    int ind = 0;

    for (i = start; i <= end; i++)
    {
        if (text[i] == ' ')
        {
            // to get the word in sen from null to i-1 length
            sen[ind++] = get_word(text, start, i - 1);
            begin = i + 1;
        }
    }

    sen[ind] = get_word(text, begin, i - 1);
    return sen;
}

// this function will get the addresses of para out of doc
char ***get_pera(char *text, int start, int end)
{
    char ***para;
    // make sentence count intially = 0
    int sen_count = 0;

    int i;

    // now check if there is dot charecter to increase the sentence count

    for (i = start; i <= end; i++)
    {
        if (text[i] == '.')
        {
            ++sen_count;
        }
    }

    // now allocate the memory to store the addresses of those sentences

    //***para will store **word addresses
    para = calloc(sen_count, sizeof(char **));

    int begin = start;
    int ind = 0;

    // now to keep getting the addresses of sentences

    for (i = begin; i<=end; i++)
    {
        if (text[i] == '.')
        {
            // to get the sentences from start to null - 1 char
            para[ind++] = get_sen(text, begin, i - 1);
            begin = i + 1;
        }
    }

    return para;
}

// this function will get the addresses of para out of doc
char ****get_document(char *text)
{
    char ****doc;
    // make para count initally = 1
    int para_count = 1;

    // now check if there is a new line charecter then increase the para count
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '\n')
        {
            ++para_count;
        }
    }

    // now allocate the memory to store the addresses of paragraphs
    //****doc will store the ***para adresses
    doc = calloc(para_count, sizeof(char ***));

    // to keep getting the addresses of para
    int start = 0;
    int ind = 0;
    int i;
    for (i = 0; text[i]; i++)
    {
        if (text[i] == '\n')
        {
            // to get the sentences from start to null - 1 char
            doc[ind++] = get_pera(text, start, i - 1);
            start = i + 1;
        }
    }

    doc[ind] = get_pera(text, start, i - 1);

    return doc;
}

char *get_input_text()
{
    int paragraph_count;
    // printf("enter number of para you want to write\n");
    scanf("%d", &paragraph_count);
   
    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    // printf("enter the doc below\n");
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);

    return returnDoc;
}

void print_word(char *word)
{

    printf("%s", word);
}

void print_sentence(char **sentence)
{
    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++)
    {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph)
{
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++)
    {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{

    char *text = get_input_text();
    char ****document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
            printf("\n");
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
            printf("\n");
        }

        else
        {
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
            printf("\n");
        }
    }
    return 0;
}