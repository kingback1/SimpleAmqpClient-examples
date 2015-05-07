#include <stdlib.h>
#include <stdio.h>
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include "SimpleSubscriber.h"
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

    //    SimpleSubscriber pub(channel,"wt");
    boost::shared_ptr<SimpleSubscriber> pub=SimpleSubscriber::Create(channel,"wt");
    
    while(1)
    {
        string a;
      //  a= pub.WaitForMessageString(5000);
        
        Envelope::ptr_t envelope;
       bool flag =  channel->BasicConsumeMessage("SimpleSubscriber_", envelope, 7000);
        if (flag == false)
        {
            cout << "timeout\n"<<endl;
            break;
        }
    
        a=envelope->Message()->Body();

        img filenames;
        filenames.ParseFromString(a);

        for (int i=0; i<filenames.name_size();i++)
        {
            cout << "src = " << filenames.src() << " ";
            cout << "dst = " << filenames.dst() << " ";
            cout << "img = " << filenames.name(i) << endl;
        }
    }
    cout << "OK"<<endl;
}

