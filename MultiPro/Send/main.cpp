/**
 * @file 
 * @author 寒霜洲
 * @brief Create a process for sending msg through message queue
 * @version 0.1 Create file
 *          0.2 use API mq_open mq_send to establish MQ and send msg.The msg is in char array.
 *              if the size of msg not handled is more than mq_maxmsg, exit send peocess.
 *                  The func is set by O_NONBLOCK.
 *          0.3 transfer proto msg between process.
 */

#include <iostream>
#include <string>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "../def.h"
#include <google/protobuf/message.h> //contain 序列化/反序列化 API
#include "../Proto/event.pb.h"

using namespace std;

int main() {
    date::door::Event evt;
    evt.set_eventtype(date::door::SayBye);
    string msg;
    evt.SerializeToString(&msg);

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 25;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    mqd_t mq_date;
    mq_date = mq_open(MQ_NAME, O_WRONLY|O_CREAT|O_NONBLOCK, S_IWUSR, &attr); // note O_NONBLOCK
    if (mq_date < 0) {
        printf("create or open MQ failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("open MQ success\n"); 
    }

    int sendOK = -1;
    while (1)
    {
        sendOK = mq_send(mq_date, msg.c_str(), sizeof(msg.length()), 0);
        if (sendOK == 0) {
            printf("send msg success\n");
        } else {
            if (errno == EAGAIN) {
                printf("msg queue is full \n");
                mq_close(mq_date);
                exit(EXIT_FAILURE);
            }
            
        }
        sleep(1);
    }
    

    return 0;
}