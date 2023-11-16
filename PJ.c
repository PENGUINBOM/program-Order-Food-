#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct menu{
    char *menu_x[4];
    int price[4];
};

int noodle();
int fried_rice();
int steak();
void login();

char name[80];
struct menu menu1 = {{"Shrimp Wonton Soup","Pork Wonton Soup","Noodle Soup with Crispy Pork","Noodle Soup with Red Roaster Pork"},{30,30,35,35}};

int main()
{
    int res, price=0;
    printf("Welcome to the restaurant!\n");
    do{
        printf("\nSelect your food group\n");
        printf("1. Noodle\n2. Fried Rice\n3. Steak\n");
        printf("Enter your group (0 to stop) >> ");
        scanf("%d", &res);
        switch(res){
            case 0:
                break;
            case 1:
                price+=noodle();
                break;
            case 2:
                price+=fried_rice();
                break;
            case 3:
                price+=steak();
                break;
            default:
                printf("Error, please try again\n");
        }
    }while(res!=0);
    printf("\nTotal price for your order: %d\n",price);
    printf("\n---Please wait for your order---\n");
    return 0;
}

int noodle(){
    int s_menu, ch=0, m, plate[4]={0,0,0,0}, i;
    do{
        printf("\n-----Noodle menu-----\n");
        for(i=0;i<4;++i){
            printf("%d. %s, price: %d\n",i+1,menu1.menu_x[i],menu1.price[i]);
        }
        printf("\nSelect your order (0 to stop) >> ");
        scanf("%d", &s_menu);
        if(s_menu>0&&s_menu<4){
            printf("How many do you want? >> ");
            scanf("%d", &m);
            ch+=menu1.price[s_menu-1]*m;
            plate[s_menu-1]+=m;
            printf("%s, price: %d, order: %d, total: %d\n", menu1.menu_x[s_menu-1], menu1.price[s_menu-1], plate[s_menu-1], plate[s_menu-1]*menu1.price[s_menu-1]);
        }
        else if(s_menu==0){
            printf("Ending order\n");
        }
        else{
            printf("Error, please try again\n");
        }
    }while(s_menu!=0);
    printf("\n-----Your order-----\n");
    for(i=0;i<4;++i){
        printf("%d. %s, price: %d, order: %d, total: %d\n",i+1,menu1.menu_x[i],menu1.price[i],plate[i],plate[i]*menu1.price[i]);
    }
    printf("\nTotal price for this order: %d\n",ch);
    printf("\n------------------------------\n");
    return ch;
}

int fried_rice(){
    int s_menu, ch=0, m, plate[4]={0,0,0,0};
}

int steak(){
    int s_menu, ch=0, m, plate[4]={0,0,0,0};
}