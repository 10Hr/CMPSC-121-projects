//Tyler McCluskey
// grader.cpp
// takes in an input file of grades and comptes the max,min,range,mean,standard deviation, as well as all of the scores from grades A-F

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double cMean(double num[], int size) {
	double sum = 0;
  double mean = 0;
  for (int i = 0; i < size; i++)
    sum += num[i];
    mean = sum / size;
    return mean;
}

double calcSD(double array[], int size, double mean) {
	double dPow[100] = {0};
	double sd =  0.0;
  for (int i = 0; i < size; i++)
    dPow[i] = pow((array[i] - mean), 2);
	sd = sqrt(cMean(dPow, size));
	
  return sd;
}


int findmin(double arr[], int size) {
	 int temp = arr[0];
   for(int i = 0; i < size; i++) 
      if(temp > arr[i]) 
        temp = arr[i];
   return temp;
}

int findmax(double arr[], int size) {
	
	int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;

}


int main() {
	
  double grades[100] = {0};  //  array containing the grades that get sorted
  int size = 0;  //  number of grades in grades[]
  string fN; // file name
  ifstream file; // input file
	ofstream filo; // output file
	
  cout << "What is the name of the file that you would like to use? => ";
  cin >> fN;
  file.open(fN);

	for (int i = 0; i < 100; i++) {
    file >> grades[i];
    if (grades[i] != 0)
      size++;
    }

	double max = findmax(grades, size); // max
	double min = findmin(grades, size); // min
	double range = max - min; // range
  double mean = cMean(grades, size); // mean
  double sd = calcSD(grades, size, mean); // standard deviation
    

  int amgrades[11] = {0}; // store grades
	
  for (int i = 0; i < size; i++)
    if (mean + ((4.0 / 3.0) * sd) <= grades[i])
      amgrades[0]++;
    else if (mean + sd <= grades[i])
      amgrades[1]++;
    else if (mean + ((2.0 / 3.0) * sd) <= grades[i])
      amgrades[2]++;
    else if (mean + ((1.0 / 3.0) * sd) <= grades[i])
      amgrades[3]++;
    else if (mean <= grades[i])
      amgrades[4]++;
    else if (mean - ((1.0 / 3.0) * sd) <= grades[i])
      amgrades[5]++;
    else if (mean - ((2.0 / 3.0) * sd) <= grades[i])
      amgrades[6]++;
    else if (mean - sd <= grades[i])
      amgrades[7]++;
    else if (mean - ((4.0 / 3.0) * sd) <= grades[i])
      amgrades[8]++;
    else if (mean - ((5.0 / 3.0) * sd) <= grades[i])
      amgrades[9]++;
    else
      amgrades[10]++;

	filo.open("output");
	string letters[11] = {"A","A-","B+","B","B-","C+","C","C-","D+","D","F"}; // stores letters
	filo << "Mean: " << setprecision(4) << mean << endl;
  filo << "Standard Deviation: " << setprecision(4) << sd << endl;
	filo << "Minimum: " << setprecision(4) << min << endl;
	filo << "Maximum: " << setprecision(4) << max << endl;
	filo << "Range: " << setprecision(4) << range << endl;

	filo << "Grade" << "\t\t" << "Number_of_scores" << endl;
  for (int i = 0; i < 12; i++) 
		if (i == 0 || i == 6 || i == 3 || i == 9 || i == 10)
			filo << setw(5) << letters[i] << setw(19) << amgrades[i] << endl;
		else
			filo << setw(6) << letters[i] << setw(18) << amgrades[i] << endl;
	cout << "The name of the output file is: output" << endl;
	file.close();
	filo.close();
	return 0;
}