// CFramer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "opencv2/core/core.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace cv;
using namespace std;

void fixFileName(string &fileName){
	fileName = fileName.substr(0, fileName.length() - 4);
}

int main(int argc, char* argv[]){
	VideoCapture cap;
	string fileName(argv[1]);
	fixFileName(fileName);
	cap.open(argv[1]);
    if( !cap.isOpened() )
        return 0;
	Mat frame;
    for(int i = 0; i < 30; i++){
        cap >> frame;
		if( frame.empty() )
            break;
		if(i % 7 == 0){
			string ruta = fileName + "_frame_" + to_string(i) + ".jpg";
			cout << ruta << endl;
			imwrite(ruta.c_str(), frame);
		}
    }
	return 0;
}

