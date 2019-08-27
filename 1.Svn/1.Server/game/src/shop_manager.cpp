//Find
		if (!pItemGroup->GetValue(i, "price", shopItems[i].price))
		{
			sys_err("row(%d) of group items of group %s does not have price column", i, pNode->GetNodeName().c_str());
			return false;
		}
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
		char getval[256];
		for (int j = 0; j < ITEM_ATTRIBUTE_MAX_NUM; j++) {
			if (j < ITEM_SOCKET_MAX_NUM) {
				snprintf(getval,sizeof(getval), "socket%d", j);
				if (!pItemGroup->GetValue(i, getval, shopItems[i].alSockets[j])) {
					sys_err("row(%d) stage %d of group items of group %s does not have socket column", i,j, pNode->GetNodeName().c_str());
					return false;
				}
			}
			snprintf(getval,sizeof(getval), "attr_type%d", j);
			if (!pItemGroup->GetValue(i, getval, shopItems[i].aAttr[j].bType)) {
				sys_err("row(%d) stage %d of group items of group %s does not have attr_type column", i, j, pNode->GetNodeName().c_str());
				return false;
			}
			snprintf(getval,sizeof(getval), "attr_value%d", j);
			if (!pItemGroup->GetValue(i, getval, shopItems[i].aAttr[j].sValue)) {
				sys_err("row(%d) stage %d of group items of group %s does not have attr_value column", i, j, pNode->GetNodeName().c_str());
				return false;
			}
		}
		if (pItemGroup->GetValue(i, "price_type", shopItems[i].price_type) && pItemGroup->GetValue(i, "price_vnum", shopItems[i].price_vnum) && shopItems[i].price_type == 3) {
			if (shopItems[i].price_type > 4 || shopItems[i].price_type < 1) {
				sys_err("row(%d) of group items of group %s price_type is wrong!", i, pNode->GetNodeName().c_str());
				return false;
			}
			TItemTable * pProto = ITEM_MANAGER::instance().GetTable(shopItems[i].price_vnum);
			if (!pProto) {
				sys_err("NOT GET ITEM PROTO %d", shopItems[i].price_vnum);
				return false;
			}
		}
#endif