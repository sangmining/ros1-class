#include "pub_advanced_test_ros.h"

using namespace std;
using namespace ros;
using namespace beginner_tutorials;

PubAdvancedTestNode::PubAdvancedTestNode() : nRectSize_(6)
{
  // publisher, custom msg
  pubRectArray_ = nh_.advertise<RectArray>("/pub_advanced_test/rect_array", 1);
}

PubAdvancedTestNode::~PubAdvancedTestNode()
{
}

void PubAdvancedTestNode::MainLoop()
{
  PubAdvancedTestFunc();
}

void PubAdvancedTestNode::PubAdvancedTestFunc()
{
  // publishing custom msg with vector type
  msgRectArray_.vecRectArray.clear();
  for (unsigned int i = 0; i < nRectSize_; i++)
  {
    RectInfo msgRectInfoTemp_;
    msgRectInfoTemp_.nNum = i;
    msgRectInfoTemp_.fXlt = (float)((10.0f) * (i));
    msgRectInfoTemp_.fYlt = (float)((20.0f) * (i));
    msgRectInfoTemp_.fWidth = (float)((30.0f) * (i));
    msgRectInfoTemp_.fHeight = (float)((40.0f) * (i));
    msgRectInfoTemp_.fScore = (float)((50.0f) * (i));
    msgRectArray_.vecRectArray.push_back(msgRectInfoTemp_);
  }
  msgRectArray_.bDetect = true;

  switch (nRectType_)
  {
    case Define::STATUS_A:
    {
      msgRectArray_.nStatus = Define::STATUS_A;
      break;
    }
    case Define::STATUS_B:
    {
      msgRectArray_.nStatus = Define::STATUS_B;
      break;
    }
    case Define::STATUS_C:
    {
      msgRectArray_.nStatus = Define::STATUS_C;
      break;
    }
    default:
    {
      msgRectArray_.nStatus = Define::STATUS_DEFAULT;
      break;
    }
  }

  pubRectArray_.publish(msgRectArray_);
}
