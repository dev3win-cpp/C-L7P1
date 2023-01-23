
//  main.cpp
//  C++L7P1
//
//  Created by Tadeusz Potoniec on 23/01/2023.
//  Based on https://www.youtube.com/watch?v=ErOzmh3BiXU&list=PLOYHgt8dIdoxx0Y5wzs7CFpmBzb40PaDo

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string subject, nick;
string content[5];
string ansA[5], ansB[5], ansC[5], ansD[5];
string correct[5];
string answer;
int points=0;

int main()
{
    int nr_line=1;
    string line;
    int nr_question=0;

    fstream plik;
    plik.open("quiz.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"Failed to open file!";
        exit(0);
    }

    while(getline(plik,line))
    {
        switch(nr_line)
        {
            case 1: subject=line;                     break;
            case 2: nick=line;                      break;
            case 3: content[nr_question] = line;       break;
            case 4: ansA[nr_question] = line;        break;
            case 5: ansB[nr_question] = line;        break;
            case 6: ansC[nr_question] = line;        break;
            case 7: ansD[nr_question] = line;        break;
            case 8: correct[nr_question] = line;    break;
        }

        if (nr_line==8) {nr_line=2; nr_question++;}
        nr_line++;
    }

    plik.close();

    for (int i=0; i<=4; i++)
    {
        cout<<endl<<content[i]<<endl;
        cout<<"A. "<<ansA[i]<<endl;
        cout<<"B. "<<ansB[i]<<endl;
        cout<<"C. "<<ansC[i]<<endl;
        cout<<"D. "<<ansD[i]<<endl;

        cout<<"Your answer: ";
        cin>>answer;

        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer[0]==correct[i][0])
        {
            cout<<"Good! You score a point!"<<endl;
            points++;
        }
        else cout<<"Bad! No point! Correct answer: "<<correct[i]<<endl;

    }

    cout<<"End of quiz. Points scored: "<<points<<endl;

    return 0;
}
/* in xcode on mac you have to choose product->scheme->edit scheme and then choose run on the left side and then options and select use custom working directory and choose the folder where the c++ file is saved */

