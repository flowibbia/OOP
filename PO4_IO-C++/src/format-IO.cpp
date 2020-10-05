 
  
  #include <iostream>    

  using namespace std;
  int main () {
    double f = 12343.1415912321;
    
    cout.setf(ios::left);
    cout.fill('*');
    cout.precision(5);
    cout.width(10);
    cout << f << '\n';
    cout.setf(ios::right);
    cout << f << '\n';
    
    cout.precision(10);
    cout << f << '\n';
    
    return 0;
  }
    

  