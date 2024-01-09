#include "sub_advanced_test_ros.h"

using namespace std;
using namespace ros;
using namespace beginner_tutorials;

SubAdvancedTestNode::SubAdvancedTestNode()
{
  subRectArray_ = nh_.subscribe("/pub_advanced_test/rect_array", 1, &SubAdvancedTestNode::currRectArrayCbLoop, this);
}

SubAdvancedTestNode::~SubAdvancedTestNode()
{
}

void SubAdvancedTestNode::currRectArrayCbLoop(const RectArray::ConstPtr& msgRaw)
{
  msgRectArray_ = *msgRaw;

  vecRectArray_.clear();
  RectArray rectArrayTemp;
  rectArrayTemp.bDetect = msgRectArray_.bDetect;
  rectArrayTemp.nStatus = msgRectArray_.nStatus;
  rectArrayTemp.vecRectArray.clear();
  for (auto i = 0u; i < msgRectArray_.vecRectArray.size(); i++)
  {
    rectArrayTemp.vecRectArray.push_back(msgRectArray_.vecRectArray[i]);
  }
  vecRectArray_.push_back(rectArrayTemp);
  bRectArraybLoop = true;
}

void SubAdvancedTestNode::MainLoop()
{
  SubAdvancedTestFunc();
}

void SubAdvancedTestNode::SubAdvancedTestFunc()
{
  if ((bRectArraybLoop) && ((int)(vecRectArray_.size()) > 0))
  {
    // for debugging
    ROS_INFO(" ");
    ROS_INFO("vecRectArray:bDetect:(%d)", (int)(vecRectArray_[0].bDetect));
    ROS_INFO("vecRectArray:nStatus:(%d)", vecRectArray_[0].nStatus);

    for (auto i = 0u; i < vecRectArray_[0].vecRectArray.size(); i++)
    {
      ROS_INFO("vecRectArray:vectRectInfo[%d].nNum:(%d)", i, vecRectArray_[0].vecRectArray[i].nNum);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fXlt:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fXlt);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fYlt:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fYlt);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fWidth:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fWidth);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fHeight:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fHeight);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fScore:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fScore);
    }
  }
}

