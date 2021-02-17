#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define HIGHSCORE_3x3 "highscore_3x3" //membuat file
#define HIGHSCORE_5x5 "highscore_5x5"
#define HIGHSCORE_7x7 "highscore_7x7"

//Variabel highscore
typedef struct {
	char nama[25];
	int win;
	int draw;
	int lose;
	int total;
} HighscoreData;

HighscoreData pemain_3x3[2];
HighscoreData pemain_5x5[2];
HighscoreData pemain_7x7[2];

HighscoreData list_3x3[100];
HighscoreData list_5x5[100];
HighscoreData list_7x7[100];

void input_nama(int musuh, int mode); //305
void initial_variabel(int mode); //341
void swap (int i, int j, int mode); //853
int GetData(); //802
void writeData(int musuh, int mode); //729
void sortHighscore(int N, int mode); //823
void highscore(int mode); //760

//Matrik 3x3
void Display_3x3(char papan_3x3[3][3], char kesulitan, int musuh); //555
void player_move_3x3(int giliran, char papan_3x3[3][3]); //491																
void computer_move_3x3(char papan_3x3[3][3], char kesulitan); //580
char check_3x3(char papan_3x3[3][3]); //525
void run_3x3(int musuh, int mode); //375
void init_board_3x3(char papan_3x3[3][3]); //331

//Matrik 5x5
void Display_5x5(char papan_5x5[5][5][2], char kesulitan, int musuh); //870
void player_move_5x5(int giliran, char papan_5x5[5][5][2]); //1092														
void computer_move_5x5(char papan_5x5[5][5][2], char kesulitan); //1136
char check_5x5(char papan_5x5[5][5][2]); //1010
void run_5x5(int musuh, int mode); //896

//Matrik 7x7
void run_7x7(int musuh, int mode); //1667
void Display_7x7(char papan_7x7[7][7][2], char kesulitan, int musuh); //1782
void player_move_7x7(int giliran, char papan_7x7[7][7][2]);	//1809											
void computer_move_7x7(char papan_7x7[7][7][2], char kesulitan); //1951
char check_7x7(char papan_7x7[7][7][2]); //1858

//Umum
void header(); //98
void playgame(); //213
void help(); //106
void credits(); //195
int PilihanMusuh(); //231
int PilihanMode(); //251
void PilihanModeHighscore(); //271
int PilihanKesulitan(); //288

void main(){
	char pilihMenu;
	do {
		system("cls");
		header();
		printf("\n\t\t\t  _________________________________\n");
		printf("\t\t\t  |\t\t\t\t  |\n");
		printf("\t\t\t  |\t      Menu  \t\t  |\n");
		printf("\t\t\t  |\t\t\t\t  |\n");
		printf("\t\t\t  |\t1.Play Game\t\t  |\n");
		printf("\t\t\t  |\t2.Highscore\t\t  |\n");
		printf("\t\t\t  |\t3.Help\t\t\t  |\n");
		printf("\t\t\t  |\t4.Credits\t\t  |\n");
		printf("\t\t\t  |\t5.Keluar\t\t  |\n");
		printf("\t\t\t  |_______________________________|\n");	
		printf("\t\t\t\tEnter Menu : ");scanf("%c",&pilihMenu);
		
		/* Pemilihan Menu */
		if(pilihMenu == '1')
			playgame();
		else if(pilihMenu == '2')
			PilihanModeHighscore();
		else if(pilihMenu == '3')
			help();
		else if(pilihMenu == '4')
			credits();
	}while(pilihMenu != '5');
    exit(0);
}

void header(){
	printf("\n\t\t\t\t_____________________");
	printf("\n\t\t\t\t|Welcome to our Game|");
	printf("\n\t\t\t\t|    TIC TAC TOE    |");
	printf("\n\t\t\t\t|    3x3|5x5|7x7    |\n");
	printf("\t\t\t\t|___________________|\n");
}

void help(){
	char pilih='0';
	char a='0';
	do{
		system("cls");
		printf("\n\t\t\t\t||||~TIC TAC TOE|||~|");
		printf("\n\n\t\t\t\t\t  |Help|");
		printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\t\t\t\t1. How to input \n");
		printf("\t\t\t\t2. Winning Conditions \n");
		printf("\t\t\t\t3. Draw Conditions \n");
		printf("\t\t\t\t4. Earning Points \n");
		printf("\t\t\t\t5. Exit \n");
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\n Enter Menu : ");
	    scanf("%s",&pilih);
	    if ( pilih == '1' ){
	    	system("cls");
	    	printf("\n\t\t\t\t||||~TIC TAC TOE|||~|");
			printf("\n\n\t\t\t\t  |Help - How to input|");
			printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\t1.Masukkan angka sesuai \n");
			printf("\t\t\t\t  dengan nomor pada papan \n");
			printf("\t\t\t\t2.Tidak boleh memasukan\n");
			printf("\t\t\t\t  angka pada kotak yang\n");
			printf("\t\t\t\t  sudah terisi \n");
			printf("\t\t\t\t3.Pemain memasukkan angka\n");
			printf("\t\t\t\t  bergantian sesuai urutan\n");
			printf("\t\t\t\t  bermain \n");
			printf("\n type anything to return : ");
	    	scanf("%s",&a);
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		}else if ( pilih == '2' ){
			system("cls");
	    	printf("\n\t\t\t\t ||||~TIC TAC TOE|||~|");
			printf("\n\n\t\t\t\t~|Help - Winning Conditions|~");
			printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\tPemain yang pertama kali\n");
			printf("\t\t\t\tberhasil menyusun tanda \n");
			printf("\t\t\t\tsecara berurutan membentuk \n");
			printf("\t\t\t\tgaris horizontal, vertikal,\n");
			printf("\t\t\t\tatau diagonal akan memenangkan\n");
			printf("\t\t\t\tpermainan. \n");
			printf("\t\t\t\t(mode 3x3 = 3 tanda) \n");
			printf("\t\t\t\t(mode 5x5 = 4 tanda)\n");
			printf("\t\t\t\t(mode 7x7 = 5 tanda)\n");
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\n type anything to return : ");
	    	scanf("%s",&a);
		}else if ( pilih == '3' ){
			system("cls");
	    	printf("\n\t\t\t\t||||~TIC TAC TOE|||~|");
			printf("\n\n\t\t\t\t |Help - Earning Points|");
			printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\tJika kotak pada papan \n");
			printf("\t\t\t\tpermainan sudah terisi \n");
			printf("\t\t\t\tsemua dan belum terdapat \n");
			printf("\t\t\t\tgaris horizontal, vertikal,\n");
			printf("\t\t\t\tatau diagonal dari tanda \n");
			printf("\t\t\t\tpemain yang sama, maka \n");
			printf("\t\t\t\tpermainan dinyatakan imbang \n");
			printf("\t\t\t\tdan permainan berakhir.\n");
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\n type anything to return : ");
	    	scanf("%s",&a);
		}else if ( pilih == '4' ){
			system("cls");
	    	printf("\n\t\t\t\t||||~TIC TAC TOE|||~|");
			printf("\n\n\t\t\t\t |Help - Earning Points|");
			printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\tHighscore akan mencatat \n");
			printf("\t\t\t\triwayat point pemain dalam\n");
			printf("\t\t\t\tpermainan\n");
			printf("\t\t\t\t• Jika pemain memenangkan \n");
			printf("\t\t\t\t  permainan, maka point win \n");
			printf("\t\t\t\t  akan bertambah 3.\n");
			printf("\t\t\t\t• Jika hasil permainan \n");
			printf("\t\t\t\t  imbang, maka point draw \n");
			printf("\t\t\t\t  akan bertambah 1.\n");
			printf("\t\t\t\t• Jika pemain mengalami \n");
			printf("\t\t\t\t  kekalahan, maka point lose \n");
			printf("\t\t\t\t  akan dikurangi 1.\n");
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\n type anything to return : ");
	    	scanf("%s",&a);
	    }
	}while(pilih != '5');
}

void credits(){
	char kembali='0';
	system("cls");
	do{
		printf("\n\t\t\t\t|~|~|~|~TIC TAC TOE~|~|~|~|");
		printf("\n\n\t\t\t\t\t~|Credits|~");
		printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\t\t\t\t Anna Kurniaty \n");
		printf("\t\t\t\t Dimas Wisnu Saputro \n\n");
		printf("\t\t\t\t D4 - Teknik Informatika \n");
		printf("\t\t\t\t JTK 2020 \n");
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\n Type 1 if you want to return to the menu : ");
	    scanf("%s",&kembali);
		}
	while(kembali != '1');
}

void playgame(){
	int musuh=0, mode=0;
	mode=PilihanMode();
	musuh=PilihanMusuh();
	input_nama(musuh, mode);
	switch(mode){
		case 3:	
			run_3x3(musuh, mode);
			break;
		case 5:
			run_5x5(musuh, mode);
			break;
		case 7:
			run_7x7(musuh, mode);
			break;
	}
}

int PilihanMusuh(){
	int a;
	system("cls");
	do{
		printf("\n\t\t\t\t|~|~|~|~TIC TAC TOE~|~|~|~|");
		printf("\n\n\t\t\t\t~|Choose Opponent Game|~");
		printf("\n\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\t\t\t\tPlay with friend:(1)\n");
		printf("\t\t\t\tPlay with computer:(2)\n");
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");	
		printf("\t\t\t\tPlease select an opponent to play : ");
		scanf("%d", &a);
		if(a!=1&&a!=2){
		printf("\n\t\t\t\tThe choice of opponent you have entered is wrong\n\t\t\t\tTry to type it right!!\n\n");
		}
	}while(a!=1&&a!=2);
	
	return a;
}

int PilihanMode(){
	int b;
	system("cls");
	printf("\n\t\t\t\t~|~|~|~|~TIC TAC TOE~|~|~|~|~");
	printf("\n\n\t\t\t\t~~Choose Mode Game~~\n");
	do{	
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\t     TIC TAC TOE 3x3:(3)\n");
		printf("\t\t\t\t     TIC TAC TOE 5x5:(5)\n");
		printf("\t\t\t\t     TIC TAC TOE 7x7:(7)\n");
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\tPlease select an mode to play: ");
		scanf("%d", &b);
		if(b!=3&&b!=5&&b!=7){
		printf("\n\t\t\t\tThe choice of mode you have entered is wrong\n\t\t\t\tTry to type it right!!\n\n");
		}
	}while(b!=3&&b!=5&&b!=7);
	return b;
}

void PilihanModeHighscore(){
	int mode;
	system("cls");
	printf("\n\t\t\t\t~|~|~|~|~TIC TAC TOE~|~|~|~|~");
	printf("\n\n\t\t\t\t~~Choose Mode Highscore Game~~\n");
	do{	
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\t     TIC TAC TOE 3x3:(3)\n");
		printf("\t\t\t\t     TIC TAC TOE 5x5:(5)\n");
		printf("\t\t\t\t     TIC TAC TOE 7x7:(7)\n");
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\tPlease select an mode highscore to play: ");
		scanf("%d", &mode);
		highscore(mode);
	}while(mode!=3&&mode!=5&&mode!=7);
}

int PilihanKesulitan(){
	char kesulitan='0';
	do{	
		system("cls");
		printf("\n\t\t\t\t~|~|~|~|~TIC TAC TOE~|~|~|~|~");
		printf("\n\n\t\t\t\t~~Choose a difficulty level~~\n");
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\t     (1):Easy\n");
		printf("\t\t\t\t     (2):Medium\n");
		printf("\t\t\t\t     (3):Hard\n");
		printf("\n\t\t\t\t>>>>---------------------<<<<\n\n");
		printf("\t\t\t\tPlease select a difficulty level to play: ");
		scanf("%c", &kesulitan);
	}while(kesulitan!='1'&&kesulitan!='2'&&kesulitan!='3');	
	return kesulitan;
}

void input_nama(int musuh, int mode){
	printf("\n\t\t\t\t(Max 15 Character)");
	printf("\n\t\t\t\tPlease enter a name Player 1: ");
	fflush(stdin);
	if(mode==3){
		scanf("%[^\n]", pemain_3x3[0].nama);	
	}else if(mode==5){
		scanf("%[^\n]", pemain_5x5[0].nama);
	}else{
		scanf("%[^\n]", pemain_7x7[0].nama);
	}
	
	if(musuh==1){
		printf("\n\t\t\t\t(Max 15 Character)");
		printf("\n\t\t\t\tPlease enter a name Player 2: ");
		fflush(stdin);
		if(mode==3){
			scanf("%[^\n]", pemain_3x3[1].nama);	
		}else if(mode==5){
			scanf("%[^\n]", pemain_5x5[1].nama);
		}else{
			scanf("%[^\n]", pemain_7x7[1].nama);
		}
	}
} 

void init_board_3x3(char papan_3x3[3][3]){
	int i,j,count=49;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			papan_3x3[i][j]=count;
			count=count+1;
		}
	}												
}

void initial_variabel(int mode){
	if(mode==3){
		pemain_3x3[0].win=0 ;
		pemain_3x3[0].draw=0;
		pemain_3x3[0].lose=0;
		pemain_3x3[0].total=0;
	
		pemain_3x3[1].win=0 ;
		pemain_3x3[1].draw=0;
		pemain_3x3[1].lose=0;
		pemain_3x3[1].total=0;	
	}else if(mode==5){
		pemain_5x5[0].win=0 ;
		pemain_5x5[0].draw=0;
		pemain_5x5[0].lose=0;
		pemain_5x5[0].total=0;
		
		pemain_5x5[1].win=0 ;
		pemain_5x5[1].draw=0;
		pemain_5x5[1].lose=0;
		pemain_5x5[1].total=0;
	}else if(mode==7){
		pemain_7x7[0].win=0 ;
		pemain_7x7[0].draw=0;
		pemain_7x7[0].lose=0;
		pemain_7x7[0].total=0;
		
		pemain_7x7[1].win=0 ;
		pemain_7x7[1].draw=0;
		pemain_7x7[1].lose=0;
		pemain_7x7[1].total=0;
	}
}

