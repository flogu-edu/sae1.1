#include <iostream>
#include <string>

void creerGrille(int tailleGrille, int tailleCase, std::string tab[][100]){
    int Morpion = (tailleGrille * tailleCase) + (tailleGrille - 1);
    int x = tailleCase + 1 ;

    for (int i = 0; i < Morpion; i++){
        for (int j = 0; j < Morpion; j++){
            bool separationLigne = (i % x == tailleCase); 
            bool separationColonne = (j % x == tailleCase);

            if(separationLigne && !separationColonne){
                tab[i][j] = "-" ;
            }
            else if(separationColonne && !separationLigne){
                tab[i][j] = "|" ;
            }
            else if (separationColonne && separationLigne){
                tab[i][j] = "+" ;
            }
            else{
                tab[i][j] = "*"; 
            }
        }
    }
}

void afficherGrille(int tailleGrille, int tailleCase, std::string tab[][100]){
    int Morpion = (tailleGrille * tailleCase) + (tailleGrille - 1);
    for (int i = 0; i < Morpion; i++){
        for (int j = 0; j < Morpion; j++){
            std::cout<<tab[i][j];
        }
        std::cout<<std::endl;
    }
}

void jouerCroix(int posX, int posY,  int tailleGrille, int tailleCase, unsigned int Croix, std::string tab[][100]){
    int posfinalX ;
    int posfinalY ;
    int pas = tailleCase + 1 ;

    if (posX < 1 || posX > tailleGrille || posY < 1 || posY > tailleGrille){
        std::cout << "Case invalide" << std::endl;
        return;
    }
    if (Croix < 1 || 2 * Croix - 1 > tailleCase){
        std::cout << "Taille de croix invalide" << std::endl;
        return;
    }

    if (tailleCase % 2 == 1) {
        posfinalX = (posX - 1) * pas + tailleCase / 2;
        posfinalY = (posY - 1) * pas + tailleCase / 2;
    }
    else {
        posfinalX = (posX - 1) * pas + (tailleCase-1) / 2;
        posfinalY = (posY - 1) * pas + (tailleCase-1) / 2;
    }

    int posdecalX = posfinalX;
    int posdecalY = posfinalY;

    tab[posfinalX][posfinalY] = 'X';
    for( int j = 0; j < (Croix - 1); j++){
        posdecalX = posdecalX + 1 ;
        posdecalY = posdecalY + 1 ;
        tab[posdecalX][posdecalY] = 'X';
    }
    posdecalX = posfinalX ;
    posdecalY = posfinalY ;
    for( int j = 0; j < (Croix - 1); j++){
        posdecalX = posdecalX - 1 ;
        posdecalY = posdecalY - 1 ;
        tab[posdecalX][posdecalY] = 'X';
    }
    posdecalX = posfinalX ;
    posdecalY = posfinalY ;
    for( int j = 0; j < (Croix - 1); j++){
        posdecalX = posdecalX + 1 ;
        posdecalY = posdecalY - 1 ;
        tab[posdecalX][posdecalY] = 'X';
    }
    posdecalX = posfinalX ;
    posdecalY = posfinalY ;
    for( int j = 0; j < (Croix - 1); j++){
        posdecalX = posdecalX - 1 ;
        posdecalY = posdecalY + 1 ;
        tab[posdecalX][posdecalY] = 'X';
    }
    afficherGrille(tailleGrille, tailleCase, tab);
}

void jouerCercle(int posX, int posY,  int tailleGrille, int tailleCase, unsigned int Cercle, std::string tab[][100]){
    int posfinalX ;
    int posfinalY ;
    int pas = tailleCase + 1 ;

    if (posX < 1 || posX > tailleGrille || posY < 1 || posY > tailleGrille){
        std::cout << "Case invalide" << std::endl;
        return;
    }
    if (Cercle < 1 || 2 * Cercle - 1 > tailleCase){
        std::cout << "Taille de cercle invalide" << std::endl;
        return;
    }

    if (tailleCase % 2 == 1) {
        posfinalX = (posX - 1) * pas + tailleCase / 2;
        posfinalY = (posY - 1) * pas + tailleCase/ 2;
    }
    else {
        posfinalX = (posX - 1) * pas + (tailleCase - 1) / 2;
        posfinalY = (posY - 1) * pas + (tailleCase - 1) / 2;
    }

    int posdecalX = posfinalX;
    int posdecalY = posfinalY;
    int x = Cercle - 1 ;

    if(Cercle == 1){
        tab[posfinalX][posfinalY] = 'O';
    }
    else {
        for( int j = 0 - x; j <= x; j++){
            posdecalX = posfinalX + j ;
            posdecalY = posfinalY + x ;  
            tab[posdecalX][posdecalY] = 'O';
        }

        for( int j = 0 - x; j <= x; j++){
            posdecalX = posfinalX + j ;
            posdecalY = posfinalY - x ;  
            tab[posdecalX][posdecalY] = 'O';
        }

        for( int j = 0 - x; j <= x; j++){
            posdecalX = posfinalX - x ;
            posdecalY = posfinalY + j ;  
            tab[posdecalX][posdecalY] = 'O';
        }

        for( int j = 0 - x; j <= x; j++){
            posdecalX = posfinalX + x ;
            posdecalY = posfinalY + j ;
            tab[posdecalX][posdecalY] = 'O';
        }
    }
    afficherGrille(tailleGrille, tailleCase, tab);
}

