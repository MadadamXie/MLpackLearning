#include <iostream>

template <typename T>
class hello{
  T a;
  T b;
};

using namespace std;
int main(int argc,char** argv){
  cout<< argc <<endl;
  cout<< argv[0] <<endl;
}
