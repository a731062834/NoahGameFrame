// -------------------------------------------------------------------------
//    @FileName      :    NFCElementInfoModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2012-12-15
//    @Module           :    NFCElementInfoModule
//
// -------------------------------------------------------------------------

#ifndef _NFC_ELEMENTINFO_MODULE_H_
#define _NFC_ELEMENTINFO_MODULE_H_

#include <string>
#include <map>
///
#include <iostream>
#include <iostream>
#include "NFComm/NFCore/NFMap.h"
#include "NFComm/NFCore/NFList.h"
#include "NFComm/RapidXML/rapidxml.hpp"
#include "NFComm/RapidXML/rapidxml_iterators.hpp"
#include "NFComm/RapidXML/rapidxml_print.hpp"
#include "NFComm/RapidXML/rapidxml_utils.hpp"
#include "NFComm/NFCore/NFCValueList.h"
#include "NFComm/NFCore/NFCRecord.h"
#include "NFComm/NFCore/NFList.h"
#include "NFComm/NFCore/NFCPropertyManager.h"
#include "NFComm/NFCore/NFCRecordManager.h"
#include "NFComm/NFCore/NFCComponentManager.h"
#include "NFComm/NFPluginModule/NFIElementInfoModule.h"
#include "NFComm/NFPluginModule/NFILogicClassModule.h"

class NFCLogicClass;

class ElementConfigInfo
{
public:
    ElementConfigInfo()
    {
        m_pPropertyManager = new NFCPropertyManager(NFIDENTID(0));
        m_pRecordManager = new NFCRecordManager(NFIDENTID(0));
        m_pComponentManager = new NFCComponentManager(NFIDENTID(0));
    }

    virtual ~ElementConfigInfo()
    {
        delete m_pComponentManager;
        delete m_pRecordManager;
        delete m_pPropertyManager;
    }

    NFIPropertyManager* GetPropertyManager()
    {
        return m_pPropertyManager;
    }

    NFIRecordManager* GetRecordManager()
    {
        return m_pRecordManager;
    }

    NFIComponentManager* GetComponentManager()
    {
        return m_pComponentManager;
    }
protected:

    //std::string mstrConfigID;

    NFIPropertyManager* m_pPropertyManager;
    NFIRecordManager* m_pRecordManager;
    NFIComponentManager* m_pComponentManager;
};

class NFCElementInfoModule
    : public NFIElementInfoModule,
      NFMap<std::string, ElementConfigInfo>
{
public:
    NFCElementInfoModule(NFIPluginManager* p);
    virtual ~NFCElementInfoModule();

    virtual bool Init();
    virtual bool Shut();

	virtual bool AfterInit();
	virtual bool BeforeShut();
	virtual bool Execute(const float fLasFrametime, const float fStartedTime);
	virtual void OnReload(const char* strModuleName, NFILogicModule* pModule);


    virtual bool Load();
    virtual bool Save();
	virtual bool Clear();

    virtual bool LoadSceneInfo(const std::string& strFileName, const std::string& strClassName);

    virtual bool ExistElement(const std::string& strConfigName);

    virtual NFIPropertyManager* GetPropertyManager(const std::string& strConfigName);
    virtual NFIRecordManager* GetRecordManager(const std::string& strConfigName);

    virtual int QueryPropertyInt(const std::string& strConfigName, const std::string& strPropertyName);
    virtual float QueryPropertyFloat(const std::string& strConfigName, const std::string& strPropertyName);
    virtual double QueryPropertyDouble(const std::string& strConfigName, const std::string& strPropertyName);
    virtual const std::string& QueryPropertyString(const std::string& strConfigName, const std::string& strPropertyName);

protected:
    virtual NFIProperty* QueryProperty(const std::string& strConfigName, const std::string& strPropertyName);

    virtual bool Load(rapidxml::xml_node<>* attrNode, NFILogicClass* pLogicClass);

	virtual bool LegalNumber(const char* str);
protected:
    NFILogicClassModule* m_pLogicClassModule;
    bool mbLoaded;
};

#endif