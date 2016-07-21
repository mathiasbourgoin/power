#ifndef POWER_SERIAL_OUT_HPP
#define POWER_SERIAL_OUT_HPP


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/asio.hpp>


namespace power
{
  namespace serial
  {

    struct serial_out
    {
      std::string dev;
      uint32_t Bdps;

      boost::asio::io_service io;
      boost::asio::serial_port serial;


      serial_out() : serial( io )
      {
        boost::property_tree::ptree p;
        try {
          boost::property_tree::read_json( "serial-config.json", p );

          dev = p.get( "serialconfig.dev", "/dev/ttyS0" );
          Bdps = p.get( "serialconfig.Bdps", 115200 );
        }
        catch(...)
        {
          dev = "/dev/ttyS0";
          Bdps = 115200;
        }
        serial.open( dev );
        serial.set_option( boost::asio::serial_port_base::baud_rate( Bdps ) );
      }

    } serial;


    serial_out & operator <<( serial_out & out, std::string const & msg )
    {
      boost::asio::write( out.serial, boost::asio::buffer( msg.c_str(), msg.size() ) );
      return out;
    }

  }
}


#endif
