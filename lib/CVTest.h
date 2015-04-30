#include "stdafx.h"

#include <iostream> 

public class CVTest
{
private:
	std::string ROBOT_IP;
	std::string videoURL;
	bool status;

	std::string control;
	std::string cmd;
	int obstacleSeed;

	std::string infoControl;
	std::string infoCmdCurrent;
	std::string infoIsObstacleLeft;
	std::string infoIsObstacleRight;

private:
	std::string get_http(const std::string &server,const std::string &path);

public:
	CVTest();
	~CVTest();

	void setControl(std::string control);
	void setCommand(std::string command);
	void setObstacleSeed(int obstacleSeed);

	void updateInfo();
	void updateControlCommands();
	std::string getInterfaceText();

	void captureStream ();
	void close();
};