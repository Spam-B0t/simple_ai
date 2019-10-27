#include <stdio.h>
#include <stdlib.h>

#define abs(x) ((x)>=0) ? (x):-(x)
#define clr(s) int i; for(i=0;i<100;i++) s[i]='\0';
//#define print(x+y+z) print("%s", x); print("%s", y); print("%s", z);

void greet(char botname[], int bdyear){
    printf("Hello! My name is %s.\nI was created in %d\n", botname, bdyear);
}

void remindName(char name[]){
    printf("Please, remind me your name.\n");
    scanf("%s", name);
    printf("What a great name you have, %s!\n", name);
}

int guessAge(){
    int rem3, rem5, rem7, age;
    printf("Let me guess your age.\n");
    printf("Enter remainders of dividing your age by 3, 5 and 7.\n");
    scanf("%d %d %d", &rem3, &rem5, &rem7);
    age=(rem3 * 70 + rem5 * 21 + rem7 * 15) % 105;
    printf( "Your age is %d; that's a good time to start programming!\n", age);
    return age;
}

void recount(int n){
    if(n>=0){recount(n-1); printf("%d!\n", n);}
}

void count(){
    int n;
    printf("Now I will prove to you that I can count to any number you want.\n");
    scanf("%d", &n);
    recount(n);
}

const int qlen=57, ansnum=3, anslen=21;

int checkans(char in[], char ans[3][21]){
    int i, j, x;
    for(i=0; i<ansnum; i++){
        x=0;
        for(j=0; j<anslen; j++)if(in[j]==ans[i][j])x++;
        if(x==anslen)break;
    }
    if(x==anslen) return 0; else return 1;
}

/*
struct qapair{
    char *q;
    char ans[3][21];
};

struct qapair pair(char q[qlen], char ans[ansnum][anslen]){
    struct qapair tmp;
    int i, j;
    tmp.q=q;
    for(j=0; j<ansnum; j++)
        for(i=0; i<anslen; i++)tmp.ans[j][i]=ans[j][i];
    return tmp;
}
*/

void question(){
    char questions[3][57]={"2+2=", "What is java", "What is the answer to life, the universe and everything"},
         answers[3][3][21]={{"4", "four", "-5 mod 9"}, {"coffee", "programming language"}, {"idk", "42"}},
         ans[100];
    int r=2;//rand()%3;
    printf("Let's test your knowledge.\n");
    printf("%s?\n", questions[r]); clr(ans); gets(ans);
    while(checkans(ans, answers[r])!=0){
        printf("Please, try again. \n");
        clr(ans);
        gets(ans);
    }
    printf("That's right! Nice job!\n");
}

int main(){
    /*struct qapair test=pair("Question?", (char[3][21]){"yes","no","idk"});
    puts(test.ans[2]); struct qapair tst[3];*/
    char botname[]="ai", username[101];
    int bdyear=2019, userage;
    greet(botname, bdyear);
    //remindName(username);
    //userage=guessAge();
    //count();
    question();
    printf("PROGRAM FINISHED");
}



