/******************************************************************************
//
// Name: Aiden R. Dusek
// Date: 10/14/2026
// Class: 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: DR. Reyes
//
// Program Description: This program allows the users to calculate the Body Mass Index (BMI) of
//                      multiple patients based on their weight and height.
//                      
//
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double convertToMeters(double centimeters);
double calculateBMI(double bmi) {
	return bmi;
}
string classifyBMI(double bmi);
int main()
{
	// My ints, strings, and doubles.
	int numberOfPatients;
		string name;
		double weight;
		double height;
		double heightInMeters;
		double bmi;

		cout << "How many patients do you want to process today? ";
		cin >> numberOfPatients;

		if (cin.fail() || numberOfPatients <= 0)
		{
			cout << "ERROR: Invalid number of patients." << endl;
			cout << "Program ended." << endl;
			return 0;
		}
		for (int i = 1; i <= numberOfPatients; i++)
		{
			cout << "Enter the patient's name (#" << i << "): ";
			cin >> name;
			getline(cin, name);

			cout << "Enter weight in kilograms: ";

			if (!(cin >> weight)) {
				cout << "ERROR: Invalid weight input." << endl;
				cout << "Program ended." << endl;
				return 0;
			} if (weight <= 0){
				cout << "ERROR: The value " << weight << "is invalid for weight in kilograms." << endl;
				cout << "Program ended." << endl;
				return 0;
			}

			cout << "Enter height in centimeters: ";
			if (!(cin >> height)) {
				cout << "ERROR: Invalid height input." << endl;
				cout << "Program ended." << endl;
				return 0;
			} if (height <= 0){
				cout << "ERROR: The value " << height << "is invalid for height in centimeters." << endl;
				cout << "Program ended." << endl;
				return 0;
			}

			heightInMeters = convertToMeters(height);

			bmi = calculateBMI(weight / (heightInMeters * heightInMeters));

			cout << fixed << setprecision(2);
			cout << name << "'s BMI is " << bmi << endl;
			cout << "The BMI classification is " << classifyBMI(bmi) << endl;
		}

		cout << "Thank you for using our system." << endl;

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