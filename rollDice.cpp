#include<iostream>
#include<stdlib.h>  // rand fonksiyonu için
#include<time.h>   // srand fonksiyonu için

using namespace std;

int choosePlayer(int &p1, int &p2, int &now);
void rollDice(int line, int& now);
void playerControl(int &now);
void primeNumberControl(int &now);
void lineChange(int &line, int &p1, int &p2, int &now);
void rollCounter(int line, int& r1, int& r2);


int main() {

	srand(time(NULL));

	int player1 = 0, player2 = 0, nowPlaying;  // Oyuncuların bulunduğu adım (step) ve anlık olarak oynayan oyuncu !
	int rollOne = 0, rollTwo = 0; // Zar sayacı
	int line = 0;  // Sıranın hangi oyuncuda olduğunu göster


	do{
		// Oyun başlamadıysa oyuncu seçimi ve sırayla değişimi
	if(line==0)
		line = choosePlayer(player1, player2, nowPlaying);
	else
		lineChange(line, player1, player2, nowPlaying);


	rollDice(line, nowPlaying);  // Oynayan oyuncu zar atıyor

	playerControl(nowPlaying);  // Gelinen adım iki basamaklı asal mı , yoksa 10'a bölünen bir sayı mı ?

	cout << "*************************************************" << endl;

	rollCounter(line, rollOne, rollTwo); // zar sayacı

	}while (nowPlaying < 100);


	cout << "Player 1 'in attigi toplam zar sayisi : " << rollOne << endl;
	cout << "Player 2 'nin attigi toplam zar sayisi : " << rollTwo << endl;
	cout << "Kazanan oyuncu . .  . PLAYER " << line << endl;

	
	return 0;
}


int choosePlayer(int &p1, int &p2, int &now) {

	int beginning;
	beginning = rand() % 2 + 1;

	cout << "Oyuna ilk baslayan : Player " << beginning << endl;

	if (beginning == 1)
		now = p1;

	else
		now = p2;

	return beginning;  // Burada dönen değer line' a atanır ve öncelik belirlenir .

}

void rollDice(int line,int &now) {

	cout << "Player " << line << " zar atiyor . . ." << endl;

	int roll;
	roll = rand() % 6 + 1;
	
	cout << "Atilan zar : " << roll << endl;

	now += roll;

	cout << "Player " << line << "  " << now << ". adima geldi " << endl;

}

void playerControl(int &now) {

	if (now>=10) {
	
		if (now % 10 == 0) {
			cout <<"TEBRIKLER "<< now << ". adim 10'a bolunebilen bir sayi ve 2 adim ileri gitmeye hak kazandi ;))) " << endl;
			now += 2;
			cout << "Su anki adim : " << now << endl;
		}

		else 
		primeNumberControl(now);  // Asal sayi kontrolü

	}

}

void primeNumberControl(int &now) {

	int sayac=0;

	for (int i = 1; i <= now / 2; i++) {

		if (now % i == 0)
			sayac++;

	}

	if (sayac == 1) {
		cout <<"MAALESEF "<< now << ". adim bir asal sayi ve bir adim geriye gidiniz :// " << endl;
		now -= 1;
		cout << "Su anki adim : " << now << endl;
	}
}

void lineChange(int &line,int &p1,int &p2,int &now) {

	++line;
	
	if (line % 2 == 0) {
		p1 = now;
		now = p2;
		line = 2;  // Player 1 ve Player 2 'yi yazdırırken dinamik olması için line'ı sürekli 1 ve 2 aralığında tutmak için .
	}
	else {
		p2 = now;
		now = p1;
		line = 1;   // Player 1 ve Player 2 'yi yazdırırken dinamik olması için line'ı sürekli 1 ve 2 aralığında tutmak için .
	}
}

void rollCounter(int line,int &r1,int &r2) {

	if (line == 1)
		r1++;
	else
		r2++;

}
