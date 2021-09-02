#pragma once

#include <iostream>

using namespace std;

template <typename T>

struct node {
	T data;
	node<T>* next;
	node<T>* prev;
};


class Gelas {
private:
	//node<int>* head;
	node<int>* tail;
	node<int>* empty_space;
	int size, length;
public:

	Gelas() {
		//head = NULL;
		tail = NULL;
		size = 0;
	}

	bool isEmpty() {
		if ( tail == NULL || tail->data == 0 ) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(int num, bool init) { 	
		
		if (num != 0) {
			length++;
		}

		node<int>* temp = new node<int>;

		temp->data = num;
		temp->next = tail;

		if (init == true) {
			size++;
			tail = temp;
			empty_space = temp;
		}

		else {
			node<int>* blok = new node<int>;
			temp = empty_space;

			if (empty_space == tail) {
				while (temp != NULL) {
					blok = temp;
					temp = temp->next;
				}
			}
			else {
				while (temp != tail) {
					if (temp->data == 0) {
						blok = temp;
					}
					temp = temp->next;
				}
			}

			blok->data = num;
			tail = blok;
		}
		
	}

	int pop() {
		if (isEmpty()) {
			cout << "STACK IS EMPTY";
			return false;
		}

		length--;

		int result;

		node<int>* temp = new node<int>;

		temp = tail;
		result = temp->data;

		tail = temp->next;

		temp->data = 0;

		if (empty_space == tail) {
			empty_space = temp;
		}
		return result;
	}

	// peek data (hanya melihat data bukan mem-pop)
	// gunanya untuk mengecek data berikutnya adalah angka berapa
	int peek() {
		if (isEmpty() == false) {
			return tail->data;
		}
		else {
			return false;
		}
	}

	bool checkStackSimilarity() { //Untuk mengecek apakah data dalam gelas sama.
		if (isEmpty()) {
			return true;
		}

		int check_number;
		node<int>* temp = tail;

		check_number = temp->data;

		while (temp != NULL) {
			if (temp->data != check_number)
				return false;
			temp = temp->next;
		}
		return true;
	}

	int getLength() {
		return length;
	}
	
	int getSize() {
		return size;
	}


	bool checkLength(int num_check,int &nyawa) { //Untuk mengecek apakah gelas sudah penuh atau tidak. Mirip dengan kegunaan isFull(). Digunakan di wadah.h
		if (length + num_check <= size) {
			return true;
		}
		cout << "BOTTLE IS FULL!\n";
		nyawa--;
		return false;
	}

	bool checkSameNumber(int number_nya,int &nyawa) { //Untuk Mengecek apakah data dalam gelas memiliki kesamaan.Digunakan di wadah.h
		if (peek() == number_nya || isEmpty()) {
			return true;
		}
		cout << "NOT THE SAME NUMBER!\n";
		nyawa--;
		return false;
	}


	void print() {

		node<int>* temp = new node<int>;

		temp = tail;
		
		int arr[15], co = 0;

		while (temp != NULL) {
			arr[co] = temp->data;
			temp = temp->next;
			co++;
		}

		for (int i = 0; i < size; i++) {
			cout << char(205) << " ";
		}
		cout << endl;


		if (isEmpty() == false) {
			for (int i = 0; i < co; i++) {
				if (arr[i] == 0) {
					cout << " " << " ";
				}
				else {
					cout << arr[i] << " ";
				}
			}
		}

		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << char(205) << " ";
		}

	}
};