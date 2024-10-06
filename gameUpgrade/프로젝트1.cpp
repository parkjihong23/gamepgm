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

//�߰� �Լ�  
void starkClock(double pet);


int main(void)
{
    int width, height, treasure_count;

    // ���� ���� ���̸� �Է¹���
    printf("���� ���� ũ�⸦ �Է��ϼ��� (�ִ� 30): ");
    scanf("%d", &width);
    printf("���� ���� ũ�⸦ �Է��ϼ��� (�ִ� 30): ");
    scanf("%d", &height);
	
	 // ���� ���� �Է�
    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &treasure_count);
	
     int tx[treasure_count], ty[treasure_count];
    int matrix[30][30] = {0};  // ����, ���� �ִ� 30���� ����
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
    printf("��� �ð� : %.1f ��", pst);
    gotoxy(1, height + 4);
    printf("��� ã�ҽ��ϴ�. ������ �����մϴ�. \n");
    getch();
    return 0;
}

void display_rule(int width, int height, int treasure_count)
{
    gotoxy(1, 1);
    printf("����ã��");
    gotoxy(1, 3);
    printf("�Ʒ��� �ٵ��� ����� ���ڿ��� %d���� ������ \n", treasure_count);
    gotoxy(1, 4);
    printf("������ �ֽ��ϴ�. \n");
    gotoxy(1, 5);
    printf("ȭ��ǥ(�����)Ű�� �������� ã���ϴ�. \n");
    gotoxy(1, 7);
    basic_map(width, height);
    printf("\n�ƹ�Ű�� ������ �����մϴ�. \n");
    getch();
}

void basic_map(int width, int height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
            printf("��");
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
            tx[i] = rand() % width;  // ������ x��ǥ
            ty[i] = rand() % height; // ������ y��ǥ
        } while ((tx[i] < 1) || (ty[i] < 1));  // �� �������� ��ġ
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
                gotoxy(j, i);  // j�� x��, i�� y�࿡ �ش���
                printf("��");
            }
            else if (matrix[i][j] == 2)
            {
                gotoxy(j, i);
                printf("��");
            }
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
    switch (key)
    {
    case 72: // ����(��) ������ ȭ��ǥ Ű �Է�
        *y1 = *y1 - 1;
        if (*y1 < 1)
            *y1 = 1; // y��ǥ�� �ּҰ�
        break;
    case 75: // ����(��) ������ ȭ��ǥ Ű �Է�
        *x1 = *x1 - 1;       // x��ǥ�� ���Ұ�
        if (*x1 < 1)
            *x1 = 1; // x��ǥ�� �ּҰ�
        break;
    case 77: // ������(��) ������ ȭ��ǥ Ű �Է�
        *x1 = *x1 + 1;       // x��ǥ�� ������
        if (*x1 > x_b)
            *x1 = x_b; // x��ǥ�� �ִ밪
        break;
    case 80: // �Ʒ���(��) ������ ȭ��ǥ Ű �Է�
        *y1 = *y1 + 1;
        if (*y1 > y_b)
            *y1 = y_b; // y��ǥ�� �ִ밪
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
    int matrix[30][30] = {0};  // �ִ� 30x30���� ó�� ����
    
	clock_t start = clock(); 
	
	do
    {	
   		 
        if (kbhit()) {
            key = getch();
            move_arrow_key(key, &x, &y, width, height);
        }
    	
        gotoxy(x, y);
        printf("��");
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
        double pet = (double)(end - start) / CLOCKS_PER_SEC;  // ��� �ð� ���
        gotoxy(1, height + 3);
		starkClock(pet);  // 0���� ��� �ð� ǥ��
      	
      	
        gotoxy(1, height + 2);
        printf("ã�� ����(��)�� ���� : %d", count);
       
        
       Sleep(70);
    } while (count < treasure_count);
}

void starkClock(double pet){
    printf("��� �ð� : %.1f ��", pet);
}