void run_3x3(int musuh, int mode){
	int ulang= 1 ;
	char kesulitan='0';
	initial_variabel(mode); //initial variabel data pemain
	char papan_3x3[3][3];
	do{
		init_board_3x3(papan_3x3);
		char first_move;
		int giliran=0;
		char done=' ';
		
		do{//Menentukan bergerak pertama
			system("cls");
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\t %s:(1)\n ", pemain_3x3[0].nama);
			if(musuh==2){
				printf("\t\t\t\tComputer:(2)\n");
			}else{
				printf("\t\t\t\t %s:(2)\n", pemain_3x3[1].nama);
			}
			printf("\n\t\t\t\t>>>---------------------<<<\n\n");
			printf("\t\t\t\tChoose who moves first: ");
			scanf("%c", &first_move);
			if(first_move!='1'&&first_move!='2'){
				printf("\n\t\t\t\tThe choice you entered is wrong\n\t\t\t\tTry to type it right!!\n\n");
			}
		}while(first_move!='1'&&first_move!='2');
		
		if(musuh==2){
			kesulitan=PilihanKesulitan();	
		}
		
		if(musuh==2){
			if (first_move == '2') {
				computer_move_3x3(papan_3x3, kesulitan);
			}
		
			do{
				Display_3x3(papan_3x3,kesulitan,musuh);
				printf("\t\t\t\t  %s (X) move\n\n", pemain_3x3[0].nama);
				player_move_3x3(giliran, papan_3x3);																//player's move
				Display_3x3(papan_3x3,kesulitan,musuh);															//displaying the current matrix
				done=check_3x3(papan_3x3);															//checking the matrix
				if(done!=' '){
					break;	
				}																	//if the return is other than ' ',we break here
				
				printf("\t Computer's move (O)\n\n");
				computer_move_3x3(papan_3x3, kesulitan);
				Display_3x3(papan_3x3,kesulitan,musuh);															//displaying the matrix
				done=check_3x3(papan_3x3);															//checking the matrix
		
			}while(done==' ');
		}else{
			Display_3x3(papan_3x3,kesulitan,musuh);
			
			if (first_move == '2') {
				giliran=giliran+1;
				printf("\t\t\t\t  %s (O) move\n\n", pemain_3x3[1].nama);
				player_move_3x3(giliran, papan_3x3);
				Display_3x3(papan_3x3,kesulitan,musuh);
				giliran++;
			}
		
			do{
				printf("\t\t\t\t  %s (X) move\n\n", pemain_3x3[0].nama);
				player_move_3x3(giliran, papan_3x3);																//player's move
				Display_3x3(papan_3x3,kesulitan,musuh);															//displaying the current matrix
				done=check_3x3(papan_3x3);															//checking the matrix
				if(done!=' '){
					break;	
				}																	//if the return is other than ' ',we break here
				giliran++;
				printf("\t\t\t\t  %s (O) move\n\n", pemain_3x3[1].nama);
				player_move_3x3(giliran, papan_3x3);
				Display_3x3(papan_3x3,kesulitan,musuh);															//displaying the matrix
				done=check_3x3(papan_3x3);															//checking the matrix
				giliran++;
			}while(done==' ');
		}
		
		switch(done){
			case 'X':
				printf("\t\t\t\t  %s won\n\n", pemain_3x3[0].nama);	
				pemain_3x3[0].win += 1; 
				if(musuh==1){
					pemain_3x3[1].lose += 1;
				}
				break;
			case 'O':
				if(musuh==2){
					printf("\t\t\t\t  Computer won\n\n");
					pemain_3x3[0].lose += 1;	
				}else{
					printf("\t\t\t\t  %s won\n\n", pemain_3x3[1].nama);
					pemain_3x3[1].win += 1;
					pemain_3x3[0].lose += 1;
				}
				break;
			case 'D':
				printf("\t\t\t\t  Match Drawn\n\n");
				pemain_3x3[0].draw += 1;
				if(musuh==1){
					pemain_3x3[1].draw += 1;
				}
				break;			
		}
		pemain_3x3[0].total = 3*pemain_3x3[0].win + pemain_3x3[0].draw - pemain_3x3[0].lose;
		pemain_3x3[1].total = 3*pemain_3x3[1].win + pemain_3x3[1].draw - pemain_3x3[1].lose;
		
		printf("\n Type 1 for Re-duel and type 0 to end game: "); //reduel sama back to menu
	    scanf("%d",&ulang);
	}while(ulang==1);
	writeData(musuh, mode);
}

void player_move_3x3(int giliran, char papan_3x3[3][3]){
	int kot,bar,kol;
	clock_t start_time = clock();
	unsigned int timeout=15000;
	do{
		printf("\n \t\t\t\tEnter the Box Number You Choose (15 Second): ");
		scanf("%d",&kot);
	    if(kot<1 || kot>9 || papan_3x3[bar][kol]=='X' || papan_3x3[bar][kol]=='O'){
			printf("\n\t\t\t\tThe Number You Enter Is Incorrect\n\t\t\t\tTry to type it right!!\n\n");
		}
		   
	    if(kot>=1 && kot<=3){
	        bar=0;
	        kol=kot-1;
	    }else if(kot>=4 && kot<=6){
	        bar=1;
	        kol=kot-4;
	    }else if(kot>=7 && kot<=9){
	        bar=2;
	        kol=kot-7;
	    }
	}while(kot<1 || kot>9 || papan_3x3[bar][kol]=='X' || papan_3x3[bar][kol]=='O');
	
	if(clock() < start_time + timeout){
		if(giliran%2==0){
		    papan_3x3[bar][kol]='X';
		    return;
		}else{
		   	papan_3x3[bar][kol]='O';
		   	return;
		}
	}
}

char check_3x3(char papan_3x3[3][3]){
	int i,j;
	//row checking
	for(i=0;i<3;i++)
		if(papan_3x3[i][0]==papan_3x3[i][1]&&papan_3x3[i][0]==papan_3x3[i][2])							//checking if the elements of rows are identical
			return papan_3x3[i][0];

	//column checking
	for(i=0;i<3;i++)
		if(papan_3x3[0][i]==papan_3x3[1][i]&&papan_3x3[0][i]==papan_3x3[2][i])							//checking if the elements of columns are identical
			return papan_3x3[0][i];

	//diagonal checking
	if(papan_3x3[0][0]==papan_3x3[1][1]&&papan_3x3[0][0]==papan_3x3[2][2])								//checking if (1,1),(2,2) & (3,3) are identical
		return papan_3x3[0][0];

	if(papan_3x3[0][2]==papan_3x3[1][1]&&papan_3x3[0][2]==papan_3x3[2][0])								//checking if (1,3),(2,2) & (3,1) are identical
			return papan_3x3[0][2];

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(papan_3x3[i][j]!='O'&&papan_3x3[i][j]!='X')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}
	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'
	return 'D';
}

void Display_3x3(char papan_3x3[3][3], char kesulitan, int musuh){
	int i;
	system("cls");
	header();
	if(musuh==1){
		printf("\n\t\t\t\t%s (X)  -  %s (O)\n\n", pemain_3x3[0].nama, pemain_3x3[1].nama);		
	}else if(musuh==2){
		printf("\n\t\t\t\t%s (X)  -  Computer (O)\n", pemain_3x3[0].nama);
	}
	
	if(kesulitan=='1'){
		printf("\t\t\t\t        ~Easy~");		
	}else if(kesulitan=='2'){
		printf("\t\t\t\t      ~Medium~");		
	}else if(kesulitan=='3'){
		printf("\t\t\t\t        ~Hard~");	
	}
	printf("\n\t\t\t\t ___________________\n");
	for(i=0; i<3; i++){
		printf("\t\t\t\t |     |     |     |\n");
 		printf("\t\t\t\t |  %c  |  %c  |  %c  |\n",papan_3x3[i][0],papan_3x3[i][1],papan_3x3[i][2]);
    	printf("\t\t\t\t |_____|_____|_____|\n");	
	}
}

void computer_move_3x3(char papan_3x3[3][3], char kesulitan){
	int i, j;
	if(kesulitan=='2'||kesulitan=='3'){
		//XX_ || _XX (Block 2 prioritas)
		short key1;
		short key2;
		for(i=0; i<3; i++){
			key1=0;//horizontal
			key2=0;//vertikal
			for(j=0; j<2;j++){
				if((papan_3x3[i][j]==papan_3x3[i][j+1])&&(papan_3x3[i][j]=='X'||papan_3x3[i][j]=='O')){
					key1++;		
					if(key1==1){
						if(papan_3x3[i][j+2]!='X'&&papan_3x3[i][j+2]!='O'&&j<2){ //j+1<=2
							papan_3x3[i][j+2]='O';
							return;
						}else if(papan_3x3[i][j-1]!='X'&&papan_3x3[i][j-1]!='O'&&j>0){ //j-1>=0
							papan_3x3[i][j-1]='O';
							return;
						}
					}
				}else{
					key1=0;
				}
	
				if((papan_3x3[j][i]==papan_3x3[j+1][i])&&(papan_3x3[j][i]=='X'||papan_3x3[j][i]=='O')){
					key2++;	
					if(key2==1){
						if(papan_3x3[j+2][i]!='X'&&papan_3x3[j+2][i]!='O'&&j<3){ //j+1<=2
							papan_3x3[j+2][i]='O';	
							return;
						}else if(papan_3x3[j-1][i]!='X'&&papan_3x3[j-1][i]!='O'&&j>0){ //j-1>=0
							papan_3x3[j-1][i]='O';
							return;
						}
					}
				}else{
					key2=0;
				}
			}
		}
		
		//Block X_X
		for(i=0;i<3;i++){
			if((papan_3x3[i][0]==papan_3x3[i][2])&&(papan_3x3[i][0]=='X'||papan_3x3[i][0]=='O')){
				if(papan_3x3[i][1]!='X'&&papan_3x3[i][1]!='O'){
					papan_3x3[i][1]='O';
					return;	
				}
			}
		}
		
		for(i=0;i<3;i++){
			if((papan_3x3[0][i]==papan_3x3[2][i])&&(papan_3x3[0][i]=='X'||papan_3x3[0][i]=='O')){
				if(papan_3x3[1][i]!='X'&&papan_3x3[1][i]!='O'){
					papan_3x3[1][i]='O';
					return;	
				}
			}
		}
		
		//diagonaL1 (Block 2 prioritas) 
		if((papan_3x3[0][0]==papan_3x3[1][1])&&(papan_3x3[0][0]=='X'||papan_3x3[0][0]=='O')){
			if(papan_3x3[2][2]!='X'&&papan_3x3[2][2]!='O'){ //[0][0] == [1][1] --> [2][2](block)
				papan_3x3[2][2]='O';
			}
		}
		if((papan_3x3[2][2]==papan_3x3[1][1])&&(papan_3x3[4][3]=='X'||papan_3x3[4][3]=='O')){
			if(papan_3x3[0][0]!='X'&&papan_3x3[0][0]!='O'){ //[1][1] == [2][2] --> [0][0](block)
				papan_3x3[0][0]='O'; 
			}
		}
		
		//diagonal2 (Block 2 prioritas)
		if((papan_3x3[2][0]==papan_3x3[1][1])&&((papan_3x3[2][0]=='X')||(papan_3x3[2][0]=='O'))){
			if((papan_3x3[0][2]!='X')&&(papan_3x3[0][2]!='O')){ //[2][0] == [1][1] --> [0][2](block)
				papan_3x3[0][2]='O';
			}
		}
		if((papan_3x3[0][2]==papan_3x3[1][1])&&(papan_3x3[0][2]=='X'||papan_3x3[0][2]=='O')){
			if((papan_3x3[2][0]!='X')&&(papan_3x3[2][0]!='O')){ //[1][1] == [0][2] --> [2][0](block)
				papan_3x3[2][0]='O'; 
			}
		}
	}
	
	if(kesulitan=='3'){
		//blocking tactis(1st move)
		if(papan_3x3[1][1]!='O'&&papan_3x3[1][1]!='X'){
			papan_3x3[1][1]='O';															
			return;
		}
		if (papan_3x3 [1][1] == 'O') {
			if (papan_3x3 [0][0] == 'X') {
				if (papan_3x3[2][2]!='O'&&papan_3x3[2][2]!='X') {
					papan_3x3 [2][2] = 'O';
					return;
				}
			}
			if (papan_3x3 [0][2] == 'X') {
				if (papan_3x3[2][0]!='O'&&papan_3x3[2][0]!='X') {
					papan_3x3[2][0] = 'O';
					return;
				}
			}
			if (papan_3x3 [2][0] == 'X') {
				if (papan_3x3[0][2]!='O'&&papan_3x3[0][2]!='X') {
					papan_3x3[0][2] = 'O';
					return;
				}	
			}
			if (papan_3x3 [2][2] == 'X') {
				if (papan_3x3[0][0]!='O'&&papan_3x3[0][0]!='X'){
					papan_3x3 [0][0] = 'O';
					return;
				}	
			}
		}
		if(papan_3x3[1][1]=='X'){
			if(papan_3x3[0][0]!='O'&&papan_3x3[0][0]!='X'){
				papan_3x3[0][0]='O';
				return;
			}
		}
		//blocking tactis(2nd move)
		if((papan_3x3[0][0]=='X'&&papan_3x3[2][2]=='X') || (papan_3x3[0][2]=='X'&&papan_3x3[2][0]=='X')){
			if(papan_3x3[0][1]!='O'&&papan_3x3[0][1]!='X'){
				papan_3x3[0][1]='O';
				return;
			}
		}
		if(papan_3x3[1][1]=='X'&&papan_3x3[2][2]=='X'){
			if(papan_3x3[0][2]!='O'&&papan_3x3[0][2]!='X'){
				papan_3x3[0][2]='O';
				return;
			}
		}
	}
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (papan_3x3[i][j]!='O'&&papan_3x3[i][j]!='X'){
				papan_3x3 [i][j] = 'O';
				return;
			}	
		}
	}
}

void writeData(int musuh, int mode){
	/* Memindahkan data pemain ke data highscore */
	if(mode==3){
		/* Tulis data ke dalam file */
		FILE *FF = fopen(HIGHSCORE_3x3, "ab");
		fwrite(&pemain_3x3[0], sizeof(HighscoreData), 1, FF);
		if(musuh==1){
			fwrite(&pemain_3x3[1], sizeof(HighscoreData), 1, FF);
		}	
		fclose(FF);	
			
	}else if(mode==5){
		/* Tulis data ke dalam file */
		FILE *FF = fopen(HIGHSCORE_5x5, "ab");
		fwrite(&pemain_5x5[0], sizeof(HighscoreData), 1, FF);
		if(musuh==1){
			fwrite(&pemain_5x5[1], sizeof(HighscoreData), 1, FF);
		}	
		fclose(FF);
			
	}else if(mode==7){
		/* Tulis data ke dalam file */
		FILE *FF = fopen(HIGHSCORE_7x7, "ab");
		fwrite(&pemain_7x7[0], sizeof(HighscoreData), 1, FF);
		if(musuh==1){
			fwrite(&pemain_7x7[1], sizeof(HighscoreData), 1, FF);
		}
		fclose(FF);	
	}
}

