//Find
	if (!InitializeShopTable())
	{
		sys_err("InitializeShopTable FAILED");
		return false;
	}
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	if (!InitializeShopEXTable())
	{
		sys_err("InitializeShopEXTable FAILED");
		return false;
	}
#endif

//Find
bool CClientManager::InitializeShopTable()
{
	...
}

///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
bool CClientManager::InitializeShopEXTable()
{
	MYSQL_ROW data;

	char s_szQuery[512];
	int len = sprintf(s_szQuery, "SELECT shopex.vnum, shopex.name, shopex.npc_vnum, shopex_item.item_vnum, shopex_item.count, shopex_item.price, shopex_item.price_vnum, shopex_item.price_type+0, ");
	
	for (BYTE i = 0; i < ITEM_SOCKET_MAX_NUM; i++)
		len += sprintf(s_szQuery + len, "socket%d, ", i);

	for (BYTE i = 0; i < ITEM_ATTRIBUTE_MAX_NUM; i++) {
		len += sprintf(s_szQuery + len, "attrtype%d, attrvalue%d ", i, i);
		if (i != ITEM_ATTRIBUTE_MAX_NUM - 1) // before FROM
			len += sprintf(s_szQuery + len, ", ");
	}

	len += sprintf(s_szQuery + len, "FROM shopex LEFT JOIN shopex_item ON shopex.vnum = shopex_item.shop_vnum ORDER BY shopex.vnum, shopex_item.item_vnum");

	std::unique_ptr<SQLMsg> pkMsg(CDBManager::instance().DirectQuery(s_szQuery));

	SQLResult* pRes = pkMsg->Get();

	if (m_pShopEXTable)
	{
		delete[](m_pShopEXTable);
		m_pShopEXTable = NULL;
	}
	
	if (!pRes->uiNumRows)
		return true;

	std::map<int, TShopTable*> map_shop;

	TShopTable* shop_table = m_pShopEXTable;

	while ((data = mysql_fetch_row(pRes->pSQLResult)))
	{
		int col = 0;
		int iShopVnum = 0;
		str_to_number(iShopVnum, data[col++]);

		if (map_shop.end() == map_shop.find(iShopVnum)) {
			shop_table = new TShopTable;
			std::memset(shop_table, 0, sizeof(TShopTable));
			shop_table->dwVnum = iShopVnum;
			map_shop[iShopVnum] = shop_table;
		}
		else
			shop_table = map_shop[iShopVnum];

		std::memcpy(shop_table->szShopName, data[col++], sizeof(shop_table->szShopName));
		str_to_number(shop_table->dwNPCVnum, data[col++]);

		TShopItemTable* pItem = &shop_table->items[shop_table->byItemCount];

		str_to_number(pItem->vnum, data[col++]);
		str_to_number(pItem->count, data[col++]);
		str_to_number(pItem->price, data[col++]);
		str_to_number(pItem->price_vnum, data[col++]);
		str_to_number(pItem->price_type, data[col++]);
		
		for (BYTE i = 0; i < ITEM_SOCKET_MAX_NUM; i++)
			str_to_number(pItem->alSockets[i], data[col++]);
		for (BYTE i = 0; i < ITEM_ATTRIBUTE_MAX_NUM; i++) {
			str_to_number(pItem->aAttr[i].bType, data[col++]);
			str_to_number(pItem->aAttr[i].sValue, data[col++]);
		}

		if (pItem->vnum)
			++shop_table->byItemCount;
	}

	m_pShopEXTable = new TShopTable[map_shop.size()];
	m_iShopEXTableSize = map_shop.size();

	int i = 0;
	for (std::map<int, TShopTable*>::const_iterator it = map_shop.begin(); it != map_shop.end(); ++it, ++i)
		std::memcpy((m_pShopEXTable + i), it->second, sizeof(TShopTable));

	return true;
}
#endif