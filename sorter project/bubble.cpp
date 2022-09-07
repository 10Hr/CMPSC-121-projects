// Tyler McCluskey
// bubble.cpp
// sorts an input file using bubble sort
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// sorts the file using a bubble sort
int bubbleSort(int arr[] /*array*/, int n /*size of array*/) {
	int checker, // checks if next value is 0
	j = 0, // pass number
	i = 0, // counter
	swap = 0, // swap checker
	temp = 0; // temp variable

	for(j = 1; j < n; j++) {
  	checker = 0;

  	for(i = 0 ; i < n - j; i++)
    	if(arr[i] > arr[i + 1]) {
    		temp = arr[i];
    		arr[i] = arr[i + 1];
    		arr[i + 1] = temp;
    		checker = 1;
				swap++;
  		}

  if(checker == 0)
  	break;
  }
	return swap;
}

int main() {
	
	int arr[100] = {0}, // array of values
	a = 0; // amount of elements
	string fn; // file name
	ifstream file; // input file
	ofstream filo; // output file

	cout << "Enter input file name => ";
	cin >> fn;

	file.open(fn);

  for(int i = 0; i < 100; i++) {
		file >> arr[i];
		if (arr[i] != 0) 
			a++;
	}
	file.close();
	filo.open("output");
				
	cout << "The output file is named output\nThere are " << a << " numbers in the file\n" << bubbleSort(arr, a) << " swaps were required to sort the file" << endl;
	
  int s = 1; // line counter
	for(int i = 0; i < a; i++) {
	  if (s < 11) 
    	filo << setw(5) << arr[i];	
    else {
    	filo << endl;
    	s = 1;
    }
    s++;
	}
	filo.close();
} 