void highscore(int mode){
	/*Menu highscore, menampilkan data pemain sesuai kriteria highscore */
	int i,N;
	int cek;
	/*  N merupakan banyak nya data pemain yang ada
		kriteria merupakan jenis sorting untuk menampilkan highscore
	*/
	N = GetData(mode);
	system("cls");
	printf("\n\n");
	sortHighscore(N,mode);
	if(mode==3){
		printf("\t\t\t\tName Player\tWin\tDraw\tLose\tTotal");printf("\n");
			for ( i = 0 ; i < N ; i++ ){
				printf("\t\t\t\t%-10s\t %d",list_3x3[i].nama ,list_3x3[i].win);
				printf("\t %d\t %d \t ",list_3x3[i].draw, list_3x3[i].lose);
				printf("%d\t \n", list_3x3[i].total);
			}
		printf("\n\t\t\t\tType anything to return: ");
		scanf("%d", &cek);
	}else if(mode==5){
		printf("\t\t\t\tName Player\tWin\tDraw\tLose\tTotal");printf("\n");
			for ( i = 0 ; i < N ; i++ ){
				printf("\t\t\t\t%-10s\t %d",list_5x5[i].nama ,list_5x5[i].win);
				printf("\t %d\t %d \t ",list_5x5[i].draw, list_5x5[i].lose);
				printf("%d\t \n", list_5x5[i].total);
			}
		printf("\n\t\t\t\tType anything to return: ");
		scanf("%d", &cek);
	}else if(mode==7){
		printf("\t\t\t\tName Player\tWin\tDraw\tLose\tTotal");printf("\n");
			for ( i = 0 ; i < N ; i++ ){
				printf("\t\t\t\t%-10s\t %d",list_7x7[i].nama ,list_7x7[i].win);
				printf("\t %d\t %d \t ",list_7x7[i].draw, list_7x7[i].lose);
				printf("%d\t \n", list_7x7[i].total);
			}
		printf("\n\t\t\t\tType anything to return: ");
		scanf("%d", &cek);		
	}

}

int GetData(int mode){
	/*  Mengambil data dari file highscore yang sudah disimpan dari modul writeData
		Mengembalikan / menghitung nilai N yaitu banyak nya data yang tersimpan dalam file highscore
	*/
	int N = 0;
	if(mode==3){
		FILE *fp = fopen(HIGHSCORE_3x3, "rb");
		while ( fread(&list_3x3[N], sizeof(HighscoreData), 1, fp ) == 1 ) N++;
		fclose(fp);
	}else if(mode==5){
		FILE *fp = fopen(HIGHSCORE_5x5, "rb");
		while ( fread(&list_5x5[N], sizeof(HighscoreData), 1, fp ) == 1 ) N++;
		fclose(fp);	
	}else if(mode==7){
		FILE *fp = fopen(HIGHSCORE_7x7, "rb");
		while ( fread(&list_7x7[N], sizeof(HighscoreData), 1, fp ) == 1 ) N++;
		fclose(fp);			
	}
	return N;
}

void sortHighscore( int N , int mode) {
	//sorting highscore berdasarkan total poin
	int i, j ;
	if(mode==3){
		for (i=0; i<N-1; i++){
			for (j=i+1; j<N; j++){
				if (list_3x3[j].total > list_3x3[i].total){
					swap(i,j,mode);
				}
			}
		}			
	}else if(mode==5){
		for (i=0; i<N-1; i++){
			for (j=i+1; j<N ;j++){
				if (list_5x5[j].total > list_5x5[i].total){
					swap(i,j,mode);
				}
			}
		}		
	}else if(mode==7){
		for (i=0; i<N-1; i++){
			for (j=i+1; j<N ;j++){
				if (list_7x7[j].total > list_7x7[i].total){
					swap(i,j,mode);
				}
			}
		}			
	}
}

void swap (int i, int j, int mode){
	HighscoreData temp;
	if(mode==3){
		temp = list_3x3[j];
		list_3x3[j] = list_3x3[i];
		list_3x3[i] = temp;
	}else if(mode==5){
		temp = list_5x5[j];
		list_5x5[j] = list_5x5[i];
		list_5x5[i] = temp;		
	}else if(mode==7){
		temp = list_7x7[j];
		list_7x7[j] = list_7x7[i];
		list_7x7[i] = temp;	
	}
}

void Display_5x5(char papan_5x5[5][5][2], char kesulitan, int musuh){
	int i;
	system("cls");
	header();

	if(musuh==1){
		printf("\n\t\t\t\t      %s (X)  -  %s (O)\n\n", pemain_5x5[0].nama, pemain_5x5[1].nama);		
	}else if(musuh==2){
		printf("\n\t\t\t\t      %s (X)  -  Computer (O)\n\n", pemain_5x5[0].nama);
	}	
	
	if(kesulitan=='1'){
		printf("\t\t\t\t               ~Easy~");		
	}else if(kesulitan=='2'){
		printf("\t\t\t\t              ~Medium~");		
	}else if(kesulitan=='3'){
		printf("\t\t\t\t               ~Hard~");	
	}
	printf("\n\t\t\t\t____________________________________\n");
	for(i=0; i<5; i++){
		printf("\t\t\t\t|      |      |      |      |      |\n");
	 	printf("\t\t\t\t|  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |\n",papan_5x5[i][0][0],papan_5x5[i][0][1],papan_5x5[i][1][0],papan_5x5[i][1][1],papan_5x5[i][2][0],papan_5x5[i][2][1],papan_5x5[i][3][0],papan_5x5[i][3][1],papan_5x5[i][4][0],papan_5x5[i][4][1]);
	    printf("\t\t\t\t|______|______|______|______|______|\n");		
	}		
}

void run_5x5(int musuh, int mode){ 
	int ulang=1;
	char kesulitan;
	initial_variabel(mode);
	do{
		char papan_5x5[5][5][2]={{{'1',' '},{'2',' '},{'3',' '},{'4',' '},{'5',' '}}, {{'6',' '},{'7',' '},{'8',' '},{'9',' '},{'1','0'}}, {{'1','1'},{'1','2'},{'1','3'},{'1','4'},{'1','5'}}, {{'1','6'},{'1','7'},{'1','8'},{'1','9'},{'2','0'}}, {{'2','1'},{'2','2'},{'2','3'},{'2','4'},{'2','5'}}};
		int first_move;
		int giliran=0;
		char done=' ';
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\t\t\t\t %s:(1)\n ", pemain_5x5[0].nama);
		if(musuh==2){
			printf("\t\t\t\tKomputer:(2)\n");
		}else{
			printf("\t\t\t\t %s:(2)\n", pemain_5x5[1].nama);
		}
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		do{
			printf("\t\t\t\tChoose who moves first: ");
			scanf("%d", &first_move);
			if(first_move!=1&&first_move!=2){
			printf("\n\t\t\t\tThe choice you entered is wrong\n\t\t\t\tTry to type it right!!\n\n");
			}
		}while(first_move!=1&&first_move!=2);
		
		if(musuh==2){
			kesulitan=PilihanKesulitan();	
		}
		
		if(musuh==2){
			if (first_move == 2) {
				computer_move_5x5(papan_5x5, kesulitan);
			}
			
			do{
				Display_5x5(papan_5x5,kesulitan,musuh);
				printf("\t\t\t\t %s (X) move\n\n\n", pemain_5x5[0].nama);
				player_move_5x5(giliran, papan_5x5);												//player's move
				Display_5x5(papan_5x5,kesulitan,musuh);												//displaying the current matrix
				done=check_5x5(papan_5x5);															//checking the matrix
				if(done!=' '){
					break;	
				}																					//if the return is other than ' ',we break here
				
				printf("\t Computer's move (O)\n\n\n");
				computer_move_5x5(papan_5x5, kesulitan);
				Display_5x5(papan_5x5,kesulitan,musuh);												//displaying the matrix
				done=check_5x5(papan_5x5);															//checking the matrix
		
			}while(done==' ');
		}else{
			Display_5x5(papan_5x5,kesulitan,musuh);
			
			if (first_move == 2) {
				giliran=giliran+1;
				printf("\t\t\t\t %s (O) move\n\n\n", pemain_5x5[1].nama);
				player_move_5x5(giliran, papan_5x5);
				Display_5x5(papan_5x5,kesulitan,musuh);
				giliran++;
			}
		
			do{
				printf("\t\t\t\t %s (X) move\n\n\n", pemain_5x5[0].nama);
				player_move_5x5(giliran, papan_5x5);												//player's move
				Display_5x5(papan_5x5,kesulitan,musuh);												//displaying the current matrix
				done=check_5x5(papan_5x5);															//checking the matrix
				if(done!=' '){
					break;	
				}																					//if the return is other than ' ',we break here
				giliran++;
				printf("\t\t\t\t %s (O) move\n\n\n", pemain_5x5[1].nama);
				player_move_5x5(giliran, papan_5x5);
				Display_5x5(papan_5x5,kesulitan,musuh);												//displaying the matrix
				done=check_5x5(papan_5x5);															//checking the matrix
				giliran++;
			}while(done==' ');
		}
		
		switch(done){
			case 'X':
				printf("\t\t\t\t%s won\n\n", pemain_5x5[0].nama);	
				pemain_5x5[0].win += 1;
				if(musuh==1){
					pemain_5x5[1].lose += 1;
				}
				break;
			case 'O':
				if(musuh==2){
					printf("\t\t\t\tComputer won\n\n");
					pemain_5x5[0].lose += 1;	
				}else{
					printf("\t\t\t\t%s won\n\n", pemain_5x5[1].nama);
					pemain_5x5[1].win += 1;
					pemain_5x5[0].lose += 1;
				}
				break;
			case 'D':
				printf("\t\t\t\tMatch Drawn\n\n");
				pemain_5x5[0].draw += 1;
				if(musuh==1){
					pemain_5x5[1].draw += 1;
				}
				break;			
		}

		pemain_5x5[0].total = 3*pemain_5x5[0].win + pemain_5x5[0].draw - pemain_5x5[0].lose;
		pemain_5x5[1].total = 3*pemain_5x5[1].win + pemain_5x5[1].draw - pemain_5x5[1].lose;
		
		printf("\n Type 1 for Re-duel and type 0 to end game: "); //reduel sama back to menu
	    scanf("%d",&ulang);
	}while(ulang==1);
	writeData(musuh,mode);
}

char check_5x5(char papan_5x5[5][5][2]){
	short i,j;
	//row checking
	for(i=0; i<5; i++){
		if((papan_5x5[i][0][0]==papan_5x5[i][1][0] && papan_5x5[i][2][0]==papan_5x5[i][3][0] && papan_5x5[i][1][0] == papan_5x5[i][2][0]) || (papan_5x5[i][1][0]==papan_5x5[i][2][0] && papan_5x5[i][3][0]==papan_5x5[i][4][0] && papan_5x5[i][2][0] == papan_5x5[i][3][0])){
			if(papan_5x5[i][2][0]=='X'||papan_5x5[i][2][0]=='O'){
				return papan_5x5[i][2][0];
			}
		}
	}
	
	//column checking
	for(i=0; i<5; i++){
		if((papan_5x5[0][i][0]==papan_5x5[1][i][0] && papan_5x5[2][i][0]==papan_5x5[3][i][0] && papan_5x5[1][i][0] == papan_5x5[2][i][0]) || (papan_5x5[1][i][0]==papan_5x5[2][i][0] && papan_5x5[3][i][0]==papan_5x5[4][i][0] && papan_5x5[2][i][0] == papan_5x5[3][i][0])){
			if(papan_5x5[2][i][0]=='X'||papan_5x5[2][i][0]=='O'){
				return papan_5x5[2][i][0];
			}
		}
	}
	
	//diagonal checking
	short streak1=0;
	short streak2=0;	
	for(i=0; i<5; i++){
        if(papan_5x5[i][i][0]==papan_5x5[i+1][i+1][0]){
            streak1++;
            if(streak1 == 3){
            	if(papan_5x5[2][2][0]=='X'||papan_5x5[2][2][0]=='O'){
            		return papan_5x5[2][2][0];
				}
			}
        }else{
        	streak1=0;
		}
		
		if(papan_5x5[4-i][i][0]==papan_5x5[3-i][i+1][0]){
            streak2++;
            if(streak2 == 3){
            	if(papan_5x5[2][2][0]=='X'||papan_5x5[2][2][0]=='O'){
            		return papan_5x5[2][2][0];
				}
			}
        }else{
        	streak2=0;
		}   
	}
	
	if(papan_5x5[0][1][0]==papan_5x5[1][2][0] && papan_5x5[1][2][0]==papan_5x5[2][3][0] && papan_5x5[2][3][0] == papan_5x5[3][4][0]){
		if(papan_5x5[1][2][0]=='X'||papan_5x5[1][2][0]=='O'){
			return papan_5x5[1][2][0];
		}	
	}
	
	if(papan_5x5[1][0][0]==papan_5x5[2][1][0] && papan_5x5[2][1][0]==papan_5x5[3][2][0] && papan_5x5[3][2][0] == papan_5x5[4][3][0]){
		if(papan_5x5[3][2][0]=='X'||papan_5x5[3][2][0]=='O'){
			return papan_5x5[3][2][0];
		}	
	}

	if(papan_5x5[0][3][0]==papan_5x5[1][2][0] && papan_5x5[1][2][0]==papan_5x5[2][1][0] && papan_5x5[2][1][0] == papan_5x5[3][0][0]){
		if(papan_5x5[1][2][0]=='X'||papan_5x5[1][2][0]=='O'){
			return papan_5x5[1][2][0];
		}	
	}
	
	if(papan_5x5[1][4][0]==papan_5x5[2][3][0] && papan_5x5[2][3][0]==papan_5x5[3][2][0] && papan_5x5[3][2][0] == papan_5x5[4][1][0]){
		if(papan_5x5[3][2][0]=='X'||papan_5x5[3][2][0]=='O'){
			return papan_5x5[3][2][0];
		}	
	}

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(papan_5x5[i][j][0]!='O'&&papan_5x5[i][j][0]!='X')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}
	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'
	return 'D';
}

