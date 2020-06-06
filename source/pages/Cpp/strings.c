#include <string.h>

int main()
{
	// The end delimiter of an array of chars is always '\0'
	char word[6] = {'G','u','i','t','a','r'};

	// We can define multi-dimentionnal arrays like that
	char week[7][9];

	strcpy(week[0], "Lundi");
	strcpy(week[1], "Mardi");
	strcpy(week[2], "Mercredi");
	strcpy(week[3], "Jeudi");
	strcpy(week[4], "Vendredi");
	strcpy(week[5], "Samedi");
	strcpy(week[6], "Dimanche");

	strlen(word); // The length of word is 6

	switch(strcmp(week[0], week[1])) {

		case 0: // week[0] == week[1]
			break;
		case -1: // week[0] < week[1]
			break;
		case 1: // week[0] > week[1]
			break;
	}
}
	