#include <stdio.h>
#include <windows.h>

#include <stdlib.h>
#include <conio.h>

#define X_MAX 79 //����(��)������ �ִ밪 80
#define Y_MAX 24 //����(��)������ �ִ밪 25 


void gotoxy(int x, int y);
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);

int main(void){
/*
	for(int i= 1; i<=9; i++) {
		gotoxy(35,5+i);
		printf("%d*%d=%2d",3,i,3*i);
	}
	printf("\n");
*/	

//--------------------------------
/*
	char ch;
	printf("���ڸ��Է��ϰ� enter : ");
	scanf(" %c", &ch);
	system("cls");
	printf("�Էµ� ���� %c\n",ch);
	getch(); //�Է� ���۸� ����� ���� �ʿ��� �ڵ� 


	int i, j;
	for(j=1;j<=9;j++){
		system("cls");
		for(i=1;i<=9;i++)
		printf("%d*%d=%d\n", j, i, j*i);
		printf("�ƹ�Ű�� �����ÿ�.\n");
		getch();
    }
*/

//----------------------------
//�Է¹��۰� �� ������� �ʾ� scanf�� ����
/*   
    char string[20];
	char c;
	
	scanf("%s", string);
	scanf("%c", &c);
	
	printf("%s\n", string);
	printf("!!%c!!\n", c);

//============> 
	
	char str[20] = "abcd";
	printf("%d\n" , sizeof(string));
	printf("%s" , string);


	int i;
	i = printf("%s", string);
	printf("%d\n", i); 
*/
/*	
	int chr;
	do{
		chr=getch();
		if (chr==0 || chr == 0xe0)
		{
			chr=getch();
			printf("Ȯ��Ű code=%d\n", chr);
		}
		else
			printf("�ƽ�Ű code=%d\n", chr);
	}while(1);
*/
	
	char key;
	int x=10, y=5;
	do{
		gotoxy(x, y);
		printf("��");
		key=getch();
		system("cls"); //�ܼ�â�� �ִ°�  ����� �Լ� 
		move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
	}while(key!=27);
	
	
	
	
	
	
	
return 0 ;}

void gotoxy(int x, int y) {
	COORD Pos = {x-1, y-1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
    
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch(key){
	case 72: //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1) *y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75: //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-1;
		if (*x1<1) *x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77: //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+1;
		if (*x1>x_b) *x1=x_b; //x��ǥ�� �ִ밪
		break;
	case 80: //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b) *y1=y_b; //y��ǥ�� �ִ밪
		break;
	default:
		return;
	}
}



