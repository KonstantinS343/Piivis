
#include "game.h"

/// \file game_field.cpp
/// \brief содержит методы игрвого поля

/** @defgroup game_field game_field.cpp
 * Игровой поле
 * @{
 */

///\brief метод создания игрового поля
/// \author Konstantsin
/// \see std::pair<int,int> points_of_empty
/// \see std::vector<std::vector<int>> pattern_of_winners_set
/// \see std::vector<std::vector<Cell>> field
/// \see int size_of_field
/// \see bool CheckCellOnRepetition(int number)
/// \see int CheckInputNumber()
/// \see game_field.cpp
void GameField::CreateField() {

    srand(time(NULL));
    std::cout<<"Please, enter the margin side size: ";
    size_of_field = CheckInputNumber();
    while(size_of_field<2 || size_of_field > 10){
        std::cout<<"Oops, that input is invalid.  Please try again!\n";
        size_of_field = CheckInputNumber();
    }
    system("./cls.sh");
    pattern_of_winners_set.resize(size_of_field);
    field.resize(size_of_field);
    int counter=1;

    for(int i = 0; i < size_of_field; i++){
        for(int j = 0; j < size_of_field; j++){
            pattern_of_winners_set.at(i).push_back(counter);
            counter++;
        }
    }
    pattern_of_winners_set.at(size_of_field-1).at(size_of_field-1)=0;

    int CheckExistValue=rand()% (size_of_field*size_of_field-1)+1;
    for(int i = 0; i < size_of_field; i++){
        for(int j = 0; j < size_of_field; j++){
            while(!CheckCellOnRepetition(CheckExistValue)){
                CheckExistValue = rand()% (size_of_field*size_of_field);
            }
                if(CheckExistValue == 0){
                    points_of_empty.first = i;
                    points_of_empty.second = j;
                }
                Cell cell;
                cell.number = CheckExistValue;
                cell.points.first=i;
                cell.points.second = j;
                field.at(i).push_back(cell);
        }
    }

}

///\brief проверка на расстановку клеток без повторения
/// \param number принимает рандомно сгенерированное число, которое нужно поместить в игровую клетку
/// \return true, если такого числа на поле нет, и false, если такое число уже имеется
/// \author Konstantsin
/// \see int size_of_field;
/// \see std::vector<std::vector<Cell>> field
/// \see game_field.cpp
bool GameField::CheckCellOnRepetition(int number) {

    for(int i = 0; i <= size_of_field; i++){
        for(int j = 0; j < size_of_field; j++){
            if(field.at(i).empty() || field.at(i).size()-1<j){
                return true;
            }
            if(field.at(i).at(j).number==number){
                return false;
            }
        }
    }
    return true;

}

///\brief метод вывода поля на экран
/// \author Konstantsin
/// \see int size_of_field;
/// \see std::vector<std::vector<Cell>> field
/// \see std::vector<Cell> operator [](int index)
/// \see game_field.cpp
void GameField::ShowField() {

    for(int i = 0; i < size_of_field; i++){
        for(int k = 0; k < size_of_field; k++){
            std::cout<<"\t"<<" "<<"\t"<<"|";
        }
        std::cout<<std::endl;
        for(int j = 0; j < size_of_field; j++){
            std::cout<<"\t"<<field[i].at(j).number<<"\t"<<"|";
        }
        std::cout<<std::endl;
        for(int k = 0; k < size_of_field; k++){
            std::cout<<"\t"<<" "<<"\t"<<"|";
        }
        std::cout<<std::endl;
        for(int k = 0; k < size_of_field; k++){
            std::cout<<"----------------";
        }
        std::cout<<std::endl;
    }

}

///\brief проверка на ввод для чисел
/// \return возвращает число, которое необходимо проверить
/// \author Konstantsin
/// \throw exception при неправильном вводе
/// \see game_field.cpp
int GameField::CheckInputNumber() {

    int choice;
    std::cin>>choice;

    do{
        try{
            if(choice==0){
                throw std::exception();
            }
            else{
                return choice;
            }
        }catch (std::exception& exception){
            std::cin.clear();
            std::cin.ignore(255,'\n');
            std::cout<<"Oops, that input is invalid.  Please try again!\n";
            std::cin>>choice;
        }
    } while (true);

}

///\brief очищает поле
/// \author Konstantsin
/// \see std::vector<std::vector<Cell>> field
/// \see int counter_of_move
/// \see std::vector<std::vector<int>> pattern_of_winners_set
/// \see game_field.cpp
void GameField::DeleteField() {

    for(int i = 0; i < size_of_field; i++){
        field.at(i).clear();
        pattern_of_winners_set.at(i).clear();
    }
    field.clear();
    pattern_of_winners_set.clear();

    counter_of_move = 0;

}

///\brief проверка на возможность выиграть при поле со стороной 2
/// \return true, если выиграть нельзя, и false, если можно
/// \author Konstantsin
/// \see  int size_of_field
/// \see std::vector<std::vector<Cell>> field
/// \see  game_field.cpp
/// \see play_game.cpp
bool GameField::CheckUnpossibleWin() {
    if(size_of_field != 2){
        return false;
    }else{
        if(field.at(0).at(0).number==1 && field.at(1).at(0).number==2 && field.at(1).at(1).number==3){
            std::cout<<"This combination cannot be solved.Start a new game!\n";
            return true;
        }else if(field.at(0).at(1).number==3 && field.at(1).at(0).number==1 && field.at(1).at(1).number==2){
            std::cout<<"This combination cannot be solved.Start a new game!\n";
            return true;
        }else if(field.at(1).at(1).number==1 && field.at(0).at(1).number==2 && field.at(0).at(0).number==3){
            std::cout<<"This combination cannot be solved.Start a new game!\n";
            return true;
        }else if(field.at(1).at(0).number==3 && field.at(0).at(1).number==1 && field.at(0).at(0).number==2){
            std::cout<<"This combination cannot be solved.Start a new game!\n";
            return true;
        }
    }
    return false;
}
/** @} */