#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_COINS 10

typedef struct Coin {
    int value;
    int real;
} Coin;

typedef struct Duck {
    char *name;
    Coin* coins[MAX_COINS];
} Duck;

typedef struct Vault {
    Coin* coins[MAX_COINS];
    int value;
} Vault;

size_t coinPointer = 0;
Vault vault = {0};

void initVault() {
    vault.value = 0;
    for (int i = 0; i < MAX_COINS; i++) {
        vault.coins[i] = (Coin*) malloc(sizeof(Coin));
        vault.coins[i] -> value = rand() % 1000;
        vault.coins[i] -> real = 1;
        vault.value += vault.coins[i] -> value;
    }
}

void viewCoins(char* name, Coin** coins, size_t size) {
    printf("Coins present in the %s: ", name);
    for (int i = 0; i < size; i++) {
        printf("Coin %d: ", i);      
        printf("%d", (coins[i] -> value));
        printf(" ");
    }
    printf("\n");
}

int giveCoinToDuck(Duck *duck, int index) {
    if (vault.coins[index] -> real) {
        printf("Where do you want to place the stolen coin in the duck's coin pouch [0-%d]: \n", MAX_COINS-1);
        int indexDuck = 0;
        do {
            scanf("%d", &indexDuck); // oob?
        } while(indexDuck > MAX_COINS);
        duck -> coins[indexDuck] = vault.coins[index];
        coinPointer++;
        vault.value -= duck -> coins[indexDuck] -> value;
        vault.coins[index] = (Coin*) malloc(sizeof(Coin));
        vault.coins[index] -> real = 0;
        puts("Do you want the fake coin to take a value from the coin pouch or take on a new one (y/n): ");
        char c;
        do {
            scanf("%c",&c);
        } while(c != 'y' && c != 'n');
        if (c == 'y') {
            // prob cold use this to leak
            viewCoins("coin pouch", duck->coins, coinPointer);
            printf("Which value from the coin pouch do you want to use [0-%d]: \n", MAX_COINS-1);
            indexDuck = 0;
            do {
                scanf("%d", &indexDuck);
            } while(indexDuck > MAX_COINS);
            vault.coins[index] -> value = duck -> coins[indexDuck];
            vault.value += vault.coins[index] -> value;
        } else {
            printf("Enter the value you want the fake coin to have: \n");
            scanf("%d", &vault.coins[index] -> value);
            vault.value += vault.coins[index] -> value;
        }
        return 0;
    } else {
        printf("Stop right there %s! This coin is fake so you can't steal it again. Scroodge will be suspicious if he has no coins left. However you can modify its value, it currently holds value %p: \n", duck->name, &(vault.coins[index]->value));
       
        vault.value -= vault.coins[index] -> value;
        printf("Enter the value you want the fake coin to have: \n");
        scanf("%p", &(vault.coins[index])); // sus?
        vault.value += vault.coins[index] -> value;
        return 1;
    }
}

void win() {
    system("cat flag.txt");
    exit(0);
}

void stealCoins(Duck *duck) {
    int index = 0;
    printf("Enter the index of the coin you want to steal [0-%d]: \n", MAX_COINS-1);
    scanf("%d", &index); // oob?

    if (index > MAX_COINS) {
        printf("That's not a valid coin\n");
        return;
    }
    if (!giveCoinToDuck(duck, index)) {
        printf("Coins stolen successfully\n");
    }
}

void menu(Duck ducks[3]) {
    while (1) {
        printf("1. Steal coins\n");
        printf("2. View coins present in the vault\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the duck you want to steal coins for\n");
            printf("1. Huey\n");
            printf("2. Dewey\n");
            printf("3. Louie\n");
            scanf("%d", &choice);
            if (choice <= 0 || choice > 3) {
                printf("Invalid choice\n");
                continue;
            }
            stealCoins(&ducks[choice - 1]);
        } else if (choice == 2) {
            viewCoins("vault", vault.coins, MAX_COINS);
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }
}

int main() {
    srand(time(NULL));
    initVault();
    Coin coinPouch[MAX_COINS] = {0};
    
    Duck huey = {"Huey", coinPouch};
    Duck dewey = {"Dewey", coinPouch};
    Duck louie = {"Louie", coinPouch};

    printf("Help Huey, Dewey and Louie get rich by stealing coins from the vault without Scroodge noticing! Try to replace the coins you stole by fake ones to prevent him from noticing\n");

    printf("Vault value: %d\n", vault.value);
    Duck ducks[3] = {huey, dewey, louie};
    menu(ducks);

    return 0;
}
