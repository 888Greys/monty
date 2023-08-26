#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Splits a string into words using specific delimiters.
 *
 * @str: The input string that you want to split into individual words.
 * @delims: The characters or delimiters used to separate or
 * split words within the string.
 *
 * Return: A 2D array of word pointers.
 */

char **strtow(char *str, char *delims)
{
char **words = NULL;
int wc, wordLen, n, i = 0;

if (str == NULL || !*str)
return (NULL);
wc = get_word_count(str, delims);


if (wc == 0)
return (NULL);
words = malloc((wc + 1) * sizeof(char *));
if (words == NULL)
return (NULL);
while (i < wc)
{
wordLen = get_word_length(str, delims);
if (is_delim(*str, delims))
{
str = get_next_word(str, delims);
}
words[i] = malloc((wordLen + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i >= 0)
{
i--;
free(words[i]);
}
free(words);
return (NULL);
}
n = 0;
while (n < wordLen)
{
words[i][n] = *(str + n);
n++;
}
words[i][n] = '\0'; /* set end of str */
str = get_next_word(str, delims);
i++;
}
words[i] = NULL; /* last element is null for iteration */
return (words);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
int i = 0;

while (delims[i])
{
if (delims[i] == ch)
return (1);
i++;
}
return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: The string from which you want to determine the
 * length of the current word.
 * @delims: The characters or delimiters used to separate or
 * split words within the string.
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
int wLen = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
wLen++;
}
if (wLen > 0 && is_delim(str[i], delims))
break;
i++;
}
return (wLen);
}

/**
 * get_word_count - Determines the number of words (tokens)
 * within a given string.
 *
 * @str: string to get word count from
 * @delims: The characters or delimiters used to separate or
 * split words within the string.
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
int wc = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
pending = 0;
wc++;
}
i++;
}
return (wc);
}

/**
 * get_next_word -it  gets the next word in a string
 *
 * @str: A string from which the next word is to be extracted.
 * @delims: The characters or delimiters used to separate or
 * split words within the string.
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
int pending = 0;
int i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
break;
i++;
}
return (str + i);
}
