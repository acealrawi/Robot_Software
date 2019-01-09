/**
**  Simple ROS Node
**/
#include <ros/ros.h>
#include <ar_publisher/ARMarker.h>
#include <moving_core/PoseMessage.h>
#include <tf/transform_listener.h>

using namespace ros;
using namespace moving_core;
using namespace ar_publisher;
using namespace tf;


class Localizer
{
public:
    Localizer(NodeHandle& nh)
    {
        ar_sub_ = nh.subscribe<ARMarker>("ar_pose_marker", 1,
        &Localizer::visionCallback, this);

        publisher = nh.advertise<PoseMessage>("PoseMessage", 1000);
        // server_ = nh.advertiseService("localize_part", &Localizer::localizePart, this);
    }

    void visionCallback(const ARMarkerConstPtr& msg)
    {
        last_msg_ = msg;
        ROS_INFO_STREAM(last_msg_->pose.pose);
        PosePublisher();
    }

    void PosePublisher(){
        ROS_INFO("PosePublisher start");
        ARMarkerConstPtr p = last_msg_;

        Transform cam_to_target;
        poseMsgToTF(p->pose.pose, cam_to_target);

        StampedTransform req_to_cam;
        listener_.lookupTransform("world", p->header.frame_id, Time(0), req_to_cam);

        Transform req_to_target;
        req_to_target = req_to_cam * cam_to_target;

        PoseMessage localizePartMessage;

        poseTFToMsg(req_to_target, localizePartMessage.pose);
        publisher.publish(localizePartMessage);
        ROS_INFO("PosePublisher end");
    }

    

    Subscriber ar_sub_;
    Publisher publisher;
    ARMarkerConstPtr last_msg_;
    TransformListener listener_;
};

int main(int argc, char* argv[])
{
    // This must be called before anything else ROS-related
    init(argc, argv, "vision_node");

    // Create a ROS node handle
    NodeHandle nh;

    // The Localizer class provides this node's ROS interfaces
    Localizer localizer(nh);

    ROS_INFO("Vision node starting");

    // Don't exit the program.
    spin();
}
