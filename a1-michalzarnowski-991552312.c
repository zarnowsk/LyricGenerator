//Assignment 1, Michal Zarnowski - 991552312

#include <stdio.h>

int acquireData(char members[], char animal[], char verseEnd[], int noOfVerses);
int extractFamilyMember(int currentMemberLen, int stringCounter, char tempMember[], char members[]);
void capitalizeMember(char tempMember[]);
void printVerse(char tempMember[], char animal[], char verseEnd[], int verseEndRepeats);

int main() {

    // Program vars
    int lenCounter = 0, stringCounter = 0, prevMemberLen = 0, currentMemberLen, verseEndRepeats, noOfVerses;
    char tempMember[15], members[100], animal[15], verseEnd[15];

    // Ask user for number of verses
    printf("How many verses would you like to compose?\n");
    scanf("%d", &noOfVerses);

    // If number of verses is greater than 0, continue execution
    if (noOfVerses > 0) {

        // Ask user for lyric input
        verseEndRepeats = acquireData(members, animal, verseEnd, noOfVerses);

        // COMPOSE THE LYRICS
        // Print title
        printf("\nHere are you lyrics:\n");

        // Loop through number of verses
        for (int i = 0; i < noOfVerses; i++) {

            // Get length of current family member
            while (members[lenCounter] != ';' && members[lenCounter] != '\n') {
                lenCounter++;
            }
            currentMemberLen = lenCounter - prevMemberLen - i; // i compensates for amount of semi-colons

            // Extract family member from input
            stringCounter = extractFamilyMember(currentMemberLen, stringCounter, tempMember, members);

            // Capitalize family member
            capitalizeMember(tempMember);

            // Print verse
            printVerse(tempMember, animal, verseEnd, verseEndRepeats);

            // Increment variables
            prevMemberLen += currentMemberLen;
            lenCounter++;
            stringCounter++;
        }
    }
    return 0;
}

int acquireData(char members[], char animal[], char verseEnd[], int noOfVerses) {

    // Ask for family members
    fflush(stdin); // flushing enter
    printf("Enter the %d family members separated by a semi-colon:\n", noOfVerses);
    fgets(members, 99, stdin);

    // Ask for the animal
    printf("Enter the animal to use in the song:\n");
    scanf("%s", animal);

    // Ask for the verse ending word
    printf("Enter the word to use for the ending of the verse:\n");
    scanf("%s", verseEnd);

    // Ask for the amount of verse ending word
    int verseEndRepeats;
    printf("How many times should it be displayed?\n");
    scanf("%d", &verseEndRepeats);

    return verseEndRepeats;
}

int extractFamilyMember(int currentMemberLen, int stringCounter, char tempMember[], char members[]) {
    for (int k = 0; k < 15; k++) {
        // Only extract amount of characters equal to length of current family member
        if (k < currentMemberLen) {
            tempMember[k] = members[stringCounter];
            stringCounter++;
        } else {
            // Fill rest of string with terminator characters
            tempMember[k] = '\0';
        }
    }

    return stringCounter;
}

void capitalizeMember(char tempMember[]) {
    // If first character's ascii value is bigger or equal to 'a'
    if ((int) tempMember[0] >= 97) {
        // Subtract 32 and cast to char to make it upper case equivalent
        tempMember[0] = (char) ((int) tempMember[0] - 32);
    }
}

void printVerse(char tempMember[], char animal[], char verseEnd[], int verseEndRepeats) {

    // Print line with repeated word
    for (int j = 0; j < 3; j++) {
        printf("\t"); //tab
        printf("%s %s,", tempMember, animal);
        // Repeated word
        for (int l = 0; l < verseEndRepeats; l++) {
            printf(" %s", verseEnd);
        }
        printf(".\n");
    }

    // Print verse end
    printf("\t%s %s!\n\n", tempMember, animal);
}
