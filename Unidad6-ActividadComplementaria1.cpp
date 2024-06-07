#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

struct Record {
    int id;
    std::string name;
    double salary;
};

bool compareById(const Record& a, const Record& b) {
    return a.id < b.id;
}

void sequentialSearch(const std::vector<Record>& database, int targetId) {
    int conditions = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& record : database) {
        conditions++;
        if (record.id == targetId) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Sueldo encontrado: " << record.salary << "\n";
            std::cout << "Condiciones evaluadas: " << conditions << "\n";
            std::cout << "Tiempo tomado: " << duration.count() << " segundos\n";
            return;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "ID no encontrado.\n";
    std::cout << "Condiciones evaluadas: " << conditions << "\n";
    std::cout << "Tiempo tomado: " << duration.count() << " segundos\n";
}

void binarySearch(const std::vector<Record>& database, int targetId) {
    int conditions = 0;
    auto start = std::chrono::high_resolution_clock::now();

    int left = 0;
    int right = database.size() - 1;
    while (left <= right) {
        conditions++;
        int mid = left + (right - left) / 2;
        if (database[mid].id == targetId) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Sueldo encontrado: " << database[mid].salary << "\n";
            std::cout << "Condiciones evaluadas: " << conditions << "\n";
            std::cout << "Tiempo tomado: " << duration.count() << " segundos\n";
            return;
        }
        if (database[mid].id < targetId)
            left = mid + 1;
        else
            right = mid - 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "ID no encontrado.\n";
    std::cout << "Condiciones evaluadas: " << conditions << "\n";
    std::cout << "Tiempo tomado: " << duration.count() << " segundos\n";
}

void loadData(const std::string& filename, std::vector<Record>& database) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return;
    }

    Record record;
    while (file >> record.id >> record.name >> record.salary) {
        database.push_back(record);
    }
    file.close();
}

int main() {
    std::vector<Record> database;
    loadData("2021_04_3_AGUASCALIENTES.txt", database);

    int targetId = 276638993;

    std::cout << "Busqueda Secuencial:\n";
    sequentialSearch(database, targetId);

    std::sort(database.begin(), database.end(), compareById);

    std::cout << "Busqueda Binaria:\n";
    binarySearch(database, targetId);

    char continueSearch;
    do {
        std::cout << "Desea realizar otra busqueda binaria? (s/n): ";
        std::cin >> continueSearch;
        if (continueSearch == 's' || continueSearch == 'S') {
            std::cout << "Ingrese el ID a buscar: ";
            std::cin >> targetId;
            binarySearch(database, targetId);
        }
    } while (continueSearch == 's' || continueSearch == 'S');

    return 0;
}
