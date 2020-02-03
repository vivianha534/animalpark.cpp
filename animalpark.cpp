//have to account for animals not being able to leave before they enter
//have to account for ccp and cpp
// have to account for spaces
//Cp doesn't work but CP does lower case p not working

#include <iostream>
#include <string>

using namespace std;

bool isValidAnimalParkString(string animalparkString) {

	bool valid = true;
	int sizeOfString = animalparkString.size();



	//returns false for empty string
	if (animalparkString.size() == 0) {
		return false;
	}

	int num_consecutive_animals = 1;
	int num_consecutive_people = 1;
	int num_consecutive_animals_people = num_consecutive_animals + num_consecutive_people;

	//checks the first letter of each string, changles value of bool valid to false if the first letter isn't C c D or d
	switch (animalparkString[0]) {
	case 'P':
		if (animalparkString [0]) {
			return false;
		}

		break;
	case 'C':
	case 'c':
	case 'D':
	case 'd':

	for (int i = 0; i < sizeOfString; i++) {
		num_consecutive_animals = 1;
		num_consecutive_people = 1;
		int num_consecutive_animals_people = num_consecutive_animals + num_consecutive_people;


			//checks if there is a p before any c's and d's
			if (i != 0 && tolower(animalparkString[i - 1]) == 'p') {
				return false;
			}

			//This accounts for if the character after i is not p
			while (tolower(animalparkString[i + num_consecutive_animals]) != 'p') {

				if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals]) == tolower(animalparkString[i])) {
					num_consecutive_animals++;
					continue;
				}
				else if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals]) == 'p') {
					i += num_consecutive_animals;

			
				}
				else {
					return false;
				}
				

				//make a statement to account for animalparkString[i +1] = p or change the condition of the while 

				//break;
			}
			//checks to see what is after p
			while (tolower(animalparkString[i + num_consecutive_animals] == 'p')) {
				//first if statement should account for if the next letter after p is p but it doesn't
				if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people]) == tolower(animalparkString[i + num_consecutive_animals])) {
					num_consecutive_people++;
					continue;
				}
				if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people]) == 'c') {
					return false;
				}
				else if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people]) == 'd') {
					return false;
				}
				// these 2 else if statements below need to account for if + or - is at the end (or address it in while loop for operators)
				else if (i != sizeOfString - 1 && animalparkString[i + num_consecutive_animals_people] == '+') {
					break;
				}
				else if (i != sizeOfString - 1 && animalparkString[i + num_consecutive_animals_people] == '-') {
					break;
				}
				else {
					return false;
				}
			}
			//break;

			//need while loop for things that come after operators
			while (animalparkString[i + num_consecutive_animals_people] == '+'|| animalparkString[i + num_consecutive_animals_people] == '-') {
				if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people + 1]) == 'c') {
					break;
				}
				else if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people + 1]) == 'd') {
					break;
				}
				else if (i != sizeOfString - 1 && tolower(animalparkString[i + num_consecutive_animals_people + 1]) == '""') {
					return false;
				}
				else {
					return false;
				}
			}
			
			

		return true;

	}
	default:
		return false;



		}
}

/*int dogsLeft(string animalparkString) {

}

int catsLeft(string animalparkString) {

}

int peopleLeft(string animalparkString) {

}
*/

int main() {

	cout.setf(ios::boolalpha);
	string animalparkString;
	getline(cin, animalparkString);
	cout << isValidAnimalParkString(animalparkString);

}


