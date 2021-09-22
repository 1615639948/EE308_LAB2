//
// Created by XY on 2021/9/22.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <stack>

using namespace std;

//Constructs a keyword string array with 32 elements.
const string keywords[32] = {
        "auto","break","case","char","const","continue","default","do",
        "double","else","enum",	"extern","float","for","goto","if","int",
        "long","register","return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void","volatile","while"
};

/*********************************Variable Area*********************************/

//The variable output on the screen after the program runs.
struct OutputData{
    int level;
    int KeywordNum;
    int SwitchNum;
    int IfElseNum;
    int IfElseifElseNum;
    vector<int> case_num;
};
//Variables that the user needs to enter.
struct InputInformation{
    int level;
    string file_address;
};

/*******************************Function area**********************************/
void DisplayInterface(InputInformation* input);
void OutputResult(OutputData* output);


//Display interface
void DisplayInterface(InputInformation* input){
    cout << "input the text address: " << endl;
    cin >> input->file_address;
    cout << "input the level which you choose: " << endl;
    cin >> input->level;
}

//Output Result
void OutputResult(OutputData* output){
    //level 1
    if(output -> level >= 1){
        cout << "total num: " << output -> SwitchNum << endl;
    }
    //level 2
    if(output->level >= 2){
        cout << "switch num: " << output -> SwitchNum <<endl;
        cout << "case num: ";
        if (output->case_num.empty()) {
            cout << 0 <<endl;
        }else{
            for (int i = 0; i < output->case_num.size(); i++) {
                cout << output->case_num[i] << " ";
            }
            cout << endl;
        }
    }
    //level 3
    if(output->level >= 3){
        cout << "if-else num: " << output -> IfElseNum << endl;
    }
    //level 4
    if(output->level >= 4){
        cout << "if-elseif-else num: " << output -> IfElseifElseNum << endl;
    }
}

//File open read close
void ReadFile(InputInformation input){
    vector<string> text;
    ifstream file(input.file_address);
    for (string txt; file >> txt;) {
        text.push_back(txt);
    }
    file.close();
}


int main(){
    InputInformation input;
    DisplayInterface(&input);
    ReadFile(input);


    return 0;
}


