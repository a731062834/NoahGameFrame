/*
            This file is part of: 
                NoahFrame
            https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2018 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef NFC_LOG_MODULE_H
#define NFC_LOG_MODULE_H

#include "NFComm/NFPluginModule/NFILogModule.h"

class NFCLogModule
    : public NFILogModule
{
public:

    NFCLogModule(NFIPluginManager* p);
    virtual ~NFCLogModule() {}

    virtual bool Awake();
    virtual bool Init();
    virtual bool Shut();

    virtual bool BeforeShut();
    virtual bool AfterInit();

    virtual bool Execute();

    ///////////////////////////////////////////////////////////////////////
    virtual void LogStack();

    virtual bool LogElement(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strElement, const std::string& strDesc, const char* func = "", int line = 0);
    virtual bool LogProperty(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strProperty, const std::string& strDesc, const char* func = "", int line = 0);
    virtual bool LogRecord(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strRecord, const std::string& strDesc, const int nRow, const int nCol, const char* func = "", int line = 0);
    virtual bool LogRecord(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strRecord, const std::string& strDesc, const char* func = "", int line = 0);
    virtual bool LogObject(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strDesc, const char* func = "", int line = 0);

    virtual bool LogNormal(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strInfo, const char* func = "", int line = 0);
    virtual bool LogNormal(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strInfo, const int64_t nDesc, const char* func = "", int line = 0);
    virtual bool LogNormal(const NF_LOG_LEVEL nll, const NFGUID ident, const std::string& strInfo, const std::string& strDesc, const char* func = "", int line = 0);
    virtual bool LogNormal(const NF_LOG_LEVEL nll, const NFGUID ident, const std::ostringstream& stream, const char* func = "", int line = 0);

    virtual bool LogDebug(const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogInfo(const std::string& strLog, const  char* func = "", int line = 0);
    virtual bool LogWarning(const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogError(const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogFatal(const std::string& strLog, const char* func = "", int line = 0);

    virtual bool LogDebug(const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogInfo(const std::ostringstream& stream, const  char* func = "", int line = 0);
    virtual bool LogWarning(const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogError(const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogFatal(const std::ostringstream& stream, const char* func = "", int line = 0);

    virtual bool LogDebug(const NFGUID ident, const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogInfo(const NFGUID ident, const std::string& strLog, const  char* func = "", int line = 0);
    virtual bool LogWarning(const NFGUID ident, const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogError(const NFGUID ident, const std::string& strLog, const char* func = "", int line = 0);
    virtual bool LogFatal(const NFGUID ident, const std::string& strLog, const char* func = "", int line = 0);

    virtual bool LogDebug(const NFGUID ident, const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogInfo(const NFGUID ident, const std::ostringstream& stream, const  char* func = "", int line = 0);
    virtual bool LogWarning(const NFGUID ident, const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogError(const NFGUID ident, const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual bool LogFatal(const NFGUID ident, const std::ostringstream& stream, const char* func = "", int line = 0);

    virtual bool LogDebugFunctionDump(const NFGUID ident, const int nMsg, const std::string& strArg, const char* func = "", const int line = 0);
    virtual bool ChangeLogLevel(const std::string& strLevel);
    
    virtual void StackTrace();
    virtual void StartTimeCheckPoint(const std::ostringstream& stream, const char* func = "", int line = 0);
    virtual void EndTimeCheckPoint(const int milliSecond = 1, const char* func = "", int line = 0);

protected:
    virtual bool Log(const NF_LOG_LEVEL nll, const char* format, ...);

    static bool CheckLogFileExist(const char* filename);
    static void rolloutHandler(const char* filename, std::size_t size);

private:
    static unsigned int idx;
    uint64_t mnLogCountTotal;
};

#endif
