/* Program Input KRS.
 * Author: Javier Fadel M.
 * Modified: 12 Oct. 2022. */
#include <iostream>
#include <array>
#include <vector>
using namespace std;

// FIXME: getline bug on input loop.

// The goal is to store two different data types on a single array (can't do this with regular array).
// This allows storing of multiple data types in a single object.
struct MataKuliah {
    string name;
    int amount;
};

// Main function.
int main() {
    // Variable declaration.
    int creditAmount, creditTotal, programAmount = 0;
    string mataKuliah;
    vector<MataKuliah> himpunanMataKuliah;

    // Display input: for the amount of program taken.
    cout << "=============== PROGRAM MENGHITUNG KRS ===============\n\n";
    cout << "Input jumlah mata kuliah yang diambil: ";
    cin >> programAmount;

    // Loops for input data.
    for (int i = 0; i < programAmount; i++) {
        // Input data: should it use a local or global variable?
        cout << "Input mata kuliah: ";
        cin >> mataKuliah;
        cout << "Input jumlah SKS: ";
        cin >> creditAmount;

        // Insert data to vector variable: the size is dynamic.
        himpunanMataKuliah.insert(himpunanMataKuliah.begin() + i, {mataKuliah, creditAmount});
    }

    // Find out how many credit are taken per semester.
    for (auto & i: himpunanMataKuliah) {
        creditTotal = creditTotal + i.amount;
    }

    // Display output: show how many program are taken and how much the cost are.
    cout << "\n\n=============== KARTU RENCANA STUDI ===============\n";
    cout << "Jumlah mata kuliah : " << programAmount << endl;
    cout << "Jumlah SKS         : " << creditTotal << endl;
    cout << "Mata kuliah" << endl;
    for (auto & i: himpunanMataKuliah) {
        cout << "\t" << i.name << ": " << i.amount << " SKS" << endl;
    }
    cout << "Total biaya SKS per semester: Rp. " << creditTotal * 2500000 << endl;

    return 0;
}
