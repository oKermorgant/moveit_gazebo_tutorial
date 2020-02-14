#include <sensor_msgs/point_cloud_conversion.h>
#include <ros/ros.h>
#include <ros/publisher.h>

class Converter
{
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  sensor_msgs::PointCloud2 pc2;

  void convert(const sensor_msgs::PointCloud &pc1)
  {
    sensor_msgs::convertPointCloudToPointCloud2(pc1, pc2);
    pub.publish(pc2);
  }


public:
  Converter(std::string in_topic, std::string out_topic)
  {
    sub = nh.subscribe(in_topic, 1, &Converter::convert, this);
    pub = nh.advertise<sensor_msgs::PointCloud2>(out_topic, 1);
  }

  void loop()
  {
    ros::spin();
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pc_convert");
  Converter converter("/kinect/3d_cloud", "kinect/3d_cloud2");
  converter.loop();
}
