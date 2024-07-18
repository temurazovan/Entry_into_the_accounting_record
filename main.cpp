#include <iostream>
#include <fstream>

bool dateValidation(std::string date) {
    int dots = 0;
    for (int i = 0; i < date.length(); i++) {
        if (date[i] == '.') {
            dots++;
        }
    }
    if (dots != 2) {
        std::cout << "error input";
        return false;
    }

    int day = std::stoi(date.substr(0, 2));
    int month;

    if (date[0] == '0' || (day >= 10 && day <= 31)) {
        month = std::stoi(date.substr(3, 2));
    } else if (day > 0 && day < 10 && date[0] != '0') {
        month = std::stoi(date.substr(2, 2));
    } else {
        std::cout << "error input";
        return false;
    }

    if (month < 0 || month > 12) {
        std::cout << "error input";
        return false;
    }

    return true;
}

int main() {
    std::ofstream file("../list.txt", std::ios::app);
    std::string name;
    std::string surname;
    std::string payStr;
    std::string date;

    if (!file) {
        std::cout << "Error";
        return 0;
    }
    std::cin >> name >> surname >> payStr >> date;
    int pay = std::stoi(payStr);

    if (pay < 0) {
        std::cout << "Payment entered incorrectly";
        return 0;
    }

    if (!dateValidation(date)) {
        return 0;
    }

    char buf[100];
    snprintf(buf, 100, "\n%s %s %d %s\n", name.c_str(), surname.c_str(), pay, date.c_str());
    file << buf;

    file.close();

    return 0;
}
