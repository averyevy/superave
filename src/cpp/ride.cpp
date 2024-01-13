/* 
ID: avelynj1
TASK: ride
LANG: C++ 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int result(std::string name) {
  long product = 1l;
  for (int i=0;i<name.size(); i++) {
    int letter = name.at(i) - 'A' + 1;
    product = product * letter;
  }
  product = product%47;
  return product;
}

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
 
  std::string cometname;
  std::string groupname;
  fin >> cometname;
  fin >> groupname;
  
  if (result(cometname) == result(groupname)) {
    fout << "GO" << endl;
  }
  else {
    fout << "STAY" << endl;
  }
  return 0;
}