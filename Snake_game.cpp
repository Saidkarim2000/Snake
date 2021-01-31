#include"Snake.h"

using namespace std;

int main() {
	int choice = 100;
	char y;
	Game myGame;
	Game* r = new Game(); // New local variable r for Game is needed in order to enable Restart command
	while (choice != 3)
	{
		Menu:
		system("cls");
		cout << "\t\t\t\t\t\tWelcome to the Snake!!!\n\n\n " << endl;

		cout << "Input 1: Start" << endl;
		cout << "Input 2: Rule" << endl;
		cout << "Input 3: Quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		 
			// Due to this commands the game is called
			
			myGame.Setup();
			while (!myGame.G_O) {
				myGame.Map();
				myGame.Input();
				myGame.Logic();
				cout << "\t\t\t\t\t\t\tPress p to Pause " << endl;
			}
			char y;
			cout << "You LOSE!!!" << endl;
			cout << "To restart press Y, but it is allowed only one time!" << endl;
			cout << "Press e to exit" << endl;
			cin >> y;
			if (y == 'y')
			{
				goto Restart;
			}
			else
				goto Menu;
		Restart: {
			r->Setup();
			while (!r->G_O) {
				r->Map();
				r->Input();
				r->Logic();
				cout << "\t\t\t\t\t\t\tPress p to Exit " << endl;
			}}

			
		case 2:
			cout << "The main rule is don't eat the tail of the Snake, otherwise you are gonna Lose!!! " << endl;
			system("pause");
			break;
			
		
		case 3:
		default:
			cout << "Goodbye!!!" << endl;
			break;

		}
		
	}


	system("pause");
	return 0;
}