#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

double convertToMeters(double centimeters);
double calculateBMI(double weight, double height);
string classifyBMI(double bmi);

int main()
{
    ifstream inputFile("patients.txt");

    int numberOfPatients;
    string firstName;
    string lastName;
    string name;
    double weight;
    double height;
    double heightInMeters;
    double bmi;

    if (!inputFile)
    {
        cout << "ERROR: Could not open the input file." << endl;
        return 0;
    }

    if (!(inputFile >> numberOfPatients) ||
        numberOfPatients <= 0)
    {
        cout << "ERROR: Invalid number of patients." << endl;
        cout << "Program ended." << endl;
        return 0;
    }

    for (int i = 1; i <= numberOfPatients; i++)
    {
        if (!(inputFile >> firstName >> lastName
            >> weight >> height))
        {
            cout << "ERROR: Invalid patient data." << endl;
            cout << "Program ended." << endl;
            return 0;
        }

        name = firstName + " " + lastName;

        if (weight <= 0)
        {
            cout << "ERROR: The value " << weight
                << " is invalid for weight in kilograms."
                << endl;
            cout << "Program ended." << endl;
            return 0;
        }

        if (height <= 0)
        {
            cout << "ERROR: The value " << height
                << " is invalid for height in centimeters."
                << endl;
            cout << "Program ended." << endl;
            return 0;
        }

        heightInMeters = convertToMeters(height);
        bmi = calculateBMI(weight, heightInMeters);

        cout << fixed << setprecision(2);
        cout << "(#" << i << ") " << name
            << "'s BMI is: " << bmi << endl;
        cout << "The BMI classification is "
            << classifyBMI(bmi) << endl;
    }

    cout << "Thank you for using our system." << endl;

    inputFile.close();

    return 0;
}

double convertToMeters(double centimeters)
{
    return centimeters / 100.0;
}

double calculateBMI(double weight, double height)
{
    return weight / (height * height);
}

string classifyBMI(double bmi)
{
    if (bmi < 18.5)
    {
        return "Underweight";
    }
    else if (bmi < 25)
    {
        return "Normal";
    }
    else if (bmi < 30)
    {
        return "Overweight";
    }
    else
    {
        return "Obese";
    }
}