#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
mp::cpp_int u = 1;
for(int i = 1; i <= 500; i++)u*=i;
cout << "500! = "<<u<<"\n";
return 0;
}

