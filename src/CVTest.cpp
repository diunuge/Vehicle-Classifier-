// Image processing

#include "stdafx.h"
#include "CVTest.h"

#include <iostream>                        // std::cout
#include <fstream>
#include <string.h>
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/highgui/highgui.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
//#include <WinSock2.h>
//#include <Windows.h>

//#using <System.dll>

using namespace std;
using namespace cv;

//using namespace System;
//using namespace System::Text;
//using namespace System::IO;
//using namespace System::Net;
//using namespace System::Net::Sockets;
//using namespace System::Collections;

CVTest::CVTest()
{
	ROBOT_IP="192.168.137.2";
	videoURL = "rtsp://192.168.137.2:8554/";

	//ROBOT_IP="192.168.138.2";
	//videoURL = "rtsp://192.168.138.2:8554/";

	control = "manual";
	cmd = "stop";
	obstacleSeed = 10;

	infoControl = "";
	infoCmdCurrent = "";
	infoIsObstacleLeft = "";
	infoIsObstacleRight = "";

	//updateInfo();
	//updateControlCommands();
}

CVTest::~CVTest()
{

}

std::string CVTest::get_http(const std::string &server,const std::string &path)
{
    using boost::asio::ip::tcp;
    stringstream result;
    boost::asio::io_service io_service;

    // Get a list of endpoints corresponding to the server name.
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(server, "http");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    // Try each endpoint until we successfully establish a connection.
    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    // Form the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    boost::asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream << "GET " << path << " HTTP/1.0\r\n";
    request_stream << "Host: " << server << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";

    // Send the request.
    boost::asio::write(socket, request);

    // Read the response status line. The response streambuf will automatically
    // grow to accommodate the entire line. The growth may be limited by passing
    // a maximum size to the streambuf constructor.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

    // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);
    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
    {
      throw runtime_error("Invalid response");
    }
    if (status_code != 200)
    {
      stringstream ss;
      ss<< "Response returned with status code " << status_code << "\n";
      throw runtime_error(ss.str());
    }
        // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

    // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r");
    //  std::cout << header << "\n";
    //std::cout << "\n";

    // Write whatever content we already have to output.
    if (response.size() > 0)
        result << &response;

    // Read until EOF, writing data to output as we go.
    boost::system::error_code error;
    while (boost::asio::read(socket, response,
          boost::asio::transfer_at_least(1), error))
      result << &response;
    if (error != boost::asio::error::eof)
      throw boost::system::system_error(error);
    return result.str();
}

void CVTest::setControl(std::string control)
{
	this->control = control;
}

void CVTest::setCommand(std::string command)
{
	cmd = command;
}

void CVTest::setObstacleSeed(int obstacleSeed)
{
	this->obstacleSeed = obstacleSeed;
}

void CVTest::updateInfo()
{
	//std::ofstream file;
    //file.open ("cout.txt");
    //std::streambuf* sbuf = std::cout.rdbuf();
    //std::cout.rdbuf(file.rdbuf());

    stringstream temp; 
	temp << get_http(ROBOT_IP,"/finch/get.php");
    //cout << "Original JSON:" << endl;
	//cout << temp.str();
    //cout << string(256,'*') << endl;

	string str = temp.str();
	char seps[] = "{}:,\"";
	char *token;

	token = strtok( &str[0], seps );

	token = strtok( NULL, seps );
	token = strtok( NULL, seps );
	infoControl = string(token);
	
	token = strtok( NULL, seps );
	token = strtok( NULL, seps );
	infoCmdCurrent = string(token);
	
	token = strtok( NULL, seps );
	token = strtok( NULL, seps );
	infoIsObstacleLeft = string(token);
	
	token = strtok( NULL, seps );
	token = strtok( NULL, seps );
	infoIsObstacleRight = string(token);

	//file.close();
}

void CVTest::updateControlCommands()
{
	string updatelink = "/finch/update.php?control="+control+"&cmd="+cmd+"&obstacle="+std::to_string(obstacleSeed);
	
	get_http(ROBOT_IP,updatelink);

}

string CVTest::getInterfaceText()
{
	string txt= "";
	txt += "Robot in " + control + " mode\n";
	//txt += "\n=========Info==========\n";
	//txt += "\nControl Mode :\t"+infoControl;
	//txt += "\nCommand Current :\t"+infoCmdCurrent;
	return txt;
}

void CVTest::captureStream () 
{
	/*
	cv::VideoCapture capture("C:\\Users\\D\\Desktop\\AI Robot\\testvideo20.h264");
	
	//cv::VideoCapture capture(videoURL);

	cv::Mat frame;

	status = true;

	int iLowH = 44;
	int iHighH = 70;

	int iLowS = 162; 
	int iHighS = 255;

	int iLowV = 21;
	int iHighV = 255;

	if (!capture.isOpened()) {
		//Error
	}

	cv::namedWindow("Control", CV_WINDOW_AUTOSIZE);

	//Create HSV controllertrackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 255); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 255);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);

	while (true)
	{
		//Load the Robot status
		updateInfo();

		Mat imgOriginal;

		bool bSuccess = capture.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		//morphological opening (remove small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

		//morphological closing (fill small holes in the foreground)
		dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		imshow("Thresholded Image", imgThresholded); //show the thresholded image

		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;

		int largest_contour_area=0;
		int largest_contour_index=0;

		Rect bounding_rect;

		Mat dst(imgThresholded.rows,imgThresholded.cols,CV_8UC1,Scalar::all(0));

		/// Find contours in treshold image (Find objects)
		findContours( imgThresholded, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

		//Find the lagest contour area..
		for( unsigned int i = 0; i< contours.size(); i++ ) // iterate through each contour. 
		{
			double a=contourArea( contours[i],false);  //  Find the area of contour
			if( a > largest_contour_area )
			{
				largest_contour_area=(int)a;
				largest_contour_index=i;                //Store the index of largest contour
				bounding_rect=boundingRect(contours[i]); // Find the bounding rectangle for biggest contour
			}
		}

		// Draw the largest contour using previously stored index.
		Scalar color( 255,255,255);
		drawContours( dst, contours,largest_contour_index, color, CV_FILLED, 8, hierarchy ); 
		rectangle(imgOriginal, bounding_rect,  Scalar(0,255,0),1, 8,0); 

		//Calculating the obstacle seed value
		if(largest_contour_area > 1000){
			int x = (int)bounding_rect.tl().x + (int)bounding_rect.width/2;
			Size imgSize = imgOriginal.size();
			int w = imgSize.width/5;

			obstacleSeed = x/w -3;
		}
		else{
			obstacleSeed = 10;
		}

		imshow( "src", imgOriginal );
		imshow( "largest Contour", dst );

		//Update the commands
		updateControlCommands();

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break; 
		}
	}

	cv::destroyWindow("Control");
	*/
}

void CVTest::close (){
	status = false;
}