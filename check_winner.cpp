//
// Created by konstantin on 10.09.22.
//

#include "game.h"

///\file check_winner.cpp
/// \brief содержит метод проверки выиграша


/** @defgroup check_winner check_winner.cpp
 * Проверка на выигрыш
 * @{
 */

///\brief проверка на победу
/// \return true, если клетки расставлены правильно, и false, если это не так
/// \author Konstantsin
/// \see  int size_of_field
/// \see std::vector<std::vector<int>> pattern_of_winners_se
/// \see std::vector<std::vector<Cell>> field
/// \see  check_winner.cpp
bool GameField::CheckWinnerSet() {

    for(int i = 0; i < size_of_field; i++){
        for(int j = 0; j < size_of_field; j++){
            if(field.at(i).at(j).number != pattern_of_winners_set.at(i).at(j)){
                return false;
            }
        }
    }
    return true;

}
/** @} */