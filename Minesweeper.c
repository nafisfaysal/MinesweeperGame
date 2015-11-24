#include<stdio.h>
#define GRID_SIZE 9

int field[GRID_SIZE][GRID_SIZE];
int shown[GRID_SIZE][GRID_SIZE];



int deploy_mine()
{
    field[0][5] = -1;
    field[2][7] = -1;
    field[3][6] = -1;
    field[3][8] = -1;
    field[4][0] = -1;
    field[4][7] = -1;
    field[5][4] = -1;
    field[6][8] = -1;
    field[7][8] = -1;
    field[8][2] = -1;

    int a,b;
    int number_of_mines=0;
    for(a=0; a<GRID_SIZE; a++)
    {
        for(b=0; b<GRID_SIZE; b++)
        {
            if(field[a][b]==-1)number_of_mines++;
        }
    }

    return number_of_mines;
}

void print()
{
    system("cls");
    int a, b;

    printf("\n\n");

    printf("      ");
    for(a=0; a<GRID_SIZE; a++)
        printf("%d   ",a);
    printf("\n");

    printf("   ");
    for(a=0; a<GRID_SIZE; a++)
        printf("----");
    printf("\n");

    for(a=0; a<GRID_SIZE; a++)
    {
        printf("%d  |  ", a);
        for(b=0; b<GRID_SIZE; b++)
        {
            if(shown[a][b])
            {
                if(field[a][b]==-1)
                {
                    printf("*   ");
                }
                else
                    printf("%d   ", field[a][b]);
            }
            else printf(".   ");
        }



        printf("\n\n");
    }

}

void calculate_adjacent()
{
    int a, b;

    for(b=0; b<GRID_SIZE; b++)
    {
        for(a=0; a<GRID_SIZE; a++)
        {
            if((field[a][b])==-1)
            {
                if( (a-1>=0) && (b-1>=0) && field[a-1][b-1]!=-1)
                    field[a-1][b-1]++;

                if( b-1>=0 && field[a][b-1]!=-1)
                    field[a][b-1]++;

                if( (a+1<=GRID_SIZE-1) && (b-1>=0) && field[a+1][b-1]!=-1)
                    field[a+1][b-1]++;

                if( a-1>=0 && field[a-1][b]!=-1)
                    field[a-1][b]++;

                if( a+1<=GRID_SIZE-1 && field[a+1][b]!=-1)
                    field[a+1][b]++;

                if( (a-1>=0) && (b+1<=GRID_SIZE-1) && field[a-1][b+1]!=-1)
                    field[a-1][b+1]++;

                if( b+1<=GRID_SIZE-1 && field[a][b+1]!=-1)
                    field[a][b+1]++;

                if( (a+1<=GRID_SIZE-1) && (b+1<=GRID_SIZE-1) && field[a+1][b+1]!=-1)
                    field[a+1][b+1]++;
            }
        }

    }
}


int main()
{
    int x,y, free_space;
    int game_over=0;

    free_space = (GRID_SIZE*GRID_SIZE)-deploy_mine();
    calculate_adjacent();
    print();


    while(!game_over && free_space)
    {
        printf("Enter X axis: ");
        scanf("%d", &y);
        if(y<0 || y >8)
        {
            printf("Wrong Input. Try again\n");
            continue;
        }

        input_y:
        printf("Enter Y axis: ");
        scanf("%d", &x);
        if(x<0 || x >8)
        {
            printf("Wrong Input. Try again\n");
            goto input_y;
        }
        if(shown[x][y])
        {
            printf("Already Shown. Give a new input\n");
            continue;
        }
        shown[x][y]=1;

        free_space--;


        if(field[x][y]==-1) game_over=1;
        print();
    }

    if(!free_space) printf("YOU WON");
    else printf("GAME OVER");
}
