#include<Windows.h>
#include<iostream>
#include<time.h>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
bool gameover;
int x, y, eggX, eggY, score;
const int width = 20, height = 20;
string p1, p2, p3;
int s1, s2, s3, k = 1;
enum Directon { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Controls
char credit[][20] = { "CREDITS","Shabareesh Aryan","Subrahmanya", "Leander Mani", "S Rochan Kumar" };
char ref1[] = { "References - \n\nGeeksforgeeks \nThe Complete Reference C++, Herbert Schildt\n" };
Directon dir;
void result()
{
	ofstream myfile;
	myfile.open("HighScore.txt");
	myfile << "High Scores : \n";
	myfile.close();


	system("cls");
	int i = 0;
	int count = 2;
	do {
		system("cls");
		if (count % 2 == 0)
			cout << "\n\n";
		cout << "       ,~~;," << endl;
		cout << "       a,a)\\9" << endl;
		cout << "       \\= ,6" << endl;
		cout << "       _/'(_8," << endl;
		cout << "      /(__/\\]\\" << endl;
		cout << "     (_,,__) \\\\" << endl;
		cout << "     //\\  ;/  \\\\" << endl;
		cout << "    //  )__\\   \\|_ " << endl;
		cout << "  _'/  |[]__L,  ,>}" << endl;
		cout << " /t}  / ,   [| " << endl;
		cout << "     /-.|=._|/" << endl;
		cout << "    /  .'`-/`" << endl;
		cout << "   ( .' | /" << endl;
		cout << "   \\ |  ( |" << endl;
		cout << "    \\_)  \_)." << endl;
		cout << "     \\ \\  \\ |" << endl;
		cout << "      \\ >  >|" << endl;
		cout << "     /.'  / /" << endl;
		cout << "         '-'" << endl;
		Sleep(150);
		count++;
	} while (count != 10);
	char cg[] = { "Hooray! The winner of the game is: " };
	if (s1 > s2 && s1 > s3) {
		for (i; cg[i] != '\0'; i++)
		{
			cout << cg[i];
			Sleep(50);
		}
		cout << p1 << "\n";
		myfile.open("HighScore.txt", ios::in | ios::app| ios::trunc );
		if (myfile.is_open())
			myfile << p1 << " : " << s1 << "\n";
		myfile.close();
	}
	if (s2 > s1 && s2 > s3) {
		for (i; cg[i] != '\0'; i++)
		{
			cout << cg[i];
			Sleep(50);
		}
		cout << p2 << "\n";
		myfile.open("HighScore.txt", ios::in | ios::app);
		if (myfile.is_open())
			myfile << p2 << " : " << s2 << "\n";
		myfile.close();
	}
	if (s3 > s1 && s3 > s2) {
		for (i; cg[i] != '\0'; i++)
		{
			cout << cg[i];
			Sleep(50);
		}
		cout << p3 << "\n"; Sleep(30);
		myfile.open("HighScore.txt", ios::in | ios::app);
		if (myfile.is_open())
			myfile << p3 << " : " << s3 << "\n";
		myfile.close();
	}

}
void details()
{
	string* p{};
	if (k == 1) {
		p = &p1;
	}
	if (k == 2) {
		p = &p2;
	}
	if (k == 3) {
		p = &p3;
	}

	system("cls"); char in[] = { "Enter name, player " };
	for (int i = 0; in[i] != '\0'; i++)
	{
		cout << in[i];
		Sleep(50);
	}
	cout << k << ": ";
	cin >> *p;
	system("cls"); char in2[] = { "Greetings, " };
	char in3[] = { "Let us begin..." };
	for (int j = 0; in2[j] != '\0'; j++)
	{
		cout << in2[j];
		Sleep(50);
	}
	cout << *p << endl;
	for (int z = 0; in3[z] != '\0'; z++)
	{
		cout << in3[z];
		Sleep(80);
	}
	Sleep(2000);

}

class setup
{
public:
	setup()
	{
		srand(time(NULL));
		details();
		gameover = false;
		dir = STOP;
		eggX = rand() % width;
		eggY = 0;
		x = width - 2;
		y = height - 2;
		score = 0;
	}
};

class Input
{
public:
	Input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			}
		}
	}
};

