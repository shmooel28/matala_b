#include <string>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main()
{
    int row = 1,col = 1;
    char a,b;
    while (row > 0)
    {
        cout<<"enter number of row"<<endl;
        cin>>row;
        cout<<"enter number of colum"<<endl;
        cin>>col;
        cout<<"enter the first char"<<endl;
        cin>>a;
        cout<<"enter the seconde char"<<endl;
        cin>>b;
        cout<<mat(row,col,a,b)<<endl;
    }
    
}