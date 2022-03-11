#include"mat.hpp"
#include<string>
#include<vector>
#include<iostream>

using namespace std;

namespace ariel
{
    int min(const int a,const int b)
    {
        int ans=0;
        if (a>b)
        {    
            ans = b;
        } 
        else
        {
            ans = a;
        }
        return ans;
    }
    string mat(int col, int row, char a, char b)
    {
        if (row <=0 || col <= 0)
        {
            throw runtime_error("only positive number");
        }
        if (row%2==0 || col%2==0)
        {
            throw runtime_error("only odd number");
        }
        if (a == '\n' || a == ' ' || a == '\t' || a == '\r')
        {
            throw runtime_error("cant enter space char");
        }
        const int max = 126;
        const int minim = 33;
        if (a < minim || a > max || b < minim || b > max)
        {
            throw runtime_error("not good symbol");
        }
        int i = 0;
        int j = 0;
        /*int **arr_1 = new int *[col];
        int **arr_2 = new int *[col];
        for ( i = 0; i < col; i++)
        {
            arr_1[i] = new int[row];
            arr_2[i] = new int[row];
        }*/
        vector<vector<int>> arr_1(row,vector<int>(col));
        vector<vector<int>> arr_2(row,vector<int>(col));
        int count_i = row-1;
        int count_j = col-1;
        for ( i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                arr_1[i][j] = min(i,j);
                arr_2[count_i][count_j] = arr_1[i][j];;
                count_j--;
            }  
            count_j = col-1;
            count_i--;
        }
        
      
        string ans;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (min(arr_1[i][j],arr_2[i][j]) % 2 == 0)
                {
                    ans += a;
                }
                else
                { 
                    ans += b;
                }
            }
            ans += '\n';
        }
        ans.pop_back();
        /*for ( i = 0; i < col; i++)
        {
            delete [] arr_1[i];
            delete [] arr_2[i];
        }
        delete [] arr_1;
        delete [] arr_2;
        */
        
        return ans;
        
    }

}