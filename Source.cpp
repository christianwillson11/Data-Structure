#include "Gelas.h"
#include "Wadah.h"
#include <stdlib.h>
#include <time.h>

//single linked list -> generate random number
node<int>* generateNumber(int how_many,int *_length,int pj) {
	node<int>* head;
	node<int>* tail;
	node<int>* temp;

	node<int>* head2;
	node<int>* tail2;
	node<int>* temp2;

	head = tail = NULL;
	head2 = tail2 = NULL;
	
	srand(time(NULL));
	int x = rand() % 1 + 3;

	for (int i = 0; i < how_many; i++) {
		/*cout << _length[i] << " " << endl;*/
		for (int j = 0; j < _length[i]; j++) {
			
			temp = new node<int>;
			temp->data = i + x;
			
			/*cout << temp->data;*/
			temp->next = NULL;
			
			if (head == NULL) {
				head = temp;
				tail = temp;
			} else {
				tail->next = temp;
				tail = temp;
			}
		}
	}

	/*while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}*/

	int count = 0;
	int lain = 0;
	for (int i = 0; i <= pj; i++) {
		lain = lain + _length[i];
	}

	int asd = lain;
	/*cout << "How many : " << how_many << endl;
	cout << lain << endl;*/

	srand(time(0));
	while(count < asd) {
		temp = head;
		int y = rand() % (asd);

		/*cout << y << endl;*/
		
		for (int j = 0; j <= y; j++) {
			temp2 = new node<int>;

			if (j == y && temp->data != -1) {
				/*cout << "sukses" << endl;*/
				temp2->data = temp->data;
				/*cout << temp2->data << endl;*/
				temp2->next = NULL;

				if (head2 == NULL) {
					head2 = temp2;
					tail2 = temp2;
				}
				else {
					tail2->next = temp2;
					tail2 = temp2;
				}
				temp->data = -1;
				count++;
				break;
			}
			temp = temp->next;
		}
	}

	return head2;
}


Wadah<Gelas> setRound(int &jumlah,int *panjang,int &angka) { //Untuk mengenerate wadah yang ingin digunakan seperti gelas-gelas beserta dengan angka-angkanya.
	Wadah<Gelas> aa;
	srand(time(NULL));

	//generate random number 
	int random_num = rand() % 7 + 3;
	cout << "Total gelas: " << random_num << "\n";

	int co = 0, jumlah_gls_cadangan = 0;

	if (random_num <= 4)
		jumlah_gls_cadangan = 1;
	else
		jumlah_gls_cadangan = 2;

	node<int>* dt = new node<int>;
	while (co != random_num - jumlah_gls_cadangan) {
		int sesuatu = rand() % 5 + 3;
		panjang[angka] = sesuatu;
		angka++;
		co++;
	}
	

	dt = generateNumber(random_num - jumlah_gls_cadangan,panjang,angka-1);
	
	//---
	node<int>* temp = dt;

	int panjang_buat_array = 0;
	co = 0;
	while (co != random_num - jumlah_gls_cadangan) {
		Gelas gelas;
		for (int i = 0; i < panjang[panjang_buat_array]; i++) {
			gelas.push(dt->data,true);
			dt = dt->next;
		}
		aa.enqueue(gelas);
		panjang_buat_array++;
		co++;
	}

	cout << co << " gelas terisi" << endl;
	jumlah = co;

	co = 0;
	while (co != jumlah_gls_cadangan) {
		Gelas gelas;
		panjang[angka] = 5;
		angka++;
		for (int i = 0; i < 5; i++) {
			gelas.push(0,true);
			/*Matthew 7 : 7 Ask, and it shall be given you; seek, and ye.shall find; knock, and it shall be opened unto you :*/
		}
		aa.enqueue(gelas);
		co++;
	}

	cout << co << " gelas cadangan" << endl;
	jumlah += co;
	aa.print(panjang);

	return aa;
}


