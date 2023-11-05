#include <iostream> 
#include <vector> 
#include <string> 
#include <map> 
#include <algorithm> 
 
// Функция для инициализации векторов 
void InitializeVectors(std::vector<std::string>& names, std::vector<int>& grades) { 
    int choice; 
    std::cout << "Выберите способ инициализации векторов:\n"; 
    std::cout << "1. Демонстрационный анализ на дефолтных входных значениях\n"; 
    std::cout << "2. Анализ на случайных входных значениях\n"; 
    std::cout << "3. Анализ на входных значениях от пользователя\n"; 
    std::cin >> choice; 
 
    if (choice == 1) { 
        names = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank", "Ivy", "Jack"}; 
        grades = {85, 90, 78, 92, 88, 85, 90, 78, 92, 88}; 
    } else if (choice == 2) { 
        int size; 
        std::cout << "Введите размер выборки: "; 
        std::cin >> size; 
        names.resize(size); 
        grades.resize(size); 
        for (int i = 0; i < size; i++) { 
            std::cout << "Введите имя и оценку для студента " << i + 1 << ": "; 
            std::cin >> names[i] >> grades[i]; 
        } 
    } else if (choice == 3) { 
        int size; 
        std::cout << "Введите размер выборки: "; 
        std::cin >> size; 
        names.resize(size); 
        grades.resize(size); 
        for (int i = 0; i < size; i++) { 
            std::cout << "Введите имя и оценку для студента " << i + 1 << ": "; 
            std::cin >> names[i] >> grades[i]; 
        } 
    } 
} 
 
// Функция для вывода содержимого вектора с использованием range-based for-loop 
void PrintVectorWithRangeFor(const std::vector<int>& vec) { 
    std::cout << "Содержимое вектора: "; 
    for (const auto& value : vec) { 
        std::cout << value << " "; 
    } 
    std::cout << std::endl; 
} 
 
// Функция для подсчета среднего значения оценок 
double CalculateAverage(const std::vector<int>& grades) { 
    int sum = 0; 
    for (int grade : grades) { 
        sum += grade; 
    } 
    return static_cast<double>(sum) / grades.size(); 
} 
 
// Функция для подсчета медианы оценок 
double CalculateMedian(const std::vector<int>& grades) { 
    std::vector<int> sortedGrades = grades; 
    std::sort(sortedGrades.begin(), sortedGrades.end()); 
    int size = sortedGrades.size(); 
    if (size % 2 == 0) { 
        return (static_cast<double>(sortedGrades[size / 2 - 1]) + static_cast<double>(sortedGrades[size / 2])) / 2.0; 
    } else { 
        return static_cast<double>(sortedGrades[size / 2]); 
    } 
} 
 
// Функция для подсчета моды оценок 
std::vector<int> CalculateMode(const std::vector<int>& grades) { 
    std::map<int, int> gradeCount; 
    for (int grade : grades) { 
        gradeCount[grade]++; 
    } 
 
    int maxCount = 0; 
    for (const auto& pair : gradeCount) { 
        if (pair.second > maxCount) { 
            maxCount = pair.second; 
        } 
    } 
 
    std::vector<int> modeGrades; 
    for (const auto& pair : gradeCount) { 
        if (pair.second == maxCount) { 
            modeGrades.push_back(pair.first); 
        } 
    } 
 
    return modeGrades; 
} 
 
int main() { 
    std::vector<std::string> names; 
    std::vector<int> grades; 
 
    InitializeVectors(names, grades); 
 
    // Вывод содержимого вектора оценок с использованием range-based for-loop 
    PrintVectorWithRangeFor(grades); 
 
    // Вывод среднего значения 
    double average = CalculateAverage(grades); 
    std::cout << "Среднее значение оценок: " << average << std::endl; 
 
    // Вывод медианы 
    double median = CalculateMedian(grades); 
    std::cout << "Медиана оценок: " << median << std::endl; 
 
    // Вывод моды 
    std::vector<int> modeGrades = CalculateMode(grades); 
    std::cout << "Мода оценок: "; 
    for (int grade : modeGrades) { 
        std::cout << grade << " "; 
    } 
    std::cout << std::endl; 
 
    return 0; 
}
