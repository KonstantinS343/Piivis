
/// \file play_game.cpp
/// \brief содержит сам игровой процесс

#include "game.h"

/** @defgroup play_game play_game.cpp
 * Игровой процесс
 * @{
 */

///\brief процесс игры
/// \author Konstantsin
/// \see void CreateField()
/// \see void ShowField()
/// \see void DeleteField()
/// \see std::pair<int,int> points_of_empty
/// \see std::vector<std::vector<Cell>> field
/// \see int size_of_field
/// \see int number
/// \see std::pair<int,int> points
/// \see char CheckInputChar()
/// \see bool CheckWinnerSet()
/// \see play_game.cpp
void GameField::PlayProcess() {

    CreateField();
    ShowField();
    char move_process;
    int buffer_number;
    bool exit = false;

    if(CheckWinnerSet()== true){
        std::cout<<"\n\nCONGRATULATIONS!\nYou won in "<<counter_of_move<<" moves!\n\n";
        exit = true;
    }

    if(!CheckUnpossibleWin() && exit==false){
        std::cout<<"Please, enter a 'w', 'a', 's', 'd', in order to move empty cell (0) or 'e', \nin order to exit (register is not important): ";
        move_process = CheckInputChar();
    }
    else{
        exit = true;
    }

    while (!exit){
        switch (move_process) {
            case 'w':
            case 'W':
                if(points_of_empty.first==0){
                    std::cout<<"\nYou are out of bounds. Please, try again!\n";
                    move_process = CheckInputChar();
                    continue;
                }
                buffer_number = field.at(points_of_empty.first-1).at(points_of_empty.second).number;
                field.at(points_of_empty.first-1).at(points_of_empty.second).number=0;
                field.at(points_of_empty.first).at(points_of_empty.second).number=buffer_number;
                points_of_empty.first = points_of_empty.first-1;
                counter_of_move++;
                break;
            case 'a' :
            case 'A':
                if(points_of_empty.second==0){
                    std::cout<<"\nYou are out of bounds. Please, try again!\n";
                    move_process = CheckInputChar();
                    continue;
                }
                buffer_number = field.at(points_of_empty.first).at(points_of_empty.second-1).number;
                field.at(points_of_empty.first).at(points_of_empty.second-1).number = 0;
                field.at(points_of_empty.first).at(points_of_empty.second).number = buffer_number;
                points_of_empty.second = points_of_empty.second-1;
                counter_of_move++;
                break;
            case 's':
            case 'S':
                if(points_of_empty.first==size_of_field-1){
                    std::cout<<"\nYou are out of bounds. Please, try again!\n";
                    move_process = CheckInputChar();
                    continue;
                }
                buffer_number = field.at(points_of_empty.first+1).at(points_of_empty.second).number;
                field.at(points_of_empty.first+1).at(points_of_empty.second).number=0;
                field.at(points_of_empty.first).at(points_of_empty.second).number=buffer_number;
                points_of_empty.first = points_of_empty.first+1;
                counter_of_move++;
                break;
            case 'd':
            case 'D':
                if(points_of_empty.second==size_of_field-1){
                    std::cout<<"\nYou are out of bounds. Please, try again!\n";
                    move_process = CheckInputChar();
                    continue;
                }
                buffer_number = field.at(points_of_empty.first).at(points_of_empty.second+1).number;
                field.at(points_of_empty.first).at(points_of_empty.second+1).number = 0;
                field.at(points_of_empty.first).at(points_of_empty.second).number = buffer_number;
                points_of_empty.second = points_of_empty.second+1;
                counter_of_move++;
                break;
            case 'e':
            case 'E':
                exit = true;
                system("./cls.sh");
                continue;
            default:
                break;
        }
        system("./cls.sh");
        ShowField();
        if(CheckWinnerSet()== true){
            std::cout<<"\n\nCONGRATULATIONS!\nYou won in "<<counter_of_move<<" moves!\n\n";
            exit = true;
            continue;
        }
        if(!CheckUnpossibleWin()){
            std::cout<<"Please, enter a 'w', 'a', 's', 'd', in order to move empty cell (0) or 'e', \nin order to exit (register is not important): ";
            move_process = CheckInputChar();
        }
        else{
            exit = true;
        }
    }

    DeleteField();

}

///\brief проверка на ввод для символов
/// \return возвращает символ, которое необходимо проверить
/// \author Konstantsin
/// \throw exception при неправильном вводе
/// \see play_game.cpp
char GameField::CheckInputChar() {

    char symbol;
    std::cin>>symbol;

    while(symbol!=119 && symbol!=97 && symbol!=115 && symbol!=100 && symbol!=87 && symbol!=65 && symbol!=83 && symbol!=68 && symbol!= 101 && symbol!=69){
        std::cin.clear();
        std::cin.ignore(255,'\n');
        std::cout<<"Oops, that input is invalid.  Please try again!\n";
        std::cin>>symbol;
    }

    return symbol;

}

/// \brief оператора индексирования,для просмотра элемента
/// \param index принимает индекс вектора, который нужно вернуть
/// \return вектор строк, который состоит из клеток поля
/// \author Konstantsin
/// \see std::vector<std::vector<Cell>> field
/// \see play_game.cpp
std::vector<GameField::Cell> GameField::operator[](int index) {

    if(index<0 && index>size_of_field){
        throw std::exception();
    }

    return field.at(index);

}

/** @} */