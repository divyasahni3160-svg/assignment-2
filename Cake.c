#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void clear() {
    system("cls");
}

void wait() {
    printf("\nPress ENTER to continue...");
    getchar();
}

int main() {
    int choice;
    char again;

    do {
        int score = 0;
        clear();
        printf("=====================================\n");
        printf("          CAKE MAKING GAME\n");
        printf("=====================================\n\n");

        printf("You are going to bake a cake!\n\n");
        wait();

        clear();
        printf("Step 1: What do you do first?\n");
        printf("1. Mix flour, sugar, and eggs\n");
        printf("2. Turn on the oven\n");
        printf("3. Eat the ingredients\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            printf("Correct! You mixed the ingredients.\n");
            score++;
        } else {
            printf("Wrong! You ruined the cake.\n");
            goto END_GAME;
        }
        wait(); clear();

        printf("Step 2: What next?\n");
        printf("1. Put the bowl in the freezer\n");
        printf("2. Pour mixture into a cake pan\n");
        printf("3. Add ketchup\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 2) {
            printf("Correct! Looks good.\n");
            score++;
        } else {
            printf("Wrong! That doesn't belong in a cake.\n");
            goto END_GAME;
        }
        wait(); clear();

        printf("Step 3: What do you do now?\n");
        printf("1. Preheat the oven to 180C\n");
        printf("2. Put pan on your head\n");
        printf("3. Add toothpaste\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            printf("Correct! Oven is heating up.\n");
            score++;
        } else {
            printf("Wrong! The cake is ruined.\n");
            goto END_GAME;
        }
        wait(); clear();

        printf("Step 4: Next step?\n");
        printf("1. Bake the cake for 30 minutes\n");
        printf("2. Water the cake like a plant\n");
        printf("3. Throw it out the window\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            printf("Correct! It’s baking...\n");
            score++;
        } else {
            printf("Wrong! Cake destroyed.\n");
            goto END_GAME;
        }
        wait(); clear();

        printf("Step 5: Your cake is ready! Final step?\n");
        printf("1. Frost it with chocolate icing\n");
        printf("2. Paint it white\n");
        printf("3. Add soap for flavor\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            printf("Perfect! Your cake is delicious!\n");
            score++;
        } else {
            printf("Nooo! You ruined the final step.\n");
            goto END_GAME;
        }

        printf("\n🎉 YOU WIN! You made a perfect cake! 🎉\n");
        printf("Your score: %d / 5\n", score);
        goto ASK_AGAIN;

END_GAME:
        printf("\n💀 GAME OVER! Cake failed.\n");
        printf("Your score: %d / 5\n", score);

ASK_AGAIN:
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &again); getchar();

    } while (again == 'y' || again == 'Y');

    printf("\nThanks for playing the Cake Making Game!\n");
    return 0;
}
