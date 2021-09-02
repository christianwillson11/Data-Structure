#include "Gelas.h";

template <class T>
class Wadah {
private:
	int length;
	int _panjangmsg[15];
	node<T>* head;
	node<T>* tail;
	node<T> *firstsomething;
	node<int>* head_num;
	node<int>* tail_num;
	int num_length;

public:

	Wadah() {
		head = NULL;
		tail = NULL;
		length = 0;

		head_num = NULL;
		tail_num = NULL;
		num_length = 0;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}

		return false;
	}

	void enqueue(T data) {
		node<T>* temp = new node<T>;

		temp->data = data;
		temp->prev = NULL;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			//tambahan
			head->prev = tail;
		}

		length++;
	}

	T dequeue() {
		if (isEmpty() == false) {
			node<T>* temp = new node<T>;


			temp = head;

			T result = head->data;
			if (head->next != NULL) {
				head = head->next;

				head->prev = NULL;

				delete[] temp;
			}


			return result;
		}
	}

	//pos = position = (index) -> start from 1
	void accessData(int pos) {		//Untuk melihat data
		node<T>* temp = new node<T>;
		node<int>* num_temp = new node<int>;

		temp = head; // wadah temp, gelas temp , num temp

		for (int i = 1; i <= length; i++) {
			if (i == pos) {
				firstsomething = temp;
				int x = temp->data.pop();

				num_temp->data = x;
				num_temp->next = NULL;

				head_num = num_temp;
				tail_num = num_temp;
				num_length++;

				while (temp->data.peek() == x && num_length < _panjangmsg[i-1]) {
					temp->data.pop();
					num_temp->data = x;
					num_temp->next = NULL;

					tail_num->next = num_temp;
					tail_num = num_temp;
					num_length++;
				}
				break;
			}
			temp = temp->next;
		}
	}

	void moveData(int pos, int first_bottle,int &score,int &nyawa) { //Untuk memindah data dari 1 gelas ke gelas lain.
		//tujuan,asal,score,nyawa;
		node<T>* temp = new node<T>;
		node<int>* num_temp = new node<int>;
		bool error_check = true;
		int banyak_maju_mundur = abs(pos - first_bottle);

		//temp = head;
		temp = firstsomething;
		num_temp = head_num;

		if (pos > first_bottle) {
			int kaunter = 0;
			while (kaunter != banyak_maju_mundur) {
				temp = temp->next;
				kaunter++;
			}
			if (kaunter == banyak_maju_mundur) {
				if (temp->data.checkLength(num_length, nyawa) && temp->data.checkSameNumber(num_temp->data, nyawa)) {
					for (int i = 1; i <= num_length; i++) {
						temp->data.push(num_temp->data, false);
						score += 10;
						num_temp = num_temp->next;
					}
					tail_num = NULL;
					head_num = NULL;
					num_length = 0;
					error_check = false;
				}
			}
		}

		else if (pos < first_bottle) {
			int kaunter = 0;
			while (kaunter != banyak_maju_mundur) {
				temp = temp->prev;
				kaunter++;
			}
			if (kaunter == banyak_maju_mundur) {
				if (temp->data.checkLength(num_length, nyawa) && temp->data.checkSameNumber(num_temp->data, nyawa)) {
					for (int i = 1; i <= num_length; i++) {
						temp->data.push(num_temp->data, false);
						score += 10;
						num_temp = num_temp->next;
					}
					tail_num = NULL;
					head_num = NULL;
					num_length = 0;
					error_check = false;
				}
			}
		}

		temp = firstsomething;
		num_temp = head_num;

		if (error_check == true) {
			for (int i = 1; i <= num_length; i++) {
				temp->data.push(num_temp->data, false);
				num_temp = num_temp->next;
			}

			tail_num = NULL;					
			head_num = NULL;
			num_length = 0;
			}
	}

	void print(int *panjang) {
		if (!isEmpty()) {
			node<T>* temp = new node<T>;
			temp = head;
			int co = 1;
			while (temp != NULL) {
				cout << " " << " " << " " << " " << " " << " " << endl;
				cout << "Gelas " << co << endl;
				_panjangmsg[co-1] = panjang[co - 1];
				/*cout << panjang[co - 1] << endl;*/
				temp->data.print();
				cout << endl;
				temp = temp->next;
				co++;
			}
		}
	}

	bool checkWin() { //Untuk memeriksa apakah kondisi menang telah tercapai. meresahkan ya bund
		node<T>* temp = new node<T>;
		temp = head;
		int counter = 0;
		while (temp != NULL) {
			if ((temp->data.checkStackSimilarity() == true) && (temp->data.getLength() != _panjangmsg[counter] && temp->data.getLength() != 0) ) {
				return false;
			}
			else if(temp->data.checkStackSimilarity() == false){
				return false;
			}
			counter++;
			temp = temp->next;
		}
		return true;
	}

	void copyData(int* panjang) {
		for(int i=0;i<length;i++){
			panjang[i] = _panjangmsg[i];
		}
		
	}

	void pindahGelas(const int satu, const int dua) { // masih misteri;
		node<T>* temp = new node<T>;
		node<T>* temp2 = new node<T>;
		temp = head;
		int majumundur = abs(dua - satu);

		for (int i = 1; i < satu; i++) {
			temp = temp->next;
		}

		temp2 = temp;

		if (dua > satu) {
			int kaunter = 0;
			while (kaunter != majumundur) {
				temp2 = temp2->next;
				kaunter++;
			}
			if (kaunter == majumundur) {
				Gelas a = temp->data;
				Gelas b = temp2->data;
				int c = _panjangmsg[satu - 1];
				_panjangmsg[satu - 1] = _panjangmsg[dua - 1];
				_panjangmsg[dua - 1] = c;
				temp2->data = a;
				temp->data = b;
				system("pause");
			}
		}

		else if (dua < satu) {
			int kaunter = 0;
			while (kaunter != majumundur) {
				temp2 = temp2->prev;
				kaunter++;
			}
			if (kaunter == majumundur) {
				Gelas a = temp->data;
				Gelas b = temp2->data;
				int c = _panjangmsg[satu -1];
				_panjangmsg[satu -1] = _panjangmsg[dua -1];
				_panjangmsg[dua -1] = c;
				temp2->data = a;
				temp->data = b;
				system("pause");
			}
		}
	};

	void deleteRear() {

		node<T>* temp = new node<T>;

		if (head == NULL || length == 0) {
			cout << "Error" << endl;
		}
		else if (head->prev == head) {
			delete[] head;
			head = NULL;
		}
		else {
			temp = tail;
			head->prev = tail->prev;
			tail = tail->prev;
			tail->next = NULL;
			delete[] temp;
		}

	}

	void newGame() { //Untuk menreset linked list dengan mendelete isi dari keseluruhan linked list.
		while (tail != head){
			deleteRear();
		}
		deleteRear();
	}

};