/*
 * Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H


class Menu {
public:
    /**
    * constructor of Menu
    */
    Menu();
    /**
     * this function accept the player choises of which game he want to play and which size the board should be
     */
    void chooseFromMenu();
    /**
     *
     * @param choise is kind of game to play
     * @param size is the size of the board
     */
    void startGame(int choise, int size);

};


#endif //UNTITLED_MENU_H
