#include "easylogging++.h"
 
INITIALIZE_EASYLOGGINGPP
 
int main(int argc, char** argv)
{
	/// 防止Fatal级别日志中断程序
	el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);	
	/// 选择划分级别的日志	
	el::Loggers::addFlag(el::LoggingFlag::HierarchicalLogging);				
	/// 设置级别门阀值，修改参数可以控制日志输出
	el::Loggers::setLoggingLevel(el::Level::Global);	
 
	LOG(TRACE);
	LOG(DEBUG);
	LOG(FATAL);
	LOG(ERROR);
	LOG(WARNING);
	LOG(INFO);
	VLOG(0);		
 
	/// Debug模式日志记录
	DLOG(TRACE);
	DLOG(DEBUG);
	DLOG(FATAL);
	DLOG(ERROR);
	DLOG(WARNING);
	DLOG(INFO);
	DVLOG(0);
	
	system("pause");
	return 0;
}