void player_move_5x5(int giliran, char papan_5x5[5][5][2]){
	int kot,bar,kol;
   	clock_t start_time = clock();
	unsigned int timeout=15000;
	do{
		printf("\t\t\t\tEnter the Box Number You Choose (15 Second): ");
        scanf("%d",&kot);
        if(kot<1 || kot>25 || papan_5x5[bar][kol][0]=='X' || papan_5x5[bar][kol][0]=='O'){
			printf("\n\t\t\t\tThe Number You Enter Is Incorrect\n\t\t\t\tTry to type it right!!\n\n");
		}
           
        if(kot>=1 && kot<=5){
            bar=0;
            kol=kot-1;
        }else if(kot>=6 && kot<=10){
            bar=1;
            kol=kot-6;
        }else if(kot>=11 && kot<=15){
            bar=2;
            kol=kot-11;
        }else if(kot>=16 && kot<=20){
        	bar=3;
            kol=kot-16;
		}else if(kot>=21 && kot<=25){
			bar=4;
			kol=kot-21;
		}
    }while(kot<1 || kot>25 || papan_5x5[bar][kol][0]=='X' || papan_5x5[bar][kol][0]=='O');

   	if(clock() < start_time + timeout){		
		if(giliran%2==0){
       		papan_5x5[bar][kol][0]='X';
       		if(papan_5x5[bar][kol][1]!=' '){
       			papan_5x5[bar][kol][1]=' ';
			}
	   	}else{
	   		papan_5x5[bar][kol][0]='O';
	   		if(papan_5x5[bar][kol][1]!=' '){
	   			papan_5x5[bar][kol][1]=' ';	
			}
		}
	}
}

void computer_move_5x5(char papan_5x5[5][5][2], char kesulitan){
	int i, j;	
	//XXX_ || _XXX (Block 3 prioritas)
	short key1;
	short key2;
	for(i=0; i<5; i++){
		key1=0;//horizontal
		key2=0;//vertikal
		for(j=0; j<4;j++){
			if((papan_5x5[i][j][0]==papan_5x5[i][j+1][0])&&(papan_5x5[i][j][0]=='X'||papan_5x5[i][j][0]=='O')){
				key1++;		
				if(key1==2){
					if(papan_5x5[i][j+2][0]!='X'&&papan_5x5[i][j+2][0]!='O'&&j<3){ //j+2<=4
						papan_5x5[i][j+2][0]='O';
						if(papan_5x5[i][j+2][1]!=' '){
	   						papan_5x5[i][j+2][1]=' ';	
						}
						return;
					}else if(papan_5x5[i][j-2][0]!='X'&&papan_5x5[i][j-2][0]!='O'&&j>1){ //j-2>=0
						papan_5x5[i][j-2][0]='O';
						if(papan_5x5[i][j-2][1]!=' '){
	   						papan_5x5[i][j-2][1]=' ';	
						}
						return;
					}
				}
			}else{
				key1=0;
			}

			if((papan_5x5[j][i][0]==papan_5x5[j+1][i][0])&&(papan_5x5[j][i][0]=='X'||papan_5x5[j][i][0]=='O')){
				key2++;	
				if(key2==2){
					if(papan_5x5[j+2][i][0]!='X'&&papan_5x5[j+2][i][0]!='O'&&j<3){ //j+2<=4
						papan_5x5[j+2][i][0]='O';	
						if(papan_5x5[j+2][i][1]!=' '){
	   						papan_5x5[j+2][i][1]=' ';	
						}
						return;
					}else if(papan_5x5[j-2][i][0]!='X'&&papan_5x5[j-2][i][0]!='O'&&j>1){ //j-2>=0
						papan_5x5[j-2][i][0]='O';
						if(papan_5x5[j-2][i][1]!=' '){
	   						papan_5x5[j-2][i][1]=' ';	
						}
						return;
					}
				}
			}else{
				key2=0;
			}
		}
	}
	
	//diagonaL1 (Block 3 prioritas) 
	if((papan_5x5[1][0][0]==papan_5x5[2][1][0])&&(papan_5x5[3][2][0]==papan_5x5[2][1][0])&&(papan_5x5[1][0][0]=='X'||papan_5x5[1][0][0]=='O')){
		if(papan_5x5[4][3][0]!='X'&&papan_5x5[4][3][0]!='O'){ //[1][0] == [2][1] == [3][2] --> [4][3](block)
			papan_5x5[4][3][0]='O';
			if(papan_5x5[4][3][1]!=' '){
	   			papan_5x5[4][3][1]=' ';	
			}
			return;
		}
	}
	if((papan_5x5[4][3][0]==papan_5x5[2][1][0])&&(papan_5x5[3][2][0]==papan_5x5[2][1][0])&&(papan_5x5[4][3][0]=='X'||papan_5x5[4][3][0]=='O')){
		if(papan_5x5[1][0][0]!='X'&&papan_5x5[1][0][0]!='O'){ //[2][1] == [3][2] == [4][3] --> [1][0](block)
			papan_5x5[1][0][0]='O'; 
			if(papan_5x5[1][0][1]!=' '){
	   			papan_5x5[1][0][1]=' ';	
			}
			return;
		}
	}
	
	//diagonal2 (Block 3 prioritas)
	if((papan_5x5[0][1][0]==papan_5x5[1][2][0])&&(papan_5x5[2][3][0]==papan_5x5[1][2][0])&&((papan_5x5[0][1][0]=='X')||(papan_5x5[0][1][0]=='O'))){
		if((papan_5x5[3][4][0]!='X')&&(papan_5x5[3][4][0]!='O')){ //[0][1] == [1][2] == [2][3] --> [3][4](block)
			papan_5x5[3][4][0]='O';
			if(papan_5x5[3][4][1]!=' '){
	   			papan_5x5[3][4][1]=' ';	
			}
			return;
		}
	}
	if((papan_5x5[3][4][0]==papan_5x5[1][2][0])&&(papan_5x5[2][3][0]==papan_5x5[1][2][0])&&(papan_5x5[3][4][0]=='X'||papan_5x5[3][4][0]=='O')){
		if((papan_5x5[0][1][0]!='X')&&(papan_5x5[0][1][0]!='O')){ //[1][2] == [2][3] == [3][4] --> [0][1](block)
			papan_5x5[0][1][0]='O'; 
			if(papan_5x5[0][1][1]!=' '){
	   			papan_5x5[0][1][1]=' ';	
			}
			return;
		}
	}
	
	//diagonaL3 (Block 3 prioritas)
	if((papan_5x5[3][0][0]==papan_5x5[2][1][0])&&(papan_5x5[1][2][0]==papan_5x5[2][1][0])&&(papan_5x5[3][0][0]=='X'||papan_5x5[3][0][0]=='O')){
		if(papan_5x5[0][3][0]!='X'&&papan_5x5[0][3][0]!='O'){ //[3][0] == [2][1] == [1][2] --> [0][3](block)
			papan_5x5[0][3][0]='O';
			if(papan_5x5[0][3][1]!=' '){
	   			papan_5x5[0][3][1]=' ';	
			}
			return;
		}
	}
	if((papan_5x5[0][3][0]==papan_5x5[2][1][0])&&(papan_5x5[1][2][0]==papan_5x5[2][1][0])&&(papan_5x5[0][3][0]=='X'||papan_5x5[0][3][0]=='O')){
		if(papan_5x5[3][0][0]!='X'&&papan_5x5[3][0][0]!='O'){ //[2][1] == [1][2] == [0][3] --> [3][0](block)
			papan_5x5[3][0][0]='O';
				if(papan_5x5[3][0][1]!=' '){
	   				papan_5x5[3][0][1]=' ';	
				}
				return;
		}
	}
	
	//diagonaL4 (Block 3 prioritas)
	if((papan_5x5[4][1][0]==papan_5x5[3][2][0])&&(papan_5x5[3][2][0]==papan_5x5[2][3][0])&&(papan_5x5[4][1][0]=='X'||papan_5x5[4][1][0]=='O')){
		if(papan_5x5[1][4][0]!='X'&&papan_5x5[1][4][0]!='O'){ //[4][1] == [3][2] == [2][3] --> [1][4](block)
			papan_5x5[1][4][0]='O';
			if(papan_5x5[1][4][1]!=' '){
	   			papan_5x5[1][4][1]=' ';	
			}
			return;
		}
	}
	if((papan_5x5[1][4][0]==papan_5x5[3][2][0])&&(papan_5x5[3][2][0]==papan_5x5[2][3][0])&&(papan_5x5[1][4][0]=='X'||papan_5x5[1][4][0]=='O')){
		if(papan_5x5[4][1][0]!='X'&&papan_5x5[4][1][0]!='O'){ //[3][2] == [2][3] == [1][4] --> [4][1](block)
			papan_5x5[4][1][0]='O';
				if(papan_5x5[4][1][1]!=' '){
	   				papan_5x5[4][1][1]=' ';	
				}
				return;
		}
	}
	
	//diagonal tengah (Block 3 prioritas)
	if((papan_5x5[1][1][0]==papan_5x5[2][2][0])&&(papan_5x5[3][3][0]==papan_5x5[2][2][0])&&(papan_5x5[1][1][0]=='X'||papan_5x5[1][1][0]=='O')){
		if(papan_5x5[0][0][0]!='X'&&papan_5x5[0][0][0]!='O'){ //[1][1] == [2][2] == [3][3] --> [0][0](block)
			papan_5x5[0][0][0]='O';
			if(papan_5x5[0][0][1]!=' '){
	   			papan_5x5[0][0][1]=' ';	
			}
			return;
		}else if(papan_5x5[4][4][0]!='X'&&papan_5x5[4][4][0]!='O'){ //[1][1] == [2][2] == [3][3] --> [4][4](block)
			papan_5x5[4][4][0]='O';
			if(papan_5x5[4][4][1]!=' '){
	   			papan_5x5[4][4][1]=' ';	
			}
			return;
		}
	}	
	if((papan_5x5[3][1][0]==papan_5x5[2][2][0])&&(papan_5x5[1][3][0]==papan_5x5[2][2][0])&&(papan_5x5[3][1][0]=='X'||papan_5x5[3][1][0]=='O')){
		if(papan_5x5[4][0][0]!='X'&&papan_5x5[4][0][0]!='O'){ //[3][1] == [2][2] == [1][3] --> [4][0](block)
			papan_5x5[4][0][0]='O';
			if(papan_5x5[4][0][1]!=' '){
	   			papan_5x5[4][0][1]=' ';	
			}
			return;
		}else if(papan_5x5[0][4][0]!='X'&&papan_5x5[0][4][0]!='O'){ //[3][1] == [2][2] == [1][3] --> [0][4](block)
			papan_5x5[0][4][0]='O';
			if(papan_5x5[0][4][1]!=' '){
	   			papan_5x5[0][4][1]=' ';	
			}
			return;
		}
	}
	if(kesulitan=='2'||kesulitan=='3'){
		//Strategi _X_X_ Horizontal dan Vertikal
		for(i=0;i<5;i++){
			if((papan_5x5[i][1][0]=='X'&&papan_5x5[i][3][0]=='X')||(papan_5x5[i][1][0]=='O'&&papan_5x5[i][3][0]=='O')){
				if(papan_5x5[i][2][0]!='O'&&papan_5x5[i][2][0]!='X'){ //Horizontal
					papan_5x5[i][2][0]='O';
					if(papan_5x5[i][2][1]!=' '){
		   				papan_5x5[i][2][1]=' ';	
					}
					return;
				}
			}
			if((papan_5x5[1][i][0]=='X'&&papan_5x5[3][i][0]=='X')||(papan_5x5[1][i][0]=='O'&&papan_5x5[3][i][0]=='O')){
				if(papan_5x5[2][i][0]!='O'&&papan_5x5[2][i][0]!='X'){ //Vertikal
					papan_5x5[2][i][0]='O';
					if(papan_5x5[2][i][1]!=' '){
		   				papan_5x5[2][i][1]=' ';	
					}
					return;
				}
			}
		}		
	}
	
	if(kesulitan=='3'){
		//Strategi _ XX _ _ && _ _ XX _ Horizontal
		for(i=0;i<5;i++){
			if((papan_5x5[i][1][0]=='X'&&papan_5x5[i][2][0]=='X')||(papan_5x5[i][1][0]=='O'&&papan_5x5[i][2][0]=='O')){
				if(papan_5x5[i][3][0]!='O'&&papan_5x5[i][3][0]!='X'){ //_ XX (_) _
					papan_5x5[i][3][0]='O';
					if(papan_5x5[i][3][1]!=' '){
		   				papan_5x5[i][3][1]=' ';	
					}
					return;
				}
			}
			if((papan_5x5[i][2][0]=='X'&&papan_5x5[i][3][0]=='X')||(papan_5x5[i][2][0]=='O'&&papan_5x5[i][3][0]=='O')){
				if(papan_5x5[i][1][0]!='O'&&papan_5x5[i][1][0]!='X'){ // _ (_) XX _
					papan_5x5[i][1][0]='O';
					if(papan_5x5[i][1][1]!=' '){
		   				papan_5x5[i][1][1]=' ';	
					}
					return;
				}
			}	
		}
	
		//Strategi _ XX _ _ && _ _ XX _ Vertikal
		for(i=0;i<5;i++){
			if((papan_5x5[1][i][0]=='X'&&papan_5x5[2][i][0]=='X')||(papan_5x5[1][i][0]=='O'&&papan_5x5[2][i][0]=='O')){
				if(papan_5x5[3][i][0]!='O'&&papan_5x5[3][i][0]!='X'){ // _ XX (_) _
					papan_5x5[3][i][0]='O';
					if(papan_5x5[3][i][1]!=' '){
		   				papan_5x5[3][i][1]=' ';	
					}
					return;
				}
			}
			if((papan_5x5[2][i][0]=='X'&&papan_5x5[3][i][0]=='X')||(papan_5x5[2][i][0]=='O'&&papan_5x5[3][i][0]=='O')){
				if(papan_5x5[1][i][0]!='O'&&papan_5x5[1][i][0]!='X'){ //_ (_) XX _
					papan_5x5[1][i][0]='O';
					if(papan_5x5[1][i][1]!=' '){
		   				papan_5x5[1][i][1]=' ';	
					}
					return;
				}
			}	
		}
		
		//Strategi _ XX _ _ && _ _ XX _ Diagonal atas ke kanan
		if((papan_5x5[1][1][0]=='X'&&papan_5x5[2][2][0]=='X')||(papan_5x5[1][1][0]=='O'&&papan_5x5[2][2][0]=='O')){
			if(papan_5x5[3][3][0]!='O'&&papan_5x5[3][3][0]!='X'){ // _ XX (_) _
				papan_5x5[3][3][0]='O';
				if(papan_5x5[3][3][1]!=' '){
		   			papan_5x5[3][3][1]=' ';	
				}
				return;
			}
		}
		if((papan_5x5[3][3][0]=='X'&&papan_5x5[2][2][0]=='X')||(papan_5x5[3][3][0]=='O'&&papan_5x5[2][2][0]=='O')){
			if(papan_5x5[1][1][0]!='O'&&papan_5x5[1][1][0]!='X'){ // _ (_) XX _ 
				papan_5x5[1][1][0]='O';
				if(papan_5x5[1][1][1]!=' '){
		   			papan_5x5[1][1][1]=' ';	
				}
				return;
			}
		}
		
		//Strategi _ XX _ _ && _ _ XX _ Diagonal bawah ke kanan
		if((papan_5x5[3][1][0]=='X'&&papan_5x5[2][2][0]=='X')||(papan_5x5[3][1][0]=='O'&&papan_5x5[2][2][0]=='O')){
			if(papan_5x5[1][3][0]!='O'&&papan_5x5[1][3][0]!='X'){ // _ XX (_) _
				papan_5x5[1][3][0]='O';
				if(papan_5x5[1][3][1]!=' '){
		   			papan_5x5[1][3][1]=' ';	
				}
				return;
			}
		}
		if((papan_5x5[1][3][0]=='X'&&papan_5x5[2][2][0]=='X')||(papan_5x5[1][3][0]=='O'&&papan_5x5[2][2][0]=='O')){
			if(papan_5x5[3][1][0]!='O'&&papan_5x5[3][1][0]!='X'){ // _ (_) XX _
				papan_5x5[3][1][0]='O';
				if(papan_5x5[3][1][1]!=' '){
		   			papan_5x5[3][1][1]=' ';	
				}
				return;
			}
		}
	}
	
	//Block 2 tanda berurutan horizontal(Baris) 
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(papan_5x5[i][j][0]=='X'&&papan_5x5[i][j+1][0]=='X'){
				if(papan_5x5[i][j+2][0]!='O'&&papan_5x5[i][j+2][0]!='X'&&j+2<=4){
					papan_5x5[i][j+2][0]='O';
					if(papan_5x5[i][j+2][1]!=' '){
	   					papan_5x5[i][j+2][1]=' ';	
					}
					return;
				}else if(papan_5x5[i][j+2][0]=='X'&&papan_5x5[i][j+3][0]!='O'&&j+3<=4){
					papan_5x5[i][j+3][0]='O';
					if(papan_5x5[i][j+3][1]!=' '){
	   					papan_5x5[i][j+3][1]=' ';	
					}
					return;
				}else if(papan_5x5[i][j-1][0]!='O'&&papan_5x5[i][j-1][0]!='X'&&j-1>=0){
					papan_5x5[i][j-1][0]='O';
					if(papan_5x5[i][j-1][1]!=' '){
	   					papan_5x5[i][j-1][1]=' ';	
					}
					return;
				}else if(papan_5x5[i][j-1][0]=='X'&&papan_5x5[i][j-1][0]!='O'&&papan_5x5[i][j-2][0]!='O'&&j-2>=0){
					papan_5x5[i][j-2][0]='O';
					if(papan_5x5[i][j-2][1]!=' '){
	   					papan_5x5[i][j-2][1]=' ';	
					}
					return;
				}
			}
		}
	}
	
	//Block 2 tanda berurutan vertikal (Kolom)
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(papan_5x5[j][i][0]=='X'&&papan_5x5[j+1][i][0]=='X'){
				if(papan_5x5[j+2][i][0]!='O'&&papan_5x5[j+2][i][0]!='X'&&j+2<=4){
					papan_5x5[j+2][i][0]='O';
					if(papan_5x5[j+2][i][1]!=' '){
	   					papan_5x5[j+2][i][1]=' ';	
					}
					return;
				}else if(papan_5x5[j+2][i][0]=='X'&&papan_5x5[j+3][i][0]!='O'&&j+3<=4){
					papan_5x5[j+3][i][0]='O';
					if(papan_5x5[j+3][i][1]!=' '){
	   					papan_5x5[j+3][i][1]=' ';	
					}
					return;
				}else if(papan_5x5[j-1][i][0]!='O'&&papan_5x5[j-1][i][0]!='X'&&j-1>=0){
					papan_5x5[j-1][i][0]='O';
					if(papan_5x5[j-1][i][1]!=' '){
	   					papan_5x5[j-1][i][1]=' ';	
					}
					return;
				}else if(papan_5x5[j-1][i][0]=='X'&&papan_5x5[j-1][i][0]!='O'&&papan_5x5[j-2][i][0]!='O'&&j-2>=0){
					papan_5x5[j-2][i][0]='O';
					if(papan_5x5[j-2][i][1]!=' '){
	   					papan_5x5[j-2][i][1]=' ';	
					}
					return;
				}
			}
		}
	}
	
	//Block 2 tanda berurutan Diagonal [0][0] dan [0][1]
	for(i=0; i<2; i++){
		for(j=0; j<5-i; j++){
			if(papan_5x5[j][j+i][0]=='X'&&papan_5x5[j+1][j+i+1][0]=='X'){
				if(papan_5x5[j+2][j+i+2][0]!='O'&&papan_5x5[j+2][j+i+2][0]!='X'&&j+i+2<=4){	
					papan_5x5[j+2][j+i+2][0]='O';
					if(papan_5x5[j+2][j+i+2][1]!=' '){
			   			papan_5x5[j+2][j+i+2][1]=' ';	
					}
					return;
				}else if(papan_5x5[j+2][j+i+2][0]=='X'&&papan_5x5[j+3][j+i+3][0]!='O'&&j+i+3<=4){
					papan_5x5[j+3][j+i+3][0]='O';
					if(papan_5x5[j+3][j+i+3][1]!=' '){
			   			papan_5x5[j+3][j+i+3][1]=' ';	
					}
					return;
				}else if(papan_5x5[j-1][j+i-1][0]!='O'&&papan_5x5[j-1][j+i-1][0]!='X'&&j-1>=0){
					papan_5x5[j-1][j+i-1][0]='O';
					if(papan_5x5[j-1][j+i-1][1]!=' '){
					 	papan_5x5[j-1][j+i-1][1]=' ';	
					}
					return;
				}else if(papan_5x5[j-1][j+i-1][0]=='X'&&papan_5x5[j-1][j+i-1][0]!='O'&&papan_5x5[j-2][j+i-2][0]!='O'&&j-2>=0){
					papan_5x5[j-2][j+i-2][0]='O';
					if(papan_5x5[j-2][j+i-2][1]!=' '){
			   			papan_5x5[j-2][j+i-2][1]=' ';	
					}
					return;
				}
			}
		}
	}
	
	//Block 2 tanda berurutan Diagonal [1][0]
	for(i=1; i<5; i++){
		if(papan_5x5[i][i-1][0]=='X'&&papan_5x5[i+1][i][0]=='X'){
			if(papan_5x5[i+2][i+1][0]!='O'&&papan_5x5[i+2][i+1][0]!='X'&&i+2<=4){
				papan_5x5[i+2][i+1][0]='O';
				if(papan_5x5[i+2][i+1][1]!=' '){
	  				papan_5x5[i+2][i+1][1]=' ';	
				}
				return;
			}else if(papan_5x5[i+2][i+1][0]=='X'&&papan_5x5[i+3][i+2][0]!='O'&&i+3<=4){
				papan_5x5[i+3][i+2][0]='O';
				if(papan_5x5[i+3][i+2][1]!=' '){
		   			papan_5x5[i+3][i+2][1]=' ';	
				}
				return;
			}else if(papan_5x5[i-1][i-2][0]!='O'&&papan_5x5[i-1][i-2][0]!='X'&&i-1>=1){
				papan_5x5[i-1][i-2][0]='O';
				if(papan_5x5[i-1][i-2][1]!=' '){
		   			papan_5x5[i-1][i-2][1]=' ';	
				}
				return;
			}else if(papan_5x5[i-1][i-2][0]=='X'&&papan_5x5[i-1][i-2][0]!='O'&&papan_5x5[i-2][i-3][0]!='O'&&i-2>=1){
				papan_5x5[i-2][i-3][0]='O';
				if(papan_5x5[i-2][i-3][1]!=' '){
		   			papan_5x5[i-2][i-3][1]=' ';	
				}
				return;
			}
		}
	}
	
	//Block 2 tanda berurutan Diagonal [0][4] dan [1][4]
	for(i=0; i<2; i++){
		for(j=0; j<5-i; j++){
			if(papan_5x5[j+i][4-j][0]=='X'&&papan_5x5[j+i+1][3-j][0]=='X'){
				if(papan_5x5[j+i+2][2-j][0]!='O'&&papan_5x5[j+i+2][2-j][0]!='X'&&j+i+2<=4){	
					papan_5x5[j+i+2][2-j][0]='O';
					if(papan_5x5[j+i+2][2-j][1]!=' '){
			   			papan_5x5[j+i+2][2-j][1]=' ';	
					}
					return;
				}else if(papan_5x5[j+i+2][2-j][0]=='X'&&papan_5x5[j+i+3][1-j][0]!='O'&&j+i+3<=4){
					papan_5x5[j+i+3][1-j][0]='O';
					if(papan_5x5[j+i+3][1-j][1]!=' '){
			   			papan_5x5[j+i+3][1-j][1]=' ';
					}
					return;
				}else if(papan_5x5[j+i-1][5-j][0]!='O'&&papan_5x5[j+i-1][5-j][0]!='X'&&j+i-1>=0){
					papan_5x5[j+i-1][5-j][0]='O';
					if(papan_5x5[j+i-1][5-j][1]!=' '){
					 	papan_5x5[j+i-1][5-j][1]=' ';	
					}
					return;
				}else if(papan_5x5[j+i-1][5-j][0]=='X'&&papan_5x5[j+i-1][5-j][0]!='O'&&papan_5x5[j+i-2][6-j][0]!='O'&&j+i-2>=0){
					papan_5x5[j+i-2][6-j][0]='O';
					if(papan_5x5[j+i-2][6-j][1]!=' '){
			   			papan_5x5[j+i-2][6-j][1]=' ';	
					}
					return;
				}
			}
		}
	}
	
	//Block 2 tanda berurutan Diagonal [0][3]	
	for(i=0; i<4; i++){
		if(papan_5x5[i][3-i][0]=='X'&&papan_5x5[i+1][2-i][0]=='X'){
			if(papan_5x5[i+2][1-i][0]!='O'&&papan_5x5[i+2][1-i][0]!='X'&&i+2<=3){
				papan_5x5[i+2][1-i][0]='O';
				if(papan_5x5[i+2][1-i][1]!=' '){
	  				papan_5x5[i+2][1-i][1]=' ';	
				}
				return;
			}else if(papan_5x5[i+2][1-i][0]=='X'&&papan_5x5[i+3][i][0]!='O'&&i+3<=3){
				papan_5x5[i+3][i][0]='O';
				if(papan_5x5[i+3][i][1]!=' '){
		   			papan_5x5[i+3][i][1]=' ';	
				}
				return;
			}else if(papan_5x5[i-1][4-i][0]!='O'&&papan_5x5[i-1][4-i][0]!='X'&&i-1>=1){
				papan_5x5[i-1][4-i][0]='O';
				if(papan_5x5[i-1][4-i][1]!=' '){
		   			papan_5x5[i-1][4-i][1]=' ';	
				}
				return;
			}else if(papan_5x5[i-1][4-i][0]=='X'&&papan_5x5[i-1][4-i][0]!='O'&&papan_5x5[i-2][5-i][0]!='O'&&i-2>=1){
				papan_5x5[i-2][5-i][0]='O';
				if(papan_5x5[i-2][5-i][1]!=' '){
		   			papan_5x5[i-2][5-i][1]=' ';	
				}
				return;
			}
		}
	}

	//titik penting
	if(papan_5x5[2][2][0]!='X'&&papan_5x5[2][2][0]!='O'){
		papan_5x5[2][2][0]='O';
		if(papan_5x5[2][2][1]!=' '){
	   		papan_5x5[2][2][1]=' ';	
		}
		return;
	}
	
	if(papan_5x5[1][1][0]!='X'&&papan_5x5[1][1][0]!='O'){
		papan_5x5[1][1][0]='O';
		if(papan_5x5[1][1][1]!=' '){
	   		papan_5x5[1][1][1]=' ';	
		}
		return;
	}
	
	if(papan_5x5[1][2][0]!='X'&&papan_5x5[1][2][0]!='O'){
		papan_5x5[1][2][0]='O';
		if(papan_5x5[1][2][1]!=' '){
	   		papan_5x5[1][2][1]=' ';	
		}
		return;
	}
	
	if(papan_5x5[2][1][0]!='X'&&papan_5x5[2][1][0]!='O'){
		papan_5x5[2][1][0]='O';
		if(papan_5x5[2][1][1]!=' '){
	   		papan_5x5[2][1][1]=' ';	
		}
		return;
	}
	
	if(papan_5x5[3][1][0]!='X'&&papan_5x5[3][1][0]!='O'){
		papan_5x5[3][1][0]='O';
		if(papan_5x5[3][1][1]!=' '){
	   		papan_5x5[3][1][1]=' ';	
		}
		return;
	}

	if(papan_5x5[3][3][0]!='X'&&papan_5x5[3][3][0]!='O'){
		papan_5x5[3][3][0]='O';
		if(papan_5x5[3][3][1]!=' '){
	   		papan_5x5[3][3][1]=' ';	
		}
		return;
	}

	//yang belum terisi
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(papan_5x5[i][j][0]!='X'&&papan_5x5[i][j][0]!='O'){
				papan_5x5[i][j][0]='O';
				if(papan_5x5[i][j][1]!=' '){
	   				papan_5x5[i][j][1]=' ';	
	   			}
			return;
			}
		}
	}
}

