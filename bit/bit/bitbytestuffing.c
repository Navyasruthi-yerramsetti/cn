Bit stuffing
#include <stdio.h>
#include <string.h>
void bitStuffing(char data[]) 
{
    char stuffed[100];
    int i, j = 0, count = 0;
    for(i = 0; i < strlen(data); i++) 
{
        stuffed[j++] = data[i];
        if(data[i] == '1) 
        {
            count++;
            if(count == 5) 
           {
                stuffed[j++] = '0'; // Stuff a '0' after five 1s
                count = 0;
            }
        } 
      else 
      {
            count = 0;
        }
    }
    stuffed[j] = '\0';
    printf("Stuffed Data: %s\n", stuffed);
}
int main() {
    char data[50];
    printf("Enter binary data (e.g., 01111110111): ");
    scanf("%s", data);
    bitStuffing(data);
    return 0;
}

Byte / Character Stuffing
#include <stdio.h>
#include <string.h>
#define FLAG ‘$'
#define ESC  ‘&’
void characterStuffing(char data[]) {
    char stuffed[200];
    int i, j = 0;
    // Add starting FLAG
    stuffed[j++] = FLAG;
    for (i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            stuffed[j++] = ESC;  // Add escape character
        }
        stuffed[j++] = data[i];  // Add actual data
    }
    // Add ending FLAG
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';
    printf("Stuffed Frame: %s\n", stuffed);
}
int main() {
    char data[100];
    
    printf("Enter input data (e.g., AEFG): ");
    scanf("%s", data);
    characterStuffing(data);
    return 0;
}

