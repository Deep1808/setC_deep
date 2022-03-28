#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check_phone_number(char phone[]);
void generate(char filename[], char phone[]);
void generate_char(FILE *file, char phone[], char word[], int index, int length);

int main()
{
	char phone[128];	
	char word[128];
	char filename[128];
printf("Enter the 7-digit phone number (no 0 or 1): ");
scanf("%s", phone);

check_phone_number(phone);

printf("Enter the name of the file to save results: ");
scanf("%s", filename);

generate(filename, phone);

printf("The words are saved into %s.\n", filename);

return 0;

}

void check_phone_number(char phone[]) {

int i;

if (strlen(phone) != 7) {
	printf("The phone number must be 7 digits (no 0 and 1).\n");
	exit(-1);
		}
	for (i = 0; phone[i] != '\0'; i++) {
	if (phone[i] < '2' || phone[i] > '9') {
	printf("The phone number must be 7 digits (no 0 and 1).\n");
	exit(-1);
	}
}
}

void generate(char filename[], char phone[]) {
FILE *file;
char word[8];
file = fopen(filename, "w");
word[7] = '\0';
generate_char(file, phone, word, 0, strlen(phone));
fclose(file);

}

void generate_char(FILE *file, char phone[], char word[], int index, int length) {

static char *mappings[] = {"" ,"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

if (index == length) {
fprintf(file, "%s\n", word);
} else {
int offset = phone[index]-'0';
char *mapping = mappings[offset];

while (*mapping != '\0') {
word[index] = *mapping;
generate_char(file, phone, word, index + 1, length); /* check next digit */
mapping ++;

}

}

}