class Logic
{
public:
	Logic()
	{
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}
		dir = STOP;
		if (x >= width)
			x = 0;
		else if (x < 0)
			x = width - 1;
		if (eggY > height)
		{
			gameover = true;		//you dropped the egg
		}
		else
			Input();
		if (y > height - 1)
		{
			y = height - 1;
		}

		if (x == eggX && y == eggY)
		{
			score += 10;
			eggX = rand() % width;			//next egg
			eggY = 0;
		}

	}
	void EggFall();
};

class Draw
{
public:
	Draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; i++)
		{
			cout << "\xB2";
		}
		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0)
					cout << "\xB2"; //walls
				if (i == y && j == x)
					cout << "U";
				else if (i == eggY && j == eggX)
					cout << "O";
				else
					cout << " ";
				if (j == width - 1)
					cout << "\xB2";
			}
			cout << endl;
		}
		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;
		cout << "Score : " << score << endl;
	}
};

void Logic::EggFall()
{
	if (score >= 100) { Sleep(0); }
	else Sleep(80);
	eggY++;
}

class display
{
public:
	display()
	{
		int choice;
		system("Color 0A");
	backbutton:
		system("cls");
		cout << "ad88888ba   88          88                         \n";
		cout << "d8*     *8b 88          **                         \n";
		cout << "Y8,         88                                     \n";
		cout << "`Y8aaaaa,   88,dPPYba,  88 8b       d8 ,adPPYYba,  \n";
		cout << "  `*****8b, 88P'    *8a 88 `8b     d8' **     `Y8  \n";
		cout << "        `8b 88       88 88  `8b   d8'  ,adPPPPP88  \n";
		cout << "Y8a     a8P 88       88 88   `8b,d8'   88,    ,88  \n";
		cout << " *Y88888P*  88       88 88     *8*     `*8bbdP*Y8  \n";
		cout << "\n\n";
		Sleep(500);
		cout << "88888888ba                                  88                                88                          \n";
		cout << "88      *8b                                 88                          ,d    **                          \n";
		cout << "88      ,8P                                 88                          88                                \n";
		cout << "88aaaaaa8P' 8b,dPPYba,  ,adPPYba,   ,adPPYb,88 88       88  ,adPPYba, MM88MMM 88  ,adPPYba,  8b,dPPYba,   \n";
		cout << "88******'   88P'   *Y8 a8*     *8a a8*    `Y88 88       88 a8*     **   88    88 a8*     *8a 88P'   `*8a  \n";
		cout << "88          88         8b       d8 8b       88 88       88 8b           88    88 8b       d8 88       88  \n";
		cout << "88          88         *8a,   ,a8* *8a,   ,d88 *8a,   ,a88 *8a,   ,aa   88,   88 *8a,   ,a8* 88       88  \n";
		cout << "88          88          `*YbbdP*'   `*8bbdP*Y8  `*YbbdP'Y8  `*Ybbd8*'   *Y888 88  `*YbbdP*'  88       88  \n";
		Sleep(500);
		cout << "\n\n\n\n\n\t\t\t\t PROUDLY PRESENTS\n";
		Sleep(1500);
		system("cls");
		cout << "#========================================================================================================#\n";
		cout << "\t 888888888                  \t 88888888ba,   \n";
		cout << "\t 88                         \t 88      `*8b  \n";
		cout << "\t 88                         \t 88        `8b \n";
		cout << "\t 88aaaaa  .dd88b.   .dd88b. \t 88         88  8b,dPPYba,  ,adPPYba,  8b,dPPYba,  \n";
		cout << "\t 88*****  d88P*88b d88P*88b \t 88         88  88P'   *Y8 a8*     *8a 88P'    *8a \n";
		cout << "\t 88       888  888 888  888 \t 88         88  88         8b       d8 88       d8 \n";
		cout << "\t 88       Y88b 888 Y88b 888 \t 88      .a8P   88         *8a,   ,a8* 88b,   ,a8* \n";
		cout << "\t 888888888 *Y88888  *Y88888 \t 88888888Y*'    88          `*YbbdP*'  88`YbbdP*'  \n";
		cout << "\t              8888     8888 \t                                       88       \n";
		cout << "\t         Y8b d88PY 8b d88PY \t                                       88       \n";
		cout << "\t          *Y88P*    *Y88P*  \t                                       88       \n";
		Sleep(500);
		cout << "\t                                                                                   .-~-.       \n";
		cout << "\t ,ad88888ba,                                                            .-~-.    .'     '.     \n";
		cout << "\t d8*'    `*8b                                                         .'     '. /         \\    \n";
		cout << "\t d8'                                                                 /         \\           ;   \n";
		cout << "\t 88            ,adPPYYba, 88,dPYba,,adPYba,   ,adPPYba,             :           ; .-~**~-, |   \n";
		cout << "\t 88      88888 **     `Y8 88P'   *88*    *8a a8P_____88             |           |/`        `.  \n";
		cout << "\t Y8,        88 aadPPPPP88 88      88      88 8PP*******             :           |            \\ \n";
		cout << "\t Y8a.    .a88  88,    ,88 88      88      88 *8b,   ,aa              \\         /             / \n";
		cout << "\t  `*Y88888P*   `*8bbdP*Y8 88      88      88  `*Ybbd8*'               `.     .' \\          .'  \n";
		cout << "\t                                                                        `~~~`    '-.____.-'    \n";
		cout << "#========================================================================================================#\n\n";
		Sleep(2000);
		cout << "Get ready, player " << k << endl;
		Sleep(500);
		cout << "1 : Start Game \n";
		Sleep(500);
		cout << "2 : Controls \n";
		Sleep(500);
		cout << "3 : Story \n";
		Sleep(500);
		cout << "4 : Credits \n";
		Sleep(500);
		cout << "Press any other key to Quit : \n";
		Sleep(500);
		cin >> choice;
		switch (choice)
		{
		case 1: setup();
			break;
		case 2: system("cls");
			cout << "The controls are simple.\nPress D to move right\nPress A to move left\nPress S to go down\nPress W to go up\n\nThat's all. Enjoy the game!\n";
			cout << "\n\n\nPress any button to go back";
			_getch();
			system("cls");
			goto backbutton;
			break;
		case 3: system("cls");
			cout << "STORY";
			cout << "\nEverything doesn't need a story to begin";
			cout << "\n\n\nPress any button to go back";
			_getch();
			system("cls");
			goto backbutton;
			break;
		case 4: system("cls");
			int ii, jj;

			for (ii = 0; ii < 5; ii++)
			{
				for (jj = 0; credit[ii][jj] != '\0'; jj++)
				{
					cout << credit[ii][jj];
					Sleep(50);
				}
				cout << endl;
			}
			//cout << "CREDITS - \n\nShabareesh Aryan \nS Subrahmanya \nLeander Mani \nS Rochan Kumar";

			for (ii = 0; ref1[ii] != '\0'; ii++)
			{
				cout << ref1[ii];
				Sleep(50);
			}
			cout << "\n\n\nPress any button to go back";
			_getch();
			system("cls");
			goto backbutton;
			break;
		default:system("cls");
			cout << "See you later, player.";
			_getch();
			exit(0);
		}
	}
};

int choose()
{
	int cho;
	cout << "Enter 1 to go back to main menu\nPress any other key to exit\n";
	cin >> cho;
	switch (cho)
	{
	case 1: system("cls");
		return cho;
		break;
	default: system("cls");
		cout << "You will be sent to main menu for playing as player 2, Press any key to exit from there";
		_getch();
		return 0;
		break;
	}
}
void store()
{
	system("cls");
	int count = 2;

	if (k == 1) {
		cout << "Your score is: " << score << ", " << p1 << endl;
		s1 = score;
	}
	if (k == 2) {
		cout << "Your score is: " << score << ", " << p2 << endl;
		s2 = score;
	}
	if (k == 3) {
		cout << "Your score is: " << score << ", " << p3 << endl;
		s3 = score;
	}
	Sleep(500);
}

int main()
{
	int choice = 0;
start:
	display screen;
	//setup game;
	while (!gameover)
	{

		Draw utility1;
		Input utility2;
		Logic counter;
		counter.EggFall();	//Egg falling
	}
	if (gameover)
		store();
	Sleep(500);
	if (k < 3)
	{
		choice = choose();
		if (choice == 1)
			k++;
		goto start;
	}
	else
	{
		result();
	}
	return 0;
}
