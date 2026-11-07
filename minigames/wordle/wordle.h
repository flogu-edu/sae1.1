#include <iostream>
#include <cstdlib>
#include <ctime>

std::string getRandomWord(std::string wordList[], int size) {
    int randomNb = rand() % size;
    return wordList[randomNb];
}

std::string displayWordle(std::string letters[][5], int status[][5]) {
    for(int i = 0; i < 5; i++) {
        std::cout<<" | ";
        for(int j = 0; j < 5; j++) {
            switch (status[i][j]) {
                case 0:
                std::cout<<"\e[0;37m"<< letters[i][j]<<"\e[0m";
                break;
                case 1:
                    std::cout<<"\e[0;33m"<< letters[i][j] <<"\e[0m";
                    break;
                case 2:
                std::cout<<"\e[0;32m"<< letters[i][j] <<"\e[0m";
                break;
            }
        }
        std::cout<<" | "<<std::endl;
    }
    return "hello";
}

std::string getUserWord() {
    std::string userWord = "";

    bool isValidEntry = false;
    while (!isValidEntry) {
        std::cout<<"Please enter a 5 letters word : ";
        std::cin>>userWord;
        std::cout<<std::endl;
        
        if (userWord.length() != 5) {
            isValidEntry = false;
            std::cout<<"Your word has not 5 letters"<<std::endl;
        } else {
            isValidEntry = true;
        }
    }
    return userWord;
}

void clearWordle(std::string letters[][5], int status[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            letters[i][j] = "-";
            status[i][j] = 0;
        }
    }
}

void checkWord(int attempt, std::string userWord, std::string chosenWord,std::string letters[][5], int status[][5]) {
    for(int j = 0; j < 5; j++) {
        letters[attempt][j] = userWord[j];
        if(userWord[j] == chosenWord[j]) {
            status[attempt][j] = 2;
        } else {
            for(int k = 0; k < 5; k++) {
                if(userWord[k] == chosenWord[j]) {
                    status[attempt][j] = 1;
                    break;
                }
            }
        }
    }
}

bool isSuccess(int status[][5]) {
    int validLetters = 0;
    for(int i = 4; i >= 0; i--) {
        for(int j = 0; j < 5; j++) {
            if(status[i][j] == 2) {
                validLetters++;
            }
        }
        if(validLetters >= 5) {
            return true;
        }
        validLetters = 0;
    }
    return false;
}

void wordle() {
    srand(time(0));

    std::string wordList[] = {
        "hello",
        "world",
        "apple",
        "house",
        "water",
        "chair",
        "table",
        "bread",
        "light",
        "night",
        "green",
        "black",
        "white",
        "smile",
        "happy",
        "music",
        "piano",
        "beach",
        "cloud",
        "dream",
        "plant",
        "stone",
        "flame",
        "grape",
        "lemon",
        "peach",
        "snake",
        "tiger",
        "horse",
        "sheep",
        "mouse",
        "train",
        "plane",
        "truck",
        "river",
        "ocean",
        "earth",
        "space",
        "heart",
        "brain",
        "clock",
        "phone",
        "water",
        "candy",
        "pizza",
        "cream",
        "bread",
        "dance",
        "laugh",
        "write",
        "trump",
        "gayyy"
    };

    std::string chosenWord = getRandomWord(wordList, 52);

    std::string letters[5][5];
    int status[5][5];
    
    int attempt = 0;
    clearWordle(letters, status);

    std::string userWord = "";

    while (attempt < 5 && !isSuccess(status)) {
        displayWordle(letters, status);
        userWord = getUserWord();
        checkWord(attempt, userWord, chosenWord, letters, status);
        attempt++;
    }

    if (attempt >= 5) {
        std::cout<<"You loose, the word was : "<<chosenWord<<std::endl;
    }

    if (isSuccess(status)) {
        std::cout<<"You won, the word was : "<<chosenWord<<std::endl;
    }
}