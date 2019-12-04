#include<stdio.h>
#include<string.h>
int match_letter(char a,char letter[50])
{
    int i, count = 0;
    for( i = 0; i < 50; i++ ){
            ++count;
        if( a == letter[i]){
            break;
        }
        else{
            continue;
        }
    }
    return count - 2;
}
int main()
{
    int a, lenth, b;
    char input[1000];
    char output[1000];

    gets(input);

char letter[] = { '`','1', '2','3','4','5', '6', '7', '8', '9', '0','-', '=', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']','\\','A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';','\'','\0' , 'Z','X','C', 'V', 'B', 'N','M', ',','.','/','\0'};


    lenth = strlen(input);

    for( a = 0; a < lenth; a++){
        if(input[a] == ' ')
            output[a] = input[a];
        else{
            b = match_letter(input[a], letter);
            output[a] = letter[b];
        }
    }
    printf("%s", output);


    return 0;
}
