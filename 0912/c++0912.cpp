#include <stdio.h>
#include <windows.h>

#include <stdlib.h>
#include <conio.h>

#define X_MAX 79 //가로(열)방향의 최대값 80
#define Y_MAX 24 //세로(행)방향의 최대값 25 


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
	printf("문자를입력하고 enter : ");
	scanf(" %c", &ch);
	system("cls");
	printf("입력된 문자 %c\n",ch);
	getch(); //입력 버퍼를 지우기 위해 필요한 코드 


	int i, j;
	for(j=1;j<=9;j++){
		system("cls");
		for(i=1;i<=9;i++)
		printf("%d*%d=%d\n", j, i, j*i);
		printf("아무키나 누르시오.\n");
		getch();
    }
*/

//----------------------------
//입력버퍼가 다 비워지지 않아 scanf가 씹힘
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
			printf("확장키 code=%d\n", chr);
		}
		else
			printf("아스키 code=%d\n", chr);
	}while(1);
*/
	
	char key;
	int x=10, y=5;
	do{
		gotoxy(x, y);
		printf("ㅁ");
		key=getch();
		system("cls"); //콘솔창에 있는걸  지우는 함수 
		move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
	}while(key!=27);
	
	
	
	
	
	
	
return 0 ;}

void gotoxy(int x, int y) {
	COORD Pos = {x-1, y-1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
    
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch(key){
	case 72: //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1) *y1=1; //y좌표의 최소값
		break;
	case 75: //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-1;
		if (*x1<1) *x1=1; //x좌표의 최소값
		break;
	case 77: //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+1;
		if (*x1>x_b) *x1=x_b; //x좌표의 최대값
		break;
	case 80: //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b) *y1=y_b; //y좌표의 최대값
		break;
	default:
		return;
	}
}



