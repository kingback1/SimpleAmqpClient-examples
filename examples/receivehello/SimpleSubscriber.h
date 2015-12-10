#ifndef SIMPLESUBSCRIBER_H
#define SIMPLESUBSCRIBER_H

#include "SimpleAmqpClient/BasicMessage.h"
#include "SimpleAmqpClient/Channel.h"
#include "SimpleAmqpClient/Util.h"

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>

#ifdef _MSC_VER
# pragma warning ( push )
# pragma warning ( disable: 4275 4251 )
#endif

namespace AmqpClient
{

class SimpleSubscriber
{
public:
    typedef boost::shared_ptr<SimpleSubscriber> ptr_t;

    //friend ptr_t
    //boost::make_shared<SimpleSubscriber>(AmqpClient::Channel::ptr_t const &a1, std::string const &a2);

    static ptr_t Create(AmqpClient::Channel::ptr_t channel, const std::string &publisher_channel)
    {
        return boost::make_shared<SimpleSubscriber>(channel, publisher_channel);
    }



    explicit SimpleSubscriber(Channel::ptr_t channel, const std::string &publisher_channel);

public:
    virtual ~SimpleSubscriber();

    std::string WaitForMessageString(int timeout = -1);
    BasicMessage::ptr_t WaitForMessage(int timeout = -1);

private:
    Channel::ptr_t m_channel;
    std::string m_consumerQueue;

};

}

#ifdef _MSC_VER
# pragma warning ( pop )
#endif

#endif // SIMPLESUBSCRIBER_H

