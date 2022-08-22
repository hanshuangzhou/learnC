/**
 * @file 
 * @author 寒霜洲
 * @brief Create a process for receiving msg through message queue
 * @version 0.1 Create file
 *          0.2 use API mq_open mq_receive to establish MQ and receive msg.The msg is in char array.
 *              if the size of msg in MQ is less than zero, exit receive peocess.
 *                  The func is set by O_NONBLOCK.
 *          0.3 transfer proto msg between process.
 *          0.4 use easylogging++ for output log.
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
#include <google/protobuf/message.h> //contain 序列化/反序列化 API
#include "../Proto/event.pb.h"
#include "../Log/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

using namespace std;

int main() {
    // 注册配置easylogging
    // 选择划分级别的日志	
	el::Loggers::addFlag(el::LoggingFlag::HierarchicalLogging);
	// 设置级别门阀值，修改参数可以控制日志输出
	el::Loggers::setLoggingLevel(el::Level::Global);
 
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.setGlobally(el::ConfigurationType::ToFile, "false");
    defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");
    defaultConf.set(el::Level::Debug, el::ConfigurationType::Format, DEBUG_FORMAT);
    
    el::Loggers::reconfigureLogger("default", defaultConf);

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 25;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    mqd_t mq_date;
    mq_date = mq_open(MQ_NAME, O_RDONLY|O_CREAT|O_NONBLOCK, S_IRUSR, &attr);
    if (mq_date < 0) {
        LOG(ERROR) << "create or open MQ failed\n";
        exit(EXIT_FAILURE);
    } else {
        LOG(DEBUG) << "open MQ success\n";
    }

    char* rcv_msg = new char[1024];
    memset(rcv_msg, 0, 1024);
    long outsize = 0;

    date::door::Event ProtoMsg;
    int receiveOK = -1;
    while (1)
    {
        receiveOK = mq_receive(mq_date, rcv_msg, 1024, NULL);
        if (receiveOK > 0) {
            ProtoMsg.ParseFromString(rcv_msg);
            //printf("receive msg eventtype: --%d-- success\n", (int)ProtoMsg.eventtype());
            LOG(DEBUG) << "receive msg eventtype: --" << (int)ProtoMsg.eventtype() << "-- success\n";
        } else {
            if (errno == EAGAIN) {
                LOG(ERROR) << "message queue is empty \n";
                mq_close(mq_date);

                if (mq_unlink(MQ_NAME) != -1) {
                    delete[] rcv_msg;
                    exit(EXIT_FAILURE);
                }
            }
            
        }
        sleep(1);
    }
    

    return 0;
}