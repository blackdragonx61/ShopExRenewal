//Find
	return ReadShopTableEx(szShopTableExFileName);
	
///Change
#if defined(ENABLE_RENEWAL_SHOPEX)
	return true;
#else
	return ReadShopTableEx(szShopTableExFileName);
#endif

//Find
void CShopManager::Destroy()

///Change
void CShopManager::Destroy()
{
#if defined(ENABLE_RENEWAL_SHOPEX)
	for (TShopMap::iterator it = m_map_pkShopByNPCVnum.begin(); it != m_map_pkShopByNPCVnum.end(); ++it)
		delete it->second;
	m_map_pkShopByNPCVnum.clear();
#else
	TShopMap::iterator it = m_map_pkShop.begin();

	while (it != m_map_pkShop.end())
	{
		M2_DELETE(it->second);
		++it;
	}

	m_map_pkShop.clear();
#endif
}

///Add new func
#if defined(ENABLE_RENEWAL_SHOPEX)
bool CShopManager::InitializeShopEX(TShopTable* table, int size)
{
	typedef std::multimap <DWORD, TShopTableEx> TMapNPCshop;
	TMapNPCshop map_npcShop;

	for (int i = 0; i < size; ++i, ++table)
	{
		TShopTableEx shopTable;
		shopTable.dwVnum = table->dwVnum;
		shopTable.name = table->szShopName;
		shopTable.coinType = SHOP_COIN_TYPE_GOLD;

		if (shopTable.name.length() >= SHOP_TAB_NAME_MAX) {
			sys_err("Shop name length must be less than %d. Error %s", SHOP_TAB_NAME_MAX, shopTable.name.c_str());
			return false;
		}

		CGrid grid(5, 9);

		memset(&shopTable.items[0], 0, sizeof(shopTable.items));

		for (size_t j = 0; j < table->byItemCount; j++)
		{
			TItemTable* item_table = ITEM_MANAGER::instance().GetTable(table->items[j].vnum);
			if (!item_table) {
				sys_err("vnum(%d) of group items of group %s does not exist.", table->items[j].vnum, shopTable.name.c_str());
				return false;
			}

			int iPos = grid.FindBlank(1, item_table->bSize);
			if (iPos == -1) {
				sys_err("vnum(%d) of group items of group %s there is no space!", table->items[j].vnum, shopTable.name.c_str());
				return false;
			}

			grid.Put(iPos, 1, item_table->bSize);
			shopTable.items[iPos] = table->items[j];
			shopTable.byItemCount++;
		}
		if (m_map_pkShopByNPCVnum.find(table->dwNPCVnum) != m_map_pkShopByNPCVnum.end()) {
			sys_err("NPCVNUM(%d) already used.", table->dwNPCVnum);
			return false;
		}

		map_npcShop.insert(TMapNPCshop::value_type(table->dwNPCVnum, shopTable));
	}

	for (TMapNPCshop::iterator it = map_npcShop.begin(); it != map_npcShop.end(); ++it)
	{
		const DWORD npcVnum = it->first;
		TShopTableEx& table = it->second;

		if (m_map_pkShop.find(table.dwVnum) != m_map_pkShop.end()) {
			sys_err("Shop vnum(%d) already exists.", table.dwVnum);
			return false;
		}

		TShopMap::const_iterator shop_it = m_map_pkShopByNPCVnum.find(npcVnum);
		LPSHOPEX pkShopEx = NULL;

		if (m_map_pkShopByNPCVnum.end() == shop_it) {
			pkShopEx = new CShopEx;
			pkShopEx->Create(0, npcVnum);
			m_map_pkShopByNPCVnum.insert(TShopMap::value_type(npcVnum, pkShopEx));
		}
		else {
			pkShopEx = dynamic_cast <CShopEx*> (shop_it->second);
			if (!pkShopEx) {
				sys_err("NPC(%d) Shop is not extended version.", shop_it->first);
				return false;
			}
		}

		if (pkShopEx->GetTabCount() >= SHOP_TAB_COUNT_MAX) {
			sys_err("ShopEx cannot have tab more than %d.", SHOP_TAB_COUNT_MAX);
			delete pkShopEx;
			return false;
		}

		pkShopEx->AddShopTable(table);
		m_map_pkShop.insert(TShopMap::value_type(table.dwVnum, pkShopEx));
	}

	return true;
}
#endif