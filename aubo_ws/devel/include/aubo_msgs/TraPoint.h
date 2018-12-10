// Generated by gencpp from file aubo_msgs/TraPoint.msg
// DO NOT EDIT!


#ifndef AUBO_MSGS_MESSAGE_TRAPOINT_H
#define AUBO_MSGS_MESSAGE_TRAPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace aubo_msgs
{
template <class ContainerAllocator>
struct TraPoint_
{
  typedef TraPoint_<ContainerAllocator> Type;

  TraPoint_()
    : bus(0)
    , num_of_trapoint(0)
    , trapoints()  {
    }
  TraPoint_(const ContainerAllocator& _alloc)
    : bus(0)
    , num_of_trapoint(0)
    , trapoints(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _bus_type;
  _bus_type bus;

   typedef int32_t _num_of_trapoint_type;
  _num_of_trapoint_type num_of_trapoint;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _trapoints_type;
  _trapoints_type trapoints;





  typedef boost::shared_ptr< ::aubo_msgs::TraPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aubo_msgs::TraPoint_<ContainerAllocator> const> ConstPtr;

}; // struct TraPoint_

typedef ::aubo_msgs::TraPoint_<std::allocator<void> > TraPoint;

typedef boost::shared_ptr< ::aubo_msgs::TraPoint > TraPointPtr;
typedef boost::shared_ptr< ::aubo_msgs::TraPoint const> TraPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::aubo_msgs::TraPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::aubo_msgs::TraPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace aubo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'aubo_msgs': ['/home/ali/Robot_Software/aubo_ws/src/aubo_robot/aubo_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::aubo_msgs::TraPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::aubo_msgs::TraPoint_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::aubo_msgs::TraPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::aubo_msgs::TraPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aubo_msgs::TraPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aubo_msgs::TraPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::aubo_msgs::TraPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "58b7060898c2855ab033e4f3ac0333d2";
  }

  static const char* value(const ::aubo_msgs::TraPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x58b7060898c2855aULL;
  static const uint64_t static_value2 = 0xb033e4f3ac0333d2ULL;
};

template<class ContainerAllocator>
struct DataType< ::aubo_msgs::TraPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aubo_msgs/TraPoint";
  }

  static const char* value(const ::aubo_msgs::TraPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::aubo_msgs::TraPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 bus\n\
int32 num_of_trapoint\n\
float32[] trapoints\n\
";
  }

  static const char* value(const ::aubo_msgs::TraPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::aubo_msgs::TraPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bus);
      stream.next(m.num_of_trapoint);
      stream.next(m.trapoints);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TraPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aubo_msgs::TraPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::aubo_msgs::TraPoint_<ContainerAllocator>& v)
  {
    s << indent << "bus: ";
    Printer<int8_t>::stream(s, indent + "  ", v.bus);
    s << indent << "num_of_trapoint: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num_of_trapoint);
    s << indent << "trapoints[]" << std::endl;
    for (size_t i = 0; i < v.trapoints.size(); ++i)
    {
      s << indent << "  trapoints[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.trapoints[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUBO_MSGS_MESSAGE_TRAPOINT_H
