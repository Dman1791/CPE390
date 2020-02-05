#include <iostream>
#include <cstring>
#include <cstdint>
using namespace std;
/*
  Author: Derek Kellerman
  Pledge: I pledge my honor that I have abided by the Stevens Honor System.
*/


void crypt(char msg[], uint32_t len, uint8_t key) {
	for(int i = 0; i < len; i++) {
		msg[i] = msg[i] ^ key;
	}
}

void dov(char msg2[], uint32_t len, char key[]) {
	int keyind = 0;
	for (int i = 0; i < len; i++) {
		if (key[keyind] == '\0')
			keyind = 0;
		msg2[i] = msg2[i] ^ key[keyind];
		keyind++;
	}
}

void print(char msg[], uint32_t len) {
	for (int i = 0; i < len; i++) {
		cout << +msg[i] << ' ';
	}
	cout << endl;
}

int main() {
	char msg[] = "hello";
	cout << "Normal Method" << endl;
	cout << "Original message: " << msg << endl;
	crypt(msg, 5, 13);
	cout << "Encrypted message as characters: " << msg << endl;
	cout << "Encrypted message as numbers: ";
	print(msg, 5);
	crypt(msg, 5, 13);
	cout << "Decrypted message: " << msg << endl << endl;
	
	cout << "DOV Method" << endl;
	char msg2[] = "This is a longer test. There are spaces and short words.";
	uint32_t len = strlen(msg2);
	cout << "Original message: " << msg2 << endl;
	dov(msg2, len, "Dov");
	cout << "Encrypted message as numbers: ";
	print(msg2, len); // print the buffer as integers (because some may not be printable). Note: this uses casting   uint8_t(msg2[i]) is a number 0..255
	dov(msg2, len, "Dov");
	cout << "Decrypted message: " << msg2 << endl;
}
