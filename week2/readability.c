#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);
int grade(int numOfletter, int numOfword, int numOfsentence);
void printGradeLevel(int gradeLevel);

int main(void)
{
   string text = get_string("text:");

    int numOfletter = count_letter(text);
    int numOfword = count_word(text);
    int numOfsentence = count_sentence(text);

    int gradeLevel = grade(numOfletter, numOfword, numOfsentence);

    printGradeLevel(gradeLevel);
}

int count_letter(string text){
    int letter=0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letter +=1;
        }
    }
    return letter;
}

int count_word(string text)
{
    int word = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            word += 1;
        }
    }
    return word + 1;
}

int count_sentence(string text)
{
    int sentence = 0;
    for(int i=0; i<strlen(text); i++){
        if (text[i]=='.' || text[i]=='!' || text[i] == '?')
        {
            sentence += 1;
        }
    }
    return sentence;
}
int grade(int numOfletter, int numOfword, int numOfsentence){
    float s = (numOfsentence / (float)numOfword) * 100;
    float l = (numOfletter / (float)numOfword) * 100;
    return round(0.0588 * l - 0.296 * s - 15.8);
}
void printGradeLevel(int gradeLevel){
    if(gradeLevel <=1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >=16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",gradeLevel);
    }
}

