# SimpleAmqpClient-examples
SimpleAmqpClient is an easy-to-use C++ wrapper around the rabbitmq-c C library. Here is the examples for SimpleAmqpClient library application.

# Installing

protobuf: https://github.com/google/protobuf

SimpleAmqpClient: https://github.com/alanxz/SimpleAmqpClient

# note:

    std::string BasicConsume(const std::string &queue,
                             const std::string &consumer_tag = "",
                             bool no_local = true,
                             bool no_ack = true,
                             bool exclusive = true,
                             boost::uint16_t message_prefetch_count = 1);

the param "exclusive" true for only one client to access the queue, false is for multithread client to access the queue.

# Docs
protobuf: https://developers.google.com/protocol-buffers/

