#include <stdlib.h>
#include <stdio.h>
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include "SimplePublisher.h"

using namespace AmqpClient;
using namespace std;
int main()
{
    char *szBroker = getenv("AMQP_BROKER");
    Channel::ptr_t channel;
    if (szBroker != NULL)
        channel = Channel::Create(szBroker);
    else
        channel = Channel::Create("192.168.66.1", 5672);

    string a="hello world";

   // SimplePublisher pub(channel);
    boost::shared_ptr<SimplePublisher> pub=SimplePublisher::Create(channel, "wt");
        pub->Publish(a);
}

