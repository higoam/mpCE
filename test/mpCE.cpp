//============================================================================
// Name        : mpCE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace std;

string convertIntString(int value);
int convertStringInt(string str);
string getTextFile(string nameInput);
void generateVerificationFile(string matrix, int lowerCost, int size, int start);
string matrixFormtVerification(string textFile, int size);
string cutSpace(string textFile, int size);
void runOptimization(string matrix, int size, int start);
string getRoute(string steps, int n);

int main(int argc, char *argv[ ]) {

  int n = convertStringInt(argv[2]);
  string formattedMatrix;

  string textInputFile = getTextFile(string(argv[1]));
  formattedMatrix = matrixFormtVerification(textInputFile,n);


  generateVerificationFile(formattedMatrix, 10000, n, 2);

  runOptimization(formattedMatrix, n, 2);

  cout << "FIM!!!" << endl;
  return 0;
}

  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  string getRoute(string steps, int n)
  {
    string routeFind="|";
    string strAux;
    string findStr;
    int j;
    int position1, position2;

    for(j=1;j<=n;j++){

      strAux = steps;
      findStr = "{" + convertIntString(j) + "#";      

      position1 = strAux.find(findStr);
      strAux = strAux.substr(position1,strAux.length());     

      position1 = strAux.find("#");
      strAux = strAux.substr(position1+1,strAux.length());

      position1 = strAux.find("}");
      strAux = strAux.substr(0,position1);

      routeFind = routeFind + strAux + "|";

    }

    return routeFind;
  }



  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  void updateVerificationFile(string newF_C)
  {





  }



  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  void runOptimization(string matrix, int size, int start)
  {
    string command = "./cbmc fileVerification.c > logVerification.txt";
    bool condition = true;

    size_t position;
    string auxString;
    string sum;
    string route;
 
    while(condition)
    {
        string fileLog = "";
        system(command.c_str());
        fileLog = getTextFile("logVerification.txt");
        std::size_t found_F = fileLog.find("FAILED");    // Search for the word FAILED in the counterexample
        std::size_t found_S = fileLog.find("SUCCESSFUL");  // Search for the word SUCCESSFUL in the counterexample 

        if(found_F!=std::string::npos)
        {
          auxString = fileLog;

          position = auxString.rfind("SOMA = ");
          auxString = auxString.substr(position+7,auxString.length());     
          position = auxString.find("!");
          sum = auxString.substr(0,position);

          cout << "|" + sum + "| ->"<< endl;

          auxString = auxString.substr(position+2,auxString.length());
          position = auxString.find("!");
          auxString = auxString.substr(0,position-1);
          route = getRoute(auxString, size);

          cout << route << endl;

//          break;
          generateVerificationFile(matrix, convertStringInt(sum), size, start);

        }
        else if(found_S!=std::string::npos)
        {
          cout << "SUCCESSFUL" << endl;
          condition = false;
        }
        else{
          cout << "COUNTEREXAMPLE UNKNOWN" << endl;
          condition = false;
        }

    }


  }











  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  void generateVerificationFile(string matrix, int lowerCost, int size, int start)
  {
    int i;
  	string name = "fileVerification.c";

    ofstream file_min;
    file_min.open(name.c_str());


    file_min << "#define soma_ant " + convertIntString(lowerCost) + "\n";
    file_min << "#include <stdio.h>\n";
    file_min << "\n";    
    file_min << "    int nondet_int();\n";
    file_min << "\n";
    file_min << "    int get_destination(int vet["+ convertIntString(size) + "], int N){\n";
    file_min << "\n";
    file_min << "      int id;\n";
    file_min << "      int c;\n";
    file_min << "      c = nondet_int();\n";
    file_min << "    \n";
    file_min << "      for(id=0;id<N;id++){\n";
    file_min << "        if(vet[id] != 0){\n";
    file_min << "          __CPROVER_assume( c != id );\n";
    file_min << "        }\n";
    file_min << "      }\n";
    file_min << "\n";
    file_min << "      __CPROVER_assume( (c>=0) && (c<N) );\n";
    file_min << "\n";
    file_min << "      return c;\n";
    file_min << "    \n";
    file_min << "    }\n";
    file_min << "\n";
    file_min << "\n";
    file_min << "    int main(){\n";
    file_min << "    \n";
    file_min << "      int Qdestiny = "+ convertIntString(size) + ";\n";
    file_min << "      int start = 5;\n";
    file_min << "      int lastD = start;\n";
    file_min << "      int step = 1;\n";
    file_min << "\n";
    file_min << "      int k=0;\n";
    file_min << "      int i=0, j=0;\n";
    file_min << "\n";
    file_min << "      float soma = 0;\n";
    file_min << "\n";
    file_min << "      int vet_destiny [" + convertIntString(size) + "] = {0";
    for(i=0;i<(size-1);i++){
      file_min << ",0";
    }
    file_min << "};\n";


    file_min << "    \n";
    file_min << "      int mat["+ convertIntString(size) + "]["+ convertIntString(size) + "];\n";
  	file_min << matrix;

    file_min << "\n";

    file_min << "      vet_destiny[lastD] = step;\n";
    file_min << "      \n";
    file_min << "      for(k=0;k<Qdestiny-1;k++){\n";
    file_min << "        j = get_destination(vet_destiny, "+ convertIntString(size) + ");\n";
    file_min << "        soma = soma + mat[lastD][j];\n";
    file_min << "        lastD = j;\n";
    file_min << "        step = step + 1;\n";
    file_min << "        vet_destiny[lastD] = step;\n";
    file_min << "      }\n";
    file_min << "      \n";
    file_min << "      __CPROVER_assume ( soma < soma_ant);\n";
    file_min << "      \n";
    file_min << "      printf(\"SOMA = %d!\",soma);\n";
    file_min << "      \n";
    for(i=0;i<size;i++){
      file_min << "      printf(\"{%d#" + convertIntString(i) + "}\",vet_destiny[" + convertIntString(i) + "]);\n";
    }
    file_min << "      printf(\"!\");\n";
    file_min << "      \n";
    file_min << "      assert( soma >= soma_ant);\n";
    file_min << "      return 0;\n";
    file_min << "      \n";
    file_min << "    }\n";
		file_min.close();
	}


  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  string matrixFormtVerification(string textFile, int size)
  {

    string matrix = "      "; 
    string item;
    string textFileAux = textFile; 
    int i=0,j=0,n=0,m=0;

    for(n=0;n<size;n++)
    {
      for(m=0;m<size;m++)
      {
        i=0;
        while(textFileAux[i] == '\n' || textFileAux[i] == ' '){
          i++;
        }

        textFileAux = textFileAux.substr(i,textFileAux.size());    

        i=0;
        while(textFileAux[i] != '\n' && textFileAux[i] != ' '){
          i++;
        }
        item = textFileAux.substr(0,i);
        textFileAux = textFileAux.substr(i,textFileAux.size());        

        matrix = matrix + "mat[" + convertIntString(n) + "][" + convertIntString(m) + "] = " + item + "; " ;

      }
        matrix = matrix + "\n      ";
    }

    return matrix;

  }

  /*******************************************************************\
  Method:
  Inputs:
  Outputs:
  Purpose:
  \*******************************************************************/
  string getTextFile(string nameFile)
  {

    char letter;
    ifstream file;
    string textFile = "";

    file.open(nameFile.c_str());

    if(!file.is_open( ))
    {
      cout<<"Could not open file with function!\n";
      file.clear( ); //reset the object read, for clean system memori
    }

    while (file.get(letter))
    {
      textFile = textFile + letter;
    }

    return textFile;
  }

  //*****************************************

	string convertIntString(int value)
	{
		ostringstream convert;
		convert << value;
		return convert.str();
	}

  int convertStringInt(string str)
  {
    return atoi(str.c_str());
  }
