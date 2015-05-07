#include <stdlib.h>
#include <stdio.h>
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include "SimplePublisher.h"
#include "img.pb.h"

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

    img filenames;
    filenames.set_src("/home/wanghui/src");
    filenames.set_dst("/home/wanghui/dst");
    
    for (int i = 0; i<5;i++)
    {
        char temp[10];
        sprintf(temp, "%d", i);
        string str(temp);
        filenames.add_name(str);
    }

    string a;
    filenames.SerializeToString(&a);

   // SimplePublisher pub(channel);
    boost::shared_ptr<SimplePublisher> pub=SimplePublisher::Create(channel, "wt");
        pub->Publish(a);
}