void run_7x7(int musuh, int mode){
	int ulang=1;
	char kesulitan;	
	initial_variabel(mode);
	do{
		char papan_7x7[7][7][2]={{{'1',' '},{'2',' '},{'3',' '},{'4',' '},{'5',' '},{'6',' '},{'7',' '}}, {{'8',' '},{'9',' '},{'1','0'},{'1','1'},{'1','2'},{'1','3'},{'1','4'}}, {{'1','5'},{'1','6'},{'1','7'},{'1','8'},{'1','9'},{'2','0'},{'2','1'}}, {{'2','2'},{'2','3'},{'2','4'},{'2','5'},{'2','6'},{'2','7'},{'2','8'}}, {{'2','9'},{'3','0'},{'3','1'},{'3','2'},{'3','3'},{'3','4'},{'3','5'}}, {{'3','6'},{'3','7'},{'3','8'},{'3','9'},{'4','0'},{'4','1'},{'4','2'}}, {{'4','3'},{'4','4'},{'4','5'},{'4','6'},{'4','7'},{'4','8'},{'4','9'}}};
		int first_move;
		int giliran=0;
		char done=' ';
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		printf("\t\t\t\t %s:(1)\n ", pemain_7x7[0].nama);
		if(musuh==2){
			printf("\t\t\t\t Computer:(2)\n");
		}else{
			printf("\t\t\t\t %s:(2)\n", pemain_7x7[1].nama);
		}
		printf("\n\t\t\t\t>>>---------------------<<<\n\n");
		do{
			printf("\t\t\t\tChoose who moves first: ");
			scanf("%d", &first_move);
			if(first_move!=1&&first_move!=2){
			printf("\n\t\t\t\tThe choice you entered is wrong\n\t\t\t\tTry to type it right!!\n\n");
			}
		}while(first_move!=1&&first_move!=2);
		
		if(musuh==2){
			kesulitan=PilihanKesulitan();	
		}
		
		if(musuh==2){
			if (first_move == 2) {
				computer_move_7x7(papan_7x7,kesulitan);
			}
		
			do{
				Display_7x7(papan_7x7,kesulitan,musuh);
				printf("\t\t\t\t %s (X) move\n\n\n", pemain_7x7[0].nama);
				player_move_7x7(giliran, papan_7x7);																//player's move
				Display_7x7(papan_7x7,kesulitan,musuh);															//displaying the current matrix
				done=check_7x7(papan_7x7);															//checking the matrix
				if(done!=' '){
					break;	
				}																	//if the return is other than ' ',we break here
				
				printf("\t Computer's move (O)\n\n\n");
				computer_move_7x7(papan_7x7,kesulitan);
				Display_7x7(papan_7x7,kesulitan,musuh);															//displaying the matrix
				done=check_7x7(papan_7x7);															//checking the matrix
		
			}while(done==' ');
		}else{
			Display_7x7(papan_7x7,kesulitan,musuh);
			
			if (first_move == 2) {
				giliran=giliran+1;
				printf("\t\t\t\t %s (O) move\n\n\n", pemain_7x7[1].nama);
				player_move_7x7(giliran, papan_7x7);
				Display_7x7(papan_7x7,kesulitan,musuh);
				giliran++;
			}
		
			do{
				printf("\t\t\t\t %s (X) move\n\n\n", pemain_7x7[0].nama);
				player_move_7x7(giliran, papan_7x7);																//player's move
				Display_7x7(papan_7x7,kesulitan,musuh);															//displaying the current matrix
				done=check_7x7(papan_7x7);															//checking the matrix
				if(done!=' '){
					break;	
				}																	//if the return is other than ' ',we break here
				giliran++;
				printf("\t\t\t\t %s (O) move\n\n\n", pemain_7x7[1].nama);
				player_move_7x7(giliran, papan_7x7);
				Display_7x7(papan_7x7,kesulitan,musuh);															//displaying the matrix
				done=check_7x7(papan_7x7);															//checking the matrix
				giliran++;
			}while(done==' ');
		}
		
		switch(done){
			case 'X':
				printf("\t\t\t\t  %s won\n\n", pemain_7x7[0].nama);	
				pemain_7x7[0].win += 1;
				if(musuh==1){
					pemain_7x7[1].lose += 1;
				}
				break;
			case 'O':
				if(musuh==2){
					printf("\t\t\t\t  Computer won\n\n");
					pemain_7x7[0].lose += 1;	
				}else{
					printf("\t\t\t\t  %s won\n\n", pemain_7x7[1].nama);
					pemain_7x7[1].win += 1;
					pemain_7x7[0].lose += 1;
				}
				break;
			case 'D':
				printf("\t\t\t\t  Match Drawn\n\n");
				pemain_7x7[0].draw += 1;
				if(musuh==1){
					pemain_7x7[1].draw += 1;
				}
				break;			
		}

		pemain_7x7[0].total = 3*pemain_7x7[0].win + pemain_7x7[0].draw - pemain_7x7[0].lose;
		pemain_7x7[1].total = 3*pemain_7x7[1].win + pemain_7x7[1].draw - pemain_7x7[1].lose;
		
		printf("\n Type 1 for Re-duel and type 0 to end game: "); //reduel sama back to menu
	    scanf("%d",&ulang);
	}while(ulang== 1 );
	
	writeData(musuh, mode);	
}

