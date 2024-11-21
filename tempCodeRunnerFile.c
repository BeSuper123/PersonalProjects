            printf("\n\n\nGuess a Letter \n-----> ");
            scanf(" %c", &guessLetter);

            for (i = 0; i < length; i++) {
                if (guessLetter == word[i]) {
                    guessedWord[i] = guessLetter;;
                } else if (strcmp(guessedWord, word) == 0) {
                    win = 1;
                    break;
                }
            } 