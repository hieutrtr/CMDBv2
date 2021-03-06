#pragma once
#include "CIInfoUpdateProcessor.h"

class CRackController;
class CRackModel;

class CCoreSwitchInfoUpdateProcessor : public CCIInfoUpdateProcessor
{
public:
	CCoreSwitchInfoUpdateProcessor(const string& strCfgFile);
	~CCoreSwitchInfoUpdateProcessor(void);
	bool Connect();
protected:
	bool CanComputeData() { return true; }	
	void InsertData(BSONObj boNewCIInfo);
	void DeleteData(BSONObj boNewCIInfo);
	void UpdateData(BSONObj boOldCIInfo, BSONObj boNewCIInfo, BSONObj boChangedFields);
/*****************************************
*Author: DuyMN
******************************************/
protected:
	CRackController *m_pRackController;
	CRackModel *m_pRackModel;
private:
	void InsertSwitchGraphicData(BSONObj boNewCIInfo);
	void DeleteSwitchGraphicData(BSONObj boNewCIInfo);
	void UpdateSwitchGraphicData(BSONObj boOldCIInfo, BSONObj boNewCIInfo, BSONObj boChangedFields);
//******************************************
};