// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <sstream>
#include <iterator>
#include <vector>


using namespace std;

int vertexNumber (char *name){

        string line;
        string elementVertexString;
        ifstream myFile (name);
        int counter=0;
        int elementVertex=0;

        if (myFile.is_open()){
            for (counter; counter<4; counter++){
                getline (myFile,line);
            }
            elementVertexString = line.substr(15);
            elementVertex = atoi(elementVertexString.c_str());
        }
        else{
            cout << "Unable to open file";
            myFile.close();
            return 0;
        }
        myFile.close();
        return elementVertex;
}


int faceNumber (char *name){

        string line;
        string elementFaceString;
        ifstream myFile (name);
        int counter=0;
        int elementFace=0;

        if (myFile.is_open()){
            for (counter; counter<8; counter++){
                getline (myFile,line);
            }
            elementFaceString = line.substr(13);
            elementFace = atoi(elementFaceString.c_str());
        }
        else{
            cout << "Unable to open file";
            myFile.close();
            return 0;
        }
        myFile.close();
        return elementFace;
}


float *readVertex (char *name, int elementVertex){

    string line;
    string elementVertexString;
    ifstream myFile (name);
    int counter=0;

    /*
    Forth line:
        element vertex NUMBER
    Eight line:
        element face NUMBER
    Initial data:
        First to 10th line
    */
    if (myFile.is_open()){
        for (counter; counter<10; counter++){
            getline (myFile,line);
        }
    }
    else{
            cout << "Unable to open file";
            myFile.close();
            return NULL;
    }

    /*
    Take memory as much as you need
    */
    float *elemVertex = (float*) malloc(elementVertex*3*sizeof(float));
    /*
    Let's collect data
    */
    for (counter=0; counter < elementVertex ; counter++){
        getline(myFile, line);
        istringstream buf(line);
        istream_iterator <string> beg(buf), end;
        vector <string> tokens(beg, end); // done!

        *(elemVertex+counter*3)=atoi(tokens[0].c_str());
        *(elemVertex+counter*3+1)=atoi(tokens[1].c_str());
        *(elemVertex+counter*3+2)=atoi(tokens[2].c_str());



        cout << tokens[0];
        cout << tokens[1];
        cout << tokens[2] << '\n';

    }
    myFile.close();
    return elemVertex;
}

float *readFace (char *name, int elementFace, int elementVertex){

    string line;
    string elementFaceString;
    ifstream myFile (name);
    int counter=0;

    /*
    Forth line:
        element vertex NUMBER
    Eight line:
        element face NUMBER
    Initial data:
        First to 10th line
    */
    if (myFile.is_open()){
        for (counter; counter<10+elementVertex; counter++){
            getline (myFile,line);
        }
    }
    else{
            cout << "Unable to open file";
            myFile.close();
            return NULL;
    }

    /*
    Take memory as much as you need
    */
    float *elemFace = (float*) malloc(elementFace * 4 * sizeof(float));
    /*
    Let's collect data
    */
    for (counter=0; counter < elementFace ; counter++){
        getline(myFile, line);
        istringstream buf(line);
        istream_iterator <string> beg(buf), end;
        vector <string> tokens(beg, end); // done!

        *(elemFace+counter*3)=atoi(tokens[0].c_str());
        *(elemFace+counter*3+1)=atoi(tokens[1].c_str());
        *(elemFace+counter*3+2)=atoi(tokens[2].c_str());
        *(elemFace+counter*3+3)=atoi(tokens[3].c_str());


        cout << tokens[0];
        cout << tokens[1];
        cout << tokens[2];
        cout << tokens[3] << '\n';

    }
    myFile.close();
    return elemFace;
}


int main () {

    char *name = "octahedron1.ply";
    float *vertexElements;
    float *faceElements;
    int vertexNum=0;
    int faceNum=0;

    vertexNum = vertexNumber (name);
    faceNum = faceNumber (name);
    vertexElements = readVertex(name, vertexNum);
    faceElements = readFace(name, faceNum, vertexNum);

  return 0;
}
