// CornerGrocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequencies;

    string ToLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    ItemTracker() {
        LoadData();
    }

    void LoadData() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        if (!inFile) {
            cerr << "Error: Unable to open input file!" << endl;
            return;
        }

        string item;
        while (getline(inFile, item)) {
            item = ToLower(item);  // Convert to lowercase before storing
            itemFrequencies[item]++;
        }
        inFile.close();
    }

    int GetItemFrequency(string item) {
        item = ToLower(item);  // Convert to lowercase before searching
        if (itemFrequencies.find(item) != itemFrequencies.end()) {
            return itemFrequencies[item];
        }
        return 0;
    }

    void PrintFrequencies() {
        for (const auto& pair : itemFrequencies) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram() {
        for (const auto& pair : itemFrequencies) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

void DisplayMenu() {
    cout << "\nCorner Grocer Item Tracker\n";
    cout << "1. Search for an item\n";
    cout << "2. Display item purchase frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

bool IsValidItemName(const string& item) {
    for (char c : item) {
        if (!isalpha(c)) { // Ensures input contains only letters
            return false;
        }
    }
    return !item.empty(); // Ensures input is not empty
}

int main() {
    ItemTracker tracker;
    int choice;
    string item;

    do {
        DisplayMenu();
        cin >> choice;

        // Input validation for menu selection
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;

            // Validate item input
            while (!IsValidItemName(item)) {
                cout << "Invalid item name. Please enter only letters: ";
                cin >> item;
            }

            cout << "Frequency: " << tracker.GetItemFrequency(item) << endl;
            break;
        case 2:
            cout << "Displaying all item frequencies:\n";
            tracker.PrintFrequencies();
            break;
        case 3:
            cout << "Displaying histogram:\n";
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
