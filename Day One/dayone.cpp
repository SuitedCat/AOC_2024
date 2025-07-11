#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;



void sorted(vector <double> &sortedVector){
    sort(sortedVector.begin(), sortedVector.end());
}


int main(){
    ifstream infile;
    ofstream outfile;
    
    
    double columnOne, columnTwo;
    vector <double> sortedColumnOne;
    vector <double> sortedColumnTwo;
    vector <double> sum;
    double totalsum;
    double i;
    
    //input file
    infile.open("/Users/myahnix/Desktop/AdventOfCode/Day One/input.txt");
    //output file
    outfile.open("/Users/myahnix/Desktop/AdventOfCode/Day One/output.txt");
    
    // checking if its open
    if(!infile || !outfile){
        cout << "error its not open";
    } else {
        // this while looks ensures that it will read to the end of the file
        // means while we have not reach the end of the file
        while (!infile.eof())
        {
            // the >> represents spaces in columns
            infile >> columnOne >> columnTwo;    
            sortedColumnOne.push_back(columnOne);
            sortedColumnTwo.push_back(columnTwo);
            
            sorted(sortedColumnOne);
            sorted(sortedColumnTwo);
 
        }
            
        for (size_t i = 0; i < sortedColumnOne.size(); i++)
            {
                // confirms that columnOne is being added into vector and sorted
                cout << sortedColumnOne[i] << " ";
                cout << sortedColumnTwo[i] << endl;
                if (sortedColumnOne[i]  > sortedColumnTwo[i])
                {
                 sum.push_back(sortedColumnOne[i] - sortedColumnTwo[i]);
                } else{
                 sum.push_back(sortedColumnTwo[i] - sortedColumnOne[i]);
                }
            
            totalsum = accumulate(sum.begin(),sum.end(), 0);
            
            outfile << setprecision(20) << sortedColumnOne[i] << " " << sortedColumnTwo[i] << " " << totalsum << endl;;   
        }    
    
    }
      infile.close(); //close input file
      outfile.close(); //close output file
      
      return 0;

}