void Display_7x7(char papan_7x7[7][7][2], char kesulitan, int musuh){
	int i;
	system("cls");
	header();
	
	if(musuh==1){
		printf("\n\t\t\t\t             %s (X)  -  %s (O)\n\n", pemain_7x7[0].nama, pemain_7x7[1].nama);		
	}else if(musuh==2){
		printf("\n\t\t\t\t             %s (X)  -  Computer (O)\n\n", pemain_7x7[0].nama);
	}
	
	if(kesulitan=='1'){
		printf("\t\t\t\t                      ~Easy~");		
	}else if(kesulitan=='2'){
		printf("\t\t\t\t                     ~Medium~");		
	}else if(kesulitan=='3'){
		printf("\t\t\t\t                      ~Hard~");	
	}
	
	printf("\n\t\t\t\t__________________________________________________\n");
	for(i=0; i<7; i++){
		printf("\t\t\t\t|      |      |      |      |      |      |      |\n");
	 	printf("\t\t\t\t|  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |\n",papan_7x7[i][0][0],papan_7x7[i][0][1],papan_7x7[i][1][0],papan_7x7[i][1][1],papan_7x7[i][2][0],papan_7x7[i][2][1],papan_7x7[i][3][0],papan_7x7[i][3][1],papan_7x7[i][4][0],papan_7x7[i][4][1],papan_7x7[i][5][0],papan_7x7[i][5][1],papan_7x7[i][6][0],papan_7x7[i][6][1]);
	    printf("\t\t\t\t|______|______|______|______|______|______|______|\n");		
	}	
}

void player_move_7x7(int giliran, char papan_7x7[7][7][2]){
	int kot,bar,kol;
	clock_t start_time = clock();
	unsigned int timeout=15000;
	do{
		printf("\t\t\t\tEnter the Box Number You Choose (15 Second): ");
        scanf("%d",&kot);
        if(kot<1 || kot>49 || papan_7x7[bar][kol][0]=='X' || papan_7x7[bar][kol][0]=='O'){
			printf("\n\t\t\t\tThe Number You Enter Is Incorrect\n\t\t\t\tTry to type it right!!\n\n");
		}
           
        if(kot>=1 && kot<=7){
            bar=0;
            kol=kot-1;
        }else if(kot>=8 && kot<=14){
            bar=1;
            kol=kot-8;
        }else if(kot>=15 && kot<=21){
            bar=2;
            kol=kot-15;
        }else if(kot>=22 && kot<=28){
        	bar=3;
            kol=kot-22;
		}else if(kot>=29 && kot<=35){
			bar=4;
			kol=kot-29;
		}else if(kot>=36 && kot<=42){
        	bar=5;
            kol=kot-36;
		}else if(kot>=43 && kot<=49){
        	bar=6;
            kol=kot-43;		
		}
    }while(kot<1 || kot>49 || papan_7x7[bar][kol][0]=='X' || papan_7x7[bar][kol][0]=='O');
	if(clock() < start_time + timeout){	    
		if(giliran%2==0){
	    	papan_7x7[bar][kol][0]='X';
	       	if(papan_7x7[bar][kol][1]!=' '){
	       		papan_7x7[bar][kol][1]=' ';
			}
		}else{
		   	papan_7x7[bar][kol][0]='O';
		   	if(papan_7x7[bar][kol][1]!=' '){
		   		papan_7x7[bar][kol][1]=' ';	
			}
		}
	}
}														

char check_7x7(char papan_7x7[7][7][2]){
	short i,j;
	//row checking
	for(i=0; i<7; i++){
		if((papan_7x7[i][0][0]==papan_7x7[i][1][0] && papan_7x7[i][2][0]==papan_7x7[i][3][0] && papan_7x7[i][1][0]==papan_7x7[i][2][0] && papan_7x7[i][3][0]==papan_7x7[i][4][0]) || (papan_7x7[i][2][0]==papan_7x7[i][3][0] && papan_7x7[i][4][0]==papan_7x7[i][5][0] && papan_7x7[i][3][0]==papan_7x7[i][4][0] && papan_7x7[i][5][0]==papan_7x7[i][6][0]) || (papan_7x7[i][1][0]==papan_7x7[i][2][0] && papan_7x7[i][3][0]==papan_7x7[i][4][0] && papan_7x7[i][2][0]==papan_7x7[i][3][0] && papan_7x7[i][4][0]==papan_7x7[i][5][0])){
			if(papan_7x7[i][3][0]=='X'||papan_7x7[i][3][0]=='O'){
				return papan_7x7[i][3][0];
			}
		}
	}
	
	//column checking
	for(i=0; i<7; i++){
		if((papan_7x7[0][i][0]==papan_7x7[1][i][0] && papan_7x7[2][i][0]==papan_7x7[3][i][0] && papan_7x7[1][i][0]==papan_7x7[2][i][0] && papan_7x7[3][i][0]==papan_7x7[4][i][0]) || (papan_7x7[2][i][0]==papan_7x7[3][i][0] && papan_7x7[4][i][0]==papan_7x7[5][i][0] && papan_7x7[3][i][0]==papan_7x7[4][i][0] && papan_7x7[5][i][0]==papan_7x7[6][i][0]) || (papan_7x7[1][i][0]==papan_7x7[2][i][0] && papan_7x7[3][i][0]==papan_7x7[4][i][0] && papan_7x7[2][i][0]==papan_7x7[3][i][0] && papan_7x7[4][i][0]==papan_7x7[5][i][0])){
			if(papan_7x7[3][i][0]=='X'||papan_7x7[3][i][0]=='O'){
				return papan_7x7[3][i][0];
			}
		}
	}	
	
	//diagonal checking
	short streak1;
	short streak2;
	short streak3;
	short streak4;	
	
	for(i=0; i<3; i++){
		streak1=0;//[0][0], [0][1], dan [0][2]
		streak2=0;//[0][6], [1][6], dan [2][6
		for(j=0; j<6-i; j++){
			if((papan_7x7[j][j+i][0] == papan_7x7[j+1][j+i+1][0])&&(papan_7x7[j][j+i][0]=='X'||papan_7x7[j][j+i][0]=='O')){
	            streak1++;
	            if(streak1 == 4){
	            	if(papan_7x7[j][j+i][0]=='X'||papan_7x7[j][j+i][0]=='O'){
	            		return papan_7x7[j][j+i][0];
					}
				}
	        }else{
	        	streak1=0;
			}
			
			if((papan_7x7[6-j][j+i][0]==papan_7x7[5-j][j+i+1][0])&&(papan_7x7[6-j][j+i][0]=='X'||papan_7x7[6-j][j+i][0]=='O')){
	            streak2++;
	            if(streak2 == 4){
	            	if(papan_7x7[6-j][j+i][0]=='X'||papan_7x7[6-j][j+i][0]=='O'){
	            		return papan_7x7[6-j][j+i][0];
					}
				}
	        }else{
	        	streak2=0;
			}   
		}
	}	

	for(i=0; i<2; i++){
		streak3=0;
		streak4=0;
		for(j=0; j<5-i; j++){
			if((papan_7x7[j+i+1][j][0]==papan_7x7[j+i+2][j+1][0])&&(papan_7x7[j+i+1][j][0]=='X'||papan_7x7[j+i+1][j][0]=='O')){
	            streak3++;
	            if(streak3 == 4){
	            	if(papan_7x7[j+i+1][j][0]=='X'||papan_7x7[j+i+1][j][0]=='O'){
	            		return papan_7x7[j+i+1][j][0];
					}
				}
	        }else{
	        	streak3=0;
			}
			
			if((papan_7x7[5-j-i][j][0]==papan_7x7[4-j-i][j+1][0])&&(papan_7x7[5-j-i][j][0]=='X'||papan_7x7[5-j-i][j][0]=='O')){
	            streak4++;
	            if(streak4 == 4){
	            	if(papan_7x7[5-j-i][j][0]=='X'||papan_7x7[5-j-i][j][0]=='O'){
	            		return papan_7x7[5-j-i][j][0];
					}
				}
	        }else{
	        	streak4=0;
			}   
		}
	}		
	
	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(papan_7x7[i][j][0]!='O'&&papan_7x7[i][j][0]!='X')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}
	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'
	return 'D';
}

