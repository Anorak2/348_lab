#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int arr1[100][100], arr2[100][100], storage[100][100];
int arr_size = -1;

// I could write something much cleaner, but ¯\_(ツ)_/¯
int createArray(){
    std::ifstream myfile;
    myfile.open("/home/adam/CLionProjects/348_lab_2/matrix.txt");
    std::string myline;
    int count = 0, arr1_pos = 0, arr2_pos = 0;
    while ( myfile ) {
        std::getline (myfile, myline);
        if(count == 0){
            arr_size = stoi(myline);
        }
        else if(count <= arr_size){
            int n, pos = 0;
            std::istringstream is( myline );
            while ( is >> n){
                arr1[arr1_pos][pos] = n;
                pos++;
            }
            arr1_pos++;
        }
        else{
            int n, pos = 0;
            std::istringstream is( myline );
            while ( is >> n){
                arr2[arr2_pos][pos] = n;
                pos++;
            }
            arr2_pos++;
        }
        count++;
    }
    return 0;
}

int printArrays(){
    std::cout << "\nMatrix A:\n";
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            std::cout << arr1[x][y] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\nMatrix B:\n";
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            std::cout << arr2[x][y] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printStorage(){
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            std::cout << storage[x][y] << " ";
        }
        std::cout << "\n";
    }
}

int sum(){
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            storage[x][y] = arr1[x][y] + arr2[x][y];
        }
    }
    std::cout << "\nMatrix Sum (A+B):\n";
    printStorage();
}

int multiply(){
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            int temp = 0;
            for(int z = 0; z < arr_size; z++){
                temp += arr1[x][z] * arr2[z][y];
            }
            storage[x][y] = temp;
        }
    }
    std::cout << "\nMatrix Product (A*B):\n";
    printStorage();
    return 0;
}

int diff(){
    for(int x = 0; x < arr_size; x++){
        for(int y = 0; y < arr_size; y++){
            storage[x][y] = arr1[x][y] - arr2[x][y];
        }
    }
    std::cout << "\nMatrix difference (A-B):\n";
    printStorage();
    return 0;
}

int main (){
    createArray();
    printArrays();
    sum();
    multiply();
    diff();
    return 0;
}
