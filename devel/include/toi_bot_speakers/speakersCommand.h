// Generated by gencpp from file toi_bot_speakers/speakersCommand.msg
// DO NOT EDIT!


#ifndef TOI_BOT_SPEAKERS_MESSAGE_SPEAKERSCOMMAND_H
#define TOI_BOT_SPEAKERS_MESSAGE_SPEAKERSCOMMAND_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace toi_bot_speakers
{
template <class ContainerAllocator>
struct speakersCommand_
{
  typedef speakersCommand_<ContainerAllocator> Type;

  speakersCommand_()
    : response()  {
    }
  speakersCommand_(const ContainerAllocator& _alloc)
    : response(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _response_type;
  _response_type response;





  typedef boost::shared_ptr< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> const> ConstPtr;

}; // struct speakersCommand_

typedef ::toi_bot_speakers::speakersCommand_<std::allocator<void> > speakersCommand;

typedef boost::shared_ptr< ::toi_bot_speakers::speakersCommand > speakersCommandPtr;
typedef boost::shared_ptr< ::toi_bot_speakers::speakersCommand const> speakersCommandConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::toi_bot_speakers::speakersCommand_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace toi_bot_speakers

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'toi_bot_speakers': ['/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_speakers/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6de314e2dc76fbff2b6244a6ad70b68d";
  }

  static const char* value(const ::toi_bot_speakers::speakersCommand_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6de314e2dc76fbffULL;
  static const uint64_t static_value2 = 0x2b6244a6ad70b68dULL;
};

template<class ContainerAllocator>
struct DataType< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "toi_bot_speakers/speakersCommand";
  }

  static const char* value(const ::toi_bot_speakers::speakersCommand_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string response\n\
";
  }

  static const char* value(const ::toi_bot_speakers::speakersCommand_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.response);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct speakersCommand_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::toi_bot_speakers::speakersCommand_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::toi_bot_speakers::speakersCommand_<ContainerAllocator>& v)
  {
    s << indent << "response: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.response);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TOI_BOT_SPEAKERS_MESSAGE_SPEAKERSCOMMAND_H
