## [방향키로 움직이는 네모] 
![Alt text](/path/to/img.jpg "Optional title")
<pre><code>
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
</code></pre>
<hr> 

## [버튼 메뉴보드 만들기]
<pre><code>
  #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int menu_display(void);
int sub_menu_display01(void); //햄버거에 대한 서브 메뉴 출력과 번호 입력
int sub_menu_display02(void); //스파게티에 대한 서브 메뉴 출력과 번호 입력
void sub_main01(void); //햄버거에 대한 서브 메뉴 제어
void sub_main02(void); //스파게티에 대한 서브 메뉴 제어
void chicken_burger(void);
void cheese_burger(void);
void tomato_spaghetti(void);
void cream_spaghetti(void);
void press_any_key(void); //아무키나 누르면 이전 메뉴로

int main(void)
{
	int c;
	while((c=menu_display())!=3)
	{
		switch(c)
		{
			case 1 : sub_main01();
			break;
			case 2 : sub_main02();
			break;
			default : break;
	}
	}
	return 0;
}

int menu_display(void)
{
	int select;
	system("cls");
	printf("간식 만들기\n\n");
	printf("1. 햄버거 \n");
	printf("2. 스파게티\n");
	printf("3. 프로그램 종료\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;
	return select;
}

void sub_main01(void)
{
	int c;
	while((c=sub_menu_display01())!= 3)
	{
		switch(c)
			{
			case 1 : chicken_burger();
			break;
			case 2 : cheese_burger();
			break;
			default : break;
	}
	}
}


void chicken_burger(void)
{
	system("cls");
	printf("치킨버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}


void cheese_burger(void)
{
	system("cls");
	printf("치즈버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}


int sub_menu_display01(void)
{
	int select;
	system("cls");
	printf("햄버거 만들기\n\n");
	printf("1. 치킨버거\n");
	printf("2. 치즈버거\n");
	printf("3. 메인 메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;
	return select;
}


void sub_main02(void)
{
	int c;
	while((c=sub_menu_display02())!= 3)
	{
		switch(c)
		{
			case 1 : tomato_spaghetti();
			break;
			case 2 : cream_spaghetti();
			break;
			default : break;
	}
	}
}

int sub_menu_display02(void)
{
	int select;
	system("cls");
	printf("스파게티 만들기\n\n");
	printf("1. 토마토 스파게티 \n");
	printf("2. 크림 스파게티 \n");
	printf("3. 메인 메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;
	return select;
}

void tomato_spaghetti(void)
{
	system("cls");
	printf("토마토 스파게티 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}

void cream_spaghetti(void)
{
	system("cls");
	printf("크림 스파게티 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}


void press_any_key(void)
{
	printf("\n\n");
	printf("아무키나 누르면 이전 메뉴로...");
	getch();
}
</code></pre>
<hr>  
