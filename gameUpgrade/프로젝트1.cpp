#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void display_rule(int width, int height, int treasure_count);
void gotoxy(int x, int y);
void make_treasure(int tx[], int ty[], int width, int height, int treasure_count);
void display_map(int matrix[][30], int tx[], int ty[], int width, int height);
void basic_map(int width, int height);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void game_control(int tx[], int ty[], int width, int height, int treasure_count);

//추가 함수  
void starkClock(double pet);


int main(void)
{
    int width, height, treasure_count;

    // 가로 세로 넓이를 입력받음
    printf("맵의 가로 크기를 입력하세요 (최대 30): ");
    scanf("%d", &width);
    printf("맵의 세로 크기를 입력하세요 (최대 30): ");
    scanf("%d", &height);
	
	 // 보물 개수 입력
    printf("보물의 개수를 입력하세요: ");
    scanf("%d", &treasure_count);
	
     int tx[treasure_count], ty[treasure_count];
    int matrix[30][30] = {0};  // 가로, 세로 최대 30으로 설정
    clock_t start, end;
    double pst;
    srand(time(NULL));
    make_treasure(tx, ty, width, height, treasure_count);
    display_rule(width, height, treasure_count);
    start = clock();
    system("cls");
    game_control(tx, ty, width, height, treasure_count);
    end = clock();
    pst = (double)(end - start) / CLK_TCK;
    gotoxy(1, height + 3);
    printf("경과 시간 : %.1f 초", pst);
    gotoxy(1, height + 4);
    printf("모두 찾았습니다. 게임을 종료합니다. \n");
    getch();
    return 0;
}

void display_rule(int width, int height, int treasure_count)
{
    gotoxy(1, 1);
    printf("보물찾기");
    gotoxy(1, 3);
    printf("아래의 바둑판 모양의 격자에는 %d개의 보물이 \n", treasure_count);
    gotoxy(1, 4);
    printf("숨겨져 있습니다. \n");
    gotoxy(1, 5);
    printf("화살표(↑↓←→)키를 움직여서 찾습니다. \n");
    gotoxy(1, 7);
    basic_map(width, height);
    printf("\n아무키나 누르면 시작합니다. \n");
    getch();
}

void basic_map(int width, int height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
            printf("■");
        printf("\n");
    }
}

void make_treasure(int tx[], int ty[], int width, int height, int treasure_count)
{
    int i;
    for (i = 0; i < treasure_count; i++)
    {
        do
        {
            tx[i] = rand() % width;  // 보물의 x좌표
            ty[i] = rand() % height; // 보물의 y좌표
        } while ((tx[i] < 1) || (ty[i] < 1));  // 맵 내에서만 배치
    }
}

void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void display_map(int matrix[][30], int tx[], int ty[], int width, int height)
{
    int i, j;
    basic_map(width, height);
    for (i = 1; i <= height; i++)
        for (j = 1; j <= width; j++)
            if (matrix[i][j] == 1)
            {
                gotoxy(j, i);  // j는 x축, i는 y축에 해당함
                printf("□");
            }
            else if (matrix[i][j] == 2)
            {
                gotoxy(j, i);
                printf("★");
            }
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
    switch (key)
    {
    case 72: // 위쪽(상) 방향의 화살표 키 입력
        *y1 = *y1 - 1;
        if (*y1 < 1)
            *y1 = 1; // y좌표의 최소값
        break;
    case 75: // 왼쪽(좌) 방향의 화살표 키 입력
        *x1 = *x1 - 1;       // x좌표의 감소값
        if (*x1 < 1)
            *x1 = 1; // x좌표의 최소값
        break;
    case 77: // 오른쪽(우) 방향의 화살표 키 입력
        *x1 = *x1 + 1;       // x좌표의 증가값
        if (*x1 > x_b)
            *x1 = x_b; // x좌표의 최대값
        break;
    case 80: // 아래쪽(하) 방향의 화살표 키 입력
        *y1 = *y1 + 1;
        if (*y1 > y_b)
            *y1 = y_b; // y좌표의 최대값
        break;
    default:
        return;
    }
}

void game_control(int tx[], int ty[], int width, int height, int treasure_count)
{
    char key;
    int i, j, count = 0;
    int x = 1, y = 1;
    int matrix[30][30] = {0};  // 최대 30x30까지 처리 가능
    
	clock_t start = clock(); 
	
	do
    {	
   		 
        if (kbhit()) {
            key = getch();
            move_arrow_key(key, &x, &y, width, height);
        }
    	
        gotoxy(x, y);
        printf("□");
        matrix[y][x] = 1;

        for (i = 0; i < treasure_count; i++)
            if ((x == tx[i]) && (y == ty[i]))
                matrix[y][x] = 2;

        gotoxy(1, 1);
        display_map(matrix, tx, ty, width, height);

        count = 0;
        for (i = 1; i <= height; i++)
            for (j = 1; j <= width; j++)
                if (matrix[i][j] == 2)
                    count++;
        
		clock_t end = clock();
        double pet = (double)(end - start) / CLOCKS_PER_SEC;  // 경과 시간 계산
        gotoxy(1, height + 3);
		starkClock(pet);  // 0부터 경과 시간 표시
      	
      	
        gotoxy(1, height + 2);
        printf("찾은 보물(★)의 개수 : %d", count);
       
        
       Sleep(70);
    } while (count < treasure_count);
}

void starkClock(double pet){
    printf("경과 시간 : %.1f 초", pet);
}

