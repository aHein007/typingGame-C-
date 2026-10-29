#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char user_type[50];
    int i;
    printf("タイピングゲームを始めます\n");
    char question[5][50]={
        "kobedeshi\n神戸電子専門",
        "kobe\n神戸",
        "hanabi\n花火",
        "oobanntou\nお弁当",
        "bennkyou\n勉強"
    };

    char answer[5][10]={"school","city","hana","eat","skill"};

    // make unique random
    char order[5]={0,1,2,3,4};
    int length = sizeof(order) / sizeof(order[0]);
    for(int k = length-1; k > 0 ;k--){/// left to right random input
        int j = rand() % (k+1);// random
        int temp = order[j];
        order[j] = order[k];
        order[k] =temp;
    }

    i=0;
    time_t start_t = time(NULL);
    while (i < 5)
    {   /// order is for unique random
       int q = order[i];// right to left
        

        while(1){// this while is main concept!
            
        printf("第%d問\n",i+1);
        printf("%s\n",question[q]);
        scanf("%s",user_type);

       // this is for random question
      
       // this is for answer
        if(strcmp(user_type,answer[q]) == 0){
            system("cls");
            break;
        }
        else
            printf("ミスがあります、もう一度！\n");
        
        }

        if(i == 4){
            time_t end_t = time(NULL);
            printf("終了！！\n");
            double total = difftime(end_t,start_t);

            int avgTime = total / i;
            printf("平均時間%ds",avgTime);
        }

        i++;
    }


   


    
    
    return 0;
}