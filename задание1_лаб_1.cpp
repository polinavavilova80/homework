/*задание 1                                                                                                  
1. strlen - в C++  std::string::length() или std::string::size() (для получения длины строки). 
2. strcpy - В C++  std::string::copy() или инициализация объекта std::string. 
3. strcmp - В C++  std::string::compare() (для сравнения строк). 
4. strcat - В C++ используется оператор + для конкатенации строк. 
5. someString[index] - В C++ someString.at(index) (для доступа к символу строки). 
6. push_back - В C++ std::string::push_back() (для добавления символа в конец строки). 
7.pop_back - В C++ std::string::pop_back() (для удаления последнего символа из строки). 
Главная разница между строками в C и C++ заключается в том, что строки в C - это массивы символов , когда в C++ есть стандартный класс std::string, который является более высокоуровневый и удобный интерфейс для работы со строками.*/


int main() { 
    std::string inputString; 
    std::cout << "Введите строку: "; 
    std::getline(std::cin, inputString); 
 
    std::string cleanedString;  // Удаляем пробелы и пунктуационные знаки из строки 
    for (char c : inputString) { 
        if (std::isalpha(c)) {  // Проверяем, является ли символ буквой 
            cleanedString += c; 
        } 
    } 
 
    std::sort(cleanedString.begin(), cleanedString.end()); // Сортируем буквы в строке 
 
    std::cout << "Отсортированная строка: " << cleanedString << std::endl; 
 
    return 0; 
}