#include <iostream>

using namespace std;


int Max10(int Number)
{
return (Number > 10) ? 10 : Number;
}

int main()
{
	int Deck[52] = { 0, };

	for (int i = 0; i < 52; ++i)
	{
		Deck[i] = (i % 13) + 1;
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 52 * 2; ++i)
	{
		int FirstNumber = rand() % 52;
		int SecondNumber = rand() % 52;
		int Temp = Deck[FirstNumber];
		Deck[FirstNumber] = Deck[SecondNumber];
		Deck[SecondNumber] = Temp;
	}

	int Player[3] = { 0, };
	int Ai[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		Player[i] = Deck[i * 2]; //0 2 4
		Ai[i] = Deck[(i * 2) + 1]; //1 3 5
	}

	int Playersum = 0;
	int Aisum = 0;

	for (int i = 0; i < 3; ++i)
	{
		Playersum = Playersum + Max10(Player[i]);// 0 = 3 , 1= 2, 2=3
		Aisum += Max10(Ai[i]);
	}
	cout << "Player :" << Playersum << endl;
	cout << "Ai :" << Aisum << endl;
 	if (Aisum > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (Aisum <= 21 && Playersum <= 21)
	{
		if (Playersum >= Aisum)
		{
			cout << "Player Win" << endl;
		}
		else
		{
			cout << "Ai win" << endl;
		}
	}
	else
	{
		cout << "Ai win" << endl;
	}

		return 0;
}
	