void computer_move_7x7(char papan_7x7[7][7][2], char kesulitan){
	int i, j;
	//XXXX_ || _XXXX (Block 4 prioritas)
	short key1;
	short key2;
	for(i=0; i<7; i++){
		key1=0;//horizontal
		key2=0;//vertikal
		for(j=0; j<6; j++){
			if((papan_7x7[i][j][0]==papan_7x7[i][j+1][0])&&(papan_7x7[i][j][0]=='X'||papan_7x7[i][j][0]=='O')){
				key1++;		
				if(key1==3){
					if(papan_7x7[i][j+2][0]!='X'&&papan_7x7[i][j+2][0]!='O'&&j<5){ //J+2<=6
						papan_7x7[i][j+2][0]='O';
						if(papan_7x7[i][j+2][1]!=' '){
	   						papan_7x7[i][j+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[i][j-3][0]!='X'&&papan_7x7[i][j-3][0]!='O'&&j>2){ //J-3>=0
						papan_7x7[i][j-3][0]='O';
						if(papan_7x7[i][j-3][1]!=' '){
	   						papan_7x7[i][j-3][1]=' ';	
						}
						return;
					}
				}
			}else{
				key1=0;
			}

			if((papan_7x7[j][i][0]==papan_7x7[j+1][i][0])&&(papan_7x7[j][i][0]=='X'||papan_7x7[j][i][0]=='O')){
				key2++;	
				if(key2==3){
					if(papan_7x7[j+2][i][0]!='X'&&papan_7x7[j+2][i][0]!='O'&&j<5){ //J+2<=6
						papan_7x7[j+2][i][0]='O';	
						if(papan_7x7[j+2][i][1]!=' '){
	   						papan_7x7[j+2][i][1]=' ';	
						}
						return;
					}else if(papan_7x7[j-3][i][0]!='X'&&papan_7x7[j-3][i][0]!='O'&&j>2){ //J-3>=0
						papan_7x7[j-3][i][0]='O';
						if(papan_7x7[j-3][i][1]!=' '){
	   						papan_7x7[j-3][i][1]=' ';	
						}
						return;
					}
				}
			}else{
				key2=0;
			}
		}
	}
	
	//XXXX_ || _XXXX (Block 4 prioritas)(Diagonal)
	//Block 4 tanda berurutan Diagonal
	short diagonal1;
	short diagonal2;
	short diagonal3;
	short diagonal4;
	for(i=0; i<3; i++){
		diagonal1=0;//[0][0], [0][1], dan [0][2]
		diagonal2=0;//[0][6], [1][6], dan [2][6]
		for(j=0; j<7-i; j++){
			if((papan_7x7[j][j+i][0]==papan_7x7[j+1][j+i+1][0])&&(papan_7x7[j][j+i][0]=='X'||papan_7x7[j][j+i][0]=='O')){
				diagonal1++;		
				if(diagonal1==3){
					if(papan_7x7[j+2][j+i+2][0]!='X'&&papan_7x7[j+2][j+i+2][0]!='O'&&j+i+2<=6){ //Pola pada kolom bertambah 1 --> j+i+2<=6
						papan_7x7[j+2][j+i+2][0]='O';
						if(papan_7x7[j+2][j+i+2][1]!=' '){
	   						papan_7x7[j+2][j+i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[j-3][j+i-3][0]!='X'&&papan_7x7[j-3][j+i-3][0]!='O'&&j-i-3>=0){ //Block bagian belakang --> j-3>=0
						papan_7x7[j-3][j+i-3][0]='O';
						if(papan_7x7[j-3][j+i-3][1]!=' '){
	   						papan_7x7[j-3][j+i-3][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal1=0;
			}
			
			if((papan_7x7[j+i][6-j][0]==papan_7x7[j+i+1][5-j][0])&&(papan_7x7[j+i][6-j][0]=='X'||papan_7x7[j+i][6-j][0]=='O')){
				diagonal2++;		
				if(diagonal2==3){
					if(papan_7x7[j+i+2][4-j][0]!='X'&&papan_7x7[j+i+2][4-j][0]!='O'&&j+i+2<=6){ //Pola pada baris bertambah 1 --> j+i+2<=6
						papan_7x7[j+i+2][4-j][0]='O';
						if(papan_7x7[j+i+2][4-j][1]!=' '){
	   						papan_7x7[j+i+2][4-j][1]=' ';	
						}
						return;
					}else if(papan_7x7[j+i-3][9-j][0]!='X'&&papan_7x7[j+i-3][9-j][0]!='O'&&9-j<=6){ //Block bagian belakang --> 9-j<=6
						papan_7x7[j+i-3][9-j][0]='O';
						if(papan_7x7[j+i-3][9-j][1]!=' '){
	   						papan_7x7[j+i-3][9-j][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal2=0;
			}
		}
	}
	
	for(j=0; j<2; j++){
		diagonal3=0; //[1][0] dan [2][0]
		diagonal4=0; //[0][5] dan [0][4]
		for(i=0; i<5-j; i++){
			if((papan_7x7[i+j+1][i][0]==papan_7x7[i+j+2][i+1][0])&&(papan_7x7[i+j+1][i][0]=='X'||papan_7x7[i+j+1][i][0]=='O')){
				diagonal3++;		
				if(diagonal3==3){
					if(papan_7x7[i+j+3][i+2][0]!='X'&&papan_7x7[i+j+3][i+2][0]!='O'&&i+j+3<=6){
						papan_7x7[i+j+3][i+2][0]='O';
						if(papan_7x7[i+j+3][i+2][1]!=' '){
	   						papan_7x7[i+j+3][i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[i+j-2][i-3][0]!='X'&&papan_7x7[i+j-2][i-3][0]!='O'&&i-3>=0){
						papan_7x7[i+j-2][i-3][0]='O';
						if(papan_7x7[i+j-2][i-3][1]!=' '){
	   						papan_7x7[i+j-2][i-3][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal3=0;
			}
			
			if((papan_7x7[i][5-j-i][0]==papan_7x7[i+1][4-j-i][0])&&(papan_7x7[i][5-j-i][0]=='X'||papan_7x7[i][5-j-i][0]=='O')){
				diagonal4++;		
				if(diagonal4==3){
					if(papan_7x7[i+2][3-j-i][0]!='X'&&papan_7x7[i+2][3-j-i][0]!='O'&&i+j+2<=5){
						papan_7x7[i+2][3-j-i][0]='O';
						if(papan_7x7[i+2][3-j-i][1]!=' '){
	   						papan_7x7[i+2][3-j-i][1]=' ';	
						}
						return;
					}else if(papan_7x7[i-3][8-j-i][0]!='X'&&papan_7x7[i-3][8-j-i][0]!='O'&&i>=3){
						papan_7x7[i-3][8-j-i][0]='O';
						if(papan_7x7[i-3][8-j-i][1]!=' '){
	   						papan_7x7[i-3][8-j-i][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal4=0;
			}
		}
	}
	
	if(kesulitan=='2'||kesulitan=='3'){ //tingkat medium dan hard
		//Strategi 7x7 XX_X Dan X_XX Horizontal
		for(i=0; i<2; i++){
			for(j=0; j<7; j++){
				if((papan_7x7[j][1+i][0]=='X'&&papan_7x7[j][2+i][0]=='X'&&papan_7x7[j][4+i][0]=='X')||(papan_7x7[j][1+i][0]=='O'&&papan_7x7[j][2+i][0]=='O'&&papan_7x7[j][4+i][0]=='O')){
					if(papan_7x7[j][3+i][0]!='X'&&papan_7x7[j][3+i][0]!='O'){
						papan_7x7[j][3+i][0]='O';
						if(papan_7x7[j][3+i][1]!=' '){
			   				papan_7x7[j][3+i][1]=' ';	
						}
						return;			
					}
				}
				if((papan_7x7[j][1+i][0]=='X'&&papan_7x7[j][3+i][0]=='X'&&papan_7x7[j][4+i][0]=='X')||(papan_7x7[j][1+i][0]=='O'&&papan_7x7[j][3+i][0]=='O'&&papan_7x7[j][4+i][0]=='O')){
					if(papan_7x7[j][2+i][0]!='X'&&papan_7x7[j][2+i][0]!='O'){
						papan_7x7[j][2+i][0]='O';
						if(papan_7x7[j][2+i][1]!=' '){
			   				papan_7x7[j][2+i][1]=' ';	
						}
						return;		
					}
				}
			}
		}
		
		//Strategi 7x7 XX_X Dan X_XX Vertikal
		for(i=0; i<2; i++){
			for(j=0; j<7; j++){
				if((papan_7x7[1+i][j][0]=='X'&&papan_7x7[2+i][j][0]=='X'&&papan_7x7[4+i][j][0]=='X')||(papan_7x7[1+i][j][0]=='O'&&papan_7x7[2+i][j][0]=='O'&&papan_7x7[4+i][j][0]=='O')){
					if(papan_7x7[3+i][j][0]!='X'&&papan_7x7[3+i][j][0]!='O'){
						papan_7x7[3+i][j][0]='O';
						if(papan_7x7[3+i][j][1]!=' '){
			   				papan_7x7[3+i][j][1]=' ';	
						}
						return;	
					}
				}
				if((papan_7x7[1+i][j][0]=='X'&&papan_7x7[3+i][j][0]=='X'&&papan_7x7[4+i][j][0]=='X')||(papan_7x7[1+i][j][0]=='O'&&papan_7x7[3+i][j][0]=='O'&&papan_7x7[4-i][j][0]=='O')){
					if(papan_7x7[2+i][j][0]!='X'&&papan_7x7[2+i][j][0]!='O'){
						papan_7x7[2+i][j][0]='O';
						if(papan_7x7[2+i][j][1]!=' '){
			   				papan_7x7[2+i][j][1]=' ';	
						}
						return;	
					}
				}
			}
		}
	}
	
	if(kesulitan=='3'){
		//Strategi 7x7 XX_X Dan X_XX Diagonal [0][0]	
		for(j=0; j<2; j++){
			if((papan_7x7[1+j][1+j][0]=='X'&&papan_7x7[2+j][2+j][0]=='X'&&papan_7x7[4+j][4+j][0]=='X')||(papan_7x7[1+j][1+j][0]=='O'&&papan_7x7[2+j][2+j][0]=='O'&&papan_7x7[4+j][4+j][0]=='O')){
				if(papan_7x7[3+j][3+j][0]!='X'&&papan_7x7[3+j][3+j][0]!='O'){
					papan_7x7[3+j][3+j][0]='O';
					if(papan_7x7[3+j][3+j][1]!=' '){
		  				papan_7x7[3+j][3+j][1]=' ';	
					}
					return;
				}	
			}
			if((papan_7x7[1+j][1+j][0]=='X'&&papan_7x7[3+j][3+j][0]=='X'&&papan_7x7[4+j][4+j][0]=='X')||(papan_7x7[1+j][1+j][0]=='O'&&papan_7x7[3+j][3+j][0]=='O'&&papan_7x7[4+j][4+j][0]=='O')){
				if(papan_7x7[2+j][2+j][0]!='X'&&papan_7x7[2+j][2+j][0]!='O'){
					papan_7x7[2+j][2+j][0]='O';
					if(papan_7x7[2+j][2+j][1]!=' '){
			  			papan_7x7[2+j][2+j][1]=' ';	
					}
					return;
				}
			}
		}
	
		//Strategi 7x7 XX_X Dan X_XX Diagonal [0][6]	
		for(j=0; j<2; j++){
			if((papan_7x7[5-j][1+j][0]=='X'&&papan_7x7[4-j][2+j][0]=='X'&&papan_7x7[2-j][4+j][0]=='X')||(papan_7x7[5-j][1+j][0]=='O'&&papan_7x7[4-j][2+j][0]=='O'&&papan_7x7[2-j][4+j][0]=='O')){
				if(papan_7x7[3-j][3+j][0]!='X'&&papan_7x7[3-j][3+j][0]!='O'){
					papan_7x7[3-j][3+j][0]='O';
					if(papan_7x7[3-j][3+j][1]!=' '){
		  				papan_7x7[3-j][3+j][1]=' ';	
					}
					return;
				}
			}
			if((papan_7x7[5-j][1+j][0]=='X'&&papan_7x7[3-j][3+j][0]=='X'&&papan_7x7[2-j][4+j][0]=='X')||(papan_7x7[5-j][1+j][0]=='O'&&papan_7x7[3-j][3+j][0]=='O'&&papan_7x7[2-j][4+j][0]=='O')){
				if(papan_7x7[4-j][2+j][0]!='X'&&papan_7x7[4-j][2+j][0]!='O'){
					papan_7x7[4-j][2+j][0]='O';
					if(papan_7x7[4-j][2+j][1]!=' '){
			  			papan_7x7[4-j][2+j][1]=' ';	
					}
					return;
				}
			}
		}
	
		//Strategi 7x7 XX_X Dan X_XX Diagonal [0][1]	
		for(j=0; j<2; j++){
			if((papan_7x7[1][2][0]=='X'&&papan_7x7[2+j][3+j][0]=='X'&&papan_7x7[4][5][0]=='X')||(papan_7x7[1][2][0]=='O'&&papan_7x7[2+j][3+j][0]=='O'&&papan_7x7[4][5][0]=='O')){
				if(papan_7x7[3-j][4-j][0]!='X'&&papan_7x7[3-j][4-j][0]!='O'){
					papan_7x7[3-j][4-j][0]='O';
					if(papan_7x7[3-j][4-j][1]!=' '){
			 			papan_7x7[3-j][4-j][1]=' ';	
					}
					return;
				}		
			}
		}
		
		//Strategi 7x7 XX_X Dan X_XX Diagonal [1][0]	
		for(j=0; j<2; j++){
			if((papan_7x7[2][1][0]=='X'&&papan_7x7[3+j][2+j][0]=='X'&&papan_7x7[5][4][0]=='X')||(papan_7x7[2][1][0]=='O'&&papan_7x7[3+j][2+j][0]=='O'&&papan_7x7[5][4][0]=='O')){
				if(papan_7x7[4-j][3-j][0]!='X'&&papan_7x7[4-j][3-j][0]!='O'){
					papan_7x7[4-j][3-j][0]='O';
					if(papan_7x7[4-j][3-j][1]!=' '){
			 			papan_7x7[4-j][3-j][1]=' ';	
					}
					return;
				}		
			}
		}
	
		//Strategi 7x7 XX_X Dan X_XX Diagonal [0][5]	
		for(j=0; j<2; j++){
			if((papan_7x7[4][1][0]=='X'&&papan_7x7[3-j][2+j][0]=='X'&&papan_7x7[1][4][0]=='X')||(papan_7x7[4][1][0]=='O'&&papan_7x7[3-j][2+j][0]=='O'&&papan_7x7[1][4][0]=='O')){
				if(papan_7x7[2+j][3-j][0]!='X'&&papan_7x7[2+j][3-j][0]!='O'){
					papan_7x7[2+j][3-j][0]='O';
					if(papan_7x7[2+j][3-j][1]!=' '){
			 			papan_7x7[2+j][3-j][1]=' ';	
					}
					return;
				}		
			}
		}
		
		//Strategi 7x7 XX_X Dan X_XX Diagonal [1][6]	
		for(j=0; j<2; j++){
			if((papan_7x7[5][2][0]=='X'&&papan_7x7[4-j][3+j][0]=='X'&&papan_7x7[2][5][0]=='X')||(papan_7x7[5][2][0]=='O'&&papan_7x7[4-j][3+j][0]=='O'&&papan_7x7[2][5][0]=='O')){
				if(papan_7x7[3+j][4-j][0]!='X'&&papan_7x7[3+j][4-j][0]!='O'){
					papan_7x7[3+j][4-j][0]='O';
					if(papan_7x7[3+j][4-j][1]!=' '){
			 			papan_7x7[3+j][4-j][1]=' ';	
					}
					return;
				}		
			}
		}
	}
	
	//XXX_ || _XXX (Block 3 prioritas)
	short key3;
	short key4;
	for(i=0; i<7; i++){
		key3=0;//horizontal
		key4=0;//vertikal
		for(j=0; j<6; j++){
			if((papan_7x7[i][j][0]==papan_7x7[i][j+1][0])&&(papan_7x7[i][j][0]=='X'||papan_7x7[i][j][0]=='O')){
				key3++;		
				if(key3==2){
					if(papan_7x7[i][j+2][0]!='X'&&papan_7x7[i][j+2][0]!='O'&&j<5){
						papan_7x7[i][j+2][0]='O';
						if(papan_7x7[i][j+2][1]!=' '){
	   						papan_7x7[i][j+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[i][j-2][0]!='X'&&papan_7x7[i][j-2][0]!='O'&&j>1){
						papan_7x7[i][j-2][0]='O';
						if(papan_7x7[i][j-2][1]!=' '){
	   						papan_7x7[i][j-2][1]=' ';	
						}
						return;
					}
				}
			}else{
				key3=0;
			}

			if((papan_7x7[j][i][0]==papan_7x7[j+1][i][0])&&(papan_7x7[j][i][0]=='X'||papan_7x7[j][i][0]=='O')){
				key4++;	
				if(key4==2){
					if(papan_7x7[j+2][i][0]!='X'&&papan_7x7[j+2][i][0]!='O'&&j<5){
						papan_7x7[j+2][i][0]='O';	
						if(papan_7x7[j+2][i][1]!=' '){
	   						papan_7x7[j+2][i][1]=' ';	
						}
						return;
					}else if(papan_7x7[j-2][i][0]!='X'&&papan_7x7[j-2][i][0]!='O'&&j>1){
						papan_7x7[j-2][i][0]='O';
						if(papan_7x7[j-2][i][1]!=' '){
	   						papan_7x7[j-2][i][1]=' ';	
						}
						return;
					}
				}
			}else{
				key4=0;
			}
		}
	}
	
	//XXXX_ || _XXXX (Block 3 prioritas)(Diagonal)
	//Block 3 tanda berurutan Diagonal
	for(i=0; i<3; i++){
		diagonal1=0;//[0][0], [0][1], dan [0][2]
		diagonal2=0;//[0][6], [1][6], dan [2][6]
		for(j=0; j<7-i; j++){
			if((papan_7x7[j][j+i][0]==papan_7x7[j+1][j+i+1][0])&&(papan_7x7[j][j+i][0]=='X'||papan_7x7[j][j+i][0]=='O')){
				diagonal1++;		
				if(diagonal1==2){
					if(papan_7x7[j+2][j+i+2][0]!='X'&&papan_7x7[j+2][j+i+2][0]!='O'&&j+i+2<=6){
						papan_7x7[j+2][j+i+2][0]='O';
						if(papan_7x7[j+2][j+i+2][1]!=' '){
	   						papan_7x7[j+2][j+i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[j-2][j+i-2][0]!='X'&&papan_7x7[j-2][j+i-2][0]!='O'&&j-2>=0){
						papan_7x7[j-2][j+i-2][0]='O';
						if(papan_7x7[j-2][j+i-2][1]!=' '){
	   						papan_7x7[j-2][j+i-2][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal1=0;
			}
			if((papan_7x7[j+i][6-j][0]==papan_7x7[j+i+1][5-j][0])&&(papan_7x7[j+i][6-j][0]=='X'||papan_7x7[j+i][6-j][0]=='O')){
				diagonal2++;		
				if(diagonal2==2){
					if(papan_7x7[j+i+2][4-j][0]!='X'&&papan_7x7[j+i+2][4-j][0]!='O'&&j+i+2<=6){
						papan_7x7[j+i+2][4-j][0]='O';
						if(papan_7x7[j+i+2][4-j][1]!=' '){
	   						papan_7x7[j+i+2][4-j][1]=' ';	
						}
						return;
					}else if(papan_7x7[j+i-2][8-j][0]!='X'&&papan_7x7[j+i-2][8-j][0]!='O'&&8-j<=6){
						papan_7x7[j+i-2][8-j][0]='O';
						if(papan_7x7[j+i-2][8-j][1]!=' '){
	   						papan_7x7[j+i-2][8-j][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal2=0;
			}
		}
	}	

	for(j=0; j<2; j++){
		diagonal3=0;//[1][0] dan [2][0]
		diagonal4=0;//[0][5] dan [0][4]
		for(i=0; i<5-j; i++){
			if((papan_7x7[i+j+1][i][0]==papan_7x7[i+j+2][i+1][0])&&(papan_7x7[i+j+1][i][0]=='X'||papan_7x7[i+j+1][i][0]=='O')){
				diagonal3++;		
				if(diagonal3==2){
					if(papan_7x7[i+j+3][i+2][0]!='X'&&papan_7x7[i+j+3][i+2][0]!='O'&&i+j+3<=6){
						papan_7x7[i+j+3][i+2][0]='O';
						if(papan_7x7[i+j+3][i+2][1]!=' '){
	   						papan_7x7[i+j+3][i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[i+j-1][i-2][0]!='X'&&papan_7x7[i+j-1][i-2][0]!='O'&&i-2>=0){
						papan_7x7[i+j-1][i-2][0]='O';
						if(papan_7x7[i+j-1][i-2][1]!=' '){
	   						papan_7x7[i+j-1][i-2][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal3=0;
			}
			
			if((papan_7x7[i][5-j-i][0]==papan_7x7[i+1][4-j-i][0])&&(papan_7x7[i][5-j-i][0]=='X'||papan_7x7[i][5-j-i][0]=='O')){
				diagonal4++;		
				if(diagonal4==2){
					if(papan_7x7[i+2][3-j-i][0]!='X'&&papan_7x7[i+2][3-j-i][0]!='O'&&i+j+2<=5){
						papan_7x7[i+2][3-j-i][0]='O';
						if(papan_7x7[i+2][3-j-i][1]!=' '){
	   						papan_7x7[i+2][3-j-i][1]=' ';	
						}
						return;
					}else if(papan_7x7[i-2][7-j-i][0]!='X'&&papan_7x7[i-2][7-j-i][0]!='O'&&i>=2){
						papan_7x7[i-2][7-j-i][0]='O';
						if(papan_7x7[i-2][7-j-i][1]!=' '){
	   						papan_7x7[i-2][7-j-i][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal4=0;
			}
		}
	}
	
	//Block 2 tanda berurutan horizontal (Baris)
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(papan_7x7[i][j][0]=='X'&&papan_7x7[i][j+1][0]=='X'){
				if(papan_7x7[i][j+2][0]!='O'&&papan_7x7[i][j+2][0]!='X'&&j+2<=6){
					papan_7x7[i][j+2][0]='O';
					if(papan_7x7[i][j+2][1]!=' '){
	   					papan_7x7[i][j+2][1]=' ';
					}
					return;
				}else if(papan_7x7[i][j+2][0]=='X'&&papan_7x7[i][j+3][0]!='O'&&papan_7x7[i][j+3][0]!='X'&&j+3<=6){
					papan_7x7[i][j+3][0]='O';
					if(papan_7x7[i][j+3][1]!=' '){
	   					papan_7x7[i][j+3][1]=' ';	
					}
					return;
				}else if(papan_7x7[i][j-1][0]!='O'&&papan_7x7[i][j-1][0]!='X'&&j-1>=0){
					papan_7x7[i][j-1][0]='O';
					if(papan_7x7[i][j-1][1]!=' '){
	   					papan_7x7[i][j-1][1]=' ';	
					}
					return;
				}else if(papan_7x7[i][j-1][0]=='X'&&papan_7x7[i][j-2][0]!='O'&&papan_7x7[i][j-2][0]!='X'&&j-2>=0){
					papan_7x7[i][j-2][0]='O';
					if(papan_7x7[i][j-2][1]!=' '){
	   					papan_7x7[i][j-2][1]=' ';	
					}
					return;
				}
			}
		}
	}
	
	//Block 2 tanda berurutan vertikal (Kolom) 
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(papan_7x7[j][i][0]=='X'&&papan_7x7[j+1][i][0]=='X'){
				if(papan_7x7[j+2][i][0]!='O'&&papan_7x7[j+2][i][0]!='X'&&j+2<=6){
					papan_7x7[j+2][i][0]='O';
					if(papan_7x7[j+2][i][1]!=' '){
	   					papan_7x7[j+2][i][1]=' ';	
					}
					return;
				}else if(papan_7x7[j+2][i][0]=='X'&&papan_7x7[j+3][i][0]!='O'&&papan_7x7[j+3][i][0]!='X'&&j+3<=6){
					papan_7x7[j+3][i][0]='O';
					if(papan_7x7[j+3][i][1]!=' '){
	   					papan_7x7[j+3][i][1]=' ';	
					}
					return;
				}else if(papan_7x7[j-1][i][0]!='O'&&papan_7x7[j-1][i][0]!='X'&&j-1>=0){
					papan_7x7[j-1][i][0]='O';
					if(papan_7x7[j-1][i][1]!=' '){
	   					papan_7x7[j-1][i][1]=' ';	
					}
					return;
				}else if(papan_7x7[j-1][i][0]=='X'&&papan_7x7[j-2][i][0]!='O'&&papan_7x7[j-2][i][0]!='X'&&j-2>=0){
					papan_7x7[j-2][i][0]='O';
					if(papan_7x7[j-2][i][1]!=' '){
	   					papan_7x7[j-2][i][1]=' ';	
					}
					return;
				}
			}
		}
	}

		
	//titik penting
	if(papan_7x7[3][3][0]!='X'&&papan_7x7[3][3][0]!='O'){
		papan_7x7[3][3][0]='O';
		if(papan_7x7[3][3][1]!=' '){
	   		papan_7x7[3][3][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[2][2][0]!='X'&&papan_7x7[2][2][0]!='O'){
		papan_7x7[2][2][0]='O';
		if(papan_7x7[2][2][1]!=' '){
	   		papan_7x7[2][2][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[4][4][0]!='X'&&papan_7x7[4][4][0]!='O'){
		papan_7x7[4][4][0]='O';
		if(papan_7x7[4][4][1]!=' '){
	   		papan_7x7[4][4][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[2][4][0]!='X'&&papan_7x7[2][4][0]!='O'){
		papan_7x7[2][4][0]='O';
		if(papan_7x7[2][4][1]!=' '){
	   		papan_7x7[2][4][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[4][2][0]!='X'&&papan_7x7[4][2][0]!='O'){
		papan_7x7[4][2][0]='O';
		if(papan_7x7[4][2][1]!=' '){
	   		papan_7x7[4][2][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[2][3][0]!='X'&&papan_7x7[2][3][0]!='O'){
		papan_7x7[2][3][0]='O';
		if(papan_7x7[2][3][1]!=' '){
	   		papan_7x7[2][3][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[3][2][0]!='X'&&papan_7x7[3][2][0]!='O'){
		papan_7x7[3][2][0]='O';
		if(papan_7x7[3][2][1]!=' '){
	   		papan_7x7[3][2][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[4][3][0]!='X'&&papan_7x7[4][3][0]!='O'){
		papan_7x7[4][3][0]='O';
		if(papan_7x7[4][3][1]!=' '){
	   		papan_7x7[4][3][1]=' ';	
		}
		return;
	}
	
	if(papan_7x7[3][4][0]!='X'&&papan_7x7[3][4][0]!='O'){
		papan_7x7[3][4][0]='O';
		if(papan_7x7[3][4][1]!=' '){
	   		papan_7x7[3][4][1]=' ';	
		}
		return;
	}
	

	//XXXX_ || _XXXX (Block 2 prioritas)(Diagonal)
	//Block 2 tanda berurutan Diagonal
	for(i=0; i<3; i++){
		diagonal1=0;//[0][0], [0][1], dan [0][2]
		diagonal2=0;//[0][6], [1][6], dan [2][6]
		for(j=0; j<7-i; j++){
			if((papan_7x7[j][j+i][0]==papan_7x7[j+1][j+i+1][0])&&(papan_7x7[j][j+i][0]=='X'||papan_7x7[j][j+i][0]=='O')){
				diagonal1++;		
				if(diagonal1==1){
					if(papan_7x7[j+2][j+i+2][0]!='X'&&papan_7x7[j+2][j+i+2][0]!='O'&&j+i+2<=6){
						papan_7x7[j+2][j+i+2][0]='O';
						if(papan_7x7[j+2][j+i+2][1]!=' '){
	   						papan_7x7[j+2][j+i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[j-1][j+i-1][0]!='X'&&papan_7x7[j-1][j+i-1][0]!='O'&&j-1>=0){
						papan_7x7[j-1][j+i-1][0]='O';
						if(papan_7x7[j-1][j+i-1][1]!=' '){
	   						papan_7x7[j-1][j+i-1][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal1=0;
			}
			
			if((papan_7x7[j+i][6-j][0]==papan_7x7[j+i+1][5-j][0])&&(papan_7x7[j+i][6-j][0]=='X'||papan_7x7[j+i][6-j][0]=='O')){
				diagonal2++;		
				if(diagonal2==1){
					if(papan_7x7[j+i+2][4-j][0]!='X'&&papan_7x7[j+i+2][4-j][0]!='O'&&j+i+2<=6){
						papan_7x7[j+i+2][4-j][0]='O';
						if(papan_7x7[j+i+2][4-j][1]!=' '){
	   						papan_7x7[j+i+2][4-j][1]=' ';	
						}
						return;
					}else if(papan_7x7[j+i-1][7-j][0]!='X'&&papan_7x7[j+i-1][7-j][0]!='O'&&7-j<=6){
						papan_7x7[j+i-1][7-j][0]='O';
						if(papan_7x7[j+i-1][7-j][1]!=' '){
	   						papan_7x7[j+i-1][7-j][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal2=0;
			}
		}
	}
	
	for(j=0; j<2; j++){
		diagonal3=0;//[1][0] dan [2][0]
		diagonal4=0;//[0][5] dan [0][4]
		for(i=0; i<5-j; i++){
			if((papan_7x7[i+j+1][i][0]==papan_7x7[i+j+2][i+1][0])&&(papan_7x7[i+j+1][i][0]=='X'||papan_7x7[i+j+1][i][0]=='O')){
				diagonal3++;		
				if(diagonal3==1){
					if(papan_7x7[i+j+3][i+2][0]!='X'&&papan_7x7[i+j+3][i+2][0]!='O'&&i+j+3<=6){
						papan_7x7[i+j+3][i+2][0]='O';
						if(papan_7x7[i+j+3][i+2][1]!=' '){
	   						papan_7x7[i+j+3][i+2][1]=' ';	
						}
						return;
					}else if(papan_7x7[i+j][i-1][0]!='X'&&papan_7x7[i+j][i-1][0]!='O'&&i-1>=0){
						papan_7x7[i+j][i-1][0]='O';
						if(papan_7x7[i+j][i-1][1]!=' '){
	   						papan_7x7[i+j][i-1][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal3=0;
			}
			
			if((papan_7x7[i][5-j-i][0]==papan_7x7[i+1][4-j-i][0])&&(papan_7x7[i][5-j-i][0]=='X'||papan_7x7[i][5-j-i][0]=='O')){
				diagonal4++;		
				if(diagonal4==1){
					if(papan_7x7[i+2][3-j-i][0]!='X'&&papan_7x7[i+2][3-j-i][0]!='O'&&i+j+2<=5){
						papan_7x7[i+2][3-j-i][0]='O';
						if(papan_7x7[i+2][3-j-i][1]!=' '){
	   						papan_7x7[i+2][3-j-i][1]=' ';	
						}
						return;
					}else if(papan_7x7[i-1][6-j-i][0]!='X'&&papan_7x7[i-1][6-j-i][0]!='O'&&i>=1){
						papan_7x7[i-1][6-j-i][0]='O';
						if(papan_7x7[i-1][6-j-i][1]!=' '){
	   						papan_7x7[i-1][6-j-i][1]=' ';	
						}
						return;
					}
				}
			}else{
				diagonal4=0;
			}
		}
	}
	
	//yang belum terisi
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(papan_7x7[i][j][0]!='X'&&papan_7x7[i][j][0]!='O'){
				papan_7x7[i][j][0]='O';
				if(papan_7x7[i][j][1]!=' '){
	   				papan_7x7[i][j][1]=' ';	
	   			}
			return;
			}
		}
	}
}
