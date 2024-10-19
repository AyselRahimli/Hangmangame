//Bu bir soztapma oyunudu, demeli eger sozde duz herfi tapirsa good, amma tapa bilmirse yasama sansi azalir. Sonda da olur
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define MaxTry 11 // En uzun sozum programming 11 herfdi
#define MaxLength 50
char list[7][MaxLength] = {"ayselka", "library", "chess", "success", "programming","life","books"};
//Demeli, burda sozu secirsen oradan soz herfleri lazimdi ki biz bilek ki soz duz deyilir ya yox.
//Function 1
int Wordfromlist(char *word){
    int index = rand()%7;
    strcpy(word,list[index]);
    return strlen(word);
}

//Indi meselen 5 herf varsa, _ _ _ _ _ goruntusu versin isteyirem
//Function2
void ShowWord(char *word, char *letter_guess){
    for (int i=0;i<strlen(word);i++){
        if(strchr(letter_guess, word[i])!=NULL){
            printf("%c ", word[i]);
        }
        else{
            printf("_ ");
        }
    }
    printf("\n");
}

//Sozun tapilmasi hissesini function kimi yazmaq
//Function 3
int Guess(char *word, char *letter_guess){
    for (int i=0;i<strlen(word);i++){
        if (strchr(letter_guess, word[i]) == NULL){
            return 0; //Butun soz tapilmayib hele
        }
    }
    return 1; // Burda butun soz tapilib ona gore exit verir.
}

//Oyunun qurulmasi
int main(){
    srand(time(0));
    char word[MaxLength];
    char letter_guess[MaxLength];
    int attempts;
    char decision;
    printf("Hello dear friend! Welcome to new game project by Aysel Rahimli\n");
    printf("\nHANGMAN GAME\n");
    do
    {
        attempts = 5; //Azalda da bilerik oyunu cetinlesdirmek ucun
        int wordlen = Wordfromlist(word);
        //Burda memsetden istifade eledim cunki burda array yaratmaliyam hamisini da 0a beraber etmeliyem ki herf yazdiqca kod duzgun islesin 
        memset(letter_guess,0,sizeof(letter_guess));

        while (1){// Oyun davam etdikce loop tekrar edecek
            printf("\nBe careful dude! You have just %d attempts left.\n",attempts);
            ShowWord(word,letter_guess);

            char guess;
            printf("Enter a letter: \n");
            scanf(" %c",&guess);

            if (strchr(letter_guess,guess)!=NULL){// Meselen library sozunde r iki defedi ozu avtomatik yerine qoyacaq. r ni bir de yazmirsan 
                printf("You already guessed. Try again bro\n");
                continue;
            }
            letter_guess[strlen(letter_guess)] = guess;
            if (strchr(word,guess) == NULL){
                printf("False!\n");// Sehv etdikce daha az sansin qalir
                attempts--;
            }
            else{
                printf("True!\n");
            }

            if (Guess(word, letter_guess)){
                printf("\nCongrats! You guessed the word: %s\n",word);
                break;
            }
        
            if (attempts==0){
                printf("\nSorry, no more attempt. The word was %s\n",word);
            }
        }
        //Tekrar oynamaq ucun while do etdim.
        printf("\nDo you wanna play again? (Yes = Y/No = N):");
        scanf(" %c",&decision);
    } while (decision == 'Y' || decision == 'y');
    
    printf("\nThanks for playing friend! See you soon.\n");
    return 0;
}
