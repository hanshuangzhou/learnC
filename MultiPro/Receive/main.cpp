/**
 * @file 
 * @author 寒霜洲
 * @brief Create a process for receiving msg through message queue
 * @version 0.1 Create file
 *          0.2 use API mq_open mq_receive to establish MQ and receive msg.The msg is in char array.
 *              if the size of msg in MQ is less than zero, exit receive peocess.
 *                  The func is set by O_NONBLOCK.
 *              TODO use msg by protobuf.
 */

#include <iostream>
#include <string>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "../def.h"
using namespace std;

int main() {
    char mq_buffer[1024];

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 25;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    mqd_t mq_date;
    mq_date = mq_open(MQ_NAME, O_RDONLY|O_CREAT|O_NONBLOCK, S_IRUSR, &attr);
    if (mq_date < 0) {
        printf("create or open MQ failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("open MQ success\n"); 
    }

    int receiveOK = -1;
    while (1)
    {
        receiveOK = mq_receive(mq_date, mq_buffer, 1024, NULL);
        if (receiveOK > 0) {
            printf("receive msg --%s-- success\n", mq_buffer);
        } else {
            if (errno == EAGAIN) {
                printf("message queue is empty \n");
                mq_close(mq_date);

                if (mq_unlink(MQ_NAME) != -1) {
                    exit(EXIT_FAILURE);
                }
            }
            
        }
        sleep(1);
    }
    

    return 0;
}