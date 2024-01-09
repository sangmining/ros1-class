// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>

// essential header for ROS-OpenCV operation
#include <ros/ros.h>

// for using custom messages
#include <beginner_tutorials/RectArray.h>
#include <beginner_tutorials/RectInfo.h>

// for using custom define enum variable
#include <beginner_tutorials/Define.h>

using namespace std;
using namespace ros;
using namespace beginner_tutorials;

class SubAdvancedTestNode
{
public:
  SubAdvancedTestNode();
  ~SubAdvancedTestNode();

  void MainLoop();

private:
  void SubAdvancedTestFunc();

  string strTpNameRectInfo_;

  // subscriber, custom msg
  void currRectArrayCbLoop(const RectArray::ConstPtr& msgRaw);
  Subscriber subRectArray_;
  RectArray msgRectArray_;
  vector<RectArray> vecRectArray_;
  bool bRectArraybLoop;
  
  // node handler in class
  NodeHandle nh_;
};
