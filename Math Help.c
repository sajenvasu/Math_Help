#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Add_Sub(int *choice);
void Mul_Del(int *choice);

int main(){
    int run = 1;
    int choice = 0;
    printf("Welcome to Math Program\n");
    printf("-----------------------\n\n");
    while(run == 1){
        printf("Select number as the choice\n");
        printf("0: Exit\n");
        printf("1: Addition\n");
        printf("2: Subtraction\n");
        printf("3: Multiplication\n");
        printf("4: Division\n>> ");
        scanf("%d", &choice);

        if (choice == 0){
            return 1;
        }else if (choice == 1 || choice == 2){
            Add_Sub(&choice);
        }else if (choice == 3 || choice == 4){
            Mul_Del(&choice);
        }else{
            printf("Enter a valid choice\n\n");
        }

    }
    return 0;
}

int Check_Ans(int *Ans1, int *Ans2){
    if (*Ans1 == *Ans2){
        return 1;
    }else{
        return 0;
    }
}

void Add_Sub(int *choice){
    printf("\n*********************************************\n");
    printf("Enter 0 as the answer to any question to stop\n");
    int run = 1;
    int count = -1;
    int correct = 0;

    while(run == 1){
        count = count + 1;
        srand(time(NULL));
        int n1 = rand() % 100 + 1;
        int n2 = rand() % 100 + 1;
        int ans = n1 + n2;
        int user_ans = 0;

        if (*choice == 1){
            //Addition
            printf("%d + %d = ", n1, n2);
            scanf("%d", &user_ans);

            if (user_ans == 0){
                run = 0;
                printf("Finished!\n");
            }else{
                int rt_val = Check_Ans(&user_ans, &ans);
                if (rt_val == 1){
                    printf("Correct!\n");
                    correct = correct + 1;
                }else{
                    printf("Incorrect!\n");
                }
            }
            
        }else{
            //Subtraction
            printf("%d - %d = ", ans, n2);
            scanf("%d", &user_ans);

            if (user_ans == 0){
                run = 0;
                printf("Finished!\n");
            }else{
                int rt_val = Check_Ans(&user_ans, &n1);
                if (rt_val == 1){
                    printf("Correct!\n");
                    correct = correct + 1;
                }else{
                    printf("Incorrect!\n");
                }
            }
        }
    }

    printf("\nFinal Score: %d/%d\n", correct, count);
    printf("*********************************************\n\n");
}

void Mul_Del(int *choice){
    printf("\n*********************************************\n");
    printf("Enter 0 as the answer to any question to stop\n");
    int run = 1;
    int count = -1;
    int correct = 0;

    while(run == 1){
        count = count + 1;
        srand(time(NULL));
        int n1 = rand() % 100 + 1;
        int n2 = rand() % 100 + 1;
        int ans = n1 * n2;
        int user_ans = 0;

        if (*choice == 3){
            //Multiplication
            printf("%d * %d = ", n1, n2);
            scanf("%d", &user_ans);

            if (user_ans == 0){
                run = 0;
                printf("Finished!\n");
            }else{
                int rt_val = Check_Ans(&user_ans, &ans);
                if (rt_val == 1){
                    printf("Correct!\n");
                    correct = correct + 1;
                }else{
                    printf("Incorrect!\n");
                }
            }
            
        }else{
            //Division
            printf("%d / %d = ", ans, n2);
            scanf("%d", &user_ans);

            if (user_ans == 0){
                run = 0;
                printf("Finished!\n");
            }else{
                int rt_val = Check_Ans(&user_ans, &n1);
                if (rt_val == 1){
                    printf("Correct!\n");
                    correct = correct + 1;
                }else{
                    printf("Incorrect!\n");
                }
            }
        }
    }

    printf("\nFinal Score: %d/%d\n", correct, count);
    printf("*********************************************\n\n");
}