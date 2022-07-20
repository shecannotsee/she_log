简单的日志库实现

请使用 namespace sheLog

Time类提供了日期和时间的格式转换，以及计时功能

SheLog类提供了简易的写入日志功能

用法如下

`sheLog::SheLog t("./","log");//初始化
t.logMessage(sheLog::logLevel::DEBUG,"123");//写入信息以及设置日志等级`