int main() {

	int jml_gelas = 0;
	int *panjang_main = new int [15];
	int angka = 0;

	Wadah<Gelas> aa = setRound(jml_gelas,panjang_main,angka);

	bool status = false;
	bool lose = false;
	int selector_one, selector_two;
	int score = 0,move = 0,nyawa = 3;

	while (status != true) {


		cout << "Pilih gelas 1: (input 0 jika ingin menambah gelas; -1 jika ingin new game; -2 jika ingin menukar gelas) "; cin >> selector_one;
		
		if (selector_one == 0) {
			char chc;
			cout << "Notes : Jika Score bernilai kurang dari 50 maka nyawa akan berkurang satu. Apakah anda setuju ? (Y/N) ";
			cin >> chc;
			if (chc == 'Y' || chc == 'y') {
				Gelas gelas;
				if (score >= 50) {
					for (int i = 0; i < 5; i++) {
						gelas.push(0,true);
					}
					panjang_main[angka] = 5;
					angka++;
					aa.enqueue(gelas);
					jml_gelas++;
					system("CLS");
					move++;
					score -= 50;
					cout << "Score : " << score << endl;
					cout << "Move : " << move << endl;
					cout << "Nyawa : " << nyawa << endl;
					aa.print(panjang_main);
				}
				else if (nyawa > 1) {
					for (int i = 0; i < 5; i++) {
						gelas.push(0,true);
					}
					panjang_main[angka] = 5;
					angka++;
					aa.enqueue(gelas);
					jml_gelas++;
					system("CLS");
					move++;
					nyawa--;
					cout << "Score : " << score << endl;
					cout << "Move : " << move << endl;
					cout << "Nyawa : " << nyawa << endl;
					aa.print(panjang_main);
				}
				else {
					system("cls");
					cout << "Score Tidak Mencukupi" << endl;
					cout << "Score : " << score << endl;
					cout << "Move : " << move << endl;
					cout << "Nyawa : " << nyawa << endl;
					aa.print(panjang_main);
				}
			}
			else {
				system("cls");
				cout << "Silahkan melanjutkan permainan" << endl;
				cout << "Score : " << score << endl;
				cout << "Move : " << move << endl;
				cout << "Nyawa : " << nyawa << endl;
				aa.print(panjang_main);
			}
		}

		else if (selector_one == -1) {
			system("CLS");
			aa.newGame();
			angka = 0;
			aa = setRound(jml_gelas, panjang_main,angka);
			score = 0;
			move = 0;
			nyawa = 3;
		}
		else if (selector_one == -2) {
			system("CLS");
			int firstglass, secondglass;
			aa.print(panjang_main);
			cout << "Masukkan gelas mana yang ingin ditukar : ";cin>> firstglass;
			cout << "Masukkan gelas mana yang ingin dituju : "; cin >> secondglass;
			aa.pindahGelas(firstglass,secondglass);
			aa.copyData(panjang_main);
			system("CLS");
			aa.print(panjang_main);
		}

		else {
			if (selector_one < -1 || selector_one > jml_gelas) {
				system("cls");
				cout << "Error : Input Salah" << endl;
				nyawa--;
				cout << "Score : " << score << endl;
				cout << "Move : " << move << endl;
				cout << "Nyawa : " << nyawa << endl;
				aa.print(panjang_main);
			}
			else {
				cout << "Ingin dipindahkan ke gelas: "; cin >> selector_two;
				if (selector_two > jml_gelas || selector_two < 1) {
					system("cls");
					cout << "Error : Gelas tidak tersedia" << endl;
					nyawa--;
					cout << "Score : " << score << endl;
					cout << "Move : " << move << endl;
					cout << "Nyawa : " << nyawa << endl;
					aa.print(panjang_main);
				}
				else {
					system("CLS");
					aa.accessData(selector_one);
					aa.moveData(selector_two, selector_one, score, nyawa);
					move++;
					cout << "Score : " << score << endl;
					cout << "Move : " << move << endl;
					cout << "Nyawa : " << nyawa << endl;
					aa.print(panjang_main);
				}
			}

			system("PAUSE");

			status = aa.checkWin();

			if (nyawa == 0) { //kalau nyawa habis, game over.
				lose = true;
				break;
			}
		}
		

	}
	system("cls");
	cout << "====== FINAL RESULT ======" << endl;
	Gelas gelasrekap;
	int co = 0;
	int co2 = 0;
	while (co != jml_gelas) {
		gelasrekap = aa.dequeue();
		if (gelasrekap.isEmpty() == false) {
			gelasrekap.print();
			co2++;
			cout << endl;
		}

		co++;
	}

	if (lose == true) {
		cout << "You LOSE!" << endl;
		cout << "Score Akhir : " << score << endl;
		cout << "Move : " << move << endl;
	}
	else {
		cout << "YOU WIN!" << endl;
		cout << "Score Akhir : " << score << endl;
		cout << "Move : " << move << endl;
	}
	

	return 0;
}