#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

float primer(string str){
    string a = "";
    string b = "";
    char lastoper = '+';
    int indexx;
    for (int i=0; i<str.size(); i++){
        if (isdigit(str[i]) or str[i]=='.'){
            b += str[i];
        } else {
            lastoper = str[i];
            indexx = i;
            break;
        }
    }
    float result = stof(b);
    indexx += 1;
    for (int i=indexx; i<str.size(); i++){
        if (isdigit(str[i]) or str[i] == '.'){
            a += str[i];
        } else {
            if (lastoper == '+'){
                result = result + stof(a);
            }if (lastoper == '-'){
                result = result - stof(a);
            }if (lastoper == '*'){
                result = result * stof(a);
            }if (lastoper == '/'){
                result = result / stof(a);
            }
            a = "";
            lastoper = str[i];
        }
    }
    if (lastoper == '+'){
        result = result + stof(a);
    } if (lastoper == '-'){
        result = result - stof(a);
    } if (lastoper == '*'){
        result = result * stof(a);
    } if (lastoper == '/'){
        result = result / stof(a);
    } 
    return result;
}


int main()
{
    string strr;
    cin >> strr;
    cout << primer(strr) << endl;
}