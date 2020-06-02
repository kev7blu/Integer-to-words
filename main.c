#include <stdio.h>

char *ones[] = {"", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine"};
    char *tens[] = {"", " ten", " twenty", " thirty", " fourty", " fifty", " sixty", " seventy", " eighty", " ninty"};
    char *teens[] = {" ten", " eleven", " twelve", " thirtee", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " ninteen"};
    char *places[] = {""," thousand", " million", " billion", " trillion", " quadrillion"};
    
int strlength(char mystr[])
{
    int i = 0;
    while (mystr[i] != 0)
    i++;
    
    return i;
}

void stringappend(char *s1, char *s2)
{
    //s2 = s1 + s2;
    int s2len = strlength(s2);
    int s1len = strlength(s1);
    char temp[256] = "";
    for (int i = 0; i <= s1len; i++)
        temp[i] = s1[i];
    for (int i = s1len; i < (s1len + s2len); i++)
        temp[i] = s2[i-s1len];
    for (int i = 0; i <= (s1len + s2len); i++)
        s2[i] = temp[i];
        //s1[i]=temp[i]; 
}

void inttowords(int x, char *words)
{
    //clearstring(words);
    int count = 0;
    while (x != 0)
    {
        int digit = x%10;
        x /= 10;
        switch(count%3)
        {
            case 0:
            if (!((digit == 0) && (x%100)==0) )
            stringappend(places[count/3], words);
            if ((x%10)==1)
            {
                stringappend(teens[digit], words);
                count +=2;
            }
            else
            {
                stringappend(ones[digit], words);
                count ++;
            }
            break;
        case 1:
            stringappend(tens[digit], words);
            count ++;
            break;
        case 2:
            if (digit != 0)
            {
            stringappend(" hundred", words);
            stringappend(ones[digit], words);
            }
            count ++;
            break;
        }
    }
}

int main()
{
    int n;
    char words[256];
    printf("enter value to be converted to words: ");
    scanf("%d", &n);
    inttowords(n, words);
    printf("for n = %d, words is%s", n, words);

    return 0;
}



