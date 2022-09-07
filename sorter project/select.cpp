// Tyler McCluskey
// select.cpp
// sorts an input file using selection sort

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// uses a selection sort to sort the file
int selectionSort(int arr[] /*array*/, int n /*size of array*/) {
	int i, // counter
	j, // pass
	min, // minimum 
	swap = 0; // swap counter
  for(i = 0; i < n - 1; i++) {
    min = i;
    for(j = i + 1; j < n; j++)
      if(arr[j] < arr[min])
        min = j;
				int temp = 0;
   			temp = arr[i];
   			arr[i] = arr[min];
   			arr[min] = temp;
				swap++;
   }
	 return swap; // returns amount of times values were swapped
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

	cout << "The output file is named output\nThere are " << a << " numbers in the file\n" << selectionSort(arr, a) << " swaps were required to sort the file" << endl;

  int s = 0; // line counter
	for(int i = 0; i < a; i++) {
	  if (s % 10 == 0) 
    	filo << setw(5) << arr[i];	
    else {
    	filo << endl;
    	s = 0;
    }
  	s = i;
	}
	filo.close();
}