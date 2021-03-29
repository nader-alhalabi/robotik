// Generated by gencpp from file beginner_tutorials/IntwithHeader.msg
// DO NOT EDIT!


#ifndef BEGINNER_TUTORIALS_MESSAGE_INTWITHHEADER_H
#define BEGINNER_TUTORIALS_MESSAGE_INTWITHHEADER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace beginner_tutorials
{
template <class ContainerAllocator>
struct IntwithHeader_
{
  typedef IntwithHeader_<ContainerAllocator> Type;

  IntwithHeader_()
    : header()
    , data(0)  {
    }
  IntwithHeader_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , data(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int64_t _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> const> ConstPtr;

}; // struct IntwithHeader_

typedef ::beginner_tutorials::IntwithHeader_<std::allocator<void> > IntwithHeader;

typedef boost::shared_ptr< ::beginner_tutorials::IntwithHeader > IntwithHeaderPtr;
typedef boost::shared_ptr< ::beginner_tutorials::IntwithHeader const> IntwithHeaderConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::beginner_tutorials::IntwithHeader_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::beginner_tutorials::IntwithHeader_<ContainerAllocator1> & lhs, const ::beginner_tutorials::IntwithHeader_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::beginner_tutorials::IntwithHeader_<ContainerAllocator1> & lhs, const ::beginner_tutorials::IntwithHeader_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace beginner_tutorials

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "28133f39b947dbb86bee940be137535f";
  }

  static const char* value(const ::beginner_tutorials::IntwithHeader_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x28133f39b947dbb8ULL;
  static const uint64_t static_value2 = 0x6bee940be137535fULL;
};

template<class ContainerAllocator>
struct DataType< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "beginner_tutorials/IntwithHeader";
  }

  static const char* value(const ::beginner_tutorials::IntwithHeader_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header \n"
"int64 data\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::beginner_tutorials::IntwithHeader_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IntwithHeader_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::beginner_tutorials::IntwithHeader_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::beginner_tutorials::IntwithHeader_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "data: ";
    Printer<int64_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_INTWITHHEADER_H
