#include <iostream>
#include <vector>
#include <cmath>
#include <time.h> 

using namespace std;

vector<int> ParseNumber(int numberEnterUser)
{
    vector <int> numbersArray;
    while(numberEnterUser != 0)
    {
        numbersArray.push_back(numberEnterUser%10);
        numberEnterUser/=10;
    }  
    return numbersArray; 
}

void printVector(vector<int> numbers){
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

//bublesort
vector<int> bubbleSort(vector<int> mas) {
    for (int i = 0; i < mas.size(); i++)    
        for (int j = 0; j < mas.size()-i-1; j++)
            if (mas[j] > mas[j+1]){
                int temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;    
            }
    return mas;
}

vector<int> reverseBubbleSort(vector<int> mas) {
    for (int i = 0; i < mas.size(); i++)    
        for (int j = 0; j < mas.size()-i-1; j++)
            if (mas[j] < mas[j+1]){
                int temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;    
            }
    return mas; 
}

bool checkEqual(vector<int> numSize, vector<int> numbersSize) {
    for (size_t i = 0; i < numSize.size(); i++) 
        if(numSize[i] != numbersSize[i]) return false;  
    return true;
}

vector<int> createSize(vector<int> empl){
    vector <int> size (10, 0);
    for (size_t i = 0; i < size.size(); i++)
        for (size_t j = 0; j < empl.size(); j++)
            if(i == empl[j]) size[i]++;
    return size;
}

bool checkEgnition(int num, vector<int> numbers) {
    vector <int> sizeNumbers = createSize(numbers);
    vector <int> sizeNum = createSize(ParseNumber(num));
    return checkEqual(sizeNum, sizeNumbers);
}

int createNumFromVector(vector<int> numbers) {
    int num = 0;
    for (size_t i = 0; i < numbers.size(); i++)
        num += numbers[i] * pow(10, numbers.size() - i - 1);
    return num;
}

void shaker(vector<int>numbersArray) {
    int num = createNumFromVector(numbersArray);
    vector<int> maxNumberArray = reverseBubbleSort(numbersArray);
    int maxNumber = createNumFromVector(maxNumberArray);
    vector <int> all;
    int count = 0;
    int countMiss = 0;
    while(num <= maxNumber) {
        if(checkEgnition(num, numbersArray))
        {
            all.push_back(num);
            count++;
        }
        num += 9;
        countMiss++;
    }
    printVector(all);
    cout << "\nCOUNT: " << count << endl;
    cout << "\nЛишних итераций: " << countMiss << endl;
    
}

int main () {
    int numberEnterUser;
    cout << "Ведите число: ";
    cin >> numberEnterUser;
    vector<int> numberArray = ParseNumber(numberEnterUser);
    clock_t start = clock();
    shaker(bubbleSort(numberArray));
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << seconds << endl;
    
}