bool jouerPossible(int posX, int posY, int tailleCase, unsigned int Croix, unsigned int Cercle,  std::string tab[][100]){
    int posfinalX ;
    int posfinalY ;
    int pas = tailleCase + 1 ;
    
    if (tailleCase % 2 == 1) {
        posfinalX = (posX - 1) * pas + tailleCase / 2;
        posfinalY = (posY - 1) * pas + tailleCase/ 2;
    }
    else {
        posfinalX = (posX - 1) * pas + (tailleCase - 1) / 2;
        posfinalY = (posY - 1) * pas + (tailleCase - 1) / 2;
    }
    
    if((tab[posfinalX - (Croix - 1)][posfinalY- (Croix - 1)] == "X" || tab[posfinalX - (Cercle - 1)][posfinalY - (Cercle - 1)] == "O")){
        return false ;
    }
    else{
        return true ;
    }
}

bool debutPartie(int & tailleGrille, int & tailleCase, std::string tab[][100], std::string & Jouer, unsigned int & Croix, unsigned int & Cercle){
    int posX = 0 ;
    int posY = 0;
    int taille = (tailleGrille * tailleCase);

    if(taille > 100){
    std::cout<<"Taille de la grille ?" <<std::endl;
    std::cin>>tailleGrille;

    std::cout<<"Taille de chaque case ?" <<std::endl;
    std::cin>>tailleCase;

    creerGrille(tailleGrille, tailleCase, tab);

    std::cout<<"Qui commence ?" <<std::endl;
    std::cin>>Jouer;

    if(Jouer == "Croix" || Jouer == "croix"){
        std::cout<<"Taille de la Croix ?"<<std::endl;
        std::cin>>Croix;
            
        std::cout<<"Quelle ligne ?" <<std::endl;
        std::cin>>posX;

        std::cout<<"Quelle colonne ?" <<std::endl;
        std::cin>>posY;
        jouerCroix(posX, posY, tailleGrille, tailleCase, Croix, tab);
        return true ;
    }
    else if(Jouer == "Cercle" || Jouer == "cercle"){
        std::cout<<"Taille du cercle ?"<<std::endl;
        std::cin>>Cercle;
        
        std::cout<<"Quelle ligne ?" <<std::endl;
        std::cin>>posX;

        std::cout<<"Quelle colonne ?" <<std::endl;
        std::cin>>posY;
        jouerCercle(posX, posY, tailleGrille, tailleCase, Cercle, tab);
        return false ;
    }
    else{
        return debutPartie(tailleGrille, tailleCase, tab, Jouer, Croix, Cercle);
    }
    }
}

void Partie(int & posX, int & posY,  int & tailleGrille, int & tailleCase, unsigned int & Cercle, unsigned int & Croix, std::string tab[][100], std::string Jouer){
    debutPartie(tailleGrille, tailleCase, tab, Jouer, Croix, Cercle);
    int x = (debutPartie(tailleGrille, tailleCase, tab, Jouer, Croix, Cercle));
    for( int i = 0 ; i < (3 * (tailleGrille*tailleGrille)); i++){
        if(x == 0){
            std::cout<<"Taille de la Croix ?"<<std::endl;
            std::cin>>Croix;
            
            std::cout<<"Quelle ligne ?" <<std::endl;
            std::cin>>posX;

            std::cout<<"Quelle colonne ?" <<std::endl;
            std::cin>>posY;
            if(jouerPossible(posX, posY, tailleCase, Croix, Cercle, tab) == 1 ){
                jouerCroix(posX, posY, tailleGrille, tailleCase, Croix, tab);
            }
            else{
                std::cout<<"Impossible"<<std::endl;
            }
        }
        else{
            std::cout<<"Taille du cercle ?"<<std::endl;
            std::cin>>Cercle;
        
            std::cout<<"Quelle ligne ?" <<std::endl;
            std::cin>>posX;

            std::cout<<"Quelle colonne ?" <<std::endl;
            std::cin>>posY;
            if(jouerPossible(posX, posY, tailleCase, Croix, Cercle, tab) == 1 ){
                jouerCercle(posX, posY, tailleGrille, tailleCase, Cercle, tab);
            }
            else{
                std::cout<<"Impossible"<<std::endl;
            }
        }
    }
}

int tictacstack()
{
    std::string tab[100][100];
    //std::string Jouer ;
    unsigned int tailleGrille = 5 ;
    unsigned int tailleCase = 3 ;
    unsigned int Croix = 0 ;
    unsigned int Cercle = 0 ;
    int posX = 0;
    int posY = 0;

    creerGrille(tailleGrille, tailleCase, tab);
    afficherGrille(tailleGrille, tailleCase, tab);

    //Partie(posX, posY, tailleGrille, tailleCase, Cercle, Croix, tab, Jouer);
